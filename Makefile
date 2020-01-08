NAME	=	pathfinder

CFLG	=	-std=c11 -Wall -Wextra -Werror -Wpedantic -g
COMP 	= 	clang

SRCD	=	src
INCD	=	inc
OBJD	=	obj

LMXD	=	libmx
LMXA:=	$(LMXD)/libmx.a
LMXI:=	$(LMXD)/inc

INC		=	pathfinder.h
INCS	=	$(addprefix $(INCD)/, $(INC))

SRC		= 	mx_addIndexPathes.c mx_addLink.c mx_addOnePath.c \
			mx_algoritm.c mx_check_spaces.c mx_addPath.c \
			mx_copyPath.c mx_create_arr.c \
			mx_create_island.c mx_create_l.c \
			mx_create_path.c mx_create_set.c \
			mx_dellPath.c mx_delMat.c \
			mx_join.c mx_matrix.c mx_parse.c \
			mx_pbi.c mx_pop_front_island.c mx_pop_middle_island.c \
			mx_printerr.c mx_printerr_exit.c mx_printOutput.c \
			mx_push_back_path.c mx_short_dist.c mx_sortPath.c \
			mx_test_err.c mx_uniquePath.c main.c


SRCS	=	$(addprefix $(SRCD)/, $(SRC))
OBJS	=	$(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: install

install: $(LMXA) $(NAME)

$(NAME): $(OBJS)
	@$(COMP) $(CFLG) $(OBJS) -L$(LMXD) -lmx -o $@

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@$(COMP) $(CFLG) -c $< -o $@ -I$(INCD) -I$(LMXI)

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

$(LMXA):
	@make -sC $(LMXD)
clean:
	@make -sC $(LMXD) $@
	@rm -rf $(OBJD)

uninstall: clean
	@make -sC $(LMXD) $@
	@rm -rf $(NAME)

reinstall: uninstall install
