#include <iostream>
#include <memory>
using namespace std;

class Cuenta_Banco{
    private:
        double balance;
        virtual void mostrarInfo() = 0;
        friend class CajaDeAhorro;
        friend class CuentaCorriente;
    protected:
        string titular_cuenta;
    public:
        Cuenta_Banco(double b, string t) : balance(b), titular_cuenta(t) {};
        virtual int retirar(double cant_retirada) = 0;

};

class CajaDeAhorro : public Cuenta_Banco{
    private:
        int cant_veces_accedido;
        friend class CuentaCorriente;
    public:
        CajaDeAhorro(double b, string t) : Cuenta_Banco(b,t), cant_veces_accedido(0) {};
        int retirar(double cant_retirada) override{
            if(cant_retirada>balance){
                cout<<"La cantidad retirada excede la cantidad en la caja de ahorro, se procedera a retirar todo el dinero\n";
                cout<<"Se ha retirado $"<<balance<<" de la caja de ahorro\n";
                balance=0;
                return 0;
            }
            cout<<"Se ha retirado $"<<cant_retirada<<" de la caja de ahorro\n";
            balance-=cant_retirada;
            return 0;
        }
        void mostrarInfo() override{
            if(cant_veces_accedido>2){
                cout<<"Se han superado las 2 muestras gratis de la informacion de la cuenta, se procedera a descontar $20";
                balance-=20;
            }
            cout<<"Titular cuenta: "<<titular_cuenta<<".\nBalance: "<<balance<<".\n";
            cant_veces_accedido++;
        }
};

class CuentaCorriente : public Cuenta_Banco{
    private:
        CajaDeAhorro *cuenta_ahorro;
    public:
        CuentaCorriente(double b, string t, CajaDeAhorro *ch) : Cuenta_Banco(b,t), cuenta_ahorro(ch) {};
        int retirar(double cant_retirada) override {
            if (cant_retirada>balance){
                cout<<"la cantidad ha retirar sobrepasa la cantidad en la cuenta corriente, se procedera a retirar la diferencia de la caja de ahorro\n";
                double diferencia=cant_retirada-balance;
                cout<<"Se ha retirado $"<<balance<<" de la cuenta corriente\n";
                balance=0;
                cuenta_ahorro->retirar(diferencia);
                if(cuenta_ahorro->balance=0){
                    cout<<"Se ha retirado todo el dinero en la cuenta, el balance total es 0";
                }
                return 0;
            }
            cout<<"Se ha retirado $"<<cant_retirada<<" de la cuenta corriente\n";
            balance-=cant_retirada;
            return 0;
        }
};