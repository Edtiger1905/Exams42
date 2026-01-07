#include <unistd.h>
#include <stdio.h>
#include <string.h>

/* sub: ricreare la funzione strcspn. Scorre la stringa da sinistra a destra e si ferma appena trova un carattere
 * che appartiene a un altro insieme di caratteri(reject) */

/* 1. ritorna come valore un size_t,nel nostro caso i. Prende in input le variabili *s  e *reject */
size_t	ft_strcspn(const char *s,const char *reject)
{
	/* 2. dichiara le tue variabili e le inizializza */
	size_t i;
	size_t k;

	i = 0;
	k = 0;
	/* 3. fa andare avanti le stringhe fino alla fine e quando trova una cosa di *reject uguale in *s,ferma
	 * il ciclo e ritorna il numero di dove e' arrivato,quindi l'indice */
	while(s[i] != '\0')
	{
		while(reject[k] != '\0')
		{
			if(reject[k] == s[i])
				return(i);
			k++;
		}
		k = 0;
		i++;
	}
	return(i);
}
