/*
Practica 1 - Equipo #6
Seccion: D05
Calendario: 2020A

Aceves García Carlos Jair
Aguirre Jasso Angel Ernesto
Lizaola Garcia Alma Denisse
Lozano Salinas Miguel Angel
Silva Sanchez Guadalupe Jocelyn
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string.h>

using namespace std;

void mostrarLinea(int , const char * const, double);

int main()
{
    int op;

    ifstream archivoClientesSalida; //archivo logico
    archivoClientesSalida.open("clientes.txt", ios::in);

    if(!archivoClientesSalida)
    {
        cerr << "No se pudo abrir el archivo" <<endl;
        exit(1);
    }//endif

    int cuenta;
    char nombre[30];
    double saldo;

    do{
        cout<<endl;
        cout<<"---------Menu- investigacion de creditos-------"<<endl
           <<"1) Mostrar cuentas con saldo en ceros"<<endl
          <<"2) Mostrar cuentas con saldo acreedor(-)"<<endl
         <<"3) Mostrar cuentas con saldo deudor(+)"<<endl
        <<"4) Salir"<<endl
        <<"Elige tu opcion: ";
        cin>>op;

        system("cls");
        switch(op){
        case 1:
            cout << "CUENTAS CON SALDO EN CEROS" << endl << endl;
            break;
        case 2:
            cout << "CUENTAS CON SALDO EN ACREDOR" << endl << endl;
            break;
        case 3:
            cout << "CUENTAS CON SALDO EN DEUDOR" << endl << endl;
            break;
        case 4: break;
        default: cout<<"---------Opcion incorrecta--------"<<endl<<endl;

        }//endswitch

        if(op>=1 && op<=3){
            cout << left << setw(10) << "CUENTA" << setw(13) << "NOMBRE"
                 << "SALDO" << endl << fixed << showpoint;

            archivoClientesSalida >> cuenta >> nombre >> saldo;//Extrae un registro

            //Mostrar cada registro del archivo
            while (!archivoClientesSalida.eof()) {
                if(op == 1 && saldo == 0){
                    mostrarLinea(cuenta, nombre, saldo);
                }else if(op == 2 && saldo < 0){
                    mostrarLinea(cuenta, nombre, saldo);
                }else if(op == 3 && saldo > 0){
                    mostrarLinea(cuenta, nombre, saldo);
                }
                archivoClientesSalida >> cuenta >> nombre >> saldo;
            }//endwhile
        }//endif

        archivoClientesSalida.clear();//Limpia el bit eof (end of file)
        archivoClientesSalida.seekg(0,ios::beg);//Pone el puntero al inicio del archivo


    }while(op!=4);
    //enddowhile

    archivoClientesSalida.close();//Cierra el flujo
    return 0;
}//findemain


//Mostrar cada registro del archivo
void mostrarLinea(int cuenta, const char * const nombre, double saldo)
{
    cout << left << setw(10) << cuenta << setw(13) << nombre << setw(7) << setprecision(2) << saldo << endl;
}//mostrarLinea
