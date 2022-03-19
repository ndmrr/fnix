

#ifndef IO_H
#define IO_H
#include <libgfx/gfx.h>

void println(const char* message);
void printstr(const char* message);
void printch(char ch);
int itoa(int value, char *sp, int radix);

// https://wiki.osdev.org/Inline_Assembly/Examples#I.2FO_access
static inline void outb(uint16_t port, uint8_t val)
{
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

static inline uint8_t inb(uint16_t port)
{
    uint8_t ret;
    asm volatile ( "inb %1, %0"
                  : "=a"(ret)
                  : "Nd"(port) );
    return ret;
}

#endif 
