section .text
	global _ft_isalnum
	extern _ft_isalpha
	extern _ft_isdigit

_ft_isalnum:
	push rbp
	mov rbp,rsp
	call _ft_isalpha
	cmp rax, 1
	je .ret1
	call _ft_isdigit
	cmp rax, 1
	je .ret1
	jmp .ret0

.ret1:
	mov rax, 1
	pop rbp
	ret

.ret0:
	mov rax, 0
	pop rbp
	ret
