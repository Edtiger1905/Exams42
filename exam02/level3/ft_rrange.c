/* sub: dobbiamo allocare un array di int con il malloc e
riempirlo con i valori da end a start compresi,e ritornare
un pointer al primo valore dell'array
es:
(1, 3) -> ritorna 3,2,1
(-1, 2) -> ritorna 2,1,0,-1 */

/* 1. funzione principale: alloca e restituisce un array
di interi come da subject */
int *ft_rrange(int start, int end)
{
    int *range;
    int i;
    int step;
    int n;

    /* 2. calcolo della dimensione: la 
    lunghezza e' la distanza tra start ed 
    end +1 per includere entrambi. */
    i = 0;
    step = 1;
    n = end - start;

    if(n < 0)
        n *= -1;
    n ++;

    range = (int *)malloc(sizeof(int) * n);
    /* 3. riempimento dell'array: inserisce i 
    valori partendo da end e avanzando verso start */
    if(range)
    {
        if(start < end)
            step = -1;
        while(i < n)
        {
            range[i] = end;
            end += step;
            i++;
        }
    }
    return (range);
}