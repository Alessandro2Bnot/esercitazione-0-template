# Osservazioni — Esercitazione 0

Gruppo: n.75 pc10

Componenti (nome, cognome e username GitHub di entrambi):

Alessandro Iemmo Alessandro2Bnot

Priscilla Focarete priscilla2261694

URL del repository condiviso:

https://github.com/Alessandro2Bnot/esercitazione-0-template.git

Chi ha usato la tastiera nello step 1 e nello step 2:

Alessandro Iemmo

Compilate insieme le osservazioni e discutete le risposte: entrambi dovete
saper spiegare le prove svolte.

## Step 1 — Hello World: compilazione ed esecuzione

Comando di compilazione: gcc -std=c17 -Wall -Wextra -Wpedantic hello.c -o hello

Comando di esecuzione e risultato osservato:

./hello

ha stampato il messaggio sul terminale

#comodo come sostituto di .dat

Che cosa ho capito su sorgente ed eseguibile: la sorgente contiene il codice scritto e spesso e' un file .c / .py

Output richiesto e comportamento del programma prima della modifica:

l'output richiedeva la stampa di un testo messaggio, prima della modifica il proramma non eseguiva nulla perche' il codice era "vuoto". 

Esito dopo la modifica e spiegazione della correzione:

dopo aver aggiunto > output.txt ha salvato il testo in un file .txt eseguibile con emacs. Il messaggio non e' stato stampato nel terminale stavolta.

## Step 1 — Git

Quali file ho incluso nel commit e perché:

ho incluso nel primo commit la versione aggiornata di hello.c

nel secondo commit, ho aggiunto anche il file .txt

ho eseguito push per entrambi.

Come ho verificato che la versione provata sia presente su GitHub:

sono andato nella sezione repositories del mio profilo github, e ho confermato che quella giusta e' stata aggiornata di recente.

Che cosa ho osservato prima e dopo `git pull`, e perché non serve un nuovo clone: 

Ho scritto questo messaggio online direttamente da GitHub, dopo pull ho notato la modifica anche sul computer. 

Non serve un nuovo clone perche' con git pull ho scaricato la modifica direttamente.

## Step 2 — Eco: prima prova

Argomenti passati, comando e risultato:

./eco multipath fox2 gen4.5
Risultato stampato: multipath 0 0.000000

Che cosa posso concludere:

Se passo alle funzioni atoi e atof delle stringhe che iniziano con lettere invece che con numeri, la conversione fallisce e il programma restituisce 0 come valore predefinito.

## Step 2 — Eco: seconda prova

Argomenti passati, comando e risultato:

./eco multipath 2fox 4.5gen
Risultato stampato: multipath 2 4.500000

Che cosa ho capito su testo, conversioni e stampa:

Tutti i parametri inseriti nel terminale (argv) vengono visti dal C come stringhe di testo (char *). Per poterli usare o stampare come interi (%d) o reali (%f), devono prima essere obbligatoriamente convertiti usando atoi e atof.

## Step 2 — Risultato ed errori

Previsioni per l'esecuzione con argomenti validi e per quella con `dodici`:

Con argomenti validi (es. "ciao 10 3.14") il programma stamperà correttamente i valori formattati. Con "dodici" al posto di un numero, la conversione atoi fallirà e stamperà 0.

Contenuto di `eco.txt`, messaggi nel terminale e codici di uscita osservati:

Reindirizzando l'output in eco.txt con il simbolo >, il file contiene i risultati corretti stampati da stdout. Se però sbaglio il numero di argomenti, il terminale mostra comunque l'errore "Uso: ..." perché stderr non viene reindirizzato nel file txt. Il codice di uscita per errore è 2.

Come un controllo automatico può riconoscere un errore:

Controllando il codice di uscita del programma (diverso da 0, es. return 2) oppure stdrr

## Step 2 — Parametri e calcolo fisico

Quando serve ricompilare e quando basta cambiare gli argomenti:

Serve ricompilare usando gcc solo quando viene modificato il codice all'interno del file sorgente .c. Basta invece cambiare gli argomenti nel terminale quando si vogliono usare nuovi dati in input senza cambiare la struttura del programma.

## Step 2 — Git

Come riconosco nella cronologia i commit dei due step:

Dai messaggi del commit.

Come ho verificato che la versione finale sia presente su GitHub:

Sono andato sul repository online da browser e ho controllato che il file eco.c contenesse le ultime modifiche fatte, in particolare l'aggiunta di atoi, atof e la printf corretta.