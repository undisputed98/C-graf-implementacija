# Graph 

C++ Graf implementacija. 

### Kako da se pokrene?

```
cd graph
make all 
./build/graph
```

### Beleske

Posto sam hteo da implementiram opstu klasu za Grafu hteo sam da ima mogucnost da doda novi cvor , tako da mi je trebala lista listi koja moze da menja svoju velicinu. Pogodno resenje mi je bilo da definisem "Vector" template, sto bi mi dozvolilo da imam vektor vektora `Vector< Vector <int> >`.

### >> operator

Čita graf u sledećem formatu:
```
no_nodes no_muchii
node1 node2
node3 node4  
....

nodeK nodeP
```


### << operator

Ispisuje graph u sledecem formatu
```
no_nodes no_muchii
node1 node2
node3 node4  
....

nodeK nodeP
```

### Napomene
* cvorovi pocinju od 0 
* funkcionalnost je prikazana u main.cpp
* program ispisuje i cita graf - neophodan je unos sa tastature


### Funkcionalnosti

* bfs 
* dfs
* proverava da li je zadatak graf drvo
* racuna distancu izmedju dva cvora
* overajduje = operator
* overajduje > and < operators
* overajduje >> and << operators
* [] vraca listu povezanosti cvora