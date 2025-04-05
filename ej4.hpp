#include <iostream>
#include <memory>
using namespace std;

/*todos los metodos que estan en publico, para todas las clases, estan asi ya que todos los usuarios del banco tendrian que tener
a disposicion los metodos para administrar su cuenta, teniendo los datos de cada usuario en privado por su seguridad.
*/
class Cuenta_Banco{
    private:
        double balance; //esta en privado ya que es un dato que solo deberia ver el usuario de la cuenta
        virtual void mostrarInfo() = 0; //esta en privado ya que solo el usuario de la cuenta tiene que ver la informacion de la misma
        friend class CajaDeAhorro;
        friend class CuentaCorriente;
    protected:
        string titular_cuenta; //este dato esta en protectec para que las clases derivadas puedan usarlo sin tener que ponerlo publico
    public:
        Cuenta_Banco(double b, string t) : balance(b), titular_cuenta(t) {};
        virtual int retirar(double cant_retirada) = 0;
        int depositar(double cant_depositada) {
            if(cant_depositada<=0){
                cout<<"Error al depositar, la cantidad es 0 o negativa\n";
                return 1;
            }
            balance+=cant_depositada;
            return 0;
        };

};

class CajaDeAhorro : public Cuenta_Banco{
    private:
        int cant_veces_accedido; //esta variable la decidi poner en privado ya que le da mas privacidad al usuario
        friend class CuentaCorriente;
    public:
        CajaDeAhorro(double b, string t) : Cuenta_Banco(b,t), cant_veces_accedido(0) {};
        int retirar(double cant_retirada) override{
            if(cant_retirada<=0){
                cout<<"Error, la cantidad que se quiere retirar es negativa o 0\n";
                return 1;
            }
            if(cant_retirada>balance){
                cout<<"La cantidad retirada excede la cantidad en la caja de ahorro\n";
                return 1;
            }
            cout<<"Se ha retirado $"<<cant_retirada<<" de la caja de ahorro\n";
            balance-=cant_retirada;
            return 0;
        }
        void mostrarInfo() override{
            if(cant_veces_accedido>=2){
                cout<<"Se han superado las 2 muestras gratis de la informacion de la cuenta, se procedera a descontar $20\n";
                balance-=20;
            }
            cout<<"Titular cuenta: "<<titular_cuenta<<".\nBalance: $"<<balance<<".\n";
            cant_veces_accedido++;
        }
};

class CuentaCorriente : public Cuenta_Banco{
    private:
        CajaDeAhorro *cuenta_ahorro; //Es importante que el puntero a la cuenta de ahorro este en privado, para impedir que cualquier otra persona que no sea el usuario pueda acceder a su caja
    public:
        CuentaCorriente(double b, string t, CajaDeAhorro *ch) : Cuenta_Banco(b,t), cuenta_ahorro(ch) {};
        int retirar(double cant_retirada) override {
            if(cant_retirada<=0){
                cout<<"Error, la cantidad que se quiere retirar es negativa o 0\n";
                return 1;
            }
            if (cant_retirada>balance){
                cout<<"la cantidad ha retirar sobrepasa la cantidad en la cuenta corriente, se procedera a retirar la diferencia de la caja de ahorro\n";
                double diferencia=cant_retirada-balance;
                cout<<"Se ha retirado $"<<balance<<" de la cuenta corriente\n";
                balance=0;
                if(diferencia>cuenta_ahorro->balance){
                    cout<<"La cantidad ha retirar sobrepasa la cantidad en la caja de ahorro\n";
                    return 1;
                }
                cuenta_ahorro->retirar(diferencia);
                return 0;
            }
            cout<<"Se ha retirado $"<<cant_retirada<<" de la cuenta corriente\n";
            balance-=cant_retirada;
            return 0;
        }
        void mostrarInfo() override{
            cout<<"Titular cuenta: "<<titular_cuenta<<".\nBalance: $"<<balance<<".\n";
        }
};