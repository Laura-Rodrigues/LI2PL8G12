//
// Created by laura on 23/04/20.
//

#ifndef PROJETORASTROS_BOT_H
#define PROJETORASTROS_BOT_H

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



COORDENADA jog ( ESTADO *e );

/**
\brief Aplica a heurística e joga no tabuleiro a melhor jogada
@param e Apontador para o estado
@returns coordenada
*/
COORDENADA bot (ESTADO *e);

#endif //PROJETORASTROS_BOT_H
