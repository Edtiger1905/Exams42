#include <unistd.h>

// 1. DICHIARAZIONE DELLA FUNZIONE
// Questa funzione riceve un numero di 8 bit (unsigned char)
// e lo stamperà in formato binario (solo 0 e 1).
void print_bits(unsigned char octet)
{
    // 2. VARIABILI DI CONTROLLO
    // i serve per contare da 7 a 0 (cioè i bit da sinistra a destra).
    // bit conterrà il singolo carattere '0' o '1' da stampare.
    int i = 8;
    unsigned char bit;

    // 3. CICLO PER SCORRERE TUTTI GLI 8 BIT
    // Il ciclo parte dal bit più significativo e arriva al meno significativo.
    while (i--)
    {
        // 4. ESTRAZIONE DEL SINGOLO BIT
        // - (octet >> i) sposta a destra i bit
        // - & 1 prende solo l’ultimo bit (0 o 1)
        // - + '0' trasforma il numero nel carattere stampabile '0' o '1'
        bit = (octet >> i & 1) + '0';

        // 5. STAMPA DEL BIT
        // write scrive il carattere sul terminale
        write(1, &bit, 1);
    }
}
