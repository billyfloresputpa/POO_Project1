//
// Created by Usuario on 3/06/2019.
//

#ifndef PROYECTO1_FUNCIONES_H
#define PROYECTO1_FUNCIONES_H

int Menu();

int** MatrizInternaIngles(int nivel_col);
int** MatrizInternaAleman(int nivel_col);
int** MatrizInternaFrances(int nivel_col);
void Imprimir(int **A, int nivel_col);
void MoverPieza(int **&A);
int ComprobarMatrix(int **A,int nivel_col);
int ComprobarMatrixPerder(int **A,int nivel_col);
#endif
