cmake_minimum_required(VERSION 3.15)
project(ProjetoRastros C)

set(CMAKE_C_STANDARD 99)

add_executable(ProjetoRastros main.c Logica_Programa.c Logica_Programa.h Camada_Interface.c Camada_Interface.h Camada_dados.c Camada_dados.h)