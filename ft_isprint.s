section .text
	global _ft_isprint

_ft_isprint:
	push rbp
	mov rbp,rsp
	cmp rdi,32
	jl .ret0
	cmp rdi,127
	jl .ret1
	jmp .ret0

.ret1:
	mov rax,1
	pop rbp
	ret

.ret0:
	mov rax,0
	pop rbp
	ret
