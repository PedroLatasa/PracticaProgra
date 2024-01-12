#ifndef _LIBRERIA
#define _LIBRERIA
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype> // para las funciones de char, pero es necesario?
#include <random>
//#include <cstdlib>
using namespace std;
#include "Activo.cpp"
#include "Cuenta.cpp"
#include "Cliente.cpp"

void interfaz();
int cargaDatosClientes(vector<Cliente> &cliente);                                         // realizada por pablo                                             // realizada por pablo
int menuInicial();                                                                         // realizada por jacobo
int menuPrincipal();                                                                       // realizada por jacobo
void operaciones(int eleccion, Cuenta& cta);
int buscarCliente(vector<Cliente> clientes, string dni);
int login(const vector<Cliente> clientes);    // realizada por pablo y pedro
bool registro(vector<Cliente> &clientes);                         // realizada por pedro
bool esDNIValido(const string& dni);
bool cumpleRequisitos(const string password);                                             // realizada por pedro
string pedirContrasenna();                                                                 // realizada por pedro
bool registro(vector<Cliente> &clientes, vector<Cuenta> &cuentas);                         // realizada por pedro
int eligeCuenta(Cliente c);
void guardaDatos(vector<Cliente> clientes, int numCuentas);
//void guardaCuentas(vector<Cuenta> cuentas);
string generarNumeroTarjeta();

#include "libreria.cpp"
#endif
