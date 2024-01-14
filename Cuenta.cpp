#include "libreria.hpp"

class Cuenta
{ // clase realizada por luis, con algunos metodos de latasa
protected:
    float fondos;
    string dni_propietario, numero_tarjeta;

public:

    Cuenta() {}

    Cuenta(string num, string n, float f)
    {
        numero_tarjeta = num;
        dni_propietario = n;
        fondos = f;
    }

    string getDni()
    {
        return dni_propietario;
    }

    void setDni(string nombre)
    {
        dni_propietario = nombre;
    }

    string getNumTarjeta()
    {
        return numero_tarjeta;
    }

    void setNumTarjeta(string num)
    {
        numero_tarjeta = num;
    }

    float getFondos()
    {
        return fondos;
    }

    void setFondos(float fondos)
    {
        this->fondos = fondos;
    }

    void getString()
    {
        cout << endl
             << "Numero de la tarjeta: " << numero_tarjeta << endl
             << "Propiedad de: " << dni_propietario << endl
             << "Saldo actual: " << fondos << endl;
    }

    bool fondos_suficientes(float cantidad)
    {
        return cantidad <= fondos;
    }
    
    void añadir_fondos()
    {
        float cantidad;
        string respuesta;
        cout << "Escriba la cantidad de fondos que desee anadir: ";
        cin >> cantidad;
        cout << "Hemos entendido que desea anadir " << cantidad << " fondos a su cuenta. \nEs esto correcto? (s para si; n para no): ";
        cin >> respuesta;
        if (respuesta == "s")
        {
            fondos += cantidad;
            //setFondos(Fondos);
            cout << "Se han anadido " << cantidad << " correctamente a su cuenta." << endl;
        }
        else
        {
            cout << "De acuerdo. No se ha realizado la operacion.";
        }
    }

    void retirar_fondos()
    {
        float cantidad;
        string respuesta;

        cout << "Escriba la cantidad de fondos que desee retirar: ";
        cin >> cantidad;

        cout << "Hemos entendido que desea retirar " << cantidad << " fondos a su cuenta. \nEs esto correcto? (s para si; n para no): ";
        cin >> respuesta;

        if (respuesta == "s")
        {
                if (!fondos_suficientes(cantidad))
                {
                    cerr << ("Insuficientes fondos"); // cerr es un cout pero dejando claro que es mensaje de error, no uno tradicional
                }
                else{
                    fondos -= cantidad;
                    //setFondos(Fondos);
                    cout << "Se han extraido " << cantidad << " correctamente de su cuenta." << endl;
                } 
        }
        else
        {
            cout << "De acuerdo. No se ha realizado la operacion." << endl;
        }
    }

    void invertir()
    {
        cerr << "\nNo puedes realizar operaciones de inversion sobre esta cuenta."
        << "(Solo es valido para una cuenta inversora)" << endl;
    }
};

class CuentaInversora : public Cuenta
{
    public:
    //vector<Activo> activos;
    
    CuentaInversora(){}

    CuentaInversora(string num, string n, float f) : Cuenta(num, n, f){}

    void invertir()
    {
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

    void crear_bono()
    {
        float cantidad;
        float pagos;
        float pago_final;
        cout << "Cuanto dinero desea pagar de forma inicial? " << endl;
        cin >> cantidad;
        if (fondos < cantidad)
        {
            cout << "Fondos Insuficientes, vuelva a ingresar la cantidad. " << endl;
            crear_bono();
        }
        if (cantidad <= 100)
        {
            pagos = cantidad * 0.08;
            pago_final = cantidad * 1.02;
        }
        else if (cantidad <= 300 and cantidad > 100)
        {
            pagos = cantidad * 0.1;
            pago_final = cantidad * 1.03;
        }
        else if (cantidad > 300)
        {
            cout << "Es un placer hacer negocios con usted. " << endl;
            pagos = cantidad * 0.15;
            pago_final = cantidad * 1.05;
        }
        Bono bono(pago_final, cantidad, pagos);
        cout << "El bono con pago inicial de: " << cantidad << " pagos de: " << pagos << " y pago final de: " << pago_final << " ha sido creado" << endl;
        //activos.push_back(bono);
    }

    void crear_prestamo()
    {
        float tipo_interes;
        float desembolso_inicial;
        float promesa_de_pago;
        cout << "¿Cuanto dinero desea prestar?" << endl;
        cin >> desembolso_inicial;
        if (fondos < desembolso_inicial)
        {
            cout << "Fondos insuficientes, operacion cancelada, vuelva a ingresar la cantidad. " << endl;
            crear_prestamo();
        }
        if (desembolso_inicial <= 100)
        {
            tipo_interes = 0.04;
            cout << "Su tipo de interes del prestamo es del: " << tipo_interes << endl;
            promesa_de_pago = 1.02 * desembolso_inicial;
        }
        else if (desembolso_inicial > 100 and desembolso_inicial <= 300)
        {
            tipo_interes = 0.06;
            cout << "Su tipo de interes del prestamo es del: " << tipo_interes << endl;
            promesa_de_pago = 1.03 * desembolso_inicial;
        }
        else if (desembolso_inicial > 300)
        {
            cout << "Es un placer hacer negocios con usted. " << endl;
            tipo_interes = 0.08;
            cout << "Su tipo de interes del prestamo es del: " << tipo_interes << endl;
            promesa_de_pago = 1.08 * desembolso_inicial;
        }
        Prestamo prestamo(tipo_interes, promesa_de_pago, desembolso_inicial);
        cout << "El prestamo con desembolso inicial de: " << desembolso_inicial << " tipo de interes del: " << tipo_interes << " y promesa de pago de: "
             << promesa_de_pago << " Ha sido emitido. " << endl;
        //activos.push_back(prestamo);
    }

};
