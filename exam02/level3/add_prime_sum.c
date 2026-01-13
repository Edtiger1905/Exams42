#include <unistd.h>


int ft_atoi(char *s)
{
    int res;

    res = 0;
    while(*s)
        res = res * 10 + *s++ - 48;
    return(res);
}
/* funzione di supporto principale: verifica se un numero
e' primo */
int is_prime(int num)
{
    int i;

    i = 2;
    //se il numero e' minore o uguale a 1, non e' primo
    if(num <= 1)
        return (0);
    //controlla se il numero e' divisibile per qualche
    //numero tra 2 e la radice quadrata del numero
    while(i * i <= num)
    {
        //se il numero e' divisibile per i, non e' primo
        if(num % i == 0)
            return (0);
        i++;
    }
    //se non ha trovato divisori, il numero e' primo
    return (1);
}

void ft_putnbr(int n)
{
    char digit;
    
    if(n >= 10)
        ft_putnbr(n / 10);
    digit = (n % 10) + '0';
    write(1, &digit, 1);
}
int main(int ac,char **av)
{
    int nbr;
    int sum;

    if(ac == 2)
    {
        nbr = ft_atoi(av[1]);
        sum = 0;
        //scorre tutti i numeri da nbr a 0
        while(nbr > 0)
        {
            //se il numero e' primo, lo aggiunge alla somma
            if(is_prime(nbr))
                sum += nbr;
            nbr--; // decrementa il numero
        }
        //stampa la somma dei numeri primi
        ft_putnbr(sum);
    }
    write(1, "\n", 1);
    return (0);
}