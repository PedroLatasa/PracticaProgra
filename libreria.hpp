#ifndef _LIBRERIA
#define _LIBRERIA
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype> 
#include <random>
#include <ctime>
#include <assert.h>
using namespace std;
#include "Activo.cpp" // clase realizada por luis
#include "Cuenta.cpp" // clase realizada por luis
#include "Cliente.cpp" //clase realizada por pablo


void interfaz(); // realizada por pablo y pedro
int cargaDatosClientes(vector<Cliente> &cliente); // realizada por pablo                                             
int menuInicial(); // realizada por jacobo
int menuPrincipal(); // realizada por jacobo
int menuInformacion(); // realizada por jacobo
int menuCambiarDatos();  // realizada por jacobo
void cambiarDatos(int opcion, Cliente& c); // realizada por pedro                                                         
int cambiarInfo(int opcion, Cliente& c, int numCuentas); // realizada por pedro
int darseDeBaja(Cliente &c, vector<Cliente> &clientes, int numCuentas); // realizada por pedro
void annadirFondos(vector<Cliente> &clientes, string num, float fondos); // realizada por luis
void realizarTransferencia(vector<Cliente> &clientes, Cuenta &cta); // realizada por pedro
int operaciones(int eleccion,vector<Cliente> &clientes,Cuenta& cta, Cliente& c, int numCuentas); // realizada por nacho
int buscarCliente(vector<Cliente> clientes, string dni); // realizada por pablo
int login(const vector<Cliente> clientes); // realizada por pablo
bool registro(vector<Cliente> &clientes);  // realizada por pedro
bool esDniValido(const string& dni); // realizada por nacho
bool cumpleRequisitos(const string password);  // realizada por nacho
string pedirContrasenna(); // realizada por nacho          
int eligeCuenta(Cliente c); // realizada por nacho
void guardaDatos(vector<Cliente> clientes, int numCuentas); // realizada por luis
string generarNumeroTarjeta(); // realizada por luis

#include "libreria.cpp"
#endif
