~~**PROIECT STRUCTURI DE DATE**
**ARTENI EDUARD**

***O(n^2)***

**BUBBLE SORT**

Pentru Bubble Sort am folosit trei teste mici cu N = 20.000 elemente:
1. vector deja sortat (0.1 milisecunde);
2. vector aproape sortat (0.35 milisecunde);
3. vector sortat descrescător (2.7 secunde);
4. vector cu valori generate aleatoriu (2.4 secunde).

Concluzie:
Rezultatele au confirmat comportamentul teoretic al algoritmului. Pe vectorul deja sortat s-a oprit după o singură parcurgere
obținând timpul cel mai mic.
Pe vectorul aproape sortat se vede inca o slabiciune, pentru cateva inversiuni rularea devine de 2-3 ori mai lenta.
Pe vectorul descrescător, algoritmul a avut cazul cel mai nefavorabil.
Pentru vectorul aleatoriu, timpul obținut a fost între cele două cazuri extreme.

**INSERTION SORT**

Pentru Insertion Sort am folosit 4 teste mici cu N = 20.000 elemente:
1. vector deja sortat (0.11 milisecunde) un pic mai lent decat gnome, probabil pt ca are putine chestii extra;
2. vector aproape sortat (0.12 milisecunde); 
3. vector sortat descrescator (1.2 secunde);
  Observație:
  Deși Bubble Sort și Insertion Sort au complexitate O(n²) în cazul nefavorabil,
 Insertion Sort a fost mult mai rapid pe testul descrescător, deoarece mută elementele prin deplasări succesive,
 în timp ce Bubble Sort folosește interschimbări repetate între elemente vecine.   
4. vector cu valori generate aleatoriu (0.6 secunde).

Concluzie:
Rezultatele obținute confirmă comportamentul teoretic al algoritmului Insertion Sort. 
Pe vectorii deja sortați sau aproape sortați, algoritmul este foarte rapid, deoarece elementele sunt
deja aproape de poziția corectă și sunt necesare foarte puține mutări. 
Pe vectorul descrescător apare cazul nefavorabil, timpul crescând semnificativ, 
deoarece fiecare element trebuie mutat spre începutul vectorului. 
Pe date aleatorii, timpul este intermediar, dar rămâne mai bun decât Bubble Sort datorită 
numărului mai mic de operații de scriere.

**GNOME SORT**

Pentru Gnome Sort am folosit de asemenea aceleasi 4 teste mici cu N = 20.000 elemente:
1. vector deja sortat (0.1 milisecunde) extrem de rapid practic un for gol;
2. vector aproape sortat (.11 milisecunde) extrem de rapid, poate pentru ca foloseste swap direct; 
3. vector sortat descrescator (3.6 secunde);
4. vector cu valori generate aleatoriu (1.8 secunde).

Concluzie:
Rezultatele confirmă comportamentul așteptat pentru Gnome Sort. 
Pe vectorii deja sortați sau aproape sortați, algoritmul este foarte rapid, 
deoarece face foarte puține interschimbări și avansează aproape continuu prin vector. 
Pe vectorul descrescător apare cazul nefavorabil, deoarece fiecare element trebuie 
mutat treptat spre poziția corectă prin swap-uri repetate între elemente vecine. 
Pe date aleatorii, timpul este intermediar, dar rămâne mai slab decât Insertion Sort, 
deoarece Gnome Sort folosește interschimbări repetate în loc de deplasări.

***O(n logn)***

**MERGESORT**

Pentru Merge Sort am folosit 4 teste mari cu N = 10.000.000 elemente:
1. vector deja sortat crescător: 2.6 secunde;
2. vector sortat descrescător: 2.6 secunde;
3. vector cu elemente generate aleatoriu pe intervalul int: 4.5 secunde;
4. vector cu multe duplicate: 4 secunde.

Merge Sort a avut un comportament stabil pe toate tipurile de input, deoarece 
împarte vectorul recursiv în subsecvențe și apoi le interclasează. 
Ordinea inițială a elementelor nu schimbă semnificativ numărul de împărțiri și 
interclasări, de aceea timpii pentru vectorul crescător și descrescător au fost identici.

Pe vectorul aleatoriu timpul a fost mai mare, deoarece în etapa de interclasare 
comparațiile dintre cele două jumătăți sunt mai amestecate, iar accesul la memorie și 
copierea în vectorul auxiliar pot deveni mai costisitoare. Testul cu multe duplicate a
fost puțin mai rapid decât cel complet aleatoriu, deoarece valorile egale pot duce
la comparații mai previzibile, dar algoritmul tot trebuie să parcurgă și să
copieze toate elementele.

