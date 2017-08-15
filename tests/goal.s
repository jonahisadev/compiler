global start

section .text
start:
	call main
	mov rdi, rdx
	mov rax, 0x2000001
	syscall
	
section .data
db 0x0
	
section .text
main:						; User Code
	mov rdx, 2
	ret