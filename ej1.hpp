using namespace std;
#include <iomanip>
#include <iostream>
#include <string>

class Tiempo{
    private:
        int HH;
        int MM;
        int SS;
        string am_o_pm;
    public:
        Tiempo();
        int funcion_variable_tiempo(string tiempo, int acote1, int acote2);
        string funcion_variable_tiempo();
        int funcion_variable_tiempo(int horas, string am_o_pm);
        int funcion_tiempo();
};