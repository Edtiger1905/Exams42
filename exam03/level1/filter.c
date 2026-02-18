/* sub: Scrivi un programma che prende in input un solo argomento.
Il programma deve leggere da stdin e scrivere tutto il contenuto
letto in stdout ad eccezione del fatto che ogni occorrenza di 
s(la stringa in input da av) deve essere rimpiazzato da un '*'
*/

/* Blocco 0: librerie e costanti.
unistd.h: per read e write
stdlib.h: per malloc e free
string.h: per strlen
stdio.h: per perror
MAX_INPUT_BUFFER_SIZE: dimensione massima del buffer di input,
10000 caratteri + 1 per il terminatore di stringa.   
*/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_INPUT_BUFFER_SIZE 10001

/* Blocco 1: Funzioni ft_strncmp
Confronta i primi n carattere delle due stringe:
- Se sono uguali, ritorna 1
- Se sono diverse, ritorna 0
Serve per controllare se,in una certa posizione del testo, c'e'
la parola da censurare.
*/
int ft_strncmp(char *s1, char *s2, int n)
{
    int i;

    i = 0;
    while(i < n && s1[i] == s2[i])
        i++;
    return (i == n);
}
/* Blocco 2: Inizio main, variabili e controllo argomenti.
buffer: contiene il testo letto da stdin
c: carattere temporaneo per la lettura
r: numero di byte letti da read
i: indice per scorrere il buffer
len: lunghezza della stringa da censurare (av[1]) 
Il check verifica che ci sia un solo argomento, che non sia vuoto
e che non sia null.
*/
int main(int ac, char **av)
{
    char *buffer;
    char c;
    ssize_t r;
    int i;
    int len;

    i = 0;
    if(ac != 2 || !av[1] || !*av[1])
        return (1);

/* Blocco 3: lunghezza stringa e allocazione memoria
I. Calcola la lunghezza della stringa da censurare.
II. Alloca la memoria per il buffer.
III. Se malloc fallisce stampa errore e termina.
*/

len = strlen(av[1]);
buffer = malloc(MAX_INPUT_BUFFER_SIZE);
if(!buffer)
    return (perror("Error"), 1);

/* Blocco 4: Lettura da stdin.
Legge l'input un carattere alla volta finche' non arriva a EOF o
finche' il buffer non e' pieno.
*/
while((r = read(STDIN_FILENO, &c, 1)) > 0
    && i < MAX_INPUT_BUFFER_SIZE - 1)
    buffer[i++] = c;

/* Blocco 5: Gestione errore di lettura 
Se read ritorna -1: c'e' un errore, stampa il messaggio, libera la 
memoria e termina.
*/

if(r == -1)
    return (perror("Error"), free(buffer), 1);

/* Blocco 6: Terminazione stringa
Aggiunge il terminatore \0 per prendere il buffer una stringa valida 
*/

buffer[i] = '\0';

/* Blocco 7: Ciclo di elaborazione output 
Scorre tutto il buffer carattere per carattere e controllo se nella
posizione corrente c'e' la stringa da censurare.
*/
i = 0;
while(buffer[i])
{
    if(i + len <= strlen(buffer) &&
        ft_strncmp(&buffer[i], av[1], len))
    
    /* Blocco 8: Caso stringa trovata.
    Se trova la stringa stampa len asterischi e avanza di len
    caratteri
    */
    for(int j = 0; j < len; j++)
        write(STDOUT_FILENO, "*", 1);
    i += len;
    /* Blocco 9: Caso stringa non trovata.
    Stampa il carattere originale e passa al successivo      
    */
    write(STDOUT_FILENO, &buffer[i++], 1);
    /* Blocco 10: Fine programma.
    Libera la memoria e termina correttamente. */
    free(buffer);
    return (0);
}
}