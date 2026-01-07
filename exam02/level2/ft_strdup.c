#include <stdlib.h>
#include <stdio.h>

/* sub: ricrea il funzionamento della funzione strdup della libreria base di C */
char *ft_strdup(char *src)
{
	/* 1. dichiarazione delle due variabili,una l'indice per entrambe le stringhe e l'altra la stringa in cui
	 * dobbiamo duplicare la stringa di origine */
	int i;
	char *dest;

	i = 0;
	/* 2. loop per far andare la stringa fino alla fine, allocamento dinamico per la nuova stringa della
	 * dimensione di sizeof(char) * (i + 1). Controlla l'allocamento e fa andare un altro loop che fa la 
	 * stessa cosa del precedente con la sola differenza che copia le informazioni di src dentro a dest,
	 * in modo da poter duplicare la stringa. Ritorna dest una volta finito,il free andra' messo poi nel
	 * main una volta usato */

	while(src[i] != '\0')
		i++;
	dest = malloc(sizeof (char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return(dest);
}
