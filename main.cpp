#include <iostream>
#include "Funciones.h"

using namespace std;

int main() {
    int num, nivel_col;
    num = Menu();
    int **matrix,cont;
    switch (num) {
        case 1:
            nivel_col = 7;
            matrix = MatrizInternaIngles(nivel_col);
            Imprimir(matrix,nivel_col);
            do{
                MoverPieza(matrix);
                Imprimir(matrix,nivel_col);
                cont = ComprobarMatrix(matrix,nivel_col);
            }while(cont>1);
            break;
        case 2:
            nivel_col = 9;
            matrix = MatrizInternaAleman(nivel_col);
            Imprimir(matrix,nivel_col);
            do{
                MoverPieza(matrix);
                Imprimir(matrix,nivel_col);
                cont = ComprobarMatrix(matrix,nivel_col);
            }while(cont>1);
            break;
        case 3:
            nivel_col = 7;
            matrix = MatrizInternaFrances(nivel_col);
            Imprimir(matrix,nivel_col);
           do{
                MoverPieza(matrix);
                Imprimir(matrix,nivel_col);
                cont = ComprobarMatrix(matrix,nivel_col);
            }while(cont>1);
            break;

    }
return 0;
}
