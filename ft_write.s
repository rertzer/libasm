;parameters
	;rdi	int fd
	;rsi	const void buff[.count]
	;rdx	size_t count

;return
	;rax ssize_t write
	;errno

extern __errno_location

section .text
	global ft_write

ft_write:
	;starter
	;appel system
	mov rax, 1		;SYS_WRITE
					;fd already in rdi
					;buf already in rsi
					;size already in rdx
	syscall
	cmp rax, 0
	js _write_error
	ret

_write_error:
	neg rax
	mov rdi, rax
	call __errno_location
	mov [rax], rdi
	mov rax, -1
	ret

