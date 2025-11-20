#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição da estrutura do Nó 2-3-4
// Um nó pode ter no máximo 3 chaves e 4 filhos.
typedef struct No234 {
    int chaves[3];             // Armazena no máximo 3 chaves (índices 0, 1, 2)
    struct No234 *filhos[4];   // Armazena no máximo 4 ponteiros para filhos (índices 0, 1, 2, 3)
    int num_chaves;            // Número atual de chaves (1, 2 ou 3)
    struct No234 *pai;         // Ponteiro para o nó pai
} No234;

// Variável global para a raiz da árvore
No234 *raiz = NULL;

// ------------------------------------------------------------------
// Funções Auxiliares
// ------------------------------------------------------------------

/**
 * Cria um novo nó vazio.
 */
No234 *criar_no(No234 *pai) {
    No234 *novo = (No234 *)malloc(sizeof(No234));
    if (novo == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    novo->num_chaves = 0;
    novo->pai = pai;
    for (int i = 0; i < 4; i++) {
        novo->filhos[i] = NULL;
    }
    return novo;
}

/**
 * Retorna true se o nó está cheio (4-nó com 3 chaves).
 */
bool esta_cheio(No234 *no) {
    return no->num_chaves == 3;
}

/**
 * Encontra o índice da chave que é maior que o valor fornecido.
 * Isso define onde a busca deve continuar ou onde a chave deve ser inserida.
 * @return O índice do filho que deve ser visitado (0 a num_chaves).
 */
int encontrar_indice_busca(No234 *no, int chave) {
    int i;
    for (i = 0; i < no->num_chaves; i++) {
        if (chave == no->chaves[i]) {
            // Chave já existe
            return -1; 
        }
        if (chave < no->chaves[i]) {
            return i;
        }
    }
    // A chave é maior que todas as chaves existentes, retorna o último índice.
    return i;
}

/**
 * Insere uma chave no nó atual (que não pode estar cheio).
 * Mantém as chaves ordenadas.
 */
void inserir_no_nao_cheio(No234 *no, int chave) {
    int i = no->num_chaves - 1;

    // Percorre as chaves de trás para frente para abrir espaço para a nova chave
    while (i >= 0 && chave < no->chaves[i]) {
        no->chaves[i + 1] = no->chaves[i];
        i--;
    }
    
    // Insere a chave na posição correta
    no->chaves[i + 1] = chave;
    no->num_chaves++;
}

// ------------------------------------------------------------------
// Lógica Central: Divisão de Nó (Split)
// ------------------------------------------------------------------

/**
 * Divide um nó cheio (4-nó) em dois 2-nós e move a chave mediana para o pai.
 * @param cheio O nó que será dividido.
 */
void dividir_no(No234 *cheio) {
    // 1. Chave mediana que sobe para o pai
    int chave_mediana = cheio->chaves[1]; 
    
    // 2. Cria os novos nós (o nó direito)
    No234 *novo_direito = criar_no(cheio->pai);

    // 3. Move a chave e o filho direito do 4-nó para o novo nó direito
    novo_direito->chaves[0] = cheio->chaves[2];
    novo_direito->num_chaves = 1;
    novo_direito->filhos[0] = cheio->filhos[2];
    novo_direito->filhos[1] = cheio->filhos[3];

    // Atualiza os pais dos filhos movidos
    if (novo_direito->filhos[0]) novo_direito->filhos[0]->pai = novo_direito;
    if (novo_direito->filhos[1]) novo_direito->filhos[1]->pai = novo_direito;

    // 4. Reduz o nó original (agora 2-nó esquerdo)
    cheio->num_chaves = 1; 
    cheio->filhos[2] = NULL;
    cheio->filhos[3] = NULL;

    // 5. Trata o pai: a chave mediana sobe

    // CASO A: Nó cheio é a raiz (Raiz Cresce)
    if (cheio->pai == NULL) {
        No234 *nova_raiz = criar_no(NULL);
        nova_raiz->chaves[0] = chave_mediana;
        nova_raiz->num_chaves = 1;
        
        // Liga os dois novos nós à nova raiz
        nova_raiz->filhos[0] = cheio;
        nova_raiz->filhos[1] = novo_direito;
        cheio->pai = nova_raiz;
        novo_direito->pai = nova_raiz;
        
        raiz = nova_raiz;
        return;
    }

    // CASO B: Nó cheio não é a raiz (Chave sobe para o pai existente)
    No234 *pai = cheio->pai;
    int pos_chave_subida = encontrar_indice_busca(pai, chave_mediana);

    // Abre espaço para a nova chave mediana e insere no pai
    for (int i = pai->num_chaves - 1; i >= pos_chave_subida; i--) {
        pai->chaves[i + 1] = pai->chaves[i];
    }
    pai->chaves[pos_chave_subida] = chave_mediana;
    pai->num_chaves++;

    // Desloca os ponteiros dos filhos no pai para abrir espaço
    for (int i = 3; i > pos_chave_subida + 1; i--) {
        pai->filhos[i] = pai->filhos[i - 1];
    }

    // Liga o novo nó direito ao pai na posição correta
    pai->filhos[pos_chave_subida + 1] = novo_direito;
    // O nó original (esquerdo) já está ligado na posição pos_chave_subida
}

// ------------------------------------------------------------------
// Função Principal de Inserção
// ------------------------------------------------------------------

/**
 * Insere uma chave na Árvore 2-3-4.
 */
void inserir(int chave) {
    if (raiz == NULL) {
        raiz = criar_no(NULL);
        raiz->chaves[0] = chave;
        raiz->num_chaves = 1;
        return;
    }

    No234 *atual = raiz;

    // Loop de busca/descida (Top-Down Splitting)
    while (atual->filhos[0] != NULL) {
        // 1. Verificar e dividir se o nó atual estiver cheio (4-nó)
        if (esta_cheio(atual)) {
            dividir_no(atual);
            // Após a divisão, o ponteiro 'atual' deve ser redefinido.
            // Se a raiz foi dividida, a nova raiz é o novo ponto de partida.
            // Caso contrário, voltamos ao pai e re-descemos.
            atual = atual->pai; 
            if (atual == NULL) {
                // Se a raiz cresceu, a nova raiz é o ponto de partida
                atual = raiz;
            }
        }
        
        // 2. Encontrar o índice para continuar a busca (ou para inserir)
        int indice = encontrar_indice_busca(atual, chave);

        if (indice == -1) {
            printf("Chave %d já existe. Ignorando.\n", chave);
            return;
        }

        // Descemos para o filho
        atual = atual->filhos[indice];
    }

    // 3. Chegou a uma folha (que garantidamente não é um 4-nó)
    if (esta_cheio(atual)) {
         // Se a folha estiver cheia (isso só acontece se ela não foi verificada no loop 'while' acima, 
         // ou se o loop terminou porque a folha é a raiz e foi dividida, o que é tratado implicitamente)
         dividir_no(atual);
         atual = atual->pai; 
         // Encontrar o nó correto após a divisão. Simplificamos para o caso mais comum:
         if (atual == NULL) atual = raiz;
         int indice = encontrar_indice_busca(atual, chave);
         if (indice == -1) return;
         
         // Descemos para a folha correta (ou o nó que a contém)
         if (atual->filhos[indice] != NULL) {
             atual = atual->filhos[indice];
         } else {
             // Se for um caso de folha após divisão, o nó correto para inserção é 'atual'
             inserir_no_nao_cheio(atual, chave);
             return;
         }
    }
    
    // Inserção final no nó folha
    inserir_no_nao_cheio(atual, chave);
}

// ------------------------------------------------------------------
// Funções de Visualização
// ------------------------------------------------------------------

/**
 * Imprime as chaves de um nó.
 */
void imprimir_no(No234 *no) {
    if (no == NULL) {
        printf("[NULO]");
        return;
    }
    printf("[");
    for (int i = 0; i < no->num_chaves; i++) {
        printf("%d%s", no->chaves[i], (i < no->num_chaves - 1 ? " | " : ""));
    }
    printf("]");
}

/**
 * Percorre e imprime a árvore em profundidade (Depth-First Traversal).
 * Esta função ajuda a visualizar a estrutura.
 */
void imprimir_arvore_recursivo(No234 *no, int profundidade) {
    if (no == NULL) return;

    // Imprime as chaves do nó atual com a devida identação
    for (int i = 0; i < profundidade; i++) printf("  ");
    printf("Nível %d: ", profundidade);
    imprimir_no(no);
    printf("\n");

    // Chama recursivamente para os filhos
    for (int i = 0; i <= no->num_chaves; i++) {
        imprimir_arvore_recursivo(no->filhos[i], profundidade + 1);
    }
}

/**
 * Função principal de impressão da árvore.
 */
void imprimir_arvore() {
    printf("--- Estrutura da Árvore 2-3-4 ---\n");
    if (raiz == NULL) {
        printf("A árvore está vazia.\n");
        return;
    }
    imprimir_arvore_recursivo(raiz, 0);
    printf("--------------------------------\n");
}

/**
 * Libera a memória alocada.
 */
void liberar_memoria_recursivo(No234 *no) {
    if (no == NULL) return;
    for (int i = 0; i <= no->num_chaves; i++) {
        liberar_memoria_recursivo(no->filhos[i]);
    }
    free(no);
}

// ------------------------------------------------------------------
// Função Principal (Main) para Demonstração
// ------------------------------------------------------------------

int main() {
    // Chaves que forçarão divisões e o crescimento da raiz:
    // 50 (raiz) -> 40 50 (3-nó) -> 30 40 50 (4-nó) -> Divide: 40 (nova raiz), 30 | 50 (filhos)
    // 60 -> 40 (raiz), 30 | 50 60
    int chaves[] = {50, 40, 30, 60, 20, 10, 70, 80, 45, 35};
    int n = sizeof(chaves) / sizeof(chaves[0]);

    printf("--- Demonstração da Árvore 2-3-4 em C ---\n");

    for (int i = 0; i < n; i++) {
        printf("\n=> Inserindo chave: %d\n", chaves[i]);
        inserir(chaves[i]);
        imprimir_arvore();
    }

    printf("\n\nFim da demonstração. Árvore finalizada.\n");

    // Limpeza de memória
    liberar_memoria_recursivo(raiz);

    return 0;
}
