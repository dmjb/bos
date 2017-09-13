#include "console.h"
#include "fb.h"

static void Console_update_cursor(Console * console)
{
    const word row = console->current_pos / 80;
    const word col = console->current_pos % 80;

    fb_set_cursor(row, col);
}

static void
Console_increment_cursor(Console * console, word count)
{
    const word new_pos = console->current_pos + count;
    console->current_pos = new_pos % FB_SIZE;
    Console_update_cursor(console);
}

static void Console_newline(Console * console)
{
    const word row = console->current_pos / 80;
    if (row >= 24)
    {
        console->current_pos=0;
    }
    else
    {
        const word new_row = (row + 1) * 80;
        console->current_pos = new_row;
    }
}

void Console_init(Console * console)
{
    console->current_pos = 0;
    Console_reset(console);
}

void Console_write(Console * console, char * str)
{
    word i = 0;
    while (str[i] != (char)0)
    {
        Console_putchar(console, str[i++]);
    }
}

void Console_writeln(Console * console, char * str)
{
    Console_write(console, str);
    Console_newline(console);
}

void Console_putchar(Console * console, char c)
{
    fb_putchar(console->current_pos, c);
    Console_increment_cursor(console, 1);
}

void Console_reset(Console * console)
{
    fb_clear();
    console->current_pos = 0;
    // no cursor update required here
}


