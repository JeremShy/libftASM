section .data
msg:
	.string db "Here"

section .text
	global _ft_bzero
	extern _puts

_ft_bzero:
	cmp rsi,0
	je done
	push rdi
	lea rdi, [rel msg.string]
	call _puts
	pop rdi
	ret

done:
	ret
