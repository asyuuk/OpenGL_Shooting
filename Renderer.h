#pragma once
#include<GL/glew.h>	

#include<GLFW/glfw3.h>
#include<iostream>
#include<string>
#include<map>
#include<unordered_map>
#include<list>

// GLM�̖��O��Ԃ��g�pGLM�������E�B���h�E�̏������A�e�N�X�`���̓ǂݍ��݁A�`�揈���Ȃǂ��s��Renderer�N���X���`���܂��B
namespace glm
{
	class Renderer
	{
	public:
		Renderer();
		~Renderer();
		void Run();
		void GL(int width,int height);//OpenGL�̏�����������B
		void InitGL();// OpenGL�̏�����
		void InitWindow(int Width, int Height); //�E�B���h�E�̏�����
		void GlewInit(); // GLEW�̏�����
		void MainLoop(); // ���C�����[�v
		void Render(); // �`�揈��
		bool LoadTexture(const std::string& filePath,const std::string& filename); // �e�N�X�`���̓ǂݍ���
		bool DrawInit(); // �e�N�X�`���̕`��
		bool DrawImage(GLuint textureID,float offsetX,float offsetY); // �摜�̕`��
		bool DrawDivImage(GLuint textureID, float offsetX, float offsetY,int sheetX,int sheetY,int numX,int numY,float size); // �����摜�̕`��

		bool LoadShaderPrograms();
		bool LoadImages();

		void SetAspect(int width, int height); // �r���[�|�[�g�̐ݒ�
		std::string LoadShaderSource(const std::string& path); // �V�F�[�_�[�̏�����
		GLuint CompileShader(GLenum type, const std::string& source); // �V�F�[�_�[�̃R���p�C��

		bool CheckHitKey(int key); // �L�[���͂̃`�F�b�N



		GLuint CreateShaderProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource); // �V�F�[�_�[�v���O�����̍쐬

	private:
		int Width=1300; // �E�B���h�E�̕�
		int Height=1000; // �E�B���h�E�̍�
		GLuint shaderProgram; // �V�F�[�_�[�v���O����ID
		GLuint shaderProgramTextures;//�؂蕪���Ȃ��V�F�[�_�[


		GLuint textureID; // �e�N�X�`��ID

		GLuint VAO, VBO;

		int width, height, channels;

		float offsetX = 0.5, offsetY = 0; // �e�N�X�`���̃I�t�Z�b�g

		GLint offsetLoc;
		GLint uSpriteIndex;
		GLint uSheetSize;
		GLint uTextureSize;

		std::vector<GLuint> textureIDs; // �ǂݍ��񂾃e�N�X�`��ID�̃��X�g
		std::unordered_map<std::string, GLuint> textureMapID; // �e�N�X�`������ID�̃}�b�v
		GLFWwindow* window; // GLFW�E�B���h�E
		float vertices[16];
		
	};
}
