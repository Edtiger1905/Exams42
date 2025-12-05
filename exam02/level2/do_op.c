#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int do_op(int a,char op,int b)
{
    int result;

    result = 0;
    if(op == '*')
        result = a * b;
    else if(op == '/')
        result = a / b;
    else if(op == '%')
        result = a % b;
    else if(op == '+')
        result = a + b;
    else if(op == '-')
        result = a - b;
    return (result);
}

int main(int ac, char **av)
{
    int a;
    int b;
    char op = 0;

    if (ac != 4)
    {
        printf("\n");
        return (0);
    }
    /* protezione accesso argv */
    a = atoi(av[1]);
    b = atoi(av[3]);

    /* se av[2] contiene '*' da qualche parte, usalo; altrimenti usa il primo char */
    if (strchr(av[2], '*'))
        op = '*';
    else
        op = av[2][0];

    if ((op == '/' || op == '%') && b == 0)
    {
        printf("\n");
        return (0);
    }
    printf("%d\n", do_op(a, op, b));
    return (0);
}













/* #include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int do_op(int a,char op,int b)
{
    int result;

    result = 0;
    if(op == '*')
        result = a * b;
    else if(op == '/')
        result = a / b;
    else if(op == '%')
        result = a % b;
    else if(op == '+')
        result = a + b;
    else if(op == '-')
        result = a - b;
    return (result);
}

int main(int ac, char **av)
{
    int a;
    int b;

    a = atoi(av[1]);
    b = atoi(av[3]);
    if (ac == 4)
        printf("%i", do_op(a, av[2][0], b));
    printf("\n");
    return (0);
} */