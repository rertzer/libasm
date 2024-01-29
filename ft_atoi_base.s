;parameters
	;rdi: char *string
	;rsi: char *base
;return
	;rax: int i

; register usage
	; rax: integer value to return
	; rdi: current string pointer
	; rsi: base pointer
	; r9: base length
	; r8: sign


section .text
	global ft_atoi_base

ft_atoi_base:
	;base check
	xor r9, r9								; base length set to 0
	xor rax, rax							; total value to return set at 0
	xor r8, r8								; sign set to 0; odd == - ,  even == +

_base_check_loop:							; check whether base char are OK and count them
	cmp byte [rsi + r9], 0
	je _skip_spaces_loop
	xor rcx, rcx							;counter set to 0
_duplicate_check_loop: 						;check for duplicated entries
	cmp rcx, r9								;while counter lower than current base length
	jge _check_forbidden_chars
	mov byte dl, [rsi +  r9]
	cmp byte [rsi + rcx], dl				; if char already in the base: return 0
	je _the_end
	inc rcx									; counter ++
	jmp _duplicate_check_loop
_check_forbidden_chars:
	cmp byte [rsi + r9], 43					; test if +
	je _the_end
	cmp byte [rsi + r9], 45					; test if -
	je _the_end
	cmp byte [rsi + r9], 32					; test if ASCII <= 32 : space and non printable
	jle _the_end
	cmp byte [rsi + r9], 127				; test if [DEL]
	je _the_end
	inc r9									; base length ++
	jmp _base_check_loop

	cmp r9, 1
	jle _the_end						; if base length is 0 or 1 : to small



	;skip spaces
_skip_spaces_loop:
	cmp byte [rdi], 9
	jl _test_space
	cmp byte [rdi], 12
	jg _test_space
	inc rdi
	jmp _skip_spaces_loop
_test_space:
	cmp byte [rdi], 32
	jne _test_sign_plus
	inc rdi
	jmp _skip_spaces_loop

	;get sign
_test_sign_plus:
	cmp byte [rdi], 43
	jne _test_sign_minus
	inc rdi
	jmp _test_sign_plus
_test_sign_minus:
	cmp byte [rdi], 45
	jne _compute_number_loop
	inc rdi
	inc r8
	jmp _test_sign_plus

	;get num
_compute_number_loop:
	cmp byte [rdi], 0			;end of string
	je _compute_sign
	xor rcx, rcx				;current base value to 0
_base_loop:
	cmp rcx, r9					;if loop outside base length
	jge _compute_sign
	mov dl, [rsi + rcx]
	cmp byte [rdi], dl			;if current string char same as current base char
	je _add_value
	inc rcx						; test for next base char
	jmp _base_loop
_add_value:
	mul r9						;offset previous result
	add rax, rcx				;add curent base char value
	inc rdi						; next string char
	jmp _compute_number_loop
	
_compute_sign:
	and r8, 1					;keep only smallest bit (odd or even)
	cmp r8, 0					; if even (+)
	je _the_end				
	imul rax, -1				; multiply by -1 (if odd numbers of -)

_the_end:
	ret
