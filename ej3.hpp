#include <iostream>
#include <memory>
#include <string>
#include <cmath>
using namespace std;

class Numero{
    public:
        virtual unique_ptr<Numero> suma(Numero& y) = 0;
        virtual unique_ptr<Numero> resta(Numero& y) = 0;
        virtual unique_ptr<Numero> multiplicacion(Numero& y) = 0;
        virtual unique_ptr<Numero> division(Numero& y) = 0;
        virtual string a_string() = 0; 
};
class Entero : public Numero{
    private:
        int num;
    public:
        Entero(int x) : num(x) {};
        unique_ptr<Numero> suma(Numero& y) override{
            Entero& num2=dynamic_cast<Entero&>(y);
            int n=num+num2.num;
            return make_unique<Entero>(n);
        }
        unique_ptr<Numero> resta(Numero& y) override{
            Entero& num2=dynamic_cast<Entero&>(y);
            int n=num-num2.num;
            return make_unique<Entero>(n);
        }
        unique_ptr<Numero> multiplicacion(Numero& y) override{
            Entero& num2=dynamic_cast<Entero&>(y);
            int n=num*num2.num;
            return make_unique<Entero>(n);
        }
        unique_ptr<Numero> division(Numero& y) override{
            Entero& num2=dynamic_cast<Entero&>(y);
            if(num2.num==0){
                cout<<"Error al dividir por cero, retornando valor 0\n";
                return make_unique<Entero>(0);
            }
            int n=num/num2.num;
            return make_unique<Entero>(n);
        }
        string a_string() override{
           return to_string(num);
        }
        ~Entero() {};
};
class Real : public Numero{
    private:
        double num;
    public:
        Real(double x) : num(x) {};
        unique_ptr<Numero> suma(Numero& y) override{
            Real& num2=dynamic_cast<Real&>(y);
            double n=num+num2.num;
            return make_unique<Real>(n);
        }
        unique_ptr<Numero> resta(Numero& y) override{
            Real& num2=dynamic_cast<Real&>(y);
            double n=num-num2.num;
            return make_unique<Real>(n);
        }
        unique_ptr<Numero> multiplicacion(Numero& y) override{
            Real& num2=dynamic_cast<Real&>(y);
            double n=num*num2.num;
            return make_unique<Real>(n);
        }
        unique_ptr<Numero> division(Numero& y) override{
            Real& num2=dynamic_cast<Real&>(y);
            if(num2.num==0){
                cout<<"Error al dividir por cero, retornando valor 0\n";
                return make_unique<Real>(0);
            }
            double n=num/num2.num;
            return make_unique<Real>(n);
        }
        string a_string() override{
           return to_string(num);
        }
        ~Real() {};
};
class Complejo : public Numero{
    private:
        double parte_real;
        double parte_imaginaria;
    public:
        Complejo(double r, double i) : parte_real(r), parte_imaginaria(i) {};
        unique_ptr<Numero> suma(Numero& y) override{
            Complejo& num2 = dynamic_cast<Complejo&>(y);
            double p_real = parte_real+num2.parte_real;
            double p_img = parte_imaginaria+num2.parte_imaginaria;
            return make_unique<Complejo>(p_real,p_img);
        }
        unique_ptr<Numero> resta(Numero& y) override{
            Complejo& num2 = dynamic_cast<Complejo&>(y);
            double p_real = parte_real-num2.parte_real;
            double p_img = parte_imaginaria-num2.parte_imaginaria;
            return make_unique<Complejo>(p_real,p_img);
        }
        unique_ptr<Numero> multiplicacion(Numero& y) override {
            Complejo& num2 = dynamic_cast<Complejo&>(y);
            double p_real = parte_real*num2.parte_real -parte_imaginaria*num2.parte_imaginaria;
            double p_img = parte_real*num2.parte_imaginaria+parte_imaginaria*num2.parte_real;
            return make_unique<Complejo>(p_real, p_img);
        }
        unique_ptr<Numero> division(Numero& y) override {
            Complejo& num2 = dynamic_cast<Complejo&>(y);
            if(num2.parte_real==0 && num2.parte_imaginaria==0){
                cout<<"Error al dividir por cero, retornando 0\n";
                return make_unique<Complejo>(0,0);
            }
            double p_real = (parte_real*num2.parte_real + parte_imaginaria*num2.parte_imaginaria)/(pow(num2.parte_real,2)+pow(num2.parte_imaginaria,2));
            double p_img = (parte_imaginaria*num2.parte_real-parte_real*num2.parte_imaginaria)/(pow(num2.parte_real,2)+pow(num2.parte_imaginaria,2));
            return make_unique<Complejo>(p_real, p_img);
        }
        string a_string() override {
            if(parte_imaginaria<0){
                return to_string(parte_real)+" "+to_string(parte_imaginaria)+"i";
            }
            return to_string(parte_real)+" + "+to_string(parte_imaginaria)+"i";
        }
        ~Complejo() {};
};
