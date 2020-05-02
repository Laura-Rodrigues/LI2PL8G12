//
// Created by laura on 23/04/20.
//

#include "Bot.h"
#include "Camada_dados.h"
#include "Logica_Programa.h"
#include "Funcoes_Ficheiro.h"

//receber o estado do tabuleiro, analisar as jogadas possíveis,
// aplicar uma heurística para escolher a melhor jogada e
// jogar nessa jogada, devolvendo o tabuleiro atualizado.
int bot (ESTADO *e){
    COORDENADA c;
    c = jog (e);
    jogar(e, c);
    return 0;
}
