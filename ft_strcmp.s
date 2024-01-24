section .text
	global ft_strcmp

;parameters:
; rdi: const char *s1
; rsi: const char *s2

ft_strcmp:
	xor rax, rax			; cleaning the whole return register as only lower part will be
							; written/used
looping:
	mov al, byte [rdi]		;al: 1 byte lower part of rax
	cmp byte al, 0			; end of s1 ?
	je no_match
	cmp byte al, byte [rsi]		; compare current char of both string
	jne no_match
	inc rdi					;s1++
	inc rsi					;s2++
	jmp looping

no_match:
	xor rdi, rdi
	mov dil, byte [rsi]
	sub  al, dil			;s1[n] - s2[n]
	movsx eax, al			; sign extension
	ret

