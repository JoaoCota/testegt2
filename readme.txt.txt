
Primeiramente, leve em consideração  um grafo como uma lista de adjacência para um grafo não dirigido para poder ser lida como arquivo pelas quebras de linha.
Leve em consideração que o número total de vértices são os nós.


Inserir_Aresta -> insere as arestas com pares ordenados do arquivo.txt
Imprimir -> retorna a saída como exemplificada abaixo.


------------------------------------------------------
Entrada: 
Arquivo com pares ordenados de vertices para grafo.

-----------------------------------------------------

Saída:

linha   grau   vertices

1: 	(2) ==> 2 3
2: 	(3) ==> 1 4 5
3: 	(2) ==> 1 4
4: 	(4) ==> 2 3 5 6
5: 	(2) ==> 2 4
6: 	(3) ==> 4 7 8
7: 	(2) ==> 6 8
8: 	(2) ==> 6 7

------------------------------------------------------


obs: utilizei a idle devc++.