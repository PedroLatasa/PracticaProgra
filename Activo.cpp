#include "libreria.hpp"

class Activo{ //realizada por luis
    public:
        virtual float rentabilidad() = 0;
};

class Bono : public Activo{
    protected:
        float pagos, precio_inicial, precio_actual;
        
    public: 
        Bono (float pa, float pi, float pg){
            pagos = pg;
            precio_actual = pa;
            precio_inicial = pi;
        }

        float rentabilidad(){
            return ((precio_actual-precio_inicial)/precio_inicial) + (pagos/precio_inicial);
        }

};

class Prestamo : public Activo{
    protected:
        float tipo_interes, promesa_de_pago, desembolso_inicial;
    
    public:
        Prestamo(float i, float pp, float di){
            tipo_interes = i;
            promesa_de_pago = pp;
            desembolso_inicial = di;
        }

        float rentabilidad(){
            return (promesa_de_pago * tipo_interes) - desembolso_inicial;
        }

};
