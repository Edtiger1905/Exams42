/* stampa tutti i numeri da 1 a 100,ognuno separati da un newline
se il numero e' un multiplo di 3,stampa fizz. Se e' multiplo di 5 stampa buzz. Se e' multiplo di entrambi,stampa fizzbuzz */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}
 
/* funzione ricorsiva che serve per calcolare i numeri fino a 100 non avendo modo di prenderli da qualche altra parte,quindi li genera facendo richiamando tot volte la sua stessa funzione per creare i numeri necessari.
se non deve convertire i numeri maggiori di 9 e inserirli,semplicemente stampa il carattere numerico,composto da n + 48,per arrivare al corrispettivo ascii del numero. */
void ft_putnbr(int n)
{
	if(n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}
/* cuore cardine della funzione,serve per fare i check sulle scritte da mettere a schermo ogni volta che questo numero e' multimo di 3,5 o di 3 e 5 insieme. se sono rispettati dei requisiti stampa la scritta imposta,
senno' stampa il numero */
void fizzbuzz(void)
{
    int n;

    n = 1;
    while (n <= 100)
    {
        if(n % 15 == 0)
            	write(1, "fizzbuzz", 8);
        else if(n % 3 == 0)
            	write(1, "fizz", 4);
        else if(n % 5 == 0)
            	write(1, "buzz", 4);
        else
           	ft_putnbr(n);
        write(1, "\n", 1);
	n++;
    }
    
}
/* il main,richiama la funzione e ritorna 0. */
int main()
{
    fizzbuzz();
    return(0);
}
