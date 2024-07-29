NAME		=		philo_bonus
CC			=		cc -Wall -Wextra -Werror -pthread #-g3 -fsanitize=thread
INC			=		-Iheaders
RM			=		rm -rf
HEADERS		=		headers/philo_bonus.h
FILES		=		exit fork free init main monitor parse \
					philosophers routine sem time utils
SRCDIR		=		src
SRCS		=		$(addprefix $(SRCDIR)/, $(addsuffix _bonus.c, $(FILES)))
OBJDIR		=		obj
OBJS		=		$(addprefix $(OBJDIR)/, $(addsuffix _bonus.o, $(FILES)))
RED			=		\e[1;31m
GREEN		=		\e[1;32m
YELLOW		=		\e[3;33m
CYAN		=		\e[3;96m
END			=		\e[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling $(CYAN)$(NAME)$(END)"
	@$(CC) $(INC) -o $(NAME) $(OBJS)
	@echo "$(CYAN)$(NAME) is ready to use$(END)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	@mkdir -p $(OBJDIR)
	@echo "$(YELLOW)Compiling $(CYAN)$(notdir $<)$(END)"
	@$(CC) $(INC) -c $< -o $@
	@echo "$(GREEN)Done.$(END)"

clean:
	@echo "$(RED)Cleaning $(OBJDIR)...$(END)"
	@$(RM) $(OBJDIR) 2> /dev/null || true

fclean: clean
	@echo "$(RED)Cleaning $(NAME)...$(END)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean
