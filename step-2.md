# Step 2 — Eco degli argomenti

Prosegui dopo il checkpoint di Hello World, nello stesso repository locale.
Questa volta il risultato dipende dagli argomenti passati al programma.

Il programma `eco.c` riceve tre argomenti:

```text
./eco TESTO INTERO REALE
```

La lettura è già implementata: il primo argomento è conservato nella variabile
`testo` così com'è, il secondo è convertito nella variabile `intero` di tipo
`int`, il terzo nella variabile `reale` di tipo `float`. Anche il controllo
sul numero e sulla validità degli argomenti è già scritto.

**Completa soltanto il TODO, scrivendo una riga con una chiamata a `printf`**
che stampi le tre variabili, nell'ordine, separate da uno spazio e seguite da
una nuova riga. Il testo deve rimanere invariato, l'intero va stampato in base
10 e il reale con sei cifre dopo il punto decimale.

Per esempio, dopo il completamento:

```console
./eco ciao 12 3.5
ciao 12 3.500000
```

Il template iniziale compila, ma con argomenti validi non stampa ancora nulla.
Le istruzioni `(void)` evitano segnalazioni sulle variabili finché manca la
stampa: puoi lasciarle dove sono. Lettura e conversioni non sono da riscrivere.

## Strumenti a disposizione

Per la compilazione diretta:

```sh
gcc -std=c17 -Wall -Wextra -Wpedantic eco.c -o eco
```

Oppure, con il Makefile:

```sh
make eco         # compila il programma del secondo step
make check-eco   # verifica eco e le conversioni; richiede Python 3
make check-all   # verifica entrambi gli step
```

`make` e `make check` restano dedicati a Hello World. `make check-eco` fallisce
finché manca la stampa del secondo step.

## Domande stimolo

- Gli elementi di `argv` sono già numeri? Che differenza ti aspetti passando
  `0012` come primo oppure come secondo argomento?
- Come puoi passare un testo che contiene spazi mantenendolo come un solo
  argomento? Che cosa cambia se togli le virgolette?
- Se scrivi `1.25e1` come terzo argomento, quale valore ti aspetti in uscita?
  La rappresentazione scritta sulla riga di comando deve rimanere uguale?
- Se un argomento manca o non rappresenta il tipo richiesto (ad esempio una 
  stringa invece di un numero), che cosa ti aspetti dal programma?
- Come distingui il risultato da un messaggio di errore?

Raccogli in `osservazioni.md` previsione, comando e risultato. 
Puoi salvare un output con la redirezione `> eco.txt`.

**Checkpoint:** sai spiegare la differenza fra testo ricevuto, valore
convertito e rappresentazione stampata, usando le tue prove.

Registra le modifiche di `eco.c` e `osservazioni.md` in un nuovo commit e
invialo con Git. Come riconosci nella cronologia il completamento dei due
step? Annota la tua verifica, poi segui la [consegna finale](README.md#consegna-finale).
