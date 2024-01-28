;parameters
	;rdi: const char *src
;return
	;rax: char * dest or NULL 
	;errno set if error

extern __errno_location
extern malloc

section .text
	global ft_strdup
ft_strdup:
	mov rsi, rdi		; *src start address copied in rsi

;strlen
_strlen:
_strlen_looping:
	cmp byte [rdi], 0
	je _strlen_found
	inc rdi
	jmp _strlen_looping
_strlen_found:
	sub rdi, rsi			; src len = end - start

	push rsi				; caller saved registers before call to malloc
	push rdi

;malloc
	add rdi, 1				;we malloc size + 1 for the '\0'
	call malloc wrt ..plt
	cmp rax, 0				;if return value null
	je _write_error

	pop rdi
	pop rsi

; duplicate
	mov rcx, rdi			; rcx is the loop counter
	mov rdx, rax			; *dest copy  in rdx
	cmp rcx, 0				; if empty, skip the loop
	je _empty_string
_duploop:
	mov rdi, [rsi]			;src[n] put in rdi
	mov [rdx], rdi			;src[n] put in dest[n]
	inc rdx
	inc rsi
	loop _duploop

_empty_string:
	xor rdi, rdi			;adding the '\0'
	mov [rdx], rdi
	ret

;errno
_write_error:
	neg rax							;switch error code to positive value
	mov rdi, rax					;save error code
	call __errno_location wrt ..plt	;errno address put in rax
	mov [rax], rdi					;put error code in errno
	mov rax, -1						;return value -1
	ret

