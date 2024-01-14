#ifndef _LIBRERIA
#define _LIBRERIA
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype> // para las funciones de char, pero es necesario?
#include <random>
#include <ctime>
#include <assert.h>
//#include <cstdlib>
using namespace std;
#include "Activo.cpp"
#include "Cuenta.cpp"
#include "Cliente.cpp"

void interfaz();
int cargaDatosClientes(vector<Cliente> &cliente);                                         // realizada por pablo                                             // realizada por pablo
int menuInicial();                                                                         // realizada por jacobo
int menuPrincipal();   
int menuInformacion();   
int menuCambiarDatos();     
void cambiarDatos(int opcion, Cliente& c);                                                            // realizada por jacobo
int cambiarInfo(int opcion, Cliente& c, int numCuentas);
int darseDeBaja(Cliente &c, int numCuentas);
void annadirFondos(vector<Cliente> &clientes, string num, float fondos);
void realizarTransferencia(vector<Cliente> &clientes, Cuenta &cta);
void operaciones(int eleccion,vector<Cliente> &clientes,Cuenta& cta, Cliente& c, int numCuentas);
int buscarCliente(vector<Cliente> clientes, string dni);
int login(const vector<Cliente> clientes);    // realizada por pablo y pedro
bool registro(vector<Cliente> &clientes);                         // realizada por pedro
bool esDNIValido(const string& dni);
bool cumpleRequisitos(const string password);                                             // realizada por pedro
string pedirContrasenna();                                                                 // realizada por pedro                       // realizada por pedro
int eligeCuenta(Cliente c);
void guardaDatos(vector<Cliente> clientes, int numCuentas);
string generarNumeroTarjeta();

#include "libreria.cpp"
#endif
