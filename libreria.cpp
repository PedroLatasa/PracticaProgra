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

#define DNI_PRUEBA "pablo"
#define PASS_PRUEBA "aloha"

bool login(const vector<Cliente> &clientes, vector<Cuenta> &cuentas, string &dniActual) { // QQQQQQQQQQQQQQ??????????????????
    string dni, password;
    int contador = 0;
    bool isIn = false;

    do {
        system("clear");
        cout << "\n\t\t\tLOGIN DE USUARIO\n";
        cout << "\t\t\t-----------------\n";
        cout << "\n\tDNI: ";
        cin >> dni;
        cout << "\tPassword: ";
        cin >> password;

        for (size_t i = 0; i < clientes.size(); ++i) {
            if (DNI_PRUEBA == dni && clientes[i].cuentas.size() > 0) {
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

bool cumpleRequisitos(const string &password)
{
    bool tieneMayuscula = false;
    bool tieneMinuscula = false;
    bool tieneNumero = false;
    bool tieneCaracterEspecial = false;

    for (char c : password)
    {
        if (isupper(c))
        {
            tieneMayuscula = true;
        }
        else if (islower(c))
        {
            tieneMinuscula = true;
        }
        else if (isdigit(c))
        {
            tieneNumero = true;
        }
        else if (ispunct(c))
        {
            tieneCaracterEspecial = true;
        }
    }

    return tieneMayuscula && tieneMinuscula && tieneNumero && tieneCaracterEspecial;
}

string pedirContrasenna(){
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
    for (const auto &cliente : clientes) // ¿auto?
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
    string password = pedirContrasenna();

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
