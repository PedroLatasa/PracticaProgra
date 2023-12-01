#include "libreria.hpp"

void interfaz()
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
            int posicionCliente = login(clientes);
            if (posicionCliente != -1) {  // sera "if(login())", pero hasta que este realizado el metodo en cuestion lo tomamos como true 

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
            archivo >> c.contrasenna;
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
            // archivo >> c.num;
            // archivo >> c.saldo;
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

int buscarCliente(vector<Cliente> clientes, string dni){
    int pos = -1; // en caso de no encontrar un cliente con dicho dni devuelve -1
    for(int i= 0; i < clientes.size(); i++){
        if (clientes.at(i).dni == dni) {
            pos = i;
            i = clientes.size();
        }
    }

    return pos;
}

int login(vector<Cliente> clientes) {
    string dni, password;
    int contador = 0;
    bool isIn = false;
    int posicion;

    do {
        system("clear");
        cout << "\n\t\t\tLOGIN DE USUARIO\n";
        cout << "\t\t\t-----------------\n";
        cout << "\n\tDNI: ";
        cin >> dni;
        cout << "\tPassword: ";
        cin >> password;

        posicion = buscarCliente(clientes, dni);
        if(posicion != -1 && clientes.at(posicion).contrasenna == password){
            isIn = true;
        }

        if (!isIn) {
            cout << "\tError en el DNI o la contrasena. Intente de nuevo." << endl;
            contador++;
        }

    } while (contador < 3 && !isIn);

    if (!isIn) {
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
    nuevoCliente.contrasenna = password;

    // Agregar el nuevo cliente y crear una nueva cuenta
    nuevoCliente.cuentas.push_back(Cuenta());  // Crear una cuenta vacía asociada al nuevo cliente
    nuevoCliente.cuentas.back().Nombre_Usuario = nuevoCliente.nombre; // Usar el nombre como nombre de usuario por ahora
    nuevoCliente.cuentas.back().Numero_Tarjeta = cuentas.size() + 1;    // Simplemente incrementar el número de tarjeta
    nuevoCliente.cuentas.back().Fondos = 0;                             // Nuevo usuario comienza con saldo cero                // Almacenar la contraseña en la cuenta

    clientes.push_back(nuevoCliente);  // Agregar el nuevo cliente al vector de clientes

    registrado = true; // Se registra con éxito y se devuelve true
    return registrado;
}
