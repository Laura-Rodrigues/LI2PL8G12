//
// Created by laura on 25/04/20.
//

#ifndef PROJETORASTROS_FUNCOES_AUX_H
#define PROJETORASTROS_FUNCOES_AUX_H

#include <bits/types/FILE.h>
#include "Bot.h"


/**
\brief Tipo de dados para a casa
*/
typedef enum {VAZIO, BRANCA, PRETA, UM, DOIS} CASA;

/**
\brief Tipo de dados para as coordenadas
*/
typedef struct {
    int coluna;
    int linha;
} COORDENADA;

/**
\brief Tipo de dados para a jogada
*/
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

/**
\brief Tipo de dados para as jogadas
*/
typedef JOGADA JOGADAS[32];

/**
\brief Tipo de dados para o estado
*/
typedef struct {
    /** O tabuleiro */
    CASA tab[8][8]; //tab- armazena informação sobre o tabuleiro
    /** A coordenada da última jogada */
    COORDENADA ultima_jogada; //ultima_jogada- a coordenada da ultima jogada
    /** As jogadas */
    JOGADAS jogadas; //jogadas - armazena informação sobre as jogadas
    /** O número das jogadas, usado no prompt */
    int num_jogadas; //num_jogadas - indica quantas jogadas foram efetuadas
    /** O jogador atual */
    int jogador_atual; //jogador_atual - indica qual é o jogador a jogar
    /** Número de movimentos*/
    int num_movimentos; //Número total de movimentos feitos
    /**Jogada anterior foi pos **/
    int alt_pos; // Se for 1 então jogada anterior foi pos; se for 0, a jogada anterior não foi a pos
} ESTADO;

/**
\brief Tipo de dados para as listas
*/
typedef struct listas *LISTA;

/**
\brief Tipo de dados para os nodos
*/
typedef struct listas {
    COORDENADA *valor;
    LISTA prox;
} Nodo;


/**
\brief Inicializa o valor do estado
Esta função inicializa o valor do estado. Isso implica o tabuleiro ser colocado na posição inicial e todos os campos do estado estarem com o valor por omissão.
@returns O novo estado
*/
ESTADO *inicializar_estado();

/**
\brief Permite obter o número do jogador atual
@param estado Apontador para o estado
@returns O número do jogador
*/
int obter_jogador_atual(ESTADO *estado);

/**
\brief Permite obter quantas jogadas foram efetuadas
@param estado Apontador para o estado
@returns O número de jogadas
*/
int obter_numero_de_jogadas(ESTADO *estado);

/**
\brief Função que troca a coluna pela linha e vice-versa
@param c A coordenada
@returns A nova coordenada
*/
COORDENADA troca_ordem (COORDENADA c);

/**
\brief Devolve o estado de uma casa
@param e Apontador para o estado
@param c A coordenada
@returns O estado atual da casa
*/
CASA obter_estado_casa(ESTADO *e, COORDENADA c);

/**
\brief Devolve a coordenada da última jogada
@param estado Apontador para o estado
@returns Coordenada da última jogada
*/
COORDENADA obter_ultima_jogada (ESTADO *estado);

/**
\brief Permite obter a jogada
@param e Apontador para o estado
@param njogada inteiro para o número da jogada
@param jogador inteiro que indica o jogador
@returns Coordenada
*/
COORDENADA obter_jogada (ESTADO *e, int njogada, int jogador);

/**
\brief Altera detalhes do estado inicial
@param estado Apontador para o estado
*/
void faz_primeira_jogada (ESTADO *e);

/**
\brief Permite alterar o valor da variavel alt_pos
@param e Apontador para o estado
*/
void altera_pos (ESTADO* e);

/**
\brief Altera o tabuleiro
@param estado Apontador para o estado
@param c A coordenada
*/
void altera_tabuleiro (ESTADO *estado, COORDENADA c);

/**
\brief Altera a última jogada, para a coordenada dada
@param e Apontador para o estado
@param c A coordenada
*/
void altera_ultimajogada (ESTADO *e, COORDENADA c);

/**
\brief Altera as jogadas
@param e Apontador para o estado
@param c A coordenada
*/
void altera_jogadas (ESTADO *e, COORDENADA c);

/**
\brief Altera o jogador atual
@param e Apontador para o estado
*/
void altera_jogadoratual(ESTADO *e);

/**
\brief Aumenta o numero de jogadas
@param e Apontador para o estado
*/
void altera_numjogadas (ESTADO *e);

