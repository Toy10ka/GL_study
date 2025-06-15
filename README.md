# GL_solution_test

このリポジトリは、OpenGL 学習用の簡単なサンプルプロジェクトです。Visual Studio を用いて GLFW と GLEW を利用する設定になっています。

- 💻 **プロジェクト内容**: C++ で書かれた OpenGL アプリケーションの最小構成。
- 🗂 **構成**:
  - `GL_solution_test.sln` – Visual Studio ソリューション
  - `GL_test/` – ソースコードとプロジェクトファイル
  - `vcpkg.json` – 依存ライブラリ (glfw3, glew)
- 🚀 **ビルド方法**:
  - Visual Studio でソリューションを開き、vcpkg を使って依存ライブラリを導入後、ビルドしてください。
  - または必要なライブラリを用意して `main.cpp` を直接コンパイルします。
- 📄 **サンプルコード**:
  - `main.cpp` – GLFW ウィンドウを生成し、GLEW を初期化するコード
  - `point.vert` / `point.flag` – シンプルなシェーダ例
- ❗ **注意**: プロジェクトは Windows 向けの設定になっているため、他環境では適宜修正が必要です。
