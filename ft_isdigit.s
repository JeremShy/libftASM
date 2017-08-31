section .text
	global _ft_isdigit

_ft_isdigit:
	push rbp
	mov rbp,rsp
	cmp rdi,48
	jl .ret0
	cmp rdi,57
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
