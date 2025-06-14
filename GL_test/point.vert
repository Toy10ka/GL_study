#version 150 core //openGL3.2相当のGLSLバージョン1.5, core profile使用

in vec4 position; //前のパイプラインから送られた変数はin. 4要素からなるベクトル
                  //inは特にattribute変数と呼ばれ，頂点属性を格納している
void main(){      //シェーダプログラムはmainから始まるが引数がない  
	gl_position = position; //GLSL特有の変数(組み込み変数)
	                        //バーテックスシェーダでは必ずこの変数に値を代入する
}