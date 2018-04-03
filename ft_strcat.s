section .text
	global _ft_strcat

_ft_strcat:
	push rbp
	mov rbp,rsp
	push rdi
	call .gotoendrdi
	call .docopy
	pop rax
	pop rbp
	ret

.gotoendrdi:
	cmp [rdi],byte 0
	je .ret
	inc rdi
	jmp .gotoendrdi

.docopy:
	cmp byte [rsi],byte 0
	je .put0andret
	mov r8, [rsi]
	mov [rdi], r8
	inc rdi
	inc rsi
	jmp .docopy

.ret:
	ret

.put0andret:
	mov [rdi], byte 0
	ret
