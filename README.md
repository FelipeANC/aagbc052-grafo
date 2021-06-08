# Algoritmos de aproximação - Coloração de vértices
Em busca de uma solução ótima, foi desenvolvido um algoritmo para o problema de coloração de vértices.
Uma descrição detalhada do problema, do projeto e dos resultados obtidos estão no [relatório](#AA_Trabalho_pratico_Felipe_Nunes.pdf) da atividade.

> ### **Entrada**  
A entrada consiste em um arquivo com várias linhas. A primeira linha contém dois inteiros *V, E* representando respectivamente o numero
de vértices e arestas do grafo. Nas próximas E linhas, teremos um par *X, Y* de inteiros, representando uma arestra entre os vértices X e Y.
A seguir, teremos um inteiro C indicando o número de cores e C linhas com a descrição das cores.
> ### **Saída**  
A saída consiste em um arquivo com várias linhas, onde cada linha representa a sequência de cores utilizada para colorir o grafo, seguida pelo número
de cores utilizados, e o tempo de execução em milisegundos.  

Como exemplo de entrada temos o arquivo [grafo05.txt](grafo05.txt) e, saída, o arquivo [output05.txt](output05.txt). O grafo representado nesse 
exemplo é o *Clebsch Graph* ([referência](https://mathworld.wolfram.com/ClebschGraph.html)).  
  
O projeto consiste em 2 métodos para colorir o grafo: uma **busca em profundidade** e um **método auxiliar** para checar se uma cor pode ser aplicada a um vértice.  
1. Busca em profundidade  
```c++
void colorir(int u, int c){  
    visitados[u] = VISITED;  
    cor[u] = c;  
      
    for(int j = 0; j < (int) AdjList[u].size(); j++){
        int v = AdjList[u][j];  
        if(visitados[v] == UNVISITED){  
            for(int i = 0; i < (int)cores.size(); i++)
                if(confere_cor(v, i) && cor[v] == UNCOLORED)  
                    colorir(v, i);  
        }  
    }  
 }

```
2. Método auxiliar
```c++
bool confere_cor(int v, int c){  
    for(int i = 0; i < (int)AdjList[v].size(); i++){  
        int t = AdjList[v][i];  
        if(cor[t] == c) return false;  
    }  
    return true;  
 }

```
