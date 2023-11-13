/*
    Realizado por: Luis Javier Romero(luis), Jacobo Chaves(jacobo), 
    Pedro Latasa(latasa), Ignacio Ochoa(nacho) y Pablo Ruiz(pablo)
    
    Primera aproximacion practica grupal Proyectos de programacion
    08/11/2023  
    APUNTE: hemos quitado todas las tildes para que no muestre errores por pantalla
    
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <cctype> // Para las funciones de caracteres
using namespace std;



class Cuenta {// clase realizada por luis, con algunos metodos de latasa

public:
    string Nombre_Usuario;
    string contraseña;
    int Numero_Tarjeta;
    float Fondos;

public:
    void Hacer_Transferencia(){}

    void Añadir_Fondos()
    {
        float cantidad;
        cout << "Escriba la cantidad de fondos que desee añadir: " << endl;
        cin >> cantidad;
        Fondos += cantidad;
    }

    void Retirar_Fondos()
    {
        float cantidad;
        cout << "Escriba la cantidad de fondos que desee retirar: " << endl;
        cin >> cantidad;
        Fondos -= cantidad;
    }

    void GetName()
    {
        cout << "El nombre de usuario es " + string(Nombre_Usuario) << endl;
    }

    // Nueva función para obtener saldo
    float Obtener_Saldo() const {
        return Fondos;
    }

};

class Cliente
{

public:
    string dni, nombre, apellido1, apellido2;
    vector<Cuenta> cuentas;

    Cliente() {}
};

void cargaDatosClientes(vector<Cliente> &cliente);                  // realizada por pablo
void cargaDatosCuentas(vector<Cuenta> &c);                          // realizada por pablo
int menuInicial();                                                  // realizada por jacobo
int menuPrincipal();                                                // realizada por jacobo
int operaciones(int eleccion);                                      // realizada por pedro
bool login(const vector<Cliente> &clientes, vector<Cuenta> &cuentas, string &dniActual); // realizada por pablo
bool registro(vector<Cliente> &clientes, vector<Cuenta> &cuentas);  // realizada por pedro

int main() // realizada por nacho basically
{
    vector<Cliente> clientes;
    vector<Cuenta> cuentas; // pero deberia hacerse desde clientes... REVISAR

    cargaDatosClientes(clientes);
    cargaDatosCuentas(cuentas);

    int opcion; 
    string dniActual; // esta variable es para saber el usuario que está usando el programa en cada momento

    do{
    
    opcion = menuInicial();
    switch (opcion)
    {
        case 1: {
            if (login(clientes, cuentas, dniActual)) {  // sera "if(login())", pero hasta que este realizado el metodo en cuestion lo tomamos como true 

                cout << "Inicio de sesion exitoso." << endl;
                int eleccion = menuPrincipal();
                operaciones(eleccion); 
            }
            else{
                cout << "Error de inicio de sesion." << endl;
            }
        }
        break;

                
        case 2:{
            if(registro(clientes, cuentas)){
                cout << "Registro exitoso. Ahora puede iniciar sesion." << endl;
                
            }
            else{
                cout <<"Error en el registro." << endl;
            }

            
        }
        break;

        case 0:
            cout << "Gracias por usar nuestro servicio. Hasta luego!" << endl;
        break;

        default:{
            cout << "Opcion no valida. Por favor, seleccione una opcion valida." << endl;
        } break;
    }
    } while(opcion != 0);

    return 0;
}

int menuInicial()
{
    int opcion;
    do
    {
        system("cls");
        cout << "\t\t\t*********************\n";
        cout << "\t\t\t Bienvenido al banco\n";
        cout << "\t\t\t*********************\n";
        cout << "\n\t1. Iniciar sesion\n";
        cout << "\t2. Crear cuenta bancaria\n";
        cout << "\t0. Salir\n";

        cout << "\nSelecciona una opcion: ";
        cin >> opcion;
        if (opcion < 0 || opcion > 2)
        {
            cout << "Opcion invalida" << endl;
        }
    } while (opcion < 0 || opcion > 2);
    return opcion;
}

int menuPrincipal()
{
    int eleccion;
    do
    {
        cout << "\n\t*************************\n";
        cout << "\n\t1. Ingresar dinero\n";
        cout << "\t2. Retirar dinero\n";
        cout << "\t3. Realizar transferencia\n";
        cout << "\t4. Pedir prestamo\n";
        cout << "\t5. Invertir\n";
        cout << "\t0. Cerrar sesion\n";

        cout << "\nSelecciona una opcion: ";
        cin >> eleccion;
        if (eleccion < 0 || eleccion > 5)
        {
            cout << "Opcion invalida" << endl;
        }
    } while (eleccion < 0 || eleccion > 5);
    return eleccion;
}

int operaciones(int eleccion){
    switch(eleccion){
                case 1:
                    // ingresar_dinero();
                break;

                case 2:
                    // retirar_dinero();
                break;

                case 3:
                    // realizar_transferencia();
                break;

                case 4:
                    // pedir_préstamo();
                break;

                case 5:
                    // invertir();
                break;

                case 0:
                    cout << "Sesion cerrada. Hasta luego!" << endl;
                break;

                default:
                    cout << "Opcion no valida. Por favor, seleccione una opción valida." << endl;
                break;
                }
                return 0;
            }

void cargaDatosClientes(vector<Cliente> &cliente)
{
    int numClientes = 0;
    ifstream archivo;
    archivo.open("datosClientes.txt");
    if (archivo.is_open())
    {
        archivo >> numClientes;
        //cout << endl << numClientes << endl;
        for (int i = 0; i < numClientes; i++)
        {
            Cliente c;
            archivo >> c.dni;
            archivo >> c.apellido1;
            archivo >> c.apellido2;
            archivo >> c.nombre;
            cliente.push_back(c);
        }
        archivo.close();
    }
    else
    {
        cout << "No se ha podido abrir el archivo.\n";
    }
}

void cargaDatosCuentas(vector<Cuenta> &c)
{
    int numCuentas = 0;
    ifstream archivo;
    archivo.open("datosCuentas.txt");
    if (archivo.is_open())
    {
        archivo >> numCuentas;
        for (int i = 0; i < numCuentas; i++)
        {
            Cuenta cta;
            archivo >> cta.Numero_Tarjeta;
            archivo >> cta.Fondos;
            archivo >> cta.Nombre_Usuario;
            c.push_back(cta);
        }
        archivo.close();
    }
    else
    {
        cout << "No se ha podido abrir el archivo.";
    }
}

//#define USER "pablo"
//#define PASS "aloha"

bool login(const vector<Cliente> &clientes, vector<Cuenta> &cuentas, string &dniActual) {
    string dni, password;
    int contador = 0;
    bool isIn = false;

    do {
        cout << "\n\t\t\tLOGIN DE USUARIO\n";
        cout << "\t\t\t-----------------\n";
        cout << "\n\tDNI: ";
        cin >> dni;
        cout << "\tPassword: ";
        cin >> password;

        for (size_t i = 0; i < clientes.size(); ++i) {
            if (clientes[i].dni == dni && clientes[i].cuentas.size() > 0) {
                // Verificar la contraseña
                for (size_t j = 0; j < clientes[i].cuentas.size(); ++j) {
                    if (clientes[i].cuentas[j].contraseña == password) {
                        isIn = true;
                        dniActual = dni;
                        break;
                    }
                }
            }

            if (isIn) {
                break;
            }
        }

        if (!isIn) {
            cout << "\tError en el DNI o la contrasena. Intente de nuevo." << endl;
            contador++;
        }

    } while (contador < 3 && !isIn);

    if (!isIn) {
        cout << "No ha podido acceder al sistema." << endl;
    }

    return isIn;
}




bool cumpleRequisitos(const string &password) {
    return any_of(password.begin(), password.end(), ::isupper) &&
           any_of(password.begin(), password.end(), ::islower) &&
           any_of(password.begin(), password.end(), ::isdigit) &&
           any_of(password.begin(), password.end(), ::ispunct);
    }

    return tieneMayuscula && tieneMinuscula && tieneNumero && tieneCaracterEspecial;
}

string pedirContraseña(){
    string password;

    do
    {
        cout << "Ingrese la contrasena (debe contener al menos 8 caracteres con al menos una mayuscula, una minuscula, un numero y un caracter especial '?'): ";
        cin >> password;
        if (cumpleRequisitos(password))
        {
            string confirmacion;
            cout << "Ahora confirme la contrasena: ";
            cin >> confirmacion;

            if (password == confirmacion)
            {
                return password;
            }
            else
            {
                cout << "Las contrasenas no coinciden. Intentelo de nuevo." << endl;
            }
        }
        else
        {
            cout << "La contrasena no cumple con los requisitos. Intentelo de nuevo." << endl;
        }
    } while (true);
}

bool registro(vector<Cliente> &clientes, vector<Cuenta> &cuentas) {
    Cliente nuevoCliente;
    bool registrado = false;

    cout << "Registro de nuevo usuario\n";
    cout << "Ingrese el DNI del nuevo usuario: ";
    cin >> nuevoCliente.dni;

    // Verificar si el usuario ya existe
    for (const auto &cliente : clientes)
    {
        if (cliente.dni == nuevoCliente.dni)
        {
            cout << "El usuario ya existe. No se puede registrar." << endl;
            return registrado; // Si ya existe, no se registra y se devuelve false
        }
    }

    cout << "Ingrese el nombre: ";
    cin >> nuevoCliente.nombre;
    cout << "Ingrese el primer apellido: ";
    cin >> nuevoCliente.apellido1;
    cout << "Ingrese el segundo apellido: ";
    cin >> nuevoCliente.apellido2;

    // Solicitar y almacenar la contraseña usando la función pedirContraseña
    string password = pedirContraseña();

    // Agregar el nuevo cliente y crear una nueva cuenta
    nuevoCliente.cuentas.push_back(Cuenta());  // Crear una cuenta vacía asociada al nuevo cliente
    nuevoCliente.cuentas.back().Nombre_Usuario = nuevoCliente.nombre; // Usar el nombre como nombre de usuario por ahora
    nuevoCliente.cuentas.back().Numero_Tarjeta = cuentas.size() + 1;    // Simplemente incrementar el número de tarjeta
    nuevoCliente.cuentas.back().Fondos = 0;                             // Nuevo usuario comienza con saldo cero
    nuevoCliente.cuentas.back().contraseña = password;                  // Almacenar la contraseña en la cuenta

    clientes.push_back(nuevoCliente);  // Agregar el nuevo cliente al vector de clientes

    registrado = true; // Se registra con éxito y se devuelve true
    return registrado;
}







