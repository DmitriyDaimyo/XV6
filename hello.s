
global _start


section .rodata

    hello_world: db 71, 0xA, 0x0


section .text
_start:
    mov eax, 0x04
    mov ebx, 0x1
    mov ecx, hello_world
    mov edx, 14
    int 0x80


    mov eax, 0x01
    mov ebx, 0
    int 0x80
