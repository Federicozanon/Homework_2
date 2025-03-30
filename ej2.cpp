#include "ej2.hpp"
//#pragma once no funciona 

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
int Curso::inscribir_o_desenscribir(string inscri_o_desinscri, Estudiante* estudiante){
    if(inscri_o_desinscri=="inscribir"){
        if(int (Estudiantess.size())>=max_curso){
            cout<<"El curso esta lleno\n";
            return 1;
        }
        Estudiantess.push_back(estudiante);
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
int Curso::esta_inscripto(int legajo){
    for(long unsigned int i=0; i<Estudiantess.size();i++){
        if (Estudiantess[i]->retornar_legajo()==legajo){
            cout<<"El estudiante "<<Estudiantess[i]->retornar_nombre()<<" esta inscripto";
            return 0;
        }
    }
    cout<<"No existe ningun estudiante en el curso con el legajo: "<<legajo;
    return 1;
}
void Curso::esta_completo(){
    if(Estudiantess.size()<=20){
        cout<<"El curso no esta completo";
    }
    else{
        cout<<"El curso esta completo";
    }
}
void Curso::imprimir_alumnos(){
    stable_sort(Estudiantess.begin(),Estudiantess.end());
    cout<<"Lista estudiantes:\n";
    for(long unsigned int i=0; i<Estudiantess.size();i++){
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