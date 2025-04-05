#include "ej2.hpp"

void Estudiante::imprimir_cursos_alumno() const{
    cout<<"Cursos con sus notas de "<<nombre_completo<<"\n";
    for(size_t i=0; i<lista_cursos_y_notas.size();i++){
        cout<<i+1<<". "<<lista_cursos_y_notas[i].curso<<". Nota: "<<lista_cursos_y_notas[i].nota<<"\n";
    }
}
double Estudiante::retornar_promedio() const{
    if(lista_cursos_y_notas.size()==0){
        return 0;
    }
    double n=0;
    double tam=lista_cursos_y_notas.size();
    for (size_t i=0; i<tam;i++){
        n+=lista_cursos_y_notas[i].nota;
    }
    return n/tam;
}
int Curso::inscribir_o_desenscribir(string inscri_o_desinscri, shared_ptr<Estudiante> estudiante, int nota_final){
    if(inscri_o_desinscri=="inscribir"){
        if(int (Estudiantess.size())>=max_curso){
            cout<<"El curso esta lleno, no se puede inscribir ningun alumno mas\n";
            return 1;
        }
        Estudiantess.push_back(estudiante);
        estudiante->agregar_curso_con_nota(nombre_curso, nota_final);
        return 0;
    }
    if(inscri_o_desinscri=="desinscribir"){
        if(Estudiantess.size()==0){
            cout<<"El curso esta vacio\n";
            return 1;
        }
        for(long unsigned int i=0; i<Estudiantess.size();i++){
            if(Estudiantess[i]->retornar_nombre()==estudiante->retornar_nombre()){
                Estudiantess.erase(Estudiantess.begin()+i);
                return 0;
            }
        }
        cout<<"No se ha encontrado el alumno "<<estudiante->retornar_nombre()<<"\n";
    }
    return 1;
}
string Curso::esta_inscripto(int legajo){
    for(long unsigned int i=0; i<Estudiantess.size();i++){
        if (Estudiantess[i]->retornar_legajo()==legajo){
            cout<<"El estudiante "<<Estudiantess[i]->retornar_nombre()<<" esta inscripto\n";
            return Estudiantess[i]->retornar_nombre();
        }
    }
    cout<<"No existe ningun estudiante en el curso con el legajo: "<<legajo<<"\n";
    return "No se ha podido encontrar al estudiante\n";
}
void Curso::esta_completo(){
    if(Estudiantess.size()<20){
        cout<<"El curso no esta completo\n";
    }
    else{
        cout<<"El curso esta completo\n";
    }
}
bool comparar_nombres(shared_ptr<Estudiante> primero, shared_ptr<Estudiante> segundo){
    return primero->retornar_nombre()< segundo->retornar_nombre();
}
void Curso::imprimir_alumnos(){
    stable_sort(Estudiantess.begin(),Estudiantess.end(), comparar_nombres);
    cout<<"Lista estudiantes:\n";
    for(size_t i=0; i<Estudiantess.size();i++){
        cout<<i+1<<". "<<Estudiantess[i]->retornar_nombre()<<"\n";
    }
}
int main(){
    cout<<"Creamos el curso de Fisica\n";
    Curso Fisica("Fisica");
    Fisica.imprimir_alumnos();
    cout<<"Creamos el curso de Paradigmas\n";
    Curso Paradigmas("Paradigmas");
    Paradigmas.imprimir_alumnos();
    
    vector<shared_ptr<Estudiante>> nuevos_estudiantes;
    cout<<"Chequeamos si el curso de Fisica esta completo\n";
    Fisica.esta_completo();
    cout<<"Creamos 20 estudiantes con puntero a nuevos_estudiantes, y los inscribimos en Fisica\n";
    for(int i=1; i<=int(Fisica.retornar_max_curso()); i++){
        /*NOTA: al crear a nuestros estudiantes con un est+i, siendo i un numero del 1 al 20,
        el ordenamiento no lo hace completamente bien ya que hay numeros de por medio, pero si se prueba con nombres de solo letras
        el ordenamiento lexicografico lo hace perfecto. En este caso pense usar este ciclo for para crear los estudiantes de esta forma
        para evitar tener que crearlos uno por uno. 
        */
        string alumno= "est"+to_string(i);
        auto e = make_shared<Estudiante>(alumno, i);
        nuevos_estudiantes.push_back(e);
        Fisica.inscribir_o_desenscribir("inscribir", e, i%11);
    }
    cout<<"Nos fijamos devuelta si el curso de Fisica esta completo\n";
    Fisica.esta_completo();
    auto estudiante_de_mas= make_shared<Estudiante>("Fede Zanon", 20050);
    cout<<"Intentamos inscribir un alumno a un curso lleno\n";
    Fisica.inscribir_o_desenscribir("inscribir", estudiante_de_mas, 10);


    cout<<"Imprimimos los alumnos en Fisica\n";
    Fisica.imprimir_alumnos();

    cout<<"Buscamos por legajo a un alumno\n";
    Fisica.esta_inscripto(4);
    Fisica.esta_inscripto(9999);

    cout<<"desinscribimos a est6\n";
    Fisica.inscribir_o_desenscribir("desinscribir", nuevos_estudiantes[5], 0);
    Fisica.imprimir_alumnos();
    cout<<"Desinscribimos a un alumno que no esta en el curso\n";
    Fisica.inscribir_o_desenscribir("desinscribir", estudiante_de_mas, 0);

    cout<<"Inscribimos estudiantes en Paradigmas\n";
    Paradigmas.inscribir_o_desenscribir("inscribir", nuevos_estudiantes[1],7);    
    Paradigmas.inscribir_o_desenscribir("inscribir", nuevos_estudiantes[2],6);
    Paradigmas.inscribir_o_desenscribir("inscribir", nuevos_estudiantes[3],7);

    cout<<"Probamos los metodos de Estudiante para un estudiante en 2 cursos\n";
    nuevos_estudiantes[1]->imprimir_cursos_alumno();
    cout << "Legajo de " << nuevos_estudiantes[1]->retornar_nombre() << ": " << nuevos_estudiantes[1]->retornar_legajo() << "\n";
    cout << "Promedio de " << nuevos_estudiantes[1]->retornar_nombre() << ": " << nuevos_estudiantes[1]->retornar_promedio() << "\n";

    cout<<"Probamos la funcion para copiar cursos (shallow copy)\n";
    Curso CopiaParadigmas(Paradigmas);
    CopiaParadigmas.imprimir_alumnos();
    
    return 0;
}