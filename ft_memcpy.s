section .text
	global _ft_memcpy

_ft_memcpy:
	push rbp
	mov rbp, rsp
	push rdi

	mov ecx, edx ; on met le troisieme argument dans ecx
	rep movsb ; on met esi(deuxieme argument) dans edi(premier argument) ecx fois

	pop rax
	jmp .return

.return:
	pop rbp
	ret
