//
// Created by laura on 12/03/20.
//

#include "Logica_Programa.h"
#include "Camada_dados.h"

/* Esta função deverá receber o estado atual e uma coordenada e modificar o estado ao jogar na casa correta se a jogada for válida.
 * A função devolve verdadeiro (valor diferente de zero) se for possível jogar e falso (zero) caso não seja possível.*/

// Testa se a Coordenada é vizinha da Coordenada anterior e se encontra-se dentro do tabuleiro
int vizinha(ESTADO *e, COORDENADA c){
    if(((((e -> ultima_jogada).linha) == (c.linha)) && ((((e -> ultima_jogada).coluna)+1) == (c.coluna))) ||
            (((((((e -> ultima_jogada).linha)+1) == (c.linha)) && ((((e -> ultima_jogada).coluna)+1) == (c.coluna))) ||
            (((((e -> ultima_jogada).linha)+1) == (c.linha)) && ((((e -> ultima_jogada).coluna)) == (c.coluna))) ||
            (((((e -> ultima_jogada).linha)+1) == (c.linha)) && ((((e -> ultima_jogada).coluna)-1) == (c.coluna))) ||
            ((((e -> ultima_jogada).linha) == (c.linha)) && ((((e -> ultima_jogada).coluna)+1) == (c.coluna))) ||
            ((((e -> ultima_jogada).linha) == (c.linha)) && ((((e -> ultima_jogada).coluna)-1) == (c.coluna))) ||
            (((((e -> ultima_jogada).linha)-1) == (c.linha)) && ((((e -> ultima_jogada).coluna)+1) == (c.coluna))) ||
            (((((e -> ultima_jogada).linha)-1) == (c.linha)) && ((((e -> ultima_jogada).coluna)) == (c.coluna))) ||
            (((((e -> ultima_jogada).linha)-1) == (c.linha)) && ((((e -> ultima_jogada).coluna)-1) == (c.coluna)))) &&
                    ((c.linha) < 8) && ((c.linha) >= 0) && ((c.coluna) < 8) && ((c.coluna) >= 0))){
        return 1;
    } else return 0;
}

//Testa se a Jogada é válida
int jogada_valida (ESTADO *estado, COORDENADA c){
    if((obter_estado_casa(estado,c) == VAZIO) && vizinha(estado, c))
        return 1;
    else return 0;
}

//Testa se a Coordenada é igual á final
int fim(COORDENADA c){
    if ((c.coluna) == 7 && (c.linha)== 0){
        printf("Jogador número 1, Ganhou!!!!");
        return 1;
    } else if((c.coluna) == 0 && (c.linha) == 7){
        printf("Jogador número 2, Ganhou!!!");
        return 1;
    } else return 0;
}


int jogar(ESTADO *estado, COORDENADA c){
    if (jogada_valida(estado,c)){
        estado -> tab[c.coluna][c.linha] = BRANCA;
        estado -> tab[(estado -> ultima_jogada).coluna][(estado -> ultima_jogada).linha] = PRETA;
    }
    if(fim (c)){
        printf("Fim do Jogo");
    }
    return 0;
}
