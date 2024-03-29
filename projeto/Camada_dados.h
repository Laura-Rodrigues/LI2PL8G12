#ifndef PROJETORASTROS_CAMADA_DADOS_H
#define PROJETORASTROS_CAMADA_DADOS_H

/**
@file Camada_dados.h
Definição do estado e das funções que o manipulam
*/

/** @CASA
\brief Tipo de dados para a casa
*/
typedef enum {
    /** Tipo de casa que não foi utilizada */
    VAZIO, 
    /** Tipo de casa onde foi feita a ultima jogadas */
    BRANCA, 
    /** Tipo de casa que já foi utilizada */
    PRETA, 
    /** Casa objetivo do jogador 1 */
    UM, 
    /** Casa objetivo do jogador 2 */
    DOIS
} CASA;


/** @COORDENADA
\brief Tipo de dados para as coordenadas
*/
typedef struct {
    /** Inteiro que representa a coluna da coordenada*/
    int coluna;
    /** Inteiro que representa a linha da coordenada */
    int linha;
} COORDENADA;

/** @JOGADA
\brief Tipo de dados para a jogada
 *
 * Cada jogada é constituida por um par de coordenadas correspondentes aos movimentos de cada jogador
*/
typedef struct {
    /** Coordenada correspondente ao movimento do jogador 1 */
    COORDENADA jogador1; 
    /** Coordenada correspondente ao movimento do jogador 2 */
    COORDENADA jogador2; 
} JOGADA;

/** @JOGADAS
\brief Tipo de dados para as jogadas
 *
 * As jogadas correspondem a uma lista de "jogada"
*/
typedef JOGADA JOGADAS[32];

/** @ESTADO
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
\brief Devolve o número de movimentos feitos
@param estado Apontador para o estado
@returns O inteiro correspondente ao número de movimentos
*/
int obter_num_mov (ESTADO *e);

/**
\brief Permite obter a jogada
@param e Apontador para o estado
@param njogada inteiro para o número da jogada
@param jogador inteiro que indica o jogador
@returns Coordenada
*/
COORDENADA obter_jogada (ESTADO *e, int njogada, int jogador);

/**
\brief Permite obter o valor da variavel alt_pos
@param e Apontador para o estado
@returns int
*/
int obter_pos (ESTADO *e);

/**
\brief Altera a variavel da alt_pos e incrementa um
@param e Apontador para o estado
@param i Inteiro
*/
void aumenta_pos (ESTADO* e, int i);

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
\brief Aumenta o numero de movimentos
@param e Apontador para o estado
@param n_mov O inteiro
*/
void altera_num_mov (ESTADO *e, int n_mov);

/**
\brief Aumenta o numero de jogadas
@param e Apontador para o estado
*/
void altera_numjogadas ( ESTADO *e );

/**
\brief Altera detalhes do estado inicial
@param estado Apontador para o estado
*/
void faz_primeira_jogada (ESTADO *e);

/**
\brief Altera o estado
@param e Apontador para o estado
@param c A coordenada
*/
void altera_estado (ESTADO *e, COORDENADA c);

#endif //PROJETORASTROS_CAMADA_DADOS_H
