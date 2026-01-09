/* sub: prendere un byte e scambiare i primi 4 bit 
con i secondi 4 bit */

unsigned char swap_bits(unsigned char octet)
{
    /* 1. operazione di scambio: 
    -shift a destra di 4 bit -> porta la parte alta in basso
    -shift a sinistra di 4 bit -> porta la parte bassa in alto
    -operazione OR -> unisce le due parti scambiate */
    return ((octet >> 4) | (octet << 4));
}