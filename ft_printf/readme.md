With libft:
*Add libft imports if needed*
gcc -Wall -Wextra -Werror main.c ./libft/*.c ft_printf.c -I. -I./libft -o program

- -I.
    Adds the current directory to the list of directories GCC searches for header files.
- -I./libft
    Adds the ./libft directory to the list of directories GCC searches for header files.
- -o program
    Specifies the name of the output file.

Without libft:

gcc -Wall -Wextra -Werror main.c ft_printf.c -o program