section .text
	global _ft_toupper

_ft_toupper:
	push rbp
	mov rbp,rsp
	cmp rdi, 97
	jl .quit
	cmp rdi, 122
	jle .islow
	jmp .quit

.islow:
	sub rdi, 32
	jmp .quit

.quit:
	mov rax, rdi
	pop rbp
	ret
