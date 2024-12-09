   map<int, int> ile_jest; // Mapa do przechowywania liczby wystąpień
   for (int n : vector) { // Zliczanie wystąpień
       ile_jest[n]++; // Zwiększ licznik dla danej liczby
   }

Załóżmy, że vector zawiera liczby {1, 2, 2, 3}. Pętla działa w następujący sposób:
1.	Pierwsza iteracja:
•	num = 1
•	ile_jest[1]++ zwiększa wartość skojarzoną z kluczem 1 w mapie ile_jest o 1.
•	Mapa ile_jest teraz zawiera: {1: 1}
2.	Druga iteracja:
•	num = 2
•	ile_jest[2]++ zwiększa wartość skojarzoną z kluczem 2 w mapie ile_jest o 1.
•	Mapa ile_jest teraz zawiera: {1: 1, 2: 1}
3.	Trzecia iteracja:
•	num = 2
•	ile_jest[2]++ ponownie zwiększa wartość skojarzoną z kluczem 2 w mapie ile_jest o 1.
•	Mapa ile_jest teraz zawiera: {1: 1, 2: 2}
