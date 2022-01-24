#ifndef TEXT_H
#define TEXT_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H
#include "Shader.h"
#include <locale>
#include <codecvt>

#include <iostream>
#include <map>
// Holds all state information relevant to a character as loaded using FreeType
struct Character
{
    GLuint TextureID;   // ID handle of the glyph texture
    glm::ivec2 Size;    // Size of glyph
    glm::ivec2 Bearing;  // Offset from baseline to left/top of glyph
    GLuint Advance;    // Horizontal offset to advance to next glyph
};


class Text
{
public:
    Text(int window_width, int window_height, const char* path);
    virtual ~Text();
    void RenderText(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
    void fillChar(wchar_t c);
protected:

private:
    Shader shader;
    FT_Library ft;
    FT_Face face;

    GLuint VAO, VBO;

    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;

    std::map<wchar_t, Character> Characters;
};

#endif 