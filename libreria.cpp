#include "libreria.hpp"

void Cuenta ::Hacer_Transferencia()
{
}

void Cuenta ::Añadir_Fondos()
{
    float cantidad;
    cout << "Escriba la cantidad de fondos que desee añadir: " << endl;
    cin >> cantidad;
    Fondos += cantidad;
}

void Cuenta ::Retirar_Fondos()
{
    float cantidad;
    cout << "Escriba la cantidad de fondos que desee retirar: " << endl;
    cin >> cantidad;
    Fondos -= cantidad;
}

void Cuenta ::GetName()
{
    cout << "El nombre de usuario es " + string(Nombre_Usuario) << endl;
}

int menuInicial()
{
    int opcion;
    do
    {
        cout << "\t\t\t*********************\n";
        cout << "\t\t\t Bienvenido al banco\n";
        cout << "\t\t\t*********************\n";
        cout << "\n\t1. Iniciar sesión\n";
        cout << "\t2. Crear cuenta bancaria\n";
        cout << "\t0. Salir\n";

        cout << "\nSelecciona una opción: ";
        cin >> opcion;
        if (opcion < 0 || opcion > 2)
        {
            cout << "Opción invalida" << endl;
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
        cout << "\t4. Pedir préstamo\n";
        cout << "\t5. Invertir\n";
        cout << "\t0. Cerrar sesión\n";

        cout << "\nSelecciona una opción: ";
        cin >> eleccion;
        if (eleccion < 0 || eleccion > 5)
        {
            cout << "Opción inválida" << endl;
        }
    } while (eleccion < 0 || eleccion > 5);
    return eleccion;
}

int operaciones(int eleccion)
{
    switch (eleccion)
    {
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
        // cout << endl << numClientes << endl;
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
            // archivo >> cta.num;
            // archivo >> cta.saldo;
            // archivo >> c.numTlf;
            // c.push_back(c);
        }
        archivo.close();
    }
    else
    {
        cout << "No se ha podido abrir el archivo.";
    }
}

#define USER "pablo"
#define PASS "aloha"

bool login()
{
    string user, password;
    int contador = 0;
    bool isIn = false;

    do
    {
        cout << "\n\t\t\tLOGIN DE USUARIO\n";
        cout << "\t\t\t-----------------\n";
        cout << "\n\tUsuario: ";
        cin >> user;
        cout << "\tPassword: ";
        cin >> password;

        if (user == USER && password == PASS)
        {
            isIn = true;
        }
        else
        {
            cout << "\tEl usuario y/o password son incorrectos.\n";
            contador++;
        }
    } while (contador < 3 && !isIn);

    if (!isIn)
    {
        cout << "No ha podido acceder al sistema.\n";
    }
    else
    {
        cout << "\nBienvenido!\n";
    }

    return isIn;
}
