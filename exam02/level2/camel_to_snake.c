#include <unistd.h>
/* sub: prendere una stringa nel formato lowerCamelCase e trasformarlo
in quello snake_case */
int main(int ac,char **av)
{
    int i;

    i = 0;
    if(ac == 2)
    {
        /* ciclo di elaborazione della stringa:
        -manda avanti la stringa fino a quando non arriva al null terminator 
        -se il carattere e' una lettera maiuscole(ascii tra 65 e 90),
        la converte in minuscola (+ 32) e scrive il "_",senno' stampa
        il carattere della stringa col write
        */
        while(av[1][i])
        {
            if(av[1][i] >= 65 && av[1][i] <= 90)
            {
                av[1][i] = av[1][i] + 32;
                write(1, "_", 1);
            }
            write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}