%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT 1
%define WRITE 4

section .data
msg:
	.string db 10
	.len equ $ - msg.string

section .text
	global _ft_puts
	extern _write

_ft_puts:
	push rbp
	mov rbp,rsp
	mov rsi, rdi
	xor rax,rax
	call .getsize
	mov rdi, STDOUT
	mov rdx, rax
	mov rax, MACH_SYSCALL(WRITE)
	syscall

	mov rdi, STDOUT
	lea rsi, [rel msg.string]
	mov rdx, msg.len
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	jmp .quit

.getsize:
	cmp [rdi],byte 0
	je .ret
	inc rax
	inc rdi
	jmp .getsize

.ret:
	ret

.quit:
	pop rbp
	ret
