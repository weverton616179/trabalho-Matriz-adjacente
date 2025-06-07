#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int NUM_CIDADES = 20;
    
char **iniciaCidades(){
    const char * cidades_originais[20] = {
        "Curitiba", "Londrina", "Maringa", "Foz do Iguacu", "Ponta Grossa",
        "Cascavel", "Colombo", "Guarapuava", "Paranagua", "S.J. dos Pinhais",
        "Toledo", "Pinhais", "Araucaria", "Umuarama", "Apucarana",
        "Campo Largo", "Arapongas", "Pato Branco", "Almirante Tamandare", "Sarandi"
    };
    
    char **cidades = (char **)malloc(20 * sizeof(char *));
    for (int i = 0; i < 20; i++) {
        cidades[i] = cidades_originais[i]; // Apenas copia o ponteiro (não aloca nova memória)
    }
    
    return cidades;
}
    
int **iniciaConexoes(){
    
    int dados[20][20] = {
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
    
    
    int **matriz = malloc(NUM_CIDADES * sizeof(int *));
    for (int i = 0; i < NUM_CIDADES; i++) {
        matriz[i] = malloc(NUM_CIDADES * sizeof(int));
    }

    // 3. Copiar os dados
    for (int i = 0; i < NUM_CIDADES; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            matriz[i][j] = dados[i][j];
        }
    }
    
    return matriz;
}
  
char **adicionaCidade(char **cidades, const char *novaCidade) {
    // Aumenta o número de cidades
    NUM_CIDADES++;
    
    // Realoca o array de ponteiros para ter espaço para mais um elemento
    cidades = (char **)realloc(cidades, NUM_CIDADES * sizeof(char *));
    
    if (cidades == NULL) {
        perror("Erro ao realocar memória");
        exit(EXIT_FAILURE);
    }
    
    // Aloca memória para a nova string e copia o conteúdo
    cidades[NUM_CIDADES - 1] = strdup(novaCidade);
    if (cidades[NUM_CIDADES - 1] == NULL) {
        perror("Erro ao alocar memória para a nova cidade");
        exit(EXIT_FAILURE);
    }
    
    return cidades;
}
    
int** aumentaConexoes(int** matriz) {
    // Novo tamanho
    int novo_tamanho = NUM_CIDADES + 1;
    
    // Aloca nova matriz com o novo tamanho
    int** nova_matriz = (int**)malloc(novo_tamanho * sizeof(int*));
    for (int i = 0; i < novo_tamanho; i++) {
        nova_matriz[i] = (int*)malloc(novo_tamanho * sizeof(int));
    }
    
    // Copia os valores da matriz antiga para a nova
    for (int i = 0; i < NUM_CIDADES; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            nova_matriz[i][j] = matriz[i][j];
        }
    }
    
    // Preenche as novas linhas e colunas com 0
    for (int i = 0; i < novo_tamanho; i++) {
        nova_matriz[i][NUM_CIDADES] = 0; // Nova coluna para todas as linhas
    }
    for (int j = 0; j < NUM_CIDADES; j++) {
        nova_matriz[NUM_CIDADES][j] = 0; // Nova linha para todas as colunas (exceto última posição)
    }
    
    // Libera a memória da matriz antiga
    for (int i = 0; i < NUM_CIDADES; i++) {
        free(matriz[i]);
    }
    free(matriz);
    
    // Atualiza o tamanho global
    NUM_CIDADES = novo_tamanho;
    
    return nova_matriz;
}

void dijkstra(int **graph, char **cidades, int src, int dest) {
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

void imprimirMatriz(int **matriz) {
    printf("Matriz de distâncias entre cidades:\n");
    for (int i = 0; i < NUM_CIDADES; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void imprimirCidades(char **matriz) {
    printf("Cidades e seus valores:\n");
    for (int i = 0; i < NUM_CIDADES; i++) {
        printf("Cidade %d: %s\n", i, matriz[i]);
    }
}

int main() {
    int **conexoes = iniciaConexoes();
    char **cidades = iniciaCidades();
    
    //imprimirCidades(cidades);
    
    
    //dijkstra(conexoes, cidades, 3, 8);
    //conexoes = aumentaConexoes(conexoes);
    //imprimirMatriz(conexoes);
    
    cidades = adicionaCidade(cidades, "banana");
    imprimirCidades(cidades);
    
    

    return 0;
}
