// shader.vert
#version 330 core
layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aTexCoord;
out vec2 TexCoord;
uniform vec2 uOffset;
uniform vec2 uSpriteIndex;//スプライトシートの列行
uniform vec2 uSheetSize;//スプライトシート全体のサイズ
uniform float uTextureSize;//テクスチャのサイズ
void main() {
    vec2 cellSize=1.0/uSheetSize;
    // スプライトシートのインデックスからテクスチャ座標を計算
    //表示したいスプライトUVoffset
    vec2 uvOffset = uSpriteIndex * cellSize;
    

    gl_Position = vec4((aPos+uOffset)*uTextureSize, 1.0, 1.0);

    //uv補正
    TexCoord = aTexCoord * cellSize + uvOffset;


}