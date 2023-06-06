#include "./includes/minitalk.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"


void msg_handler(int signum)
{
    static int  byte;
    static int  pos;

    if (signum == SIGUSR1)
        byte +=  0x01 << pos;
    pos++;
    if (pos == 8)
    {
        ft_printf("%c", byte);
        pos = 0;
        byte = 0;
    }
}

int main(int argc, char **argv)
{
    int pid;
    (void) argv;

    pid = getpid();
    if (argc != 1)
    {
        write(1, "Wrong input", 11);
        return(1);
    }
    ft_printf("PID: %d\n", pid);
    while(1)
    {
        signal(SIGUSR1, msg_handler);
        signal(SIGUSR2, msg_handler);
        pause();
    }
    return (0);
}

