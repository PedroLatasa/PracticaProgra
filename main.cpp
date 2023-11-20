/*
    Realizado por: Luis Javier Romero(luis), Jacobo Chaves(jacobo), 
    Pedro Latasa(latasa), Ignacio Ochoa(nacho) y Pablo Ruiz(pablo)
    
    Primera aproximacion practica grupal Proyectos de programacion
    08/11/2023  
*/

#include "libreria.hpp"

int main() // realizada por nacho basically
{
    vector<Cliente> clientes;
    vector<Cuenta> cuentas; // pero debería hacerse desde clientes... REVISAR
    cargaDatosClientes(clientes);
    // cargaDatosCuentas(cuentas);

    int opcion = menuInicial();
    switch (opcion)
    {
        case 1:
        {
            if (login()) // sera "if(login())", pero hasta que este realizado el metodo en cuestion lo tomamos como true
            {
                cout << "Inicio de sesión exitoso." << endl;

                int eleccion = menuPrincipal();
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
                    cout << "Sesión cerrada. ¡Hasta luego!" << endl;
                break;
                default:
                    cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                break;
                }
            }

            else
            {
                cout << "Error de inicio de sesión." << endl;
            }
        }
        break;
        case 2:
        {
            // crear cuenta();

            int eleccion = menuPrincipal();
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
                cout << "Sesión cerrada. ¡Hasta luego!" << endl;
            break;
            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
            break;
            }
        }
            break;
        case 0:
            cout << "Gracias por usar nuestro servicio. ¡Hasta luego!" << endl;
        break;
        default:
            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
        break;
    }

    return 0;
}


