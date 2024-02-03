;parameters:
	;rdi	t_list **begin_list
	;rsi	void * data_ref	
	;rdx	int (*cmp)()
	;rcx	void (*free_fct)(void *)

	extern free
section .text
	global ft_list_remove_if

ft_list_remove_if:
	;move parameters in non-volatile registers

	push r12
	push r13
	push r14
	push r15
	push rbx

	mov r12, rdi		;t_list **begin_list
	mov r13, rsi		;void *data_ref
	mov r14, rdx		;int(*cmp)()
	mov r15, rcx		;void (*free_fct)(void *)
	mov rbx, [rdi]		;current element
	xor r8, r8			;previous set to null

_foreach_element:
	cmp qword rbx, 0	;if current t_list* is null
	je _the_end			;end programm

_comparison_function_call:
	push r8
	mov rdi, [rbx]
	mov rsi, r13
	call r14
	pop r8
	jne _next_element				;if not equal, next
_remove_element:
	cmp rbx, [r12]					;test if first element
	jne _not_first_element
_first_element:
	mov rax, [rbx + 8]	;next element become the first
	mov [r12], rax
	jmp _free_element
_not_first_element:
	mov rax, [rbx + 8] ;current->next element becomes previous->next
	mov [r8 + 8], rax
_free_element:
	push rax
	push r8
	mov rdi, [rbx]		;current->data
	call r15			;free data
	mov rdi, rbx		;current
	call free wrt ..plt	;free t_list
	pop r8
	pop rax
	mov rbx, rax
	jmp _foreach_element
_next_element:
	mov r8, rbx			;store previous element
	mov rbx, [rbx + 8]	;next become current
	jmp _foreach_element

_the_end:
	pop rbx
	pop r15
	pop r14
	pop r13
	pop r12
	ret
