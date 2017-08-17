global _start

section .text
_start:
    call main
    mov ebx, edx
    mov eax, 1
    int 0x80
    
main:
    mov edx, 2
    ret
    
section .data
x: dd 0