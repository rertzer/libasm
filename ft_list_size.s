;parameters:
	;rdi	t_list	*begin
;return
	;rax	size

section .text
	global ft_list_size

ft_list_size:
xor	rax, rax		;set size at 0

_list_loop:
cmp rdi, 0			;if end of the list
je	_the_end
mov rdi, [rdi + 8]	;elem.next put in  current elem
inc rax				;increment list size	
jmp _list_loop

_the_end:
ret 
