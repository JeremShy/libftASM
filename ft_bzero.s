section .text
	global _ft_bzero

_ft_bzero:
	push rbp
	mov rbp,rsp
	cmp rsi,0
	je return
	mov [rdi],byte 0
	dec rsi
	inc rdi
	call _ft_bzero
	pop rbp
	ret

return:
	pop rbp
	ret
