using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

struct Notacurso{ 
    string curso;
    int nota;
};
/*La relacion entre Estudiantes y Curso es de agregacion, ya que Curso solo usa a los objetos Estudiantes
pero no los crea ni los destruye, y ademas al eliminar Curso, los estudiantes no desaparecen
*/
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
        vector<shared_ptr<Estudiante>> Estudiantess;
        int max_curso=20;
        void copiar(Curso &original){
            max_curso=original.max_curso; //deep copy de max_curso
            nombre_curso=original.nombre_curso; //deep copy de nombre_curso
            Estudiantess=original.Estudiantess; //shallow copy, estoy copiando los punteros a los objetos estudiantes
        }
    public:
        int retornar_max_curso(){
            return max_curso;
        }
        Curso(string nombre) : nombre_curso(nombre) {};
        Curso( Curso&original){
            copiar(original);
        }
        int inscribir_o_desenscribir(string inscri_o_desinscri, shared_ptr<Estudiante> estudiante, int nota_final);
        string esta_inscripto(int legajo);
        void esta_completo();
        void imprimir_alumnos();
};