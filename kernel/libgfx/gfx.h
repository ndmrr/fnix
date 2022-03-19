#ifndef GFX_H
#define GFX_H
#include <stdint.h>
typedef struct
{
    uint32_t* framebuffer_address;
    uint16_t  framebuffer_width;
    
} gfxGraphicsInfo;

typedef struct
{
    gfxGraphicsInfo info;
    uint32_t vertex_color;
    
} gfxGlobalRenderer;

typedef struct
{
    uint8_t* font;
    uint32_t w;
    uint32_t h;
    
} gfxFont;

gfxFont gfxCreateFont(uint8_t* font, uint32_t w, uint32_t h);
void DrawText(gfxFont font, const char* text, uint32_t x, uint32_t y);
void DrawCharacter(gfxFont font, char character, uint32_t x, uint32_t y);
void PushFontToActive(gfxFont font);
gfxFont GetActiveFont(void);
void gfxCreateGlobalRenderer(gfxGraphicsInfo gfx);
void gfxSetVertexColor(uint8_t r, uint8_t g, uint8_t b);
void gfxPlotPixel(uint32_t x, uint32_t y);
void gfxSwapbuffers(void);
gfxGlobalRenderer gfxGetGlobalRenderer(void);
#endif 
