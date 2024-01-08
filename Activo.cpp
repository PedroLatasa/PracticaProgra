#include "libreria.hpp"
using namespace std;


class Activo{
    protected:
        float precio_actual;
        float precio_inicial;

    public:

        float get_rentabilidad(){
            (precio_actual - precio_inicial) / precio_inicial;
        }    

};

class Bono : protected Activo{
    protected:
        float pagos;
        
    public: 
        float rentabilidad = get_rentabilidad_bono();
        Bono (float pa, float pi, float pg){
            pagos = pg;
            precio_actual = pa;
            precio_inicial = pi;
        }

        float get_rentabilidad_bono(){
            get_rentabilidad() + (pagos / precio_inicial);
        }

};

class Prestamo : protected Activo{
    protected:
        float tipo_interes;
        float promesa_de_pago;
    
    public:
        //float rentabilidad = get_rentabilidad_prestamo();
        
        Prestamo(float i, float pp, float pi){
            tipo_interes = i;
            promesa_de_pago = pp;
            precio_inicial = pi;
        }

        //float get_rentabilidad_prestamo(){
        //    (promesa_de_pago * (1 + tipo_interes)) - precio_inicial;
        //}

};

/*
int main(){
    Bono b34(340,300,15);
    Prestamo p82(0.1,320,310);

    cout << "La rentabilidad del bono es de: " << b34.rentabilidad << endl;

    return 0;
}
*/