section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_memcpy

_ft_strdup:
	push rbp
	mov rbp, rsp
	push rdi

	call _ft_strlen
	inc rax
	push rax

	mov rdi, rax ; On donne la taille de la chaine comme argument a malloc
	call _malloc

	cmp rax, 0 ; Si malloc a renvoyé null...
	je .reterr ; Alors on renvoit null aussi

	mov rdi, rax ; Destination - Premier argument
	pop rdx ; Taille - 3e argument
	pop rsi ; source - Deuxieme argument

	call _ft_memcpy
	jmp .return

.return:
	pop rbp
	ret

.reterr:
	pop rdi
	pop rax
	pop rbp
	mov rax, 0
	ret
