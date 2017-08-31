section .text
	global _ft_isascii

_ft_isascii:
	push rbp
	mov rbp,rsp
	cmp rdi,0
	jl .ret0
	cmp rdi,127
	jle .ret1
	jmp .ret0

.ret1:
	mov rax,1
	pop rbp
	ret

.ret0:
	mov rax,0
	pop rbp
	ret
