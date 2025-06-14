#include <cstdlib> //atexit
#include <iostream>
#include <GL/glew.h> //glfwより前に
#include <GLFW/glfw3.h>
//-------------------------------------
//プログラムオブジェクトを作成
//vsrc : バーテックスシェーダのソース文字列
//fsrc : フラグメントシェーダのソース文字列

//-------------------------------------
GLint createProgram(const char* vsrc, const char* fsrc) //一連の処理をする関数
{
	//空のプログラムオブジェクトを作成
	const GLint program = glCreateProgram();

	if (vsrc != NULL) {
		//バーテックスシェーダのシェーダオブジェクトを作ろう（vsrcあるなら）
		const GLint vobj = glCreateShader(GL_VERTEX_SHADER); //空を作る
		
		glShaderSource(vobj, 1, &vsrc, NULL); //文字列としてソースを結びつける
		glCompileShader(vobj); //結びつけたシェーダオブジェクト(のソース)をコンパイル

		//プログラムオブジェクトにVシェーダオブジェクトを組み込む
		glAttachShader(program, vobj);
		glDeleteShader(vobj); //Detachされたらシェーダオブジェクトは削除されるように
	}

	//プログラムオブジェクトをリンクしよう
	//個々のシェーダはコンパイルされているが，統合され実行可能な状態にはまだなってない
	
	//GPUがverシェーダの入力を受け取る場所，fragシェーダの出力されるものを渡す場所を指定
	glBindAttribLocation(program, 0, "position"); //スロット０，変数名はpotision
	glBindFragDataLocation(program, 0, "fragment");

	glLinkProgram(program); //リンクして複数のシェーダオブジェクトが1つのプログラムに

	//作成したプログラムオブジェクトを返す
	return program;
}

//-------------------------------------
// GLFW main処理
int main()
{
	//(1)GLFWを初期化する（このプログラムで OpenGL を使用するための準備）
	//初期化に失敗した場合はglfwInit() の戻り値が GL_FALSEになる
	if (glfwInit() == GL_FALSE)
	{
		//エラー用の出力cerrと，エラー用の戻り値1
		std::cerr << "can't initialize GLFW" << std::endl;
		return 1;
	}

	//プログラム正常終了時の処理を登録
	atexit(glfwTerminate);

//---------------
	//ウィンドウの特性（ヒント）を設定
	//バージョン指定（3.2）
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

	//macでのみ必要
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
	//プロファイル指定（Core Profile）
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

//---------------
	//(2)ウィンドウを作成する
	GLFWwindow *const window = glfwCreateWindow(640, 480, "window_name", NULL, NULL);
	//constにしてるので後から window に別の GLFWwindow* を代入したい場合に問題が出る
	if (window == NULL)
	{
		//windowのポインタ(情報そのもの，ウィンドウの構造体の先頭ポインタ)作成に失敗した場合
		std::cerr << "can't create GLFW window...." << std::endl;
		//glfwTerminate(); //取得したメモリ開放
		return 1;
	}

	//作成したウィンドウをカレント（OpenGLの処理対象）にする
	glfwMakeContextCurrent(window);
	//---------------
	//GLEW(ドライバに関数ポインタの取得手続きをしてくれる)はコンテキストに依存
	//有効なコンテキストを決めたためここで初期化
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		//GLEWの初期化に失敗
		std::cerr << "can't initialize GLEW" << std::endl;
		return 1;
	}
	//---------------
	//背景色を指定
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	//ウィンドウ作成後のV-sync設定(ウィンドウのfpsに合わせる)
	glfwSwapInterval(1);

//---------------
	//(3) ウィンドウが開いている間処理を繰り返す
	while (glfwWindowShouldClose(window) == GL_FALSE)
	{
		//ウィンドウの描画内容を消去（上書き）
		glClear(GL_COLOR_BUFFER_BIT); //カラーバッファのみを指定しglClearColorで上書き

		//
		//描画処理
		//


		//GLFWは標準でダブルバッファなのでカラーバッファを入れ替える(画面表示)
		glfwSwapBuffers(window); //やらないと描画だけで表示されない（奥にあるまま）
		

		//イベントのチェック
		glfwWaitEvents(); //OSからイベントメッセージ来るまで描画停止(発生->対応するコールバックを発火->while描画先頭へ)
	}
}
//-------------------------------------