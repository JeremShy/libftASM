section .text
	global _ft_strlen

_ft_strlen:
	push rbp
	mov rbp,rsp
	xor eax, eax
	xor ecx, ecx
	not ecx
	repne SCASB
	mov rax, rcx
	not ecx
	dec ecx
	mov eax, ecx
	jmp .return

.return:
	pop rbp
	ret
