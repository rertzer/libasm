;parameters
	;rdi	int fd
	;rsi	const void buff[.count]
	;rdx	size_t count

;return
	;rax ssize_t write
	;errno

extern __errno_location

section .text
	global ft_read

ft_read:
	mov rax, 0		;SYS_WRITE
					;fd already in rdi
					;buf already in rsi
					;size already in rdx
	syscall
	cmp rax, 0		;if return value negative
	js _write_error
	ret

_write_error:
	neg rax					;switch error code to positive value
	mov rdi, rax			;save error code
	call __errno_location	;errno address put in rax
	mov [rax], rdi			;put error code in errno
	mov rax, -1				;return value -1
	ret

