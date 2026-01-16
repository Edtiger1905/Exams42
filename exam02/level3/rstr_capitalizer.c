/* sub: scrivi un programma che prende
una o piu' stringhe e per ogni argomento
scrive l'ultima lettera della parola in
maiuscolo,scrivendo il resto della parola
in minuscolo. */
#include <unistd.h>

void rstr_capitalizer(char *str)
{
    int i;

    i = 0;
    /* 2. quanto la funzione non e' al null terminator, 
    fa i check */
    while(str[i])
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        if(str[i] >= 'a' && str[i] <= 'z' && str[i + 1] == '\0' 
                || str[i + 1] == ' ' || (str[i + 1] >= 9 && str[i + 1] <= 13))
            str[i] -= 32;
        write(1, &str[i++], 1);
    }
}

int main(int ac, char **av)
{
    int i;

    if (ac > 1)
    {
        i = 1;
        while(i < ac)
        {
            rstr_capitalizer(av[i]);
            write(1, "\n", 1);
            i += 1;
        }
    }
    write(1, "\n", 1);
    return (0);
}