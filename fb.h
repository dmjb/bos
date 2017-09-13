#ifndef BOS_FB_H
#define BOS_FB_H

#include "types.h"
#include "io.h"

#define FB_CURSOR_HI 14
#define FB_CURSOR_LO 15
#define FB_CMD_PORT  0x3D4
#define FB_DATA_PORT 0x3D5

extern const word FB_SIZE;
extern word * FB;

void fb_putchar(word pos, char c);
void fb_puts(word pos, char * str);
void fb_clear();
void fb_set_cursor(byte row, byte column);

#endif
