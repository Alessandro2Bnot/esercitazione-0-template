#include <stdio.h>
#include <stdlib.h>

/* Esempio di riferimento: https://en.cppreference.com/c/string/byte/strtol */
int leggi_intero(char *testo)
{
    char *fine;
    long valore = strtol(testo, &fine, 10);

    /* Nessuna cifra letta oppure caratteri rimasti dopo il numero. */
    if (fine == testo || *fine != '\0') {
        fprintf(stderr, "Il secondo argomento deve essere un intero in base 10.\n");
        exit(2);
    }
    return (int)valore;
}

/* Esempio di riferimento: https://en.cppreference.com/c/string/byte/strtof
 * Per ottenere un double usiamo strtod, descritta nella stessa pagina. */
double leggi_reale(char *testo)
{
    char *fine;
    double valore = strtod(testo, &fine);

    if (fine == testo || *fine != '\0') {
        fprintf(stderr, "Il terzo argomento deve essere un numero reale.\n");
        exit(2);
    }
    return valore;
}

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Uso: %s TESTO INTERO REALE\n", argv[0]);
        return 2;
    }

    char *testo = argv[1];

    /* TODO: converti gli argomenti in tipi appropriati. */

    /* Evita una segnalazione finche' testo non viene usato nella stampa. */
    (void)testo;

    /* TODO: scrivi una sola chiamata a printf che stampi testo, intero e reale,
     * separati da uno spazio e seguiti da un carattere di nuova riga. */

    return 0;
}
