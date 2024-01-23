section .data

section .text
	global ft_strlen

ft_strlen:
	;parametres const char *s in register rdi
	mov	rax, 0
looping:
	cmp byte [rdi + rax], 0
	je end_found
	add rax, 1
	jmp looping
end_found:
	ret

