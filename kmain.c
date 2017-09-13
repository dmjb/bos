#include "console.h"

int kmain()
{
    Console console;
    Console_init(&console);
    Console_writeln(&console, "Loading BOS 0.0.2...");
    return 0x1234;
}

