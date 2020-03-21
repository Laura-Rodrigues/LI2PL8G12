//
// Created by laura on 12/03/20.
//

/**
@file Camada_dados.h
Definição do estado e das funções que o manipulam
*/

#ifndef PROJETORASTROS_CAMADA_DADOS_H
#define PROJETORASTROS_CAMADA_DADOS_H


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
} ESTADO;

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
@param c A coordenada
*/
void altera_jogadoratual(ESTADO *e);

/**
\brief Aumenta o numero de jogadas
@param e Apontador para o estado
@param c A coordenada
*/
void altera_numjogadas (ESTADO *e);

/**
\brief Altera o estado
@param e Apontador para o estado
@param c A coordenada
*/
void altera_estado (ESTADO *e, COORDENADA c);

#endif //PROJETORASTROS_CAMADA_DADOS_H
