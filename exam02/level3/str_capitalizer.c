/* sub: scrivi un programma che prende
una o piu' stringhe e per ogni argomento
scrive la prima lettera della parola in
maiuscolo,scrivendo il resto della parola
in minuscolo. */

/* 1. funzione di supporto: funziona da mente 
del programma,fa tutte le conversioni necessarie.*/
void str_capitalizer(char *str)
{
    int i;

    i = 0;
    /* 2. quanto la funzione non e' al null terminator, 
    fa i check sulle lettere,se la lettera e' minuscola
    la fa diventare maiuscola in codice ascii (-32),
    senno' se il carattere dopo della stringa e' uno spazio
    (ascii 9-13) o una lettera maiuscola,
    la converte in minuscola(+32) */
    if(str[i] >= 'a' && str[i] <= 'z')
        str[i] -= 32;
    write(1, &str[i], 1);
    while(str[++i])
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        if((str[i] >= 'a' && str[i] <= 'z') && (str[i - 1] == ' ' ||
        str[i - 1] == '\t'))
            str[i] -= 32;
        write(1, &str[i], 1);
    }
}
/* 3. funzione principale: fa check sugli
argomenti e richiama la funzione di supporto 
che si occupa dei calcoli.*/
int main(int ac, char *av[])
{
    int i;

    if(ac > 1)
    {
        i = 1;
        while(i < ac)
        {
            str_capitalizer(av[i]);
            i += 1;
        }
    }
    write(1, "\n", 1);
    return (0);
}