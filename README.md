**PROIECT STRUCTURI DE DATE**
**ARTENI EDUARD**

**BUBBLE SORT**

Pentru Bubble Sort am folosit trei teste mici cu N = 20.000 elemente:
1. vector deja sortat crescător (0.25 milisecunde);
2. vector aproape sortat (1 milisecunda);
3. vector sortat descrescător (4-5 secunde);
4. vector cu valori generate aleatoriu (2.4-2.5 secunde).

Concluzie:
Rezultatele au confirmat comportamentul teoretic al algoritmului. Pe vectorul deja sortat s-a oprit după o singură parcurgere
obținând timpul cel mai mic.
Pe vectorul aproape sortat se vede inca o slabiciune, pentru cateva inversiuni rularea devine de 4-5 ori mai lenta.
Pe vectorul descrescător, algoritmul a avut cazul cel mai nefavorabil.
Pentru vectorul aleatoriu, timpul obținut a fost între cele două cazuri extreme.

**INSERTION SORT**

Pentru Insertion Sort am folosit 4 teste mici cu N = 20.000 elemente:
1. vector deja sortat crescator (0.2-0.25 milisecunde)
2. vector aproape sortat (0.2-0.25 milisecunde) 
3. vector sortat descrescator (2 secunde):
  Observație:
  Deși Bubble Sort și Insertion Sort au complexitate O(n²) în cazul nefavorabil,
 Insertion Sort a fost mult mai rapid pe testul descrescător, deoarece mută elementele prin deplasări succesive,
 în timp ce Bubble Sort folosește interschimbări repetate între elemente vecine.   
4. vector cu valori generate aleatoriu (0.8-1 secunda)

Concluzie:
Rezultatele obținute confirmă comportamentul teoretic al algoritmului Insertion Sort. 
Pe vectorii deja sortați sau aproape sortați, algoritmul este foarte rapid, deoarece elementele sunt
deja aproape de poziția corectă și sunt necesare foarte puține mutări. 
Pe vectorul descrescător apare cazul nefavorabil, timpul crescând semnificativ, 
deoarece fiecare element trebuie mutat spre începutul vectorului. 
Pe date aleatorii, timpul este intermediar, dar rămâne mai bun decât Bubble Sort datorită 
numărului mai mic de operații de scriere.
