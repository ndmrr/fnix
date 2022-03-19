#include <klibc/io.h>
#include <stdlib.h>

static uint32_t rows = 0;
static uint32_t col = 0;
void println(const char* message)
{
    col = 0;
    rows += GetActiveFont().h + (GetActiveFont().h/4);
    DrawText(GetActiveFont(), message, GetActiveFont().w , rows);
    
}

void printstr(const char* message)
{
    uint32_t length = 0;
    while (message[length++] != '\0');
    
    DrawText(GetActiveFont(), message, GetActiveFont().w + (GetActiveFont().w * col), rows +  GetActiveFont().h + (GetActiveFont().h/4));
    col += (length-1);
}

void printch(char ch)
{
    DrawCharacter(GetActiveFont(), ch, GetActiveFont().w + (GetActiveFont().w * col), rows +  GetActiveFont().h + (GetActiveFont().h/4));
    col += 1;
}



int itoa(int value, char *sp, int radix)
{
    char tmp[16];// be careful with the length of the buffer
    char *tp = tmp;
    int i;
    unsigned v;
    
    int sign = (radix == 10 && value < 0);    
    if (sign)
        v = -value;
    else
        v = (unsigned)value;
    
    while (v || tp == tmp)
    {
        i = v % radix;
        v /= radix;
        if (i < 10)
            *tp++ = i+'0';
        else
            *tp++ = i + 'a' - 10;
    }
    
    int len = tp - tmp;
    
    if (sign) 
    {
        *sp++ = '-';
        len++;
    }
    
    while (tp > tmp)
        *sp++ = *--tp;
    
    return len;
}