**Concluzie:**  
Rezultatele confirmă complexitatea O(n log n) a algoritmului Merge Sort și faptul că 
acesta nu are un caz nefavorabil puternic dependent de ordinea inițială a datelor.
Spre deosebire de algoritmii O(n²), Merge Sort poate sorta eficient volume mari de date.
Principalul dezavantaj observabil este folosirea memoriei suplimentare pentru vectorul 
auxiliar, dar în schimb oferă timpi constanți și predictibili pe inputuri diferite.

**QUICK SORT**

Pentru Quick Sort am folosit 4 teste mari cu N = 10.000.000 elemente:
1. vector deja sortat crescător: 0.7 secunde;
2. vector sortat descrescător: 0.7 secunde;
3. vector cu elemente generate aleatoriu: 2.4 secunde;
4. vector cu multe duplicate: 2.4 secunde.

Implementarea folosită pentru Quick Sort alege pivotul prin metoda median-of-three și folosește partiționare Hoare. 
Această alegere a avut un efect foarte bun pe vectorii deja sortați crescător 
și descrescător. 

Astfel, algoritmul evită cazul nefavorabil O(n²), care apare la implementările 
naive de Quick Sort atunci când pivotul este ales prost. Pe vectorii aleatorii 
și pe cei cu multe duplicate timpul a fost mai mare, deoarece partiționarea implică
mai multe comparații și interschimbări reale, iar ordinea elementelor este mai
puțin previzibilă.

Concluzie:
Quick Sort a fost cel mai rapid algoritm testat până acum pe seturile mari,
în special pe vectorii ordonați crescător și descrescător. Alegerea pivotului prin
median-of-three a prevenit degradarea performanței pe date deja sortate. 
Comparativ cu Merge Sort, Quick Sort a folosit mai puțină memorie suplimentară și
a obținut timpi mai buni, dar performanța sa depinde mai mult de alegerea pivotului 
și de metoda de partiționare.


**HEAP SORT**

Pentru Heap Sort am folosit 4 teste mari cu N = 10.000.000 elemente:
1. vector deja sortat crescător: aproximativ 5 secunde;
2. vector sortat descrescător: aproximativ 5 secunde;
3. vector cu elemente generate aleatoriu: aproximativ 8 secunde;
4. vector cu multe duplicate: aproximativ 7 secunde.

Heap Sort a avut un comportament relativ stabil, deoarece are complexitate O(n log n)
indiferent de ordinea inițială a datelor. Spre deosebire de Quick Sort, nu depinde de
alegerea unui pivot și nu are un caz nefavorabil O(n²).

Timpii pentru vectorul crescător și descrescător au fost asemănători, deoarece 
algoritmul construiește heap-ul și apoi extrage maximul în același mod, indiferent 
dacă datele sunt deja ordonate sau invers ordonate. Pe vectorul aleatoriu timpul a 
fost mai mare, deoarece operațiile de heapify produc mai multe comparații și 
interschimbări greu de prezis.

Comparativ cu Quick Sort și Merge Sort, Heap Sort a fost mai lent în testele efectuate.
Acest lucru se explică prin accesul mai puțin eficient la memorie: în timpul 
operațiilor de heapify, algoritmul sare între poziții diferite ale vectorului, 
ceea ce duce la o folosire mai slabă a cache-ului.

**Concluzie:**  
Rezultatele confirmă faptul că Heap Sort este un algoritm sigur și predictibil, 
având complexitate O(n log n) în toate cazurile. Avantajul său principal este că nu 
folosește memorie suplimentară semnificativă și nu are degradare la O(n²). 
Totuși, în practică poate fi mai lent decât Quick Sort și Merge Sort din cauza 
accesului mai slab la memorie și a numărului mare de operații de heapify.

**INTROSORT**

Pentru IntroSort am folosit 4 teste mari cu N = 10.000.000 elemente:

1. vector deja sortat crescător: aproximativ 0.6 secunde;
2. vector sortat descrescător: aproximativ 0.6 secunde;
3. vector cu valori generate aleatoriu: aproximativ 2.5 secunde;
4. vector cu multe duplicate: aproximativ 1.8 secunde.

IntroSort a avut rezultate foarte bune pe vectorii deja sortați crescător și descrescător. 
Acest lucru se datorează faptului că algoritmul pornește de la Quick Sort cu pivot ales 
prin metoda median-of-three.

