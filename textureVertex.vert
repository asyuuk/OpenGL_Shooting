// shader.vert
#version 330 core
layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aTexCoord;
out vec2 TexCoord;
uniform vec2 uSpriteIndex;//スプライトシートの列行
uniform vec2 uSheetSize;//スプライトシート全体のサイズ
uniform float uTextureSize;//テクスチャのサイズ
void main() {

    //uv補正
    TexCoord = aTexCoord;


}