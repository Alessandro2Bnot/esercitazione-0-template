#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Uso: %s TESTO INTERO REALE\n", argv[0]);
        return 2;
    }

    char *testo = argv[1];

    /* TODO: converti gli argomenti in tipi appropriati. Usa atoi o atof */

    /* Evita una segnalazione finche' testo non viene usato nella stampa. */
    (void)testo;

    /* TODO: scrivi una sola chiamata a printf che stampi testo, intero e reale,
     * separati da uno spazio e seguiti da un carattere di nuova riga. */

    return 0;
}
