/* sub: il primo parametro e' un array di int,il secondo e' il numero degli elementi nell'array
la funzione ritorna il valore maggiore nell'array */

int max(int *tab, unsigned int len)
{
/* 1. se la lunghezza di len e' uguale a 0,ritorna 0 */
    if(len == 0)
        return (0);
/* 2. inizializza la variabile res con il primo elemento dell'array */    
    int res;
    res = tab[0];
/* 3. confronta ogni elemento dell'array 
con res e aggiorna res se l'elemento è maggiore */
    for(unsigned int i = 0; i < len; i += 1)
    {
        if(res < tab[i])
            res = tab[i];
    }
/* 4. ritorna res */
    return (res);
}