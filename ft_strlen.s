section .data

section .text
	global ft_strlen

	;parameter const char *s in register rdi
ft_strlen:
	xor	rax, rax
	xor rdx, rdx
looping:
	cmp [rdi + rax], rdx
	je end_found
	inc rax
	jmp looping
end_found:
	ret

