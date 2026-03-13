/* sub: ricreare il funzionamento di get_next_line,una funzione che legge un file
riga per riga. */

/* Blocco 0: librerie e define
stdlib.h -> fornisce malloc e free
string.h -> fornisce strlen
unistd.h -> fornisce read e close
stdio.h  -> fornisce printf (usato solo nel main)
fcntl.h  -> fornisce open e le costanti come O_RDONLY
BUFFER_SIZE -> dimensione del buffer di lettura, cioe' di quanti byte 
vengono letti ala volta nel file.
#ifndef -> controlla se BUFFER_SIZE non e' gia' stato definito. Se non lo e' lo definisce 
come 42. Questo permette di compilare il programma con "-D BUFFER_SIZE=1000" per cambiare
la dimensione del buffer senza modificare il codice.*/
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

/* Blocco 1: ft_strdup -> duplica una stringa allocando nuova memoria.
Flusso:
I. Dichiara i come contatore e s1 come puntatore alla nuova stringa.
II. Inizializza i = 0.
III. Controlla se str e' NULL. Se lo e', ritorna NULL subito.
IV. Alloca memoria con malloc per una stringa lunga quanto str piu' 1 byte per il terminatore
'\0'. La dimensione e' strlen(str) + 1.
V. Se malloc fallisce e ritorna NULL, la funzione ritorna NULL.
VI. Copia carattere per carattere da str a s1 usando un ciclo while.
VII. Aggiunge il terminatore  '\0' alla fine di s1.
VIII. Ritorna il puntatore alla nuova stringa duplicata.
*/
char *ft_strdup(const char *str)
{
    int i;
    char *s1;

    i = 0;
    if(str == NULL)
        return (NULL);
    s1 = malloc(sizeof(char) * (strlen(str) + 1));
    if(s1 == NULL)
        return (NULL);
    while(str[i])
    {
        s1[i] = str[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}
/* Blocco 2: get_next_line -> legge una riga alla volta dal file descriptor fd.
Flusso:
I. Dichiara le variabili: buffer statico per conservare i dati letti, line temporaneo per
costruire la riga, b_read e b_pos statici per tracciare lo stato del buffer, i per la
posizione in line.
II. Inizializza i = 0.
III. Controlla validita': fd < 0 (file descriptor invalido) o BUFFER_SIZE < 1, ritorna NULL.
IV. Entra nel loop infinito while(1) che si fermera' solo con un break.
V. Prima parte del loop -> riempimento buffer:
- Se b_pos >= b_read significa che abbiamo consumato tutto il buffer e dobbiamo leggere 
nuovi dati.
- Chiama read(fd, buffer, BUFFER_SIZE) che legge fino a BUFFER_SIZE byte dal file e li mette
in buffer. Ritorna il numero di byte effettivamente letti.
- Resetta b_pos = 0 per iniziare a leggere dal primo byte del nuovo buffer.
- Se b_read <= 0 (fine file o errore), esce dal loop con break.
VI. Seconda parte del loop -> copia carattere:
- Copia il carattere corrente dal buffer alla riga: line[i++] = buffer[b_pos++].
- Questo incrementa sia i (posizione inline) che b_pos (posizione nel buffer).
VII. Controllo newline: 
- Se il carattere appena copiato e' '\n' (cioe' buffer[b_pos - 1] == '\n'), la riga e'
completa e esce dal loop con break.
VIII. Aggiunge il termianatore '\0' alla fine di line.
IX. Se i == 0 significa che non e' stato letto nessun carattere (file vuoto o gia' finito),
ritorna NULL.
X. Chiama ft_strdup(line) per duplicare la riga in memoria dinamica e la ritorna al chiamante.
*/

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    char        line[70000];
    static int  b_read;
    static int  b_pos;
    int         i;

    i = 0;
    if(fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    while(1)
    {
        if(b_pos >= b_read)
        {
            b_read = read(fd, buffer, BUFFER_SIZE);
            b_pos = 0;
            if(b_read <= 0)
                break ;
        }
        line[i++] = buffer[b_pos++];
        if(buffer[b_pos - 1] == '\n')
            break ;
    }
    line[i] = '\0';
    if(i == 0)
        return (NULL);
    return (ft_strdup(line));
}
/* Blocco 3: main
Flusso: 
I. Dichiara fd per il file descritor e line per la riga letta.
II. Apre il file "test.txt" in sola lettura con open("test.txt", O_RDONLY). Ritorna un numero
(file descriptor) che identifica il file aperto.
III. Inizializza line = NULL.
IV. Entra nel while che continua finche' get_next_line non ritorna NULL (fine file).
V. Ad ogni iterazione:
- Chiama get_next_line(fd) per leggere la prossima riga.
- Stampa la riga con printf("%s", line). Nota: non serve aggiungere '\n' perche' la riga 
gia' lo contiene.
- Libera la memoria con free(line), altrimenti si avrebbe un memory leak.
VI. Quando il file finisce, get_next_line ritorna NULL e il loop termina.
VII. Chiude il file con close(fd) per liberare le risorse.
*/

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    line = NULL;

    while((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
}