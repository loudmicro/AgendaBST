//
// Created by Juanu on 28/11/2020.
//

#include <fstream>
#include "Persona.h"

Persona::Persona() {
    this->name = "";
    this->surname1 = "";
    this->surname2 = "";
    this->date = "";
    this->id = "";
}

Persona::Persona(string name, string surname1, string surname2, string date, string id) {
    this->name = name;
    this->surname1 = surname1;
    this->surname2 = surname2;
    this->date = date;
    this->id = id;
}

Persona::~Persona() {

}

const string &Persona::getName() const {
    return name;
}

const string &Persona::getSurname1() const {
    return surname1;
}

const string &Persona::getSurname2() const {
    return surname2;
}

const string &Persona::getDate() const {
    return date;
}

const string &Persona::getId() const {
    return id;
}

bool operator==(Persona &p1, Persona &p2){

    return p1.getId() == p2.getId();
}
bool operator!=(Persona &p1, Persona &p2){

    return p1.getId() != p2.getId();
}

bool operator>(Persona const& c1, Persona const& c2){
    return c1.id > c2.id;
}
bool operator>=(Persona const& c1, Persona const& c2){
    return c1.id >= c2.id;
}

bool operator<(Persona const& c1, Persona const& c2){
    return c1.id < c2.id;
}
bool operator<=(Persona const& c1, Persona const& c2){
    return c1.id <= c2.id;
}

ostream& operator << (ostream &os, Persona &persona){
    os << "\t- " <<  persona.name << " " << persona.surname1 << " " << persona.surname2 << ", DNI: " << persona.id;

    return os;
}
// "serializacion" ¿ ? lo dejo aqui pero creo que mejor implementarlo en el arbol binario la carga y guardado general, no le veo sentido en guardarlo uno a uno
void Persona::save() {

    ofstream file_obj;
    file_obj.open("data.ag", ios::app); //app coloca el puntero al final del fichero antes de escribir

    Persona obj = *this;

    file_obj.write((char *)&obj, sizeof(obj) );

}

void Persona::load() {

    ifstream file_obj;
    Persona obj;
    //abrimos el fichero
    file_obj.open("data.ag", ios::in);
    //le pasamos el contenido a obj
    file_obj.read((char*)&obj,sizeof(obj));

}





