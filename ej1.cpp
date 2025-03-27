#include "ej1.hpp"

int funcion_variable_tiempo(string tiempo, int acote1, int acote2){
    int n;
    cout<<"Ingrese los datos del tiempo en "<<tiempo<<"\n";
    cin>>n;
    while(acote1>n || acote2<n){
        cout<<"Ingrese una valor en "<<tiempo<<" correcto\n";
        cin>>n;
    }
    return n;
}
string funcion_variable_tiempo(){
    int am_o_pm;
    cout<<"Escriba 1 si quiere elegir a.m, escriba 2 si quiere elegir p.m\n";
    cin>>am_o_pm;
    while(am_o_pm!=1 && am_o_pm!=2){
        cout<<"Elija una opcion correcta\n";
        cin>>am_o_pm;
    }
    if(am_o_pm==1){
        return "a.m.";
    }
    if(am_o_pm==2){
        return "p.m.";
    }
    return "a.m.";
}
int funcion_variable_tiempo(int horas, string am_o_pm){
    if(am_o_pm=="a.m."){
        if(horas==12){
            return 0;
        }
        return horas;
    }
    if(am_o_pm=="p.m." && horas==12){
        return horas;
    }
    return horas+12;
}
int funcion_tiempo(){
    int HH=0;
    int MM=0;
    int SS=0;
    string am_o_pm="a.m.";
    int n;
    cout<<"Bienvenido, eliga por favor la forma en la que desea expresar el tiempo:\n";
    cout<<"1) Sin parametros\n2) Solo hora\n3) Solo hora y minuto\n4) Solo hora, minuto y segundo\n5) Expresion completa\n";
    cin>>n;
    while (n<1 || n>5){
        cout<<"ingrese una opcion correcta\n";
        cin>>n;
    }
    if(n>=2){
        HH=funcion_variable_tiempo("horas", 0, 12);
        if(n>=3){
            MM=funcion_variable_tiempo("minutos", 0, 59);
            if(n>=4){
                SS=funcion_variable_tiempo("segundos", 0, 59);
                if(n==5){
                    am_o_pm=funcion_variable_tiempo();
                }
            }
        }
    }
    int m;
    cout<<"Elija si quiere cambiar algun dato, leer el tiempo completo o de forma individual o terminar el programa\n";
    cout<<"1) Cambiar hora\n2) Cambiar minutos\n3) Cambiar segundos\n4) Cambiar meridiem\n5) Leer solo hora\n6) Leer solo los minutos\n7) Leer solo los segundos\n8) Leer solo a.m/p.m\n9) Leer tiempo completo en formato a.m/p.m\n10) Leer tiempo completo en formato 24h\n11) Salir del programa\n";
    cin>>m;
    while(m<12 || m>0){
        if(m==1){
            HH=funcion_variable_tiempo("horas", 0, 12);
        }
        if(m==2){
            MM=funcion_variable_tiempo("minutos", 0, 59);
        }
        if(m==3){
            SS=funcion_variable_tiempo("segundos", 0, 59);
        }
        if(m==4){
            am_o_pm=funcion_variable_tiempo();
        }
        if (m==5){
            cout<<"El tiempo en horas: "<<setfill('0')<<setw(2)<<HH<<"h\n";
        }
        if(m==6){
            cout<<"El tiempo en minutos: "<<setfill('0')<<setw(2)<<MM<<"m\n";
        }
        if(m==7){
            cout<<"El tiempo en segundos: "<<setfill('0')<<setw(2)<<SS<<"s\n";
        }
        if(m==8){
            cout<<"El tiempo en a.m/p.m: "<<am_o_pm<<"\n";
        }
        if(m==9){
           cout<<"Tiempo completo en a.m/p.m: "<<setfill('0')<<setw(2)<<HH<<"h, "<<setfill('0')<<setw(2)<<MM<<"m, "<<setfill('0')<<setw(2)<<SS<<"s "<<am_o_pm<<"\n";
        }
        if(m==10){
           cout<<"Tiempo completo en formato 24h: "<<setfill('0')<<setw(2)<<funcion_variable_tiempo(HH, am_o_pm)<<"h, "<<setfill('0')<<setw(2)<<MM<<"m, "<<setfill('0')<<setw(2)<<SS<<"s\n";
        }
        if(m==11){
            return 0;
        }
        if(m<1 || m>11){
            cout<<"Ingrese una opcion correcta\n";
        }
        cout<<"1) Cambiar hora\n2) Cambiar minutos\n3) Cambiar segundos\n4) Cambiar meridiem\n5) Leer solo hora\n6) Leer solo los minutos\n7) Leer solo los segundos\n8) Leer solo a.m/p.m\n9) Leer tiempo completo en formato a.m/p.m\n10) Leer tiempo completo en formato 24h\n11) Salir del programa\n";
        cin>>m;
    }
    return 0;
}
int main(){
    funcion_tiempo();
    return 0;
}