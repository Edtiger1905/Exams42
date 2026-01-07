
/* 
1. octet % 2
Prende l’ultimo bit del byte (0 o 1).
Ad esempio, se octet = 13 (00001101), octet % 2 = 1.

2. res = res * 2 + (octet % 2)
Sposta i bit di res verso sinistra di 1 (res * 2) 
e aggiunge il bit preso da octet.
In pratica costruisce res bit per bit, ma in ordine inverso.

3. octet = octet / 2
Divide per 2 per “scorrere” al prossimo bit del byte.
Equivalente a uno shift a destra (octet >> 1).

4. i--
Ripete il ciclo 8 volte, una per ogni bit del byte. 
*/


unsigned char reverse_bits(unsigned char octet)
{
    int i;
    unsigned char res;

    i = 8;
    res = 0;
    while(i > 0)
    {
        res = res * 2 + (octet % 2);
        octet = octet / 2;
        i--;
    }
    return (res);
}