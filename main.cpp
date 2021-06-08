#include <bits/stdc++.h>
#define UNVISITED 0
#define VISITED 1
#define EXPLORED 2
#define UNCOLORED -1

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vii;

vii AdjList;
vi visitados;
vi cor;
vector<string> cores;
long long int exe;


bool confere_cor(int v, int c){
    for(int i = 0; i < (int)AdjList[v].size(); i++)
    {
        int t = AdjList[v][i];
        if(cor[t] == c) return false;
    }
    return true;
}

void colorir(int u, int c){
    auto begin = chrono::high_resolution_clock::now();

    visitados[u] = VISITED;
    cor[u] = c;

    for(int j = 0; j < (int)AdjList[u].size(); j++)
    {
        int v = AdjList[u][j];
        if(visitados[v] == UNVISITED)
        {
            for(int i = 0; i < (int)cores.size(); i++)
                if(confere_cor(v, i) && cor[v] == UNCOLORED)
                    colorir(v, i);
        }
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - begin);

    exe+=elapsed.count();
    printf("total = %lld ms\n", exe);
    //printf("%lld ns\n", elapsed.count());
}
double desvioPadrao(double data[], int n){
    double soma = 0.0, media, desvio = 0.0;
    for(int i = 0; i < n; i++)
    {
        soma += data[i];
    }

    media = soma/(double)n;
    for(int i = 0; i < n; i++)
    {
        desvio += pow(data[i] - media, 2);
    }

    return sqrt(desvio/(double)n);

}
void printGrafo(){
    printf("GRAFO:\n");
    for(int i = 0; i < (int) AdjList.size(); i++)
    {
        printf("Vertice %d:", i);
        for(int j = 0; j < (int) AdjList[i].size(); j++)
            printf(" %d", AdjList[i][j]);
        printf("\n");
    }
    printf("\n");
}
void printCores(){
    printf("CORES:\n");
    for(int i = 0; i < (int)cores.size(); i++)
        printf("#%d - %s\n", i, cores[i].c_str());
    printf("\n");
}
void printGrafoColorido(){
    printf("Resultado:\n");
    for(int i = 0; i < (int) cor.size(); i++)
        printf("Vertice %d: %s\n", i, cores[cor[i]].c_str());
}
void clearConsole(){
    system("CLS");
}

int main()
{
    ofstream out;
    ifstream f;
    string line;
    int v, e, w, z, nc, idxc = 0;
    int t = 100;
    long long int t_total = 0;
    double data[t];
    out.open("output05.txt");
    f.open("grafo05.txt");
    f >> v >> e;

    visitados.assign(v, UNVISITED);
    AdjList.assign(v, vi()); //grafo representado em lista de adjacencia
    cor.assign(v, UNCOLORED); //vetor para guardar as cores dos vertices

    while(e--)
    {
        f >> w >> z;
        AdjList[w].push_back(z);
        AdjList[z].push_back(w);
    }
    f >> nc;
    cores.assign(nc, "");
    while(nc--)
    {
        string c;
        f >> c;
        cores[idxc++] = c;
    }

    //colorir(vertice inicial, cor inicial)
    //iniciando vertice 0, com a primeira cor (0)
    for(int j = 0; j < t; j++)
    {
        set<string> conj;
        colorir(0, 0);
        for(int i = 0; i < v; i++)
        {
            conj.insert(cores[cor[i]]);
            out << cores[cor[i]] << ",";
        }
        out << conj.size() << ",";
        out << exe << endl;
        t_total += exe;
        data[j] = exe;
        visitados.assign(v, UNVISITED);
        cor.assign(v, UNCOLORED);
        exe = 0;
    }

    printf("Media: %.4lf ms\n", (double) t_total/t);
    printf("Desvio padrão: %.4lf ms\n", desvioPadrao(data, t));

    return 0;
}
