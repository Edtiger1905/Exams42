/*
prende una stringa e stampa la prima parola,seguita da newline
una parola e' una sezione di una stringa delimitata da spazi/tabs o dall'inizio/fine della stringa
se il parametro non e' 1,o se non ci sono parole,stampa un newline
*/

#include <unistd.h>

void first_word(char *str)
{
    int i;

    i = 0; //dichiarazione e inizializzazione dell'indice
    while (str[i] && (str[i] == ' ' || str[i] == '\t')) // salta spazi/tabs e ferma se '\0'
        i++;
    while (str[i] && str[i] != ' ' && str[i] != '\t') // stampa fino a '\0', spazio o tab
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if(argc == 2) //se il numero degli argomenti e' uguale a 2,quindi ha un argomento diverso dal nome del programma,richiama la funzione 
        first_word(argv[1]);
    write(1, "\n", 1); // mette il newline alla fine della parola
    return(0);
}