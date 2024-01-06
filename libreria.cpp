#include "libreria.hpp"

void interfaz()
{
    vector<Cliente> clientes;
    cargaDatosClientes(clientes);
    int opcion;
    do
    {
        opcion = menuInicial();
        switch (opcion)
        {
        case 1:
        {
            int posicionCliente = login(clientes);
            if (posicionCliente != -1)
            { // sera "if(login())", pero hasta que este realizado el metodo en cuestion lo tomamos como true

                cout << "Inicio de sesion exitoso." << endl;
                int eleccion = menuPrincipal();
                operaciones(eleccion, clientes.at(posicionCliente));
            }
            else
            {
                cout << "Error de inicio de sesion." << endl;
            }
        }
        break;

        case 2:
        {
            if (registro(clientes))
            {
                cout << "Registro exitoso. Ahora puede iniciar sesion." << endl;
            }
            else
            {
                cout << "Error en el registro." << endl;
            }
        }
        break;

        case 0:
            cout << "Gracias por usar nuestro servicio. Hasta luego!" << endl;
            break;

        default:
        {
            cout << "Opcion no valida. Por favor, seleccione una opcion valida." << endl;
        }
        break;
        }
    } while (opcion != 0);
}

int menuInicial()
{
    int opcion;
    do
    {
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

int operaciones(int eleccion, Cliente c)
{
    Cuenta cta = c.cuentas.at(0);
    if (c.cuentas.size() > 1) cta = c.cuentas.at(eligeCuenta(c));

    
        switch (eleccion)
        {
        case 1:
            cta.añadir_Fondos();
            break;

        case 2:
            cta.retirar_Fondos();
            break;

        case 3:
            cta.hacer_Transferencia();
            break;

        case 4:
            // pedir_préstamo();
            break;

        case 5:
            // invertir();
            break;

        case 0:
            cout << "Sesión cerrada. Hasta luego!" << endl;
            break;

        default:
            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
            break;
        }

        eleccion = menuPrincipal();
   
   return 0;
}


void cargaDatosClientes(vector<Cliente> &cliente)
{
    int numClientes = 0, numCuentas = 0;
    ifstream archivo;
    archivo.open("C:\\Users\\Admin\\OneDrive - CUNEF\\Documentos\\PracticaProgra\\datosClientes.txt"); //aquí poner "datosClentes.txt"
    if (archivo.is_open())
    {
        archivo >> numClientes;

        for (int i = 0; i < numClientes; i++)
        {
            Cliente c;
            archivo >> c.dni;
            archivo >> c.apellido1;
            archivo >> c.apellido2;
            archivo >> c.nombre;
            archivo >> c.contrasenna;

            ifstream archivo2;
            archivo2.open("C:\\Users\\Admin\\OneDrive - CUNEF\\Documentos\\PracticaProgra\\datosCuentas.txt");//aquí poner "datos.cuentas.txt"
            if (archivo2.is_open())
            {
                archivo2 >> numCuentas;
                for (int i = 0; i < numCuentas; i++)
                {
                    Cuenta cta;
                    archivo2 >> cta.Numero_Tarjeta;
                    archivo2 >> cta.Nombre_Usuario;
                    archivo2 >> cta.Fondos;

                    if (cta.Nombre_Usuario == c.dni){
                        c.cuentas.push_back(cta);
                    }
                }
                archivo2.close();
            }
            else
            {
                cout << "No se ha podido acceder a los datos de cuentas.\n";
            }

            cliente.push_back(c);
        }
        archivo.close();
    }
    else
    {
        cout << "No se ha podido acceder a los datos de clientes.\n";
    }
}

int buscarCliente(vector<Cliente> clientes, string dni)
{
    int pos = -1; // en caso de no encontrar un cliente con dicho dni devuelve -1
    for (int i = 0; i < clientes.size(); i++)
    {
        if (clientes.at(i).dni == dni)
        {
            pos = i;
            i = clientes.size();
        }
    }

    return pos;
}


int login(vector<Cliente> clientes)
{
    string dni, password;
    int contador = 0;
    bool isIn = false;
    int posicion;

    do
    {
        cout << "\n\t\t\tLOGIN DE USUARIO\n";
        cout << "\t\t\t-----------------\n";
        cout << "\n\tDNI: ";
        cin >> dni;
        //esto sirve para cambiar una posible minúscula por mayúscula en el DNI
        if (!dni.empty() && isalpha(dni.back())) {
            dni.back() = toupper(dni.back());
        }
        cout << "\tPassword: ";
        cin >> password;

        posicion = buscarCliente(clientes, dni);
        if (posicion != -1 && clientes.at(posicion).contrasenna == password)
        {
            isIn = true;
        }

        if (!isIn)
        {
            cout << "\tError en el DNI o la contrasena. Intente de nuevo." << endl;
            contador++;
        }

    } while (contador < 3 && !isIn);

    if (!isIn)
    {
        posicion = -1;
        cout << "No ha podido acceder al sistema." << endl;
    }

    return posicion;
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

string pedirContrasenna()
{
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

bool esDNIValido(const string& dni) {
    if (dni.length() != 9) {
        return false;
    }

    for (int i = 0; i < 8; ++i) {
        if (!isdigit(dni[i])) {
            return false;
        }
    }

    if (!isalpha(dni[8])) {
        return false;
    }

    return true;
}

bool registro(vector<Cliente> &clientes)
{
    Cliente nuevoCliente;
    bool registrado = false;

    cout << "Registro de nuevo usuario\n";
    do {
        cout << "Ingrese el DNI del nuevo usuario (8 numeros y 1 letra): ";
        cin >> nuevoCliente.dni;

        if (!esDNIValido(nuevoCliente.dni)) {
            cout << "Formato de DNI no valido. Por favor, intentelo de nuevo." << endl;
        }
    } while (!esDNIValido(nuevoCliente.dni));

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
    nuevoCliente.contrasenna = password;

    // Agregar el nuevo cliente y crear una nueva cuenta
    nuevoCliente.cuentas.push_back(Cuenta());                      // Crear una cuenta vacía asociada al nuevo cliente
    nuevoCliente.cuentas.back().Nombre_Usuario = nuevoCliente.dni; // Usar el nombre como nombre de usuario por ahora
    nuevoCliente.cuentas.back().Numero_Tarjeta = 1;                // Simplemente incrementar el número de tarjeta
    nuevoCliente.cuentas.back().Fondos = 0;                        // Nuevo usuario comienza con saldo cero                // Almacenar la contraseña en la cuenta

    clientes.push_back(nuevoCliente); // Agregar el nuevo cliente al vector de clientes

    registrado = true; // Se registra con éxito y se devuelve true
    return registrado;
}

int eligeCuenta(Cliente c)
{
    int eleccion;
    cout << "\n Elige sobre que cuenta operar: ";
    for (int i = 0; i < c.cuentas.size(); i++)
    {
        cout << i << "- " << c.cuentas.at(i).Numero_Tarjeta << endl;
    }
    cout << "Elige: ";
    cin >> eleccion;

    return eleccion;
}
