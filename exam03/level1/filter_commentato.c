#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/* BUFFER_SIZE definisce quanti byte leggiamo da stdin per volta.
 * Può essere impostato a compile time con -D BUFFER_SIZE=N,
 * altrimenti usa 42 come valore di default. */
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

/* Calcola la lunghezza di una stringa senza usare strlen della libc.
 * Restituisce 0 se il puntatore è NULL, per sicurezza. */
size_t ft_strlen(char *s)
{
	size_t i = 0;
	if (!s)
		return i;
	while (s[i] != '\0')
		i++;
	return i;
}

/* Concatena due stringhe in una nuova stringa allocata dinamicamente.
 * Alloca esattamente size1 + size2 + 1 byte (il +1 è per il '\0' finale).
 * Restituisce NULL se malloc fallisce.
 * NOTA: il chiamante è responsabile di liberare la memoria restituita. */
char *ft_strjoin(char *s1, char *s2)
{
	size_t size1 = ft_strlen(s1);
	size_t size2 = ft_strlen(s2);
	char *tmp = malloc(size1 + size2 + 1);
	if (!tmp)
		return NULL;
	/* memmove è più sicuro di memcpy perché gestisce i buffer sovrapposti */
	memmove(tmp, s1, size1);
	memmove(&tmp[size1], s2, size2);
	tmp[size1 + size2] = '\0';
	return tmp;
}

/* Confronta i primi n caratteri di s1 e s2.
 * Restituisce 0 se sono uguali, altrimenti la differenza tra i caratteri
 * che divergono (positivo se s1 > s2, negativo se s1 < s2).
 * Si ferma al primo '\0' trovato o dopo n caratteri. */
int ft_strncmp(char *s1, char *s2, size_t n)
{
	int i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < (int)n)
	{
		if (s1[i] != s2[i])
			return s1[i] - s2[i];
		i++;
	}
	return 0;
}

/* Scorre s1 carattere per carattere e scrive su stdout.
 * Ogni volta che trova il pattern s2, scrive tanti '*' quanti sono
 * i caratteri del pattern e salta avanti di conseguenza.
 * Se non c'è corrispondenza, scrive il carattere corrente e va avanti di 1. */
void filter(char *s1, char *s2)
{
	int i = 0;
	size_t size2 = ft_strlen(s2);
	while (s1[i] != '\0')
	{
		/* Confronta i prossimi size2 caratteri con il pattern */
		if (ft_strncmp(&s1[i], s2, size2) == 0)
		{
			/* Pattern trovato: scrivi un '*' per ogni carattere del pattern */
			int j = 0;
			while (j < (int)size2)
			{
				write(1, "*", 1);
				i++;
				j++;
			}
		}
		else
		{
			/* Nessuna corrispondenza: scrivi il carattere com'è */
			write(1, &s1[i], 1);
			i++;
		}
	}
}

int main(int argc, char **argv)
{
	ssize_t bytes = 0;
	char *r    = NULL; /* buffer accumulatore: contiene tutto ciò che è stato letto */
	char *tmp  = NULL; /* buffer temporaneo usato durante il realloc manuale */
	char *s    = argv[1]; /* il pattern da sostituire, passato come argomento */
	char b[BUFFER_SIZE + 1] = ""; /* buffer di lettura chunk per chunk (+1 per il '\0') */

	/* Valida gli argomenti: deve essercene esattamente uno e non essere NULL */
	if (argc != 2 || !s)
		return 1;

	/* Legge stdin a blocchi di BUFFER_SIZE byte finché non arriva EOF.
	 * Ad ogni iterazione:
	 *   1. Termina il buffer di lettura con '\0'
	 *   2. Concatena il chunk appena letto al buffer accumulatore r
	 *   3. Libera il vecchio r e aggiorna il puntatore */
	while ((bytes = read(0, b, BUFFER_SIZE)) > 0)
	{
		b[BUFFER_SIZE] = '\0';
		tmp = ft_strjoin(r, b);
		free(r);  /* libera il vecchio accumulatore (NULL è sicuro con free) */
		r = tmp;
	}

	/* Se read() ha restituito un valore negativo c'è stato un errore di I/O */
	if (bytes < 0)
		return (free(r), 1);

	/* Se r è ancora NULL, stdin era vuoto: niente da stampare */
	if (!r)
		return 0;

	/* Applica il filtro e scrivi il risultato su stdout */
	filter(r, s);

	/* Libera la memoria e termina con successo.
	 * L'operatore virgola esegue free(r) prima di restituire 0. */
	return (free(r), 0);
}