#ifndef _LIBRERIA
#define _LIBRERIA
#include <iostream>
#include <vector>
#include <fstream>
#include <cctype> // para las funciones de char, pero es necesario?
using namespace std;

class Cuenta // clase realizada por luis, con algunos metodos de latasa
{
private:

public:
    string Nombre_Usuario, contraseña;
    int Numero_Tarjeta;
    float Fondos;
    
    void Hacer_Transferencia();
    void Añadir_Fondos();
    void Retirar_Fondos();
    void GetName();
    //Cuenta() {}
};

class Cliente
{
private:

public:
    string dni, nombre, apellido1, apellido2;
    vector<Cuenta> cuentas;
    // Cliente() {}
};

void cargaDatosClientes(vector<Cliente> &cliente);                                         // realizada por pablo
void cargaDatosCuentas(vector<Cuenta> &c);                                                 // realizada por pablo
int menuInicial();                                                                         // realizada por jacobo
int menuPrincipal();                                                                       // realizada por jacobo
int operaciones(int eleccion);
bool login(const vector<Cliente> &clintes, vector<Cuenta> &cuentas, string &dniActual);    // realizada por pablo y pedro
bool registro(vector<Cliente> &clientes, vector<Cuenta> &cuentas);                         // realizada por pedro
bool cumpleRequisitos(const string &password);                                             // realizada por pedro
string pedirContrasenna();                                                                 // realizada por pedro
bool registro(vector<Cliente> &clientes, vector<Cuenta> &cuentas);                         // realizada por pedro

#include "libreria.cpp"
#endif
