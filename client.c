#include "./includes/minitalk.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"

void    convert(char c, int pid)
{
    int i;
    int bit;

    bit = 0x01;
    i = 0;
    while(i != 8)
    {
        if (bit & c)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        bit = bit << 1;
        usleep(100);
        i++;
    }
}

int main(int argc, char **argv)
{
    int pid;
    int i;

    i = 0;
    pid = ft_atoi(argv[1]);
    if (argc != 3)
    {
        ft_printf("%s", "Invalid arguments!\n");
        return (1);
    }
    while(argv[2][i])
        convert(argv[2][i++], pid);
    return (0);
}
