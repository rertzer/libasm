section .text
	global ft_strcpy

;char * dest in rdi
;const char * src in rsi
ft_strcpy:
	mov rax, rdi			;store dest address for return
looping:
	mov cl, byte [rsi]		;cl: lower part of rcx
	mov [rdi], cl			;moving one byte at a time
	cmp byte [rsi], 0		; reached '\0' ?
	je end_of_string		
	inc rdi					; dest++
	inc rsi					; src++
	jmp looping
end_of_string:
	ret

