NAME := libasm_tester

OBJ_DIR := obj/

SRCS := libasm_tester.c \
		read_tester.c \
		write_tester.c \
		strcmp_tester.c \
		strcpy_tester.c \
		strdup_tester.c \
		strlen_tester.c \
		atoi_base_tester.c \
		piscine_atoi_base.c \
		piscine_create_element.c \
		piscine_list_push_front.c \
		piscine_list_size.c \
		piscine_list_sort.c \
		#piscine_list_remove_if.c

INCS := ../libasm.h \
		libasm_tester.h

OBJS := $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

CC := gcc 
CFLAGS :=  -Wall -Werror -Wextra -g

all: $(NAME)

bonus: all

$(OBJ_DIR)%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJS) $(INCS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -L.. -lasm

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJS)
	rm -fd $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:	clean
	make all

.PHONY: all, clean, fclean, re