/**
\brief Aumenta o numero de movimentos
@param e Apontador para o estado
*/
void altera_num_mov (ESTADO *e);

/**
\brief Altera o estado
@param e Apontador para o estado
@param c A coordenada
*/
void altera_estado (ESTADO *e, COORDENADA c);

/**
\brief Testa se a Coordenada é vizinha da Coordenada anterior e se se encontra dentro do tabuleiro
@param e Apontador para o estado
@param c A coordenada
@returns 0 ou 1 para verdadeiro ou falso
*/
int vizinha(ESTADO *e, COORDENADA c);

/**
\brief Testa se a jogada é possível
@param e Apontador para o estado
@param c A coordenada
@returns 0 ou 1 para verdadeiro ou falso
*/
int possivel ( ESTADO *e, COORDENADA c);

/**
\brief Testa se a Jogada é válida
@param estado Apontador para o estado
@param c A coordenada
@returns 0 ou 1 para verdadeiro ou falso
*/
int jogada_valida (ESTADO *estado, COORDENADA c);

/**
\brief Coloca num array as coordenadas vizinhas à ultima jogada
@param e Apontador para o estado
@param ls Array de coordenadas
*/
void coordvizinho(ESTADO *e, COORDENADA ls[]);

/**
\brief Cria uma lista vazia
@returns lista
*/
LISTA criar_lista();

/**
\brief Insere um valor na cabeça da lista
@param L Apontador para a lista
@param valor Apontador para a cabeça da lista
@returns lista
*/
LISTA insere_cabeca(LISTA L, COORDENADA *valor);

/**
\brief Devolve a cabeça da lista
@param L Apontador para a lista
*/
void *devolve_cabeca(LISTA L);

/**
\brief Devolve a cauda da lista
@param L Apontador para a lista
@returns lista
*/
LISTA proximo(LISTA L);

/**
\brief Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
@param L Apontador para a lista
@returns lista
*/
LISTA remove_cabeca(LISTA L);

/**
\brief Devolve verdareiro se a lista é vazia
@param L Apontador para a lista
@returns verdadeiro ou falso
*/
int lista_esta_vazia(LISTA L);

/**
\brief descobre o comprimento da lista
@param l Apontador para a lista
@returns tamanho da lista
*/
int len_Lista(LISTA l);

/**
\brief Função que determina se a coordenada se encontra fora do tabuleiro
@param c A coordenada
@returns 1 ou 0 para verdadeiro ou falso
*/
int cond_canto (COORDENADA c);

/**
\brief Testar se tem vizinhos validos
@param e Apontador para o estado
@returns 1 ou 0 para verdadeiro ou falso, respetivamente
*/
int vizivalide(ESTADO *e, COORDENADA c);

/**
\brief Testa se a Coordenada é igual à final
@param c A coordenada
@returns 0 ou 1 para verdadeiro ou falso
*/
int fim(ESTADO *e, COORDENADA c);

/**
\brief Mostra a lista de movimentos
@param e Apontador para o estado
@returns 0
*/
int movs ( ESTADO *e);

/**
\brief Permite mostrar o tabuleiro
@param estado Apontador para o estado
*/
void mostrar_tabuleiro(ESTADO *estado);

/**
\brief Permite imprimir o tabuleiro no ficheiro
@param Projeto_Rastros Apontador para o ficheiro
@param e Apontador para o estado
*/
void fptabuleiro(FILE *Projeto_Rastros, ESTADO *e);

/**
\brief Mostra a lista de movimentos no ficheiro
@param estado Apontador para o estado
@param nome Apontador para o ficheiro
@returns 0
*/
int movsficheiro (ESTADO *estado, FILE *nome_fich);

/**
\brief Grava o tabuleiro
@param estado Apontador para o estado
@param nomeficheiro Apontador para o ficheiro
@returns 1
*/
int gr ( char nomeficheiro[], ESTADO *estado );

/**
\brief Lê o tabuleiro e atualiza o estado
@param estado Apontador para o estado
@param nomeficheiro Apontador para o ficheiro
@returns o estado alterado
*/
ESTADO *ler ( char nomeficheiro[], ESTADO *estado );

/**
\brief Modifica o estado ao jogar na casa correta se a jogada for válida
@param estado Apontador para o estado
@param c A coordenada
@returns 0 ou 1 para verdadeiro ou falso
*/
int jogar(ESTADO *estado, COORDENADA c);

#endif //PROJETORASTROS_FUNCOES_AUX_H
