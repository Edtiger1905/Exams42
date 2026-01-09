#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* sub: Calcola il risultato dell'operazione richiesta tra due interi, 
 * gestendo moltiplicazione, divisione, modulo, somma e sottrazione 
 * tramite il carattere operatore passato come parametro. */
int do_op(int a,char op,int b) //prende come input due interi e un carattere operatore
{
    int result; //variabile per memorizzare il risultato

    result = 0; //inizializza il risultato a 0
    if(op == '*') //se l'operatore è '*', moltiplica a e b
        result = a * b;
    else if(op == '/') //se l'operatore è '/', dividi a per b
        result = a / b;
    else if(op == '%') //se l'operatore è '%', calcola il modulo di a per b
        result = a % b;
    else if(op == '+') //se l'operatore è '+', somma a e b
        result = a + b;
    else if(op == '-') //se l'operatore è '-', sottrai b da a
        result = a - b;
    return (result); //ritorna il risultato dell'operazione
}
int main(int ac, char **av)
{
    int a; //variabile per il primo operando
    int b; //variabile per il secondo operando
    char op = 0; //variabile per l'operatore

    if (ac != 4) //controlla se il numero di argomenti è corretto, altrimenti stampa una nuova linea e termina
    {
        printf("\n");
        return (0);
    }
    a = atoi(av[1]); //converte il primo argomento in intero
    b = atoi(av[3]); //converte il terzo argomento in intero

    if (strchr(av[2], '*')) //controlla se l'operatore è '*', altrimenti assegna l'operatore passato come argomento
        op = '*';
    else
        op = av[2][0]; //assegna l'operatore passato come argomento

    if ((op == '/' || op == '%') && b == 0) //
    {
        printf("\n");
        return (0);
    }
    printf("%d\n", do_op(a, op, b));
    return (0);
}













/* #include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int do_op(int a,char op,int b)
{
    int result;

    result = 0;
    if(op == '*')
        result = a * b;
    else if(op == '/')
        result = a / b;
    else if(op == '%')
        result = a % b;
    else if(op == '+')
        result = a + b;
    else if(op == '-')
        result = a - b;
    return (result);
}

int main(int ac, char **av)
{
    int a;
    int b;

    a = atoi(av[1]);
    b = atoi(av[3]);
    if (ac == 4)
        printf("%i", do_op(a, av[2][0], b));
    printf("\n");
    return (0);
} */