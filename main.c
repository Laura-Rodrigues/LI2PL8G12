#include <stdio.h>
#include "Mapa.h"

int main() {
    int jogPlayer;
    printf (" Introduza o que pertende fazer: ( 1 - coordenada Ou ...  \n");
    scanf ( "%d", jogPlayer);
    switch (jogPlayer){
        case 1: verificaCoordenada;
                alteraEstado;
                break;

    }
    //coordenada
    //gr nome_do_ficheiro
    //ler nome_do_ficheiro
    //movs
    //jogs
    //pos numero_da_jogada
    //Q
    mapa();
    char j [2];
    while ( j != 'a1'|| j != 'h8'){
        alteraCardinal;
        recebeJogada;
    }
}


