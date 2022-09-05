#SHELL := bash
# Makefile is written with bash as the shell
# ZSH ?

.SHELLFLAGS := -eu -o pipefail -c
# Bash strict mode prevents subtle bugs
.DELETE_ON_ERROR:
# Makefile deletes any target file whose build 
# sequence completes with non-zero return status
MAKEFLAGS += --warn-undefined-variables
# Receive warning when referring to make variables
# that don't exist

NAME = gnl.a
CC = clang
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=15

SRC = ./get_next_line.c ./get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo Creating $(NAME)...
	$(CC) $(CFLAGS) -I . -c $(SRC)
	ar -rcs $(NAME) $(OBJ)

clean:
	@echo Removing object files...
	rm -rf $(OBJ)
#	Removes any files matching $(OBJ), as the object
#	files are already in the archive

fclean: clean
	@echo Removing archive file...
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
#	Make will not look for a file named `test` 
#	on the file system, but will view the keywords
#	as functions


# $(NAME):
#	ar - archiver command compiles archive '.a' file
#	-r - flag inserts files into archive & replaces
#		 files of the same name
#	-s - flag represents ranlib command to create/update
#		 an object-file index into the archive

# Questions
#	substitutions (SRC:.c=.o) vs building files (%.o: %.c)