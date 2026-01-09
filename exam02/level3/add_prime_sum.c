#include <unistd.h>

int ft_atoi(char *s)
{
    int res;

    res = 0;
    while(*s)
        res = res * 10 + *s++ - 48;
    return(res);
}
int is_prime(int num)
{
    int i;

    i = 2;
    if(num <= 1)
        return (0);
    while(i * i <= num)
    {
        if(num % i == 0)
            return (0);
        i++;
    }
    return (1);
}

void ft_putnbr(int n)
{
    
}