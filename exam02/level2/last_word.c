
#include <unistd.h>

/* 1. funzione che serve a trovare l'ultima parola di una stringa,
seguito da un newline */

void last_word(char *str)
{
    /* 2. dichiarazione e inizializzazione delle variabili */
    int i;
    int j;

    i = 0;
    j = 0;

    /* 3. scansione della stringa: fino a quando esiste la stringa
    fa andare avanti il primo while, il secondo serve per vedere
    se c'e' uno spazio o un carattere,se c'e' j viene aggiornato
    con l'indice di inizio della parola. */
    while(str[i])
    {
        if(str[i] == ' ' && str[i + 1] >= 33 && str[i + 1] <= 126)
            j = i + 1;
        i++;
    }
    /* 4. stampa dell'ultima parola: si parte dall'inizio
    dell'ultima parola,partendo da j, e si stampa un carattere
    alla volta. Appena trova uno spazio o il null terminator,
    il ciclo di ferma. */
    while(str[j] >= 33 && str[j] <= 127)
    {
        write(1, &str[j], 1);
        j++;
    }
}

int main(int ac,char **av)
{
    /* 5. richiamo della funzione e check vari con aggiunta del
    newline come da subject */
    if(ac == 2)
        last_word(av[1]);
    write(1, "\n", 1);
    return (0);
}
