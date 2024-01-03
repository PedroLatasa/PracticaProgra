#ifndef _LIBRERIA
#define _LIBRERIA
#include <iostream>
#include <vector>
#include <fstream>
#include <cctype> // para las funciones de char, pero es necesario?
//#include <cstdlib>
using namespace std;
#include "Cuenta.cpp"
#include "Cliente.cpp"

void interfaz();
void cargaDatosClientes(vector<Cliente> &cliente);                                         // realizada por pablo                                             // realizada por pablo
int menuInicial();                                                                         // realizada por jacobo
int menuPrincipal();                                                                       // realizada por jacobo
int operaciones(int eleccion, Cliente c);
int buscarCliente(vector<Cliente> clientes, string dni);
int login(const vector<Cliente> clientes);    // realizada por pablo y pedro
bool registro(vector<Cliente> &clientes);                         // realizada por pedro
bool cumpleRequisitos(const string &password);                                             // realizada por pedro
string pedirContrasenna();                                                                 // realizada por pedro
bool registro(vector<Cliente> &clientes, vector<Cuenta> &cuentas);                         // realizada por pedro
int eligeCuenta(Cliente c);

#include "libreria.cpp"
#endif
