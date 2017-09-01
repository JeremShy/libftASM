section .text
	global _ft_memset

_ft_memset:
	push rbp
	mov rbp, rsp
	push rdi

	mov eax, esi ; On met le deuxième argument dans eax
	mov rcx, rdx ; On met le troisieme argument dans rcx
	rep stosb ; On copie rcx fois le contenu de eax dans edi.

	pop rax
	jmp .return

.return:
	pop rbp
	ret
