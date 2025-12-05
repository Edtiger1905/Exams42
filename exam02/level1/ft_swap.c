
// funzione che scambia il contenuto di due interi pointer che sono passati come parametri


void ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}