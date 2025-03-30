using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

//La relacion entre estas clases puede ser de agregación

using Notacurso=struct{
    string curso;
    int nota;
};
class Estudiante{
    private:
        string nombre_completo;
        int legajo;
        vector<Notacurso>lista_cursos_y_notas;
    public:
        Estudiante(string nombre, int legajo): nombre_completo(nombre), legajo(legajo), lista_cursos_y_notas(){}
        string retornar_nombre(){
            return nombre_completo;
        }
        int retornar_legajo(){
            return legajo;
        }
        vector<Notacurso> retornar_cursos_y_notas() const{
            return lista_cursos_y_notas;
        }
        double retornar_promedio() const;
};
class Curso {
    private:
        vector<Estudiante*> Estudiantess;
        int max_curso=20;
    public:
        Curso() = default;
        Curso(const Curso &original);
        Curso &asignacion_punteros(const Curso &original);

        int inscribir_o_desenscribir(string inscri_o_desinscri, Estudiante* estudiante);
        int esta_inscripto(int legajo);
        void esta_completo();
        void imprimir_alumnos();
};