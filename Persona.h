//
// Created by Juanu on 28/11/2020.
//

#ifndef AGENDALION_PERSONA_H
#define AGENDALION_PERSONA_H


#include <string>
#include <iostream>

using namespace std;

class Persona
{
    //atributos
private:
    string name;
    string surname1;
    string surname2;
    string date;
    string id;

public:
    Persona();
    Persona(string name, string surname1, string surname2, string date, string id);
    ~Persona();

    //getters

    const string &getName() const;
    const string &getSurname1() const;
    const string &getSurname2() const;
    const string &getDate() const;
    const string &getId() const;
    void save();
    void load();


    //operadores sobrecargados
    friend bool operator>(Persona const& c1, Persona const& c2);
    friend bool operator<(Persona const& c1, Persona const& c2);
    friend bool operator>=(Persona const& c1, Persona const& c2);
    friend bool operator<=(Persona const& c1, Persona const& c2);

    friend ostream& operator << (ostream &os, Persona &persona);

    friend bool operator==(Persona &p1, Persona &p2);
    friend bool operator!=(Persona& p1, Persona& p2);
    //faltan los de entrada y salida << >>


};


#endif //AGENDALION_PERSONA_H
