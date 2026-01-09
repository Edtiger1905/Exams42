/* sub: Stampa tutti i caratteri di argv[1] e argv[2] una sola volta,
mantenendo l’ordine della prima apparizione. */
#include <unistd.h>

/* 1. funzione di controllo: verifica se il carattere 'c' e' gia'
presente nella stringa 'str' prima della posizione 'index' */
int check(int c,char *str, int index)
{
    int i;
    
    i = 0;
    while(i < index)
    {
        if(str[i] == c)
            return (0);
        i++;
    }
    return (1);
}

/* 2. funzione principale: unisce e due stringhe e stampa ogni
carattere una volta sola, mantenendo l'ordine di apparizione */
int main(int ac,char **av)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    
    /* 3. Controllo argomenti: il programma funziona solo con
    due argomenti */
    if(ac == 3)
    {
        /* 4. concatenazione: copia la seconda stringa alla
        fine della prima */
        while(av[1][i] != '\0')
            i++;
        while(av[2][j] != '\0')
        {
            av[1][i] = av[2][j];
            i++;
            j++;
        }
        i--;

        /* 5. stampa senza duplicati: stampa ogni 
        carattere solo alla sua prima apparzione */
        while(k <= i)
        {
            /* primo parametro -> carattere da controllare,in 
            questo caso il primo carattere della prima stringa(av[1][k]) 
            secondo parametro -> stringa dalla quale prendere il carattere
            terzo parametro -> posizione nella quale controllare
            check -> se il parametro di ritorno e' 1,significa che non
            ci sono caratteri uguali nella stringa concatenata
            stampa -> stampa la stringa concatenata ripulita dalle
            lettere doppie. */
            if(check(av[1][k], av[1], k) == 1) 
                write(1, &av[1][k], 1);
            k++;
        }
    }
    write(1, "\n", 1);
}