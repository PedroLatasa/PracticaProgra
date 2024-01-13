#include "libreria.hpp"

class Cuenta { // clase realizada por luis, con algunos metodos de latasa
    protected:
        string Nombre_Usuario, Numero_Tarjeta;
        float Fondos;
        vector <Activo> activos;

    public:
        Cuenta(string n, string num, float f){
            Nombre_Usuario = n;
            Numero_Tarjeta = num;
            Fondos = f;
        }

        
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

void hacer_Transferencia() {
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
    
        

        void añadir_Fondos() {
            float cantidad;
            cout << "Escriba la cantidad de fondos que desee anadir: " << endl;
            cin >> cantidad;
            Fondos += cantidad;
        }

        void retirar_Fondos() {
            float cantidad;
            cout << "Escriba la cantidad de fondos que desee retirar: " << endl;
            cin >> cantidad;
            Fondos -= cantidad;
        }

        void getName() {
            cout << "El nombre de usuario es " + string(Nombre_Usuario) << endl;
        }

       
        // Cuenta() {}
};

class Cuenta_Inversora : protected Cuenta{
    protected: 
        vector <Activo> activos;

    public:
        Cuenta_Inversora(string n, string num, float f , vector <Activo> act) : Cuenta(n, num, f){
            Nombre_Usuario = n;
            Numero_Tarjeta = num;
            Fondos = f;
            activos = act;
        }
        
         void invertir(){
            int eleccion;
            cout << "¿En que Activo desea invertir?" << endl;
            cout << "Los Bonos dan pagos y los Prestamos tienen interes." << endl;
            cout << "1.- Bonos" << endl;
            cout << "2.- Prestamos" << endl;
            cout << "0.- Salir" << endl;
            switch (eleccion)
            {
            case 1:
                crear_bono();
                break;

            case 2:
                crear_prestamo();
                break;

            case 0:
                {
                    cout << "Fin de Actividad. " << endl;
                }
                break;
            
            default:
                cout << "Opcion, no valida, eliga de nuevo. " << endl;
                break;
            }
            cin >> eleccion;
        }
        
    void crear_bono(){
        float cantidad;
        float pagos;
        float pago_final;
        cout << "Cuanto dinero desea pagar de forma inicial? " << endl;
        cin >> cantidad;
        if (Fondos < cantidad){
            cout << "Fondos Insuficientes, vuelva a ingresar la cantidad. " << endl;
            crear_bono();
        }
        if (cantidad <= 100)
        {
           pagos = cantidad * 0.08;
           pago_final = cantidad * 1.02;
        } else if (cantidad <= 300 and cantidad > 100)
        {
            pagos = cantidad * 0.1;
            pago_final = cantidad * 1.03;
        } else if (cantidad > 300)
        {
            cout << "Es un placer hacer negocios con usted. " << endl;
            pagos = cantidad * 0.15;
            pago_final = cantidad * 1.05;
        }
        Bono bono(pago_final,cantidad,pagos);
        cout << "El bono con pago inicial de: " << cantidad << " pagos de: " << pagos << " y pago final de: " << pago_final << " ha sido creado" << endl;
        activos.push_back(bono);
}

    void crear_prestamo(){
        float tipo_interes;
        float desembolso_inicial;
        float promesa_de_pago;
        cout << "¿Cuanto dinero desea prestar?" << endl;
        cin >> desembolso_inicial;
        if (Fondos < desembolso_inicial){
            cout << "Fondos insuficientes, operacion cancelada, vuelva a ingresar la cantidad. " << endl;
            crear_prestamo();
        }
        if(desembolso_inicial <= 100){
            tipo_interes = 0.04;
            cout << "Su tipo de interes del prestamo es del: " << tipo_interes << endl;
            promesa_de_pago = 1.02 * desembolso_inicial;
        } else if (desembolso_inicial > 100 and desembolso_inicial <= 300)
        {
            tipo_interes = 0.06;
            cout << "Su tipo de interes del prestamo es del: " << tipo_interes << endl;
            promesa_de_pago = 1.03 * desembolso_inicial;
        } else if (desembolso_inicial > 300)
        {
            cout << "Es un placer hacer negocios con usted. " << endl;
            tipo_interes = 0.08;
            cout << "Su tipo de interes del prestamo es del: " << tipo_interes << endl;
            promesa_de_pago = 1.08 * desembolso_inicial;
        }
        Prestamo prestamo(tipo_interes,promesa_de_pago,desembolso_inicial);
        cout << "El prestamo con desembolso inicial de: " << desembolso_inicial << " tipo de interes del: " << tipo_interes << " y promesa de pago de: " 
        << promesa_de_pago << " Ha sido emitido. " << endl;
        activos.push_back(prestamo);
        
        
    }

};


