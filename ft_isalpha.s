section .text
	global _ft_isalpha

_ft_isalpha:
	push rbp
	mov rbp,rsp
	cmp rdi,65
	jge .aboveA
	mov rax,0
	pop rbp
	ret

.aboveA:
	cmp rdi,90
	jg .aboveZ
	jmp .ret1

.aboveZ:
	cmp rdi,97
	jge .abovea
	jmp .ret0

.abovea:
	cmp rdi,122
	jg .ret0
	jmp .ret1

.ret1:
	mov rax,1
	pop rbp
	ret

.ret0:
	mov rax,0
	pop rbp
	ret
