#include <cstdlib> // atexit
#include <iostream>
#include <GL/glew.h> // glfwより前に
#include <GLFW/glfw3.h>
//-------------------------------------
// プログラムオブジェクトを作成
// vsrc : バーテックスシェーダのソース文字列
// fsrc : フラグメントシェーダのソース文字列

// プログラムオブジェクト作成関数 (コンテキスト確定後に呼ぶ)
GLint createProgram(const char* vsrc, const char* fsrc) 
{
	//(1) 空のプログラムオブジェクトを作成
	const GLint program = glCreateProgram();

	// 個々のシェーダをコンパイル
	if (vsrc != NULL) { 
		//(2) 空のシェーダオブジェクト作成
		const GLint vobj = glCreateShader(GL_VERTEX_SHADER); 

		//(3) GLSL文字列ソースを結びつける
		glShaderSource(vobj, 1, &vsrc, NULL);

		//(4) シェーダオブジェクトのGLSLをコンパイル (ドライバが)
		glCompileShader(vobj); 

		//(5) プログラムオブジェクトにシェーダオブジェクトを組み込む
		glAttachShader(program, vobj);
		glDeleteShader(vobj); // Detachされたらシェーダオブジェクトは削除されるように
	}

	// 統合したプログラムオブジェクトをリンク
	
	//(6) GPU上でvシェーダの入力先，fシェーダの出力先を指定
	glBindAttribLocation(program, 0, "position");  // ID, 頂点属性スロット０，in変数
	glBindFragDataLocation(program, 0, "fragment"); // ID, flag出力スロット，out変数

	//(7) プログラムオブジェクトをリンク．複数のシェーダオブジェクトが1つのプログラムに
	glLinkProgram(program); 

	// 作成したプログラムオブジェクトを返す
	return program;
}

//-------------------------------------
// GLFW main処理
int main()
{
	//[1] GLFWを初期化する（このプログラムで OpenGL を使用するための準備）
	if (glfwInit() == GL_FALSE)
	{
		// エラー用の出力cerrと，エラー用の戻り値1
		std::cerr << "can't initialize GLFW" << std::endl;
		return 1;
	}

	//プログラム正常終了時の処理を登録
	atexit(glfwTerminate);

//---------------
	// ウィンドウの特性（ヒント）を設定
	// バージョン指定（3.2）
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

	// macでのみ必要
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
	// プロファイル指定（Core Profile）
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

//---------------
	//[2]ウィンドウを作成する
	GLFWwindow *const window = glfwCreateWindow(640, 480, "window_name", NULL, NULL);
	// window：ウィンドウ情報の構造体の先頭ポインタ
	// constにしてるので後から別の GLFWwindow* は代入できない
	if (window == NULL)
	{
		std::cerr << "can't create GLFW window...." << std::endl;
		return 1; // glfwTerminate()
	}

	// windowに紐づくコンテキストをカレントコンテキスト(gl*関数の処理対象)に
	glfwMakeContextCurrent(window);

	//---------------
	// GLEW初期化(ドライバに関数ポインタの取得手続き，コンテキストに依存)
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "can't initialize GLEW" << std::endl;
		return 1;
	}
	//---------------
	// 背景色を指定
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	// ウィンドウ作成後のV-sync設定(ウィンドウのfpsに合わせる)
	glfwSwapInterval(1);

//-------------------------------------
	// vシェーダのソース単一文字列(GLSL)
	static constexpr GLchar vsrc[] = // 外に漏らさない＆ビルド時に内容確定
		"#version 150 core¥n"
		"in vec4 osition;¥n"
		"void main()¥n"
		"{¥n"
		" gl_Position = position;¥n"
		"}¥n";

	// fシェーダのソース単一文字列(GLSL)
	static constexpr GLchar fsrc[] =
		"#version 150 core¥n"
		"out vec4 fragment;¥n"
		"void main()¥n"
		"{¥n"
		" fragment = vec4(1.0, 0.0, 0.0, 1.0);¥n"
		"}¥n";





//-------------------------------------
	//[3] ウィンドウが開いている間処理を繰り返す
	while (glfwWindowShouldClose(window) == GL_FALSE)
	{
		// ウィンドウの描画内容を消去（上書き）
		glClear(GL_COLOR_BUFFER_BIT); //カラーバッファのみを指定しglClearColorで上書き

		//
		// 描画処理
		//


		//[4] GLFWは標準でダブルバッファなのでカラーバッファを入れ替える(画面表示)
		glfwSwapBuffers(window); // やらないと描画だけで表示されない（奥にあるまま）
		

		// イベントのチェック
		glfwWaitEvents(); // OSからイベントメッセージ来るまで描画停止(発生->対応するコールバックを発火->while描画先頭へ)
	}
}
//-------------------------------------