section .text
	global _ft_tolower

_ft_tolower:
	push rbp
	mov rbp,rsp
	cmp rdi, 65
	jl .quit
	cmp rdi, 90
	jle .isup
	jmp .quit

.isup:
	add rdi, 32
	jmp .quit

.quit:
	mov rax, rdi
	pop rbp
	ret
