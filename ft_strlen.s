section .data

section .text
	global ft_strlen

	;parameter const char *s in register rdi
ft_strlen:
	xor	rax, rax
looping:
	cmp byte [rdi], 0
	je end_found
	inc rax
	inc rdi
	jmp looping
end_found:
	ret

