#ifndef BOS_CONSOLE_H
#define BOS_CONSOLE_H

#include "types.h"

typedef struct
{
    word current_pos;
}
Console;

// TODO: create `Console_new` once mem allocation exists
void Console_init(Console * console);
void Console_write(Console * console, char * str);
void Console_writeln(Console * console, char * str);
void Console_putchar(Console * console, char c);
void Console_reset(Console * console);

#endif

