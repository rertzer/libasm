NAME := libasm.a

TESTER_NAME := libasm_tester

TESTER_DIR := tester/

OBJ_DIR := obj/

SRCS := ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s \
		ft_read.s \
		ft_strdup.s \
		ft_atoi_base.s \
		ft_list_push_front.s \
		ft_list_size.s \
		ft_list_sort.s \
		ft_list_remove_if.s


OBJ := $(SRCS:.s=.o)

OBJS := $(addprefix $(OBJ_DIR), $(OBJ))

AS := nasm
ASFLAGS := -f elf64 -g -F dwarf

all: $(NAME)

bonus: all

tester: all
	make -C $(TESTER_DIR)

$(NAME): $(OBJ_DIR) $(OBJS) libasm.h
	ar -rcs $@ $(OBJS)

$(OBJ_DIR)%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJS)
	rm -fd $(OBJ_DIR)
	make -C $(TESTER_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(TESTER_DIR) fclean

re:	clean
	make all

test:	tester
		./$(TESTER_DIR)$(TESTER_NAME)

vtest:	tester
		valgrind ./$(TESTER_DIR)$(TESTER_NAME)

.PHONY: all, bonus, clean, fclean, re, tester
