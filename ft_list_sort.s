;parameters
	;rdi	t_list ** begin
	;rsi	int (*cmp)() pointer to comparaison function
;return
	;void


section .text
	global ft_list_sort

ft_list_sort:
push rbx
push r12				;callee saved registers
push r13
push r14
push r15

cmp rdi, 0				;if **begin null, return
je _the_end
cmp qword [rdi], 0		;if *begin null, return
je _the_end

mov r15, [rdi]			;set list begin
mov r12, rdi			;t_list **begin
mov r13, rsi			;*cmp
xor rbx, rbx			;boolean, 1 if sorted, else 0

_sort_list_loop:
cmp rbx, 1				;if loop sorted, end
je _the_end
mov qword rbx, 1		;set loop as sorted
mov r15, [r12]			;reset list begin
_sort_elem_loop:
mov r14, [r15 + 8]			;pointer to next
cmp qword r14, 0		; if next element is null
je _sort_list_loop
;call comparaison func
mov rdi, [r15]				;char *data
mov rsi, [r14]				;next->data
call r13					;*cmp
jle _sorted_elem
;swapping
mov rdi, [r14]
mov rsi, [r15]
mov [r15], rdi
mov [r14], rsi
xor rbx, rbx		;set as not sorted

_sorted_elem:
mov r15, r14
jmp _sort_elem_loop

_the_end:
pop r15
pop r14
pop r13
pop r12
pop rbx
ret
