#ifndef _LIBRERIA
#define _LIBRERIA
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Cliente
{
private:
    // vector<CtaCte> cuentas;

public:
    string dni, nombre, apellido1, apellido2;
    // Cliente() {}
};

class Cuenta // clase realizada por luis, con algunos metodos de latasa
{
private:
    string Nombre_Usuario;
    int Numero_Tarjeta;
    float Fondos;

public:
    void Hacer_Transferencia();
    void Añadir_Fondos();
    void Retirar_Fondos();
    void GetName();
    //Cuenta() {}
};

void cargaDatosClientes(vector<Cliente> &cliente);                                         // realizada por pablo
void cargaDatosCuentas(vector<Cuenta> &c);                                                 // realizada por pablo
int menuInicial();                                                                         // realizada por jacobo
int menuPrincipal();                                                                       // realizada por jacobo
int operaciones(int eleccion);
bool login(const vector<Cliente> &clintes, vector<Cuenta> &cuentas, string &dniActual);    // realizada por pablo y pedro
bool registro(vector<Cliente> &clientes, vector<Cuenta> &cuentas);                         // realizada por pedro

#include "libreria.cpp"
#endif
