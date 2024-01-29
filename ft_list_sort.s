;parameters
	;rdi	t_list ** begin
	;rsi	int (*cmp)() pointer to comparaison function
;return
	;void


section .text
	global ft_list_sort

ft_list_sort:
cmp rdi, 0				;if null list, return
je _the_end

push r12				;callee saved registers
push r13
push r14
push r15

mov r12, rdi			;**begin
mov r13, rsi			;*cmp
xor r14, r14			;boolean, 1 if sorted, else 0

_sort_list_loop:
cmp r14, 1				;if loop sorted, end
je _the_end

mov r14, 1				;set loop as sorted
mov r15, [r14]			;reset list begin
_sort_elem_loop:
cmp qword [r15 + 8], 0		; if next element is null
je _sort_list_loop
;call comparaison func
mov rdi, [r15]
mov rdx, [r15 + 8]
mov rsi, [rdx]
call r13
cmp rax, 0
jle _sorted_elem
;swapping
xor r14, r14		;set as not sorted
_sorted_elem:
mov r15, [r15 + 8]
jmp _sort_elem_loop

_the_end:
pop r15
pop r14
pop r13
pop r12

ret
