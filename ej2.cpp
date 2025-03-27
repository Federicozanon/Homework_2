using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm> //para usar en el ej b) iv

//#pragma once para el hpp
//USAR USING EN VEZ DE TYPEDEF

//La relacion entre estas clases puede ser de agregación
class Estudiante{
    private:
        string nombre_completo;
        int legajo;
        map <string, int> lista_cursos_y_notas;//CAMBIAR MAP
        Estudiante(string nombre, int legajo): nombre_completo(nombre), legajo(legajo), lista_cursos_y_notas(){}
    public:
        
};
class Curso {
    private:
        vector<Estudiante*> Estudiantess;
        int max_curso=20;
    public:
        string retornar_nombre(int orden_de_inscripcion){
            return Estudiantess[orden_de_inscripcion]->nombre_completo;
        }
        int retornar_legajo(string nombre){

        }
};