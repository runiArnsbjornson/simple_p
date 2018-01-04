NAME = libftp.a

INCL = -I includes/ -I libft/

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/main.c \
	srcs/parse.c \
	srcs/handler.c \
	srcs/printer.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	@gcc $(LIBS) -g -o $@ -c $< $(CFLAGS) $(INCL)
	@echo "\033[K\033[34mLibft :\033[0m [ Compiling :\033[33m $^\033[0m]\033[1A"

$(NAME): $(OBJS)
	@cd Libft && make
	@libtool -static -o $@ $^ libft/libft.a
	@echo [ $(NAME) ] "\033[K\033[32mCreated\033[0m"

clean:
	@cd Libft && make clean
	@/bin/rm -f $(OBJS)
	@echo "\033[31mClean \033[35mDone\033[0m"

fclean: clean
	@/bin/rm -f $(NAME) libft/libft.a
	@echo "\033[31mFclean \033[35mDone\033[0m"

re: fclean
	@make
	@echo "\033[32mRe\033[01mDone\033[0m"

.PHONY : all clean fclean re