// shader.vert
#version 330 core
layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aTexCoord;
out vec2 TexCoord;
uniform vec2 uSpriteIndex;//�X�v���C�g�V�[�g�̗�s
uniform vec2 uSheetSize;//�X�v���C�g�V�[�g�S�̂̃T�C�Y
uniform float uTextureSize;//�e�N�X�`���̃T�C�Y
void main() {

    //uv�␳
    TexCoord = aTexCoord;


}