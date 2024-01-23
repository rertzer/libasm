NAME := libasm.a

TESTER_NAME := libasm_tester.c

SRCS := ft_strlen.s ft_strcpy.s

OBJS := $(SRCS:.s=.o)

AS := nasm
ASFLAGS := -f elf64

CC := clang

CFLAGS :=  -Wall -Werror -Wextra

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	ar -rcs $@ $(OBJS)

%.o: %.s
	$(AS) $(ASFLAGS) $<

tester: all $(TESTER_NAME)
	$(CC) $(CFLAGS)  $(TESTER_NAME) -o $@ -L. -lasm -L. -lasm

clean:
	rm -rf $(OBJS)
	rm -rf libasm_tester.o

fclean: clean
	rm -rf $(NAME)
	rm -rf libasm_tester

re:	clean
	$(MAKE) all

test:	tester
		./tester

vtest:	tester
		valgrind ./tester

.PHONY: all, clean, fclean, re
