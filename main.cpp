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

    return 0;
}
