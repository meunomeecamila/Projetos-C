#include <stdio.h>
#include <stdlib.h>

// Definição das cores conforme a solicitação do usuário.
// AMARELO (Black) e ROSA (Red)
typedef enum { AMARELO, ROSA } Cor;

// Estrutura do Nó da Árvore Bicolor
typedef struct No {
    int chave;
    Cor cor;
    struct No *pai;
    struct No *esquerda;
    struct No *direita;
} No;

// Variáveis globais para a raiz e o nó sentinela AMARELO (NIL)
No *raiz;
No *NIL; // Nó sentinela: sempre AMARELO, representa as folhas externas (NULL)

// ------------------------------------------------------------------
// Funções Auxiliares de Inicialização e Criação de Nó
// ------------------------------------------------------------------

/**
 * Inicializa o nó sentinela AMARELO (NIL).
 * Ele é essencial e deve ser sempre AMARELO.
 */
void inicializar_nil() {
    NIL = (No *)malloc(sizeof(No));
    if (NIL == NULL) {
        fprintf(stderr, "Erro de alocação de memória para NIL.\n");
        exit(EXIT_FAILURE);
    }
    NIL->cor = AMARELO;
    NIL->chave = 0;
    NIL->esquerda = NULL;
    NIL->direita = NULL;
    NIL->pai = NULL;
}

/**
 * Cria e aloca memória para um novo nó.
 * Todo novo nó inserido é pintado de ROSA (Regra 1 da Inserção).
 * @param chave O valor a ser armazenado.
 * @param pai O nó pai do novo nó.
 * @return O novo nó.
 */
No *criar_no(int chave, No *pai) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "Erro de alocação de memória para novo nó.\n");
        exit(EXIT_FAILURE);
    }
    novo->chave = chave;
    novo->cor = ROSA; // Novo nó sempre começa ROSA (Vermelho)
    novo->pai = pai;
    novo->esquerda = NIL; // Filhos externos apontam para NIL
    novo->direita = NIL;
    return novo;
}

// ------------------------------------------------------------------
// Funções de Rotação (Ações de Balanceamento)
// ------------------------------------------------------------------

/**
 * Realiza uma Rotação para a Esquerda em torno do nó X.
 * @param x O nó pivô da rotação.
 */
void rotacao_esquerda(No *x) {
    No *y = x->direita; 
    x->direita = y->esquerda; 

    if (y->esquerda != NIL) {
        y->esquerda->pai = x;
    }

    y->pai = x->pai; 

    // Reconecta Y ao resto da árvore
    if (x->pai == NIL) {
        raiz = y; 
    } else if (x == x->pai->esquerda) {
        x->pai->esquerda = y; 
    } else {
        x->pai->direita = y; 
    }

    y->esquerda = x; 
    x->pai = y;
}

/**
 * Realiza uma Rotação para a Direita em torno do nó X.
 * @param x O nó pivô da rotação.
 */
void rotacao_direita(No *x) {
    No *y = x->esquerda; 
    x->esquerda = y->direita; 

    if (y->direita != NIL) {
        y->direita->pai = x;
    }

    y->pai = x->pai; 

    // Reconecta Y ao resto da árvore
    if (x->pai == NIL) {
        raiz = y; 
    } else if (x == x->pai->direita) {
        x->pai->direita = y; 
    } else {
        x->pai->esquerda = y; 
    }

    y->direita = x; 
    x->pai = y;
}

// ------------------------------------------------------------------
// Função de Correção e Balanceamento (Fixup)
// ------------------------------------------------------------------

/**
 * Corrige as violações das propriedades da Árvore Bicolor após a inserção.
 * A violação principal é: um nó ROSA não pode ter um filho ROSA.
 * @param z O nó recém-inserido (ROSA) onde a violação pode começar.
 */
