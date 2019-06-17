#include "Funciones.h"
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int Menu(){
    int num;
    cout<<"Menu - Juego Senku/n\n1. Estilo Ingles\n2. Estilo aleman\n3. Estilo frances\n-------------------------------------\n0. Salir del Programa\n";
    do{ cout<<"Juego elegido:";cin>>num;} while(num<0||num>3);
    return num;
}

int** MatrizInternaIngles(int nivel_col){
    //creamos la matriz
    int **A;
    A = new int*[nivel_col];

    for (int i=0; i < nivel_col; i++) {
        A[i] = new int[nivel_col];
    }
    for(int f=0;f<nivel_col;f++){
        for(int c=2;c<5;c++)A[f][c]=1;}
    for(int f=2;f<5;f++){
        for(int c=0;c<nivel_col;c++)A[f][c]=1;
    }A[3][3]=0;
    //------------------Espacios en blanco------------------
    for(int f=0;f<2;f++){
        for(int c=0;c<2;c++)A[f][c]=8;}
    for(int f=5;f<nivel_col;f++){
        for(int c=0;c<2;c++)A[f][c]=8;}
    //--------------------------
    for(int f=0;f<2;f++){
        for(int c=5;c<nivel_col;c++)A[f][c]=8;}
    for(int f=5;f<nivel_col;f++){
        for(int c=5;c<nivel_col;c++)A[f][c]=8;}

    return A;
}

int** MatrizInternaAleman(int nivel_col){
    //creamos matriz
    int **A;
    A = new int*[nivel_col];

    for (int i=0; i < nivel_col; i++) {
        A[i] = new int[nivel_col];
    }

    for(int f=0;f<nivel_col;f++){
        for(int c=3;c<6;c++)A[f][c]=1;}
    for(int f=3;f<6;f++){
        for(int c=0;c<nivel_col;c++)A[f][c]=1;
    }A[4][4]=0;
    //------------------Espacios en blanco------------------
    for(int f=0;f<3;f++){
        for(int c=0;c<3;c++)A[f][c]=8;}
    for(int f=6;f<nivel_col;f++){
        for(int c=0;c<3;c++)A[f][c]=8;}
    //--------------------------
    for(int f=0;f<3;f++){
        for(int c=6;c<nivel_col;c++)A[f][c]=8;}
    for(int f=6;f<nivel_col;f++){
        for(int c=6;c<nivel_col;c++)A[f][c]=8;}
    return A;
}

int** MatrizInternaFrances(int nivel_col){
    //creamos la matriz
    int **A;
    A = new int*[nivel_col];

    for (int i=0; i < nivel_col; i++) {
        A[i] = new int[nivel_col];
    }

    for(int f=0;f<nivel_col;f++){
        for(int c=2;c<5;c++)A[f][c]=1;}
    for(int f=2;f<5;f++){
        for(int c=0;c<nivel_col;c++)A[f][c]=1;
    }A[2][3]=0;
    //------------------Espacios en blanco------------------
    for(int f=0;f<2;f++){
        for(int c=0;c<2;c++)A[f][c]=8;}
    for(int f=5;f<nivel_col;f++){
        for(int c=0;c<2;c++)A[f][c]=8;}
    //--------------------------
    for(int f=0;f<2;f++){
        for(int c=5;c<nivel_col;c++)A[f][c]=8;}
    for(int f=5;f<nivel_col;f++){
        for(int c=5;c<nivel_col;c++)A[f][c]=8;}
    A[1][1]=1;A[1][5]=1;A[5][1]=1;A[5][5]=1;
    return A;
}

void Imprimir(int **A,int nivel_col){
    cout<<setw(4)<<" "<<setw(4)<<"0"<<setw(4)<<"1"<<setw(4)<<"2"<<setw(4)<<"3"<<setw(4)<<"4"<<setw(4)<<"5"<<setw(7)<<"6\n\n\n";
    for(int f=0;f<nivel_col;f++)
    {cout<<f<<"   ";
        for(int c=0;c<nivel_col;c++)
        cout<<setw(4)<<A[f][c];
        cout<<"\n";
    }
}

void MoverPieza(int **&A) {
    int fila, col,mov;
    cout << "Indique pieza que quiere mover (fila):"; cin >> fila;
    cout << "Indique pieza que quiere mover (columna):"; cin >> col;
    cout << "Indique hacia donde quiere moverse (1)Derecha (2)Izquierda (3)Arriba (4)Abajo: "; cin>>mov;

    switch (mov) {
        case 1:
            if (A[fila][col+2] == 0)
                if (A[fila][col+1] == 1)
                    if(A[fila][col]==1) {
                        A[fila][col + 2] = 1;
                        A[fila][col + 1] = 0;
                        A[fila][col] = 0;
                    }
            else
                cout<<"No puede realizar este movimiento";
            break;
        case 2:
            if (A[fila][col-2] == 0)
                if (A[fila][col] == 1) {
                    if (A[fila][col] == 1) {
                        A[fila][col - 2] = 1;
                        A[fila][col] = 0;
                        A[fila][col - 1] = 0;
                    }
                }
                else
                    cout<<"No puede realizar este movimiento";
                break;

        case 3:
            if (A[fila][col] == 1){
                if (A[fila-2][col] == 0){
                    if (A[fila-1][col]==1){
                        A[fila-1][col] = 0;
                        A[fila][col]=0;
                        A[fila-2][col]=1;}}}
            else
                cout<<"No puede realizar este movimiento";
            break;
        case 4:
            if (A[fila+2][col] == 0)
                if (A[fila+1][col]==1){
                    if (A[fila][col] == 1) {
                        A[fila + 2][col] = 1;
                        A[fila][col] = 0;
                        A[fila + 1][col] = 0;
                }
            }
            else
                cout<<"No puede realizar este movimiento";
            break;
    }
}

int ComprobarMatrix(int **A,int nivel_col)
{
    int cont=0;
    for(int i=0;i<nivel_col;i++)
        for(int r=0;r<nivel_col;r++)
            if(A[i][r]==1)
                cont++;
    return cont;
}

int ComprobarMatrixPerder(int **A,int nivel_col)
{
    int cont1=0;
    for(int i=0;i<nivel_col;i++)
        for(int r=0;i<nivel_col;r++)
        {
            if(A[i][r]==1){
                if(((A[i-1][r]==1)||(A[i][r-1]==1)||(A[i][r+1]==1)||(A[i+1][r]==1)))
                {
                    cont1++;
                }
            }
        }

    return cont1;
}
