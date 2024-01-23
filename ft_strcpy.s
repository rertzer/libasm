section .text
	global ft_strcpy

;char * dest in rdi
;const char * src in rsi
ft_strcpy:
	mov rax, rdi
looping:
	mov cl, byte [rsi]
	mov [rdi], cl
	cmp byte [rsi], 0
	je end_of_string
	inc rdi
	inc rsi
	jmp looping
end_of_string:
	ret

