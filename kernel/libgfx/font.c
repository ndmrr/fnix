#include "gfx.h"
static gfxFont active_font;
gfxFont gfxCreateFont(uint8_t* font, uint32_t w, uint32_t h)
{
    gfxFont _font;
    _font.font = font;
    _font.w = w;
    _font.h = h;
    return _font;
}
void PushFontToActive(gfxFont font)
{
    active_font = font;
}
gfxFont GetActiveFont(void) 
{
    return active_font;
}
void DrawText(gfxFont font, const char* text, uint32_t x, uint32_t y)
{
    uint32_t len = 0;
    while (text[len++] != '\0');
    for (uint32_t i=0;i<len;i++)
    {
        DrawCharacter(font, text[i], x + (i*font.w), y);
    }
}
void DrawCharacter(gfxFont font, char character, uint32_t x, uint32_t y)
{
    uint32_t mask[8] = {1,2,4,8,16,32,64,128};
    uint8_t* glyph = font.font+(int)character*font.h;
    
    for (uint32_t _y=0;_y<font.h;_y++)
    {
        for (uint32_t _x=0;_x <font.w;_x++)
        {
            if (glyph[_y]&mask[_x])
                gfxPlotPixel(x-_x, y+_y-12);
        }
    }
    
}