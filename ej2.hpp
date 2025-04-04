using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//La relacion entre estas clases puede ser de agregación

struct Notacurso{ //como puedo usar using?
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
        void imprimir_cursos_alumno() const;
        double retornar_promedio() const;
        void agregar_curso_con_nota(const string &curso, int nota){
            lista_cursos_y_notas.push_back(Notacurso{curso, nota});
        }
};
class Curso {
    private:
        string nombre_curso;
        vector<Estudiante*> Estudiantess;
        int max_curso=20;
    public:
        int retornar_max_curso(){
            return max_curso;
        }
        Curso(string nombre) : nombre_curso(nombre) {};
        Curso(const Curso &original);
        Curso &asignacion_punteros(const Curso &original);

        int inscribir_o_desenscribir(string inscri_o_desinscri, Estudiante* estudiante, int nota_final);
        string esta_inscripto(int legajo);
        void esta_completo();
        void imprimir_alumnos();
};