Pe vectorul aleatoriu timpul a fost mai mare, deoarece partiționarea implică mai multe
comparații și interschimbări. Totuși, timpul a rămas bun pentru un set de 10.000.000 de 
elemente. Pe testul cu multe duplicate, timpul a fost mai mic decât pe random,
deoarece structura datelor a permis partiționări mai favorabile și mai puține operații
costisitoare.

IntroSort combină avantajele mai multor algoritmi: folosește Quick Sort pentru viteză, 
Heap Sort ca metodă de siguranță dacă recursivitatea devine prea adâncă și Insertion Sort
pentru subsecvențe mici.

**Concluzie:**  
Rezultatele confirmă faptul că IntroSort este un algoritm foarte eficient și stabil 
pentru volume mari de date. A obținut timpi apropiați de Quick Sort pe cazurile 
favorabile, dar are avantajul suplimentar că evită degradarea la O(n²) prin trecerea 
la Heap Sort atunci când partiționările devin nefavorabile.
Comparativ cu Heap Sort și Merge Sort, IntroSort a fost mai rapid în testele efectuate, 
iar comparativ cu Quick Sort oferă o garanție mai bună în cazul unor inputuri dificile.

**PATIENCE SORTING**

Pentru Patience Sorting am folosit 4 teste mari cu N = 10.000.000 elemente:
1. vector deja sortat crescător: aproximativ 12 secunde;
2. vector sortat descrescător: aproximativ 2 secunde;
3. vector cu valori generate aleatoriu: aproximativ 10.5 secunde;
4. vector cu multe duplicate: aproximativ 10.5 secunde.

Patience Sorting a avut succes pe vectorul sortat descrescător. 
Acest lucru se explică prin modul de construire al grămezilor: pentru un vector descrescător,
elementele pot fi puse în aceeași grămadă, deci se creează foarte puține grămezi.

Pe vectorul crescător timpul a fost cel mai mare, deoarece fiecare element tinde să
formeze o grămadă nouă. Astfel, numărul de grămezi devine foarte mare, iar etapa de
extragere cu min-heap devine mai costisitoare.

Pe vectorii aleatorii și pe cei cu multe duplicate, timpul a fost 
apropiat de cel al cazului crescător, deoarece algoritmul creează un număr mare de 
grămezi și are cost suplimentar pentru căutarea poziției fiecărui element și pentru 
reconstrucția finală a vectorului sortat.

**Concluzie:**  
Patience Sorting are un comportament foarte dependent de structura inițială a datelor.
A fost rapid pe vectorul descrescător, dar semnificativ mai lent pe vectorii crescători 
și aleatorii (Adica are doar un caz bun si este o prostie). 
Timpul obținut a fost foarte slab pe majoritatea testelor mari. *Este o mare aberatie
si o prostie complicata si inutila*

***O(n)***

**RADIX SORT**

Pentru Radix Sort am folosit 4 teste mari cu N = 10.000.000 elemente:

1. vector deja sortat crescător: aproximativ 0.65 secunde;
2. vector sortat descrescător: aproximativ 0.65 secunde;
3. vector cu valori generate aleatoriu: aproximativ 0.63 secunde;
4. vector cu multe duplicate: aproximativ 0.62 secunde.

Implementarea folosită sortează numerele pe câte un byte, de la cel mai puțin semnificativ
byte până la cel mai semnificativ. Pentru fiecare byte se folosește o sortare stabilă
de tip Counting Sort, cu un vector de frecvență de dimensiune 256. Astfel, algoritmul nu
are nevoie de un vector de frecvență pentru toate valorile posibile ale unui int, ci
doar pentru valorile posibile ale unui byte.

Pentru a suporta și numere negative, valorile au fost normalizate prin modificarea bitului
de semn, astfel încât ordinea unsigned folosită intern să corespundă ordinii normale a
numerelor întregi cu semn.

Timpii obținuți sunt foarte apropiați pentru toate tipurile de input, deoarece Radix Sort
nu depinde de ordinea inițială a elementelor.

**Concluzie:**  
Radix Sort a fost cel mai rapid algoritm testat până acum pe seturile mari.
Rezultatele confirmă comportamentul aproape liniar al algoritmului, O(k·n), deci timpul este
foarte stabil indiferent dacă vectorul este sortat, descrescător, aleatoriu sau are multe duplicate.
Principalul avantaj este viteza foarte mare, iar principalul dezavantaj este faptul că algoritmul este specializat pentru valori întregi și folosește memorie suplimentară pentru vectorul temporar.
