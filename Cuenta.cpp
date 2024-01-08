#include "libreria.hpp"

class Cuenta
{ // clase realizada por luis, con algunos metodos de latasa
private:
    float Fondos;
public:
    string Nombre_Usuario, Numero_Tarjeta; // nombre_usuario es realmente el dni del propietario (un nombre no podria ser pk)

    // En la clase Cuenta

    /*bool validarTransferencia(const vector<Cuenta>& cuentas, const string& numCuentaDestinatario, float cantidad) const {
        // Buscar al destinatario por el número de tarjeta
        auto it = find_if(cuentas.begin(), cuentas.end(), [&numCuentaDestinatario](const Cuenta& cuenta) {
            return cuenta.Numero_Tarjeta == numCuentaDestinatario;
        });

        // Comprobar si se encontró al destinatario
        if (it == cuentas.end()) {
            cout << "Número de cuenta del destinatario no válido.\n";
            return false;
        }

        // Comprobar si el remitente tiene fondos suficientes
        if (Fondos < cantidad) {
            cout << "Fondos insuficientes para realizar la transferencia.\n";
            return false;
        }

        return true;
    }*/

    void hacer_Transferencia()
    {
        float cantidad = 0;
        string num_Cuenta = " ";

        // Solicitar al usuario el número de cuenta del destinatario y la cantidad
        cout << "Ingrese el numero de tarjeta del destinatario: ";
        cin >> num_Cuenta;

        cout << "Ingrese la cantidad a transferir: ";
        cin >> cantidad;

        /*// Realizar las comprobaciones y la transferencia
        if (validarTransferencia(cuentas, num_Cuenta, cantidad)) {
            Fondos -= cantidad; // Restar fondos al remitente

            // Actualizar los fondos del destinatario
            auto it = find_if(cuentas.begin(), cuentas.end(), [&num_Cuenta](const Cuenta& cuenta) {
                return cuenta.Numero_Tarjeta == num_Cuenta;
            });

            if (it != cuentas.end()) {
                it->Fondos += cantidad; // Sumar fondos al destinatario
                cout << "Transferencia exitosa a la cuenta " << num_Cuenta << "\n";
            } else {
                cout << "Error al actualizar los fondos del destinatario.\n";
            }
        } else {
            cout << "No se pudo realizar la transferencia.\n";
        }*/
    }

    void añadir_Fondos()
    {
        float cantidad = 0;
        cout << "Escriba la cantidad de fondos que desee anadir: " << endl;
        cin >> cantidad;
        cantidad += getFondos();
        setFondos(cantidad);
        cout << "Se han anadido " << cantidad << " correctamente a su cuenta." << endl;
    }

    void retirar_Fondos()
    {
        float cantidad;
        cout << "Escriba la cantidad de fondos que desee retirar: " << endl;
        cin >> cantidad;
        Fondos -= cantidad;
        cout << "Se han extraido " << cantidad << " correctamente de su cuenta." << endl;
    }

    void getString()
    {
        cout << endl << "Numero de la tarjeta: " << Numero_Tarjeta << endl 
        << "Propiedad de: " << Nombre_Usuario << endl
        << "Saldo actual: " << getFondos() << endl;
    }

    float getFondos()
    {
        return Fondos;
    }

    void setFondos(float fondos)
    {
        Fondos = fondos;
    }

    // Cuenta() {}
};