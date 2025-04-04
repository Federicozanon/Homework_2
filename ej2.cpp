#include "ej2.hpp"

//#pragma once no funciona 

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
int Curso::inscribir_o_desenscribir(string inscri_o_desinscri, Estudiante* estudiante, int nota_final){
    if(inscri_o_desinscri=="inscribir"){
        if(int (Estudiantess.size())>=max_curso){
            cout<<"El curso esta lleno\n";
            return 1;
        }
        srand(time(0));
        
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
        cout<<"No se ha encontrado el alumno";
    }
    return 1;
}
string Curso::esta_inscripto(int legajo){
    for(long unsigned int i=0; i<Estudiantess.size();i++){
        if (Estudiantess[i]->retornar_legajo()==legajo){
            cout<<"El estudiante "<<Estudiantess[i]->retornar_nombre()<<" esta inscripto";
            return Estudiantess[i]->retornar_nombre();
        }
    }
    cout<<"No existe ningun estudiante en el curso con el legajo: "<<legajo;
    return "No se ha podido encontrar al estudiante";
}
void Curso::esta_completo(){
    if(Estudiantess.size()<20){
        cout<<"El curso no esta completo";
    }
    else{
        cout<<"El curso esta completo";
    }
}
bool comparar_nombres(Estudiante* primero, Estudiante* segundo){
    return primero->retornar_nombre()< segundo->retornar_nombre();
}

void Curso::imprimir_alumnos(){
    stable_sort(Estudiantess.begin(),Estudiantess.end(), comparar_nombres);
    cout<<"Lista estudiantes:\n";
    for(size_t i=0; i<Estudiantess.size();i++){
        cout<<i+1<<". "<<Estudiantess[i]->retornar_nombre()<<"\n";
    }
}
Curso::Curso(const Curso &original){
    //Para hacer la copia de un objeto curso uso shallow copy, ya que puedo tener varios estudiantes apuntando a varios cursos
    //Ademas, no necesito duplicar los estudiantes y si cambio los datos de un estudiante, se reflejara en todos sus cursos
    //Creo un nuevo Curso a partir de uno existente, le asigno max_curso y los punteros en Estudiantess
    max_curso=original.max_curso;
    for(size_t i=0; i<original.Estudiantess.size();i++){
        Estudiantess.push_back(original.Estudiantess[i]);
    }
}
Curso &Curso::asignacion_punteros(const Curso &original){
    //Asigno los punteros a un objeto Curso ya creado, por eso uso clear para limpiar datos existentes para copiar nuevos
    if(this!=&original){
        Estudiantess.clear();
        max_curso=original.max_curso;
        for(size_t i=0; i<original.Estudiantess.size();i++){
            Estudiantess.push_back(original.Estudiantess[i]);
        }
    }
    return *this;
}
int main(){
    //Caso inscribir al mismo estudiante?

    //Creamos los cursos
    Curso Fisica("Fisica");
    Curso Paradigmas("Paradigmas");
  
    //Creamos los estudiantes
    Estudiante est1("Jaimito Valderrama",36456);
    Estudiante est2("Richard Rios",36457);
    Estudiante est3("Bart simpsons",36458);
    Estudiante est4("Horacio larreta",36456);
    Estudiante est5("Donald Trump",36457);
    Estudiante est6("Lebron James",36458);
    Estudiante est7("Armancio Ortega",36456);
    Estudiante est8("Lautaro Martinez",36457);
    Estudiante est9("Carlos Slim",36458);

    cout<<"inscribimos los estudiantes en Fisica\n";
    Fisica.inscribir_o_desenscribir("inscribir",&est1, 6);
    Fisica.inscribir_o_desenscribir("inscribir",&est2, 9);
    Fisica.inscribir_o_desenscribir("inscribir",&est3, 2);
    Fisica.inscribir_o_desenscribir("inscribir",&est4, 4);
    Fisica.inscribir_o_desenscribir("inscribir",&est5, 8);
    Fisica.inscribir_o_desenscribir("inscribir",&est6, 7);
    Fisica.inscribir_o_desenscribir("inscribir",&est7, 10);
    Fisica.inscribir_o_desenscribir("inscribir",&est8, 3);
    Fisica.inscribir_o_desenscribir("inscribir",&est9, 5);
    Fisica.imprimir_alumnos();

    for(int i=0;i<int(Fisica.retornar_max_curso());i++){
        int n=i+1;
        string alumno= "est"+n;
        Estudiante alumno(alumno, n);
        Fisica.inscribir_o_desenscribir("inscribir",&alumno, n%11);
    }


    cout<<"inscribimos los estudiantes en Paradigmas\n";
    Paradigmas.inscribir_o_desenscribir("inscribir", &est3, 8);
    Paradigmas.imprimir_alumnos();
    
    cout<<"Probamos los metodos Estudiante\n";
    cout<<"Legajo estudiante "<<est3.retornar_nombre()<<": "<<est3.retornar_legajo()<<"\n";
    cout<<"Promedio estudiante "<<est3.retornar_nombre()<<": "<<est3.retornar_promedio()<<"\n";
    est3.imprimir_cursos_alumno();
    return 0;
}