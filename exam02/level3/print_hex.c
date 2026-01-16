/* sub: scrivi un programma che prende un
numero positivo in base 10 e lo stampa in
base 16(in lowercase),seguito da un newline
*/

#include <unistd.h>

/* 1. funzione di supporto: converte una stringa
in un numero intero positivo */
int ft_atoi(char *str)
{
    int n;

    n = 0;
    /* 2. costruzione del numero: moltiplica il valore
    corrente oer 10 e aggiunge la cifra successiva */
    while(*str != '\0')
    {
        n = n * 10;
        n += (*str - '0');
        ++str;
    }
    return (n);
}
/* 3. funzione di supporto: stampa un numero intero in
formato esadecimale usando la ricorsione. */
void print_hex(int n)
{
    char hex_digit[] = "0123456789abcdef";

    /* 4. ricorsione: stampa prima le cifre piu'
    significative. */
    if(n >= 16)
        print_hex(n / 16);
    /* 5. stampa cifra esadecimale: usa il resto come
    indice nella stringa. */
    write(1, &hex_digit[n % 16], 1);
}

/* 6. funzione principale: converte l'argomento in intero
e lo stampa in formato esadecimale. */
int main(int ac, char **av)
{
    if(ac == 2)
        print_hex(ft_atoi(av[1]));
    write(1, "\n", 1);
    return (0);
}