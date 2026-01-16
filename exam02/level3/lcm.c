/* sub: scrivi una funzione che prende in
input 2 parametri unsigned int e ritorna 
l'lcm (least common multiple) 
dei due numeri */

/* 1. funzione principale: prende 2 
parametri unsigned int e fa il MCM  */
unsigned int lcm(unsigned int a, unsigned int b)
{
    unsigned int n;
    /* 2. controllo input: se uno 
    dei due numeri è 0, il MCM è 0 */
    if(a == 0 || b == 0)
        return (0);
    /* 3. calcoli: se a > b, il numero preso come valore
    iniziale e' a,senno' b */
    if(a > b)
        n = a;
    else
        n = b;
    /* 4. ricerca del MCM: incrementa n finche' non e' 
    divisibile per entrambi i numeri */
    while(1)
    {
        if(n % a == 0 && n % b == 0)
            return (n);
        ++n;
    }
}