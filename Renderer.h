#pragma once
#include<GL/glew.h>	

#include<GLFW/glfw3.h>
#include<iostream>
#include<string>
#include<map>
#include<unordered_map>
#include<list>

// GLMの名前空間を使用GLM初期化ウィンドウの初期化、テクスチャの読み込み、描画処理などを行うRendererクラスを定義します。
namespace glm
{
	class Renderer
	{
	public:
		Renderer();
		~Renderer();
		void Run();
		void GL(int width,int height);//OpenGLの初期化をする。
		void InitGL();// OpenGLの初期化
		void InitWindow(int Width, int Height); //ウィンドウの初期化
		void GlewInit(); // GLEWの初期化
		void MainLoop(); // メインループ
		void Render(); // 描画処理
		bool LoadTexture(const std::string& filePath,const std::string& filename); // テクスチャの読み込み
		bool DrawInit(); // テクスチャの描画
		bool DrawImage(GLuint textureID,float offsetX,float offsetY); // 画像の描画
		bool DrawDivImage(GLuint textureID, float offsetX, float offsetY,int sheetX,int sheetY,int numX,int numY,float size); // 分割画像の描画

		bool LoadShaderPrograms();
		bool LoadImages();

		void SetAspect(int width, int height); // ビューポートの設定
		std::string LoadShaderSource(const std::string& path); // シェーダーの初期化
		GLuint CompileShader(GLenum type, const std::string& source); // シェーダーのコンパイル

		bool CheckHitKey(int key); // キー入力のチェック



		GLuint CreateShaderProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource); // シェーダープログラムの作成

	private:
		int Width=1300; // ウィンドウの幅
		int Height=1000; // ウィンドウの高
		GLuint shaderProgram; // シェーダープログラムID
		GLuint shaderProgramTextures;//切り分けないシェーダー


		GLuint textureID; // テクスチャID

		GLuint VAO, VBO;

		int width, height, channels;

		float offsetX = 0.5, offsetY = 0; // テクスチャのオフセット

		GLint offsetLoc;
		GLint uSpriteIndex;
		GLint uSheetSize;
		GLint uTextureSize;

		std::vector<GLuint> textureIDs; // 読み込んだテクスチャIDのリスト
		std::unordered_map<std::string, GLuint> textureMapID; // テクスチャ名とIDのマップ
		GLFWwindow* window; // GLFWウィンドウ
		float vertices[16];
		
	};
}
