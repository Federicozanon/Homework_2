#include "ej4.hpp"

int main(){
    CajaDeAhorro Nueva_caja(1000, "Jaimito");
    CuentaCorriente Nueva_cuentacorriente(2000, "Jaimito", &Nueva_caja);

    cout<<"\nPrueba de los metodos de CuentaCorriente:\n";
    cout<<"1. Mostrar info\n";
    Nueva_cuentacorriente.mostrarInfo();
    cout<<"2. Depositar -10\n";
    Nueva_cuentacorriente.depositar(-10);
    cout<<"3. Depositar 1000\n";
    Nueva_cuentacorriente.depositar(1000);
    cout<<"4. Mostrar info\n";
    Nueva_cuentacorriente.mostrarInfo();
    cout<<"5. Retirar 4000\n";
    Nueva_cuentacorriente.retirar(4000);
    cout<<"6. Retirar -500\n";
    Nueva_cuentacorriente.retirar(-500);
    cout<<"7. Retirar 800\n";
    Nueva_cuentacorriente.retirar(800);
    cout<<"8. Mostrar info\n";
    Nueva_cuentacorriente.mostrarInfo();

    cout<<"\nPrueba de los metodos de CajaDeAhorro\n";
    cout<<"1. Mostrar info\n";
    Nueva_caja.mostrarInfo();
    cout<<"2. Depositar -10\n";
    Nueva_caja.depositar(-10);
    cout<<"3. Depositar 1000\n";
    Nueva_caja.depositar(1000);
    cout<<"4. Mostrar info\n";
    Nueva_caja.mostrarInfo();
    cout<<"5. Retirar 1500\n";
    Nueva_caja.retirar(1500);
    cout<<"6. Retirar -500\n";
    Nueva_caja.retirar(-500);
    cout<<"7. Retirar 800\n";
    Nueva_caja.retirar(800);
    cout<<"8. Mostrar info\n";
    Nueva_caja.mostrarInfo();
    return 0;
}