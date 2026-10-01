# Step 2 — Eco degli argomenti

Prosegui dopo il checkpoint di Hello World, nello stesso repository locale.
Questa volta il risultato dipende dagli argomenti passati al programma.

Scambiatevi i ruoli: chi ha usato la tastiera nello step 1 ora controlla il
codice e discute le prove, mentre il compagno esegue i comandi. Sul PC
comune aggiornate l'identità Git e l'autenticazione come indicato nel README.

```sh
git config user.name "Nome Cognome"
git config user.email "email-associata-a-GitHub"
```

Se invece cambiate computer, chi prosegue riceve prima il lavoro già inviato con
`git pull`, partendo da una copia locale senza modifiche in sospeso.

Il programma `eco.c` riceve tre argomenti:

```text
./eco TESTO INTERO REALE
```

Il primo argomento è già conservato nella variabile
`testo` così com'è, il secondo va convertito nella variabile `intero` di tipo
`int`, il terzo nella variabile `reale` di tipo `double`.
Per le conversioni usa le funzioni fornite `leggi_intero` e `leggi_reale`:
riconoscono gli argomenti non numerici, ma non controllano i limiti dei tipi.
Per queste prove usa numeri piccoli e finiti.

**Completa il TODO, con una chiamata a `printf` dopo la conversione**
che stampi le tre variabili, nell'ordine, separate da uno spazio e seguite da
una nuova riga. Il testo deve rimanere invariato, l'intero va stampato in base
10 e il reale con sei cifre dopo il punto decimale.

Per esempio, dopo il completamento:

```console
./eco ciao 12 3.5
ciao 12 3.500000
```

Il template iniziale compila, ma con argomenti validi non stampa ancora nulla.
L'istruzione `(void)testo` evita una segnalazione finché manca la stampa:
puoi rimuoverla quando usi la variabile. Completa le chiamate alle funzioni
di conversione e la stampa; le due funzioni sono già fornite.

## Strumenti a disposizione

Per la compilazione diretta:

```sh
gcc -std=c17 -Wall -Wextra -Wpedantic eco.c -o eco
```

Oppure, con il Makefile:

```sh
make eco         # compila il programma del secondo step
```

`make` senza argomenti resta dedicato a Hello World. Dopo la compilazione,
esegui `./eco ciao 12 3.5` e confronta il risultato con l'esempio precedente.

## Domande stimolo

- Gli elementi di `argv` sono già numeri? Che differenza ti aspetti passando
  `0012` come primo oppure come secondo argomento?
- Come puoi passare un testo che contiene spazi mantenendolo come un solo
  argomento?
- Se scrivi `1.25e1` come terzo argomento, quale valore ti aspetti in uscita?
  La rappresentazione scritta sulla riga di comando deve rimanere uguale?
- Se un argomento manca o non rappresenta il tipo richiesto (ad esempio una
  stringa invece di un numero), che cosa ti aspetti dal programma?
- Come distingui il risultato da un messaggio di errore?

Raccogliete in `osservazioni.md` le vostre osservazioni.
Puoi salvare un output con la redirezione `> eco.txt`.

## Risultato, messaggio d'errore e codice di uscita

Dopo aver completato il programma, esegui queste due prove. Per ciascuna,
prevedi che cosa finirà nel file e che cosa comparirà nel terminale:

```sh
./eco ciao 12 3.5 > eco.txt
echo $?
cat eco.txt

./eco ciao dodici 3.5 > eco.txt
echo $?
cat eco.txt
```

`echo $?` mostra il codice di uscita del comando appena terminato: eseguilo
subito dopo `./eco`, prima di altri comandi. Zero indica una conclusione
regolare; un valore diverso da zero segnala un errore. `cat` mostra il
contenuto del file. La seconda redirezione `>` sostituisce il contenuto
precedente di `eco.txt`.

- Che cosa contiene `eco.txt` nei due casi?
- Perché nel secondo caso il messaggio d'errore compare ancora nel terminale?
  Individua nel sorgente le stampe su `stdout` e su `stderr`. Cosa viene 
  rediretto da `>`?
- Quali codici di uscita osservi? Come potresti usarli in un controllo automatico?

Scrivi le tue osservazioni in `osservazioni.md`.

## Dai parametri al calcolo fisico

Esegui lo stesso programma cambiando soltanto il terzo argomento.
Se quel numero rappresentasse il passo temporale di una simulazione,
dovresti ricompilare per cambiarlo? E per cambiare la formula usata dal
programma? Annota la differenza tra cambiare i parametri di un'esecuzione
e modificare il codice che implementa il calcolo.

**Checkpoint:** sai spiegare la differenza fra testo ricevuto, valore
convertito e rappresentazione stampata, usando le tue prove, e riconoscere
un'esecuzione terminata con un errore? Prova a usare eco2.c, cosa cambia?

Registra le modifiche di `eco.c` e `osservazioni.md` in un nuovo commit e
invialo con Git. Come riconosci nella cronologia il completamento dei due
step? Annota la verifica in `osservazioni.md` e registra anche questa aggiunta.
Poi controllate insieme il lavoro e seguite la
[consegna finale di gruppo](README.md#consegna-finale).
