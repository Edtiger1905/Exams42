#include <unistd.h>

void ft_putchar(char c)
{
        write(1, &c, 1);
}
void rotone(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if(str[i] >= 'a' && str[i] <= 'y')
        {
            ft_putchar(str[i] + 1);
            i++;
        }
        else if(str[i] == 'z')
        {
            ft_putchar('a');
            i++;
        }
        else if(str[i] >= 'A' && str[i] <= 'Y')
        {
            ft_putchar(str[i] + 1);
            i++;
        }
        else if(str[i] == 'Z')
        {
            ft_putchar('A');
            i++;
        }
        else
        {
            ft_putchar(str[i]);
            i++;
        }
    }
}
int main(int ac, char **av)
{

    if(ac == 2)
        rotone(av[1]);
    write (1, "\n", 1);
    return (0);
}