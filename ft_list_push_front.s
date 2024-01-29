;parameters:
	;rdi	t_list **begin_list
	;rsi	void *data
;return: void

;registers use
	;rax	new_elem

extern __errno_location
extern malloc

section .text
	global ft_list_push_front

ft_list_push_front:

;create element
	push rsi
	push rdi
;malloc
	mov rdi, 16	;t_list size
	call malloc wrt ..plt			;malloc new t_list element
	cmp rax, 0						;if malloc failed
	je _write_error
;set new element values	
	pop rdi
	pop rsi
	mov [rax], rsi					;*data put in t_list new_elem.data
	mov r8, [rdi]					;set new_elem.next at previous first elem
	mov [rax + 8], r8
	mov [rdi], rax					;set new_elem as the new first elem
	ret

;errno
_write_error:
	neg rax							;switch error code to positive value
	mov rdi, rax					;save error code
	call __errno_location wrt ..plt	;errno address put in rax
	mov [rax], rdi					;put error code in errno
	ret

