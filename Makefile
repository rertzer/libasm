NAME := libasm.a

TESTER_NAME := libasm_tester.c

SRCS := ft_strlen.s

OBJS := $(SRCS:.s=.o)

AS := nasm
ASFLAGS := -f elf64

CC := gcc

CFLAGS := -no-pie -Wall -Werror -Wextra

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	ar -rcs $@ $(OBJS)

%.o: %.s
	$(AS) $(ASFLAGS) $<

tester: all
	$(CC) $(CFLAGS) $(NAME) $(TESTER_NAME) -o $@

clean:
	rm -rf $(OBJS)
	rm -rf tester.o

fclean: clean
	rm -rf $(NAME)
	rm -rf libasm_tester

re:	clean
	$(MAKE) all

.PHONY: all, clean, fclean, re
