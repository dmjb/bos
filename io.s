global outb

; outb(unsigned short port, char data)
outb:
    mov al, [esp + 8]
    mov dx, [esp + 4]
    out dx, al
    ret
