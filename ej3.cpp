#include "ej3.hpp"

int main(){
    cout<<"Verificacion de funcionalidad de los metodos de la clase Entero:\n";
    unique_ptr<Numero> Primer_Entero = make_unique<Entero>(-4);
    unique_ptr<Numero> Segundo_Entero = make_unique<Entero>(0);

    cout<<"Prueba de suma de enteros: ";
    unique_ptr<Numero> Resultado1=Primer_Entero->suma(*Segundo_Entero);
    cout<<Resultado1->a_string()<<"\n";

    cout<<"Prueba de resta de enteros: ";
    unique_ptr<Numero> Resultado2 = Primer_Entero->resta(*Segundo_Entero);
    cout<<Resultado2->a_string()<<"\n";

    cout<<"Prueba de multiplicacion de enteros: ";
    unique_ptr<Numero> Resultado3 = Primer_Entero->multiplicacion(*Segundo_Entero);
    cout<<Resultado3->a_string()<<"\n";

    cout<<"Prueba de division de enteros: ";
    unique_ptr<Numero> Resultado4 = Primer_Entero->division(*Segundo_Entero);
    cout<<Resultado4->a_string()<<"\n";

    
    cout<<"Verificacion de funcionalidad de los metodos de la clase Real:\n";
    unique_ptr<Numero> Primer_Real = make_unique<Real>(1.5);
    unique_ptr<Numero> Segundo_Real = make_unique<Real>(-0.25);

    cout<<"Prueba de suma de reales: ";
    unique_ptr<Numero> Resultado5=Primer_Real->suma(*Segundo_Real);
    cout<<Resultado5->a_string()<<"\n";

    cout<<"Prueba de resta de reales: ";
    unique_ptr<Numero> Resultado6 = Primer_Real->resta(*Segundo_Real);
    cout<<Resultado6->a_string()<<"\n";

    cout<<"Prueba de multiplicacion de reales: ";
    unique_ptr<Numero> Resultado7 = Primer_Real->multiplicacion(*Segundo_Real);
    cout<<Resultado7->a_string()<<"\n";

    cout<<"Prueba de division de reales: ";
    unique_ptr<Numero> Resultado8 = Primer_Real->division(*Segundo_Real);
    cout<<Resultado8->a_string()<<"\n";


    cout<<"Verificacion de funcionalidad de los metodos de la clase Compleja:\n";
    unique_ptr<Numero> Primer_Complejo = make_unique<Complejo>(1.5, 2.25);
    unique_ptr<Numero> Segundo_Complejo = make_unique<Complejo>(-2, -4);

    cout<<"Prueba de suma de complejos: ";
    unique_ptr<Numero> Resultado9=Primer_Complejo->suma(*Segundo_Complejo);
    cout<<Resultado9->a_string()<<"\n";

    cout<<"Prueba de resta de complejos: ";
    unique_ptr<Numero> Resultado10 = Primer_Complejo->resta(*Segundo_Complejo);
    cout<<Resultado10->a_string()<<"\n";

    cout<<"Prueba de multiplicacion de reales: ";
    unique_ptr<Numero> Resultado11 = Primer_Complejo->multiplicacion(*Segundo_Complejo);
    cout<<Resultado11->a_string()<<"\n";

    cout<<"Prueba de division de reales: ";
    unique_ptr<Numero> Resultado12 = Primer_Complejo->division(*Segundo_Complejo);
    cout<<Resultado12->a_string()<<"\n";

    return 0;
}