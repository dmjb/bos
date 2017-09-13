#include "fb.h"

const word FB_SIZE = 80 * 25;
word * FB = (word *)0xB8000;

void fb_putchar(word pos, char c)
{
    char * dest = (char *)(FB + pos);
    *dest = c;
    *(dest + 1) = 31; // white on blue
}

void fb_puts(word pos, char * str)
{
    //for (word i = 0; i < chars; i++)
    word i = 0;
    while (str[i] != (char)0)
    {
        fb_putchar(pos++, str[i++]);
    }
    const word row = pos / 80;
    const word col = pos % 80;
    fb_set_cursor(row, col);
}

void fb_clear()
{
    for (word i = 0; i < FB_SIZE; i++)
    {
        fb_putchar(i, 0);
    }
    fb_set_cursor(0, 0);
}

void fb_set_cursor(byte row, byte column)
{
    outb(FB_CMD_PORT,  FB_CURSOR_HI);
    outb(FB_DATA_PORT, row);
    outb(FB_CMD_PORT,  FB_CURSOR_LO);
    outb(FB_DATA_PORT, column);
}