void corrigir_arvore_rb(No *z) {
    // Loop principal: Continua enquanto o pai de Z for ROSA (violação da Regra 4)
    while (z != raiz && z->pai->cor == ROSA) {
        // Encontra o avô (G) e o tio (U)
        No *pai = z->pai;
        No *avo = pai->pai;

        // Se o pai (P) for o filho esquerdo do avô (G)
        if (pai == avo->esquerda) {
            No *tio = avo->direita; // Tio (U) é o filho direito

            // CASO 1: Tio é ROSA (Recoloração)
            if (tio->cor == ROSA) {
                // Pinta P de AMARELO, Tio de AMARELO, e Avô (G) de ROSA
                pai->cor = AMARELO;
                tio->cor = AMARELO;
                avo->cor = ROSA;
                z = avo; // Move o foco para o avô, pois ele pode ter violado a regra
            } 
            // CASO 2 & 3: Tio é AMARELO (Rotações)
            else { 
                // CASO 2: O nó (Z) é filho direito (Rotação Dupla / Interna)
                if (z == pai->direita) {
                    z = pai;
                    rotacao_esquerda(z); // Transforma em Caso 3
                    pai = z->pai; // O novo pai após a rotação
                }
                
                // CASO 3: O nó (Z) é filho esquerdo (Rotação Simples / Externa)
                // Pinta P de AMARELO, G de ROSA e faz Rotação Direita no G
                pai->cor = AMARELO;
                avo->cor = ROSA;
                rotacao_direita(avo);
            }
        }
        // CASO 4 & 5 (SIMÉTRICOS): O pai (P) for o filho direito do avô (G)
        else {
            No *tio = avo->esquerda; // Tio (U) é o filho esquerdo

            // CASO 4.1: Tio é ROSA (Recoloração)
            if (tio->cor == ROSA) {
                pai->cor = AMARELO;
                tio->cor = AMARELO;
                avo->cor = ROSA;
                z = avo;
            } 
            // CASO 4.2 & 4.3: Tio é AMARELO (Rotações)
            else {
                // CASO 4.2: O nó (Z) é filho esquerdo (Rotação Dupla / Interna)
                if (z == pai->esquerda) {
                    z = pai;
                    rotacao_direita(z); // Transforma em Caso 4.3
                    pai = z->pai;
                }
                
                // CASO 4.3: O nó (Z) é filho direito (Rotação Simples / Externa)
                pai->cor = AMARELO;
                avo->cor = ROSA;
                rotacao_esquerda(avo);
            }
        }
    }
    // A raiz deve ser sempre AMARELO (Regra RB #2)
    raiz->cor = AMARELO;
}

// ------------------------------------------------------------------
// Função Principal de Inserção
// ------------------------------------------------------------------

/**
 * Insere uma chave na Árvore Bicolor.
 * @param chave O valor a ser inserido.
 */
void inserir(int chave) {
    // 1. Encontra o local de inserção como em uma BST normal
    No *y = NIL;
    No *x = raiz;

    while (x != NIL) {
        y = x;
        if (chave < x->chave) {
            x = x->esquerda;
        } else if (chave > x->chave) {
            x = x->direita;
        } else {
            // Chave já existe, ignora inserção.
            printf("Chave %d já existe. Ignorando.\n", chave);
            return; 
        }
    }

    // 2. Cria o novo nó (sempre ROSA) e o liga à árvore
    No *z = criar_no(chave, y);

    if (y == NIL) {
        raiz = z; // A árvore estava vazia
    } else if (z->chave < y->chave) {
        y->esquerda = z;
    } else {
        y->direita = z;
    }

    // 3. Corrige as violações para manter o balanceamento
    corrigir_arvore_rb(z);
}

// ------------------------------------------------------------------
// Funções de Visualização
// ------------------------------------------------------------------

/**
 * Percorre a árvore em ordem (In-Order Traversal) e imprime a chave e a cor.
 */
void percorrer_em_ordem(No *no) {
    if (no != NIL) {
        percorrer_em_ordem(no->esquerda);
        // Exibe as cores: AMARELO (cor AMARELO) e ROSA (cor ROSA)
        printf("%d [%s] ", no->chave, (no->cor == ROSA ? "ROSA" : "AMARELO")); 
        percorrer_em_ordem(no->direita);
    }
}

/**
 * Limpa a memória recursivamente.
 */
void liberar_memoria(No *no) {
    if (no != NIL) {
        liberar_memoria(no->esquerda);
        liberar_memoria(no->direita);
        free(no);
    }
}

// ------------------------------------------------------------------
// Função Principal (Main) para Demonstração
// ------------------------------------------------------------------

int main() {
    // Inicializa o nó sentinela e a raiz
    inicializar_nil();
    raiz = NIL;

    printf("--- Simulador de Árvore Bicolor ROSA e AMARELO em C ---\n");
    printf("ROSA = Cor 'Vermelha' (Regras RB) | AMARELO = Cor 'Preta' (Regras RB)\n\n");
    printf("Chaves a serem inseridas (para demonstrar rotações e recolorações): 10, 20, 30, 40, 50, 60, 70.\n\n");

    int chaves[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(chaves) / sizeof(chaves[0]);

    for (int i = 0; i < n; i++) {
        inserir(chaves[i]);
        printf("Árvore após inserir %d (In-Order): ", chaves[i]);
        percorrer_em_ordem(raiz);
        printf("\n");
    }

    printf("\n-------------------------------------------------\n");
    printf("Árvore finalizada. O balanceamento é mantido com ROSA e AMARELO!\n");
    
    // Limpeza de memória
    liberar_memoria(raiz);
    free(NIL);

    return 0;
}
