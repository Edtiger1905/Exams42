/* sub: prendere in input due stringhe e vedere se
con la seconda stringa si puo' scrivere la parola scritta nella
prima stringa,rispettando l'ordine con la quale sono scritte nella
seconda.  */

/* 1. funzione di stampa: scrive una stringa su stdout carattere
per carattere */
#include <unistd.h>

void ft_putstr(char const *str)
{
    int i;

    i = 0;
    while(str[i])
        write(1, &str[i++], 1);
}
/* 2. funzione principale: controlla se la prima stringa e' una
sottosequenza della seconda,mantenendo l'ordine dei caratteri */

int main(int ac, char **av)
{
    int i;
    int j;

    i = 0;
    j = 0;
    /* 3. il programma funiona solo con due argomenti */
    if(ac == 3)
    {
        /* 4. confronto delle stringhe: scorre la seconda stringa
        cercando,in ordine, i caratteri della prima */
        while(av[2][j])
            if(av[2][j++] == av[1][i])
                i += 1;
        /* 5. risultato: se tutti i caratteri della prima
        stringa sono stati trovati in ordine,viene stampata */
        if(!av[1][i])
            ft_putstr(av[1]);
    }
    write(1, "\n", 1);
    return (0);
}
