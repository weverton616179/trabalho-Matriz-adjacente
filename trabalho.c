#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

int NUM_CIDADES = 20;

const char * cidades[20] = {
        "Curitiba", "Londrina", "Maringa", "Foz do Iguacu", "Ponta Grossa",
        "Cascavel", "Colombo", "Guarapuava", "Paranagua", "S.J. dos Pinhais",
        "Toledo", "Pinhais", "Araucaria", "Umuarama", "Apucarana",
        "Campo Largo", "Arapongas", "Pato Branco", "Almirante Tamandare", "Sarandi"
    };
    
int mixed[20][20] = {
    // Cur       Lond      Mar       Foz       Pont      Casc      Colom     Guara     Paran     S.J.      Toled     Pinh      Arauc     Umu       Apu       CampL     Arap      PatB      AlmT      Sar
    {   0,        0,        0,        0,        0,        0,        16,       0,        90,       13,       0,        8,        22,       0,        0,        29,       0,        0,        21,       0      }, // Curitiba
    {   0,        0,        0,        0,      277,        0,        0,      315,        0,        0,        0,        0,        0,        0,        53,       0,        38,       0,        0,        0      }, // Londrina
    {   0,        0,        0,        0,      400,        273,      0,      329,        0,        0,      278,        0,        0,        145,      51,       0,       61,        0,        0,        14     }, // Maringa
    {   0,        0,        0,        0,        0,        131,      0,        0,        0,        0,      156,        0,        0,        0,        0,        0,        0,      337,        0,        0      }, // Foz do Iguacu
    {   0,      277,      400,        0,        0,      516,        0,        163,      0,        0,        0,        0,        0,        0,      250,       90,        0,        0,        0,        0      }, // Ponta Grossa
    {   0,        0,      273,        131,    516,        0,        0,        252,      0,        0,        39,       0,        0,      168,      348,        0,        0,      232,        0,        0      }, // Cascavel
    {   16,       0,        0,        0,        0,        0,        0,        0,        105,      0,        0,        17,       0,        0,        0,        0,        0,        0,        10,       0      }, // Colombo
    {   0,      315,      329,        0,        163,    252,        0,        0,        0,        0,        0,        0,        0,        0,      264,      226,        0,        200,      0,      287      }, // Guarapuava
    {   90,       0,        0,        0,        0,        0,        105,      0,        0,        82,       0,        75,       0,        0,        0,        0,        0,        0,        0,        0      }, // Paranagua
    {   13,       0,        0,        0,        0,        0,        0,        0,        82,       0,        0,        10,       21,       0,        0,        0,        0,        0,        0,        0      }, // S.J. dos Pinhais
    {   0,        0,      278,      156,        0,        39,       0,        0,        0,        0,        0,        0,        0,      132,        334,      0,        0,        285,      0,        0      }, // Toledo
    {   8,        0,        0,        0,        0,        0,        17,       0,        75,       10,       0,        0,        0,        0,        0,        0,        0,        0,        13,       0      }, // Pinhais
    {   22,       0,        0,        0,        0,        0,        0,        0,        0,        21,       0,        0,        0,        0,        0,       30,        0,        0,        0,        0      }, // Araucaria
    {   0,        0,        145,      0,        0,      168,        0,        0,        0,        0,      132,        0,        0,        0,        0,        0,        0,        0,        0,        0      }, // Umuarama
    {   0,       53,        51,       0,      250,      348,        0,      264,        0,        0,      334,        0,        0,        0,        0,        0,        18,       0,        0,        63     }, // Apucarana
    {   29,       0,        0,        0,       90,        0,        25,     226,        0,        0,        0,        0,       30,        0,        0,        0,        0,        0,        42,       0      }, // Campo Largo
    {   0,        38,       61,       0,        0,        0,        0,        0,        0,        0,        0,        0,        0,        0,        18,       0,        0,        0,        0,        70     }, // Arapongas
    {   0,        0,        0,      337,        0,      232,        0,        200,      0,        0,        285,      0,        0,        0,        0,        0,        0,        0,        0,        0      }, // Pato Branco
    {   21,       0,        0,        0,        0,        0,        10,       0,        0,        0,        0,        13,       0,        0,        0,        42,       0,        0,        0,        0      }, // Almirante Tamandare
    {   0,        0,        14,       0,        0,        0,        0,      287,        0,        0,        0,        0,        0,        0,       63,        0,        70,       0,        0,        0      }  // Sarandi
};

void dijkstra(int graph[NUM_CIDADES][NUM_CIDADES], int src, int dest) {
    int dist[NUM_CIDADES];          // Array de distâncias mínimas
    bool visited[NUM_CIDADES];      // Array para marcar vértices visitados
    int previous[NUM_CIDADES];      // Array para reconstruir o caminho

    // Inicialização
    for (int i = 0; i < NUM_CIDADES; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        previous[i] = -1;
    }
    dist[src] = 0;

    // Encontrar o caminho mais curto para todos os vértices
    for (int count = 0; count < NUM_CIDADES - 1; count++) {
        // Encontrar o vértice com a menor distância não visitado
        int min = INT_MAX, u = -1;
        for (int v = 0; v < NUM_CIDADES; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }

        // Marcar o vértice como visitado
        visited[u] = true;

        // Atualizar as distâncias dos vértices adjacentes
        for (int v = 0; v < NUM_CIDADES; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && 
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                previous[v] = u;
            }
        }
    }

    // Se não há caminho para o destino
    if (dist[dest] == INT_MAX) {
        printf("Não há caminho entre %s e %s\n", cidades[src], cidades[dest]);
        return;
    }

    // Reconstruir e imprimir o caminho
    int path[NUM_CIDADES];
    int current = dest;
    int path_length = 0;

    while (current != -1) {
        path[path_length++] = current;
        current = previous[current];
    }

    printf("Distância total: %d km\nCaminho: ", dist[dest]);
    for (int i = path_length - 1; i >= 0; i--) {
        printf("%s", cidades[path[i]]);
        if (i > 0) printf(" -> ");
    }
    printf("\n");
}

void imprimirMatriz() {
    for (int i = 0; i < NUM_CIDADES; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            printf("%4d ", mixed[i][j]);
        }
        printf("\n");
    }
}

int main() {
    dijkstra(mixed, 8, 3);
    
    imprimirMatriz();

    return 0;
}