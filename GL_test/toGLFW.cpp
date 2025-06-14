//GLEW導入前のコード
/*
#include <cstdlib> //atexitがほしい
#include <iostream>
#include <GLFW/glfw3.h>


//int main()
{
	//(1)GLFWを初期化する（このプログラムで OpenGL を使用するための準備）
	//初期化に失敗した場合はglfwInit() の戻り値が GL_FALSEになる
	if (glfwInit() == GL_FALSE)
	{
		//エラー用の出力cerrと，エラー用の戻り値1
		std::cerr << "can't initialize GLFW" << std::endl;
		return 1;
	}

	//プログラム終了時の処理を登録する
	atexit(glfwTerminate);

	//(2)ウィンドウを作成する
	GLFWwindow* const window = glfwCreateWindow(640, 480, "window名", NULL, NULL);
	//constにしちゃってるので後から window に別の GLFWwindow* を代入したい場合に問題が出る。
	if (window == NULL)
	{
		//windowのポインタ(情報そのもの，ウィンドウの構造体の先頭ポインタ)が作成できなかったようだね
		std::cerr << "can't create GLFW window...." << std::endl;
		//glfwTerminate(); //取得したメモリ開放
		return 1;
	}

	//作成したウィンドウをカレント（OpenGLの処理対象）にする
	glfwMakeContextCurrent(window);

	//背景色を指定
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	//(3) ウィンドウが開いている間処理を繰り返す
	while (glfwWindowShouldClose(window) == GL_FALSE)
	{
		//ウィンドウの描画内容を消去（上書き）
		glClear(GL_COLOR_BUFFER_BIT); //カラーバッファのみを指定しglClearColorで上書き

		//
		//描画処理
		//


		//カラーバッファを入れ替える
		glfwSwapBuffers(window); //やんないと描画だけで表示されないよね


		//イベントのチェック
		glfwWaitEvents(); //停止しない(glfwPollEventsはイベントあるまで停止)
	}
}
*/