;while ((r = read(0, buf, 5)) > 0)
;{
;	write(1, buf, r);
;}

%define BUFF_SIZE 0x1000
%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT 1
%define READ 3
%define WRITE 4

section .bss
buffer:
	.buf resb BUFF_SIZE + 1

section .text
	global _ft_cat

_ft_cat:
	push rbp
	mov rbp,rsp

	cmp rdi, 0 ; Si fd < 0
	jl .return ; on quitte.

	mov r10, rdi
	call .while
	jmp .return

.while:
	lea rsi, [rel buffer.buf]
	mov rdx, BUFF_SIZE
	mov rdi, r10
	mov rax, MACH_SYSCALL(READ)
	syscall
	jc .ret ; on quitte
	cmp rax, 0
	jle .ret
	mov rdi, STDOUT
	lea rsi, [rel buffer.buf]
	mov rdx, rax
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	jmp .while

.ret:
	ret

.return:
	pop rbp
	ret
