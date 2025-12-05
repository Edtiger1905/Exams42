
/*
Scrivi una funzione che stampa una stringa nel standart output
il pointer passato alla funzione contiene l'indirizzo del carattere della stringa
*/

#include <unistd.h>

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

/*
int main(int argc, char **argv)
{
    if(argc == 2)
        ft_putstr(srgv[1]);
    write(1, "\n", 1);
    return (0);
}
*/