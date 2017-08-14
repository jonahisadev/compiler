global start

section .data
db 0x0

section .text
start:
	call main
	mov rdi, rdx
	mov rax, 0x2000001
	syscall
	
main:						; User Code
	mov rdx, 2
	ret