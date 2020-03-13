#include <stdio.h>
#include "Mapa.h"


int main(){
    ESTADO *e = inicializar_estado();
    interpretador(e);
    return 0;
}

