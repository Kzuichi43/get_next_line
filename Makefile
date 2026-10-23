CC = cc
CFLAGS = -Wall -Wextra -Werror
BUFFER = -D BUFFER_SIZE=42
SRC = get_next_line.c \ get_next_line_utils.c
HEADER = get_next_line.h
OBJS      := $(SRC:.c=.o)
NAME = get_next_line.a
AR = ar
RCS = rcs
RM = rm -f

all: $(NAME)
$(NAME): $(OBJS)
	$(AR) $(RCS) $@ $^

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) $(BUFFER) -c -o $@ $<
clean: 
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY : all clean fclean re 
