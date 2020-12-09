//
// Created by Juanu on 28/11/2020.
//

#ifndef AGENDALION_CONTACTO_H
#define AGENDALION_CONTACTO_H


#include "Persona.h"

class Contacto : public Persona {

private:
    string address;
    string cp;
    string mobile;
    string landLine;

public:
    //constructor
    Contacto();

    void setAddress(const string &address);

    void setCp(const string &cp);

    void setMobile(const string &mobile);

    void setLandLine(const string &landLine);

    Contacto(const string &name, const string &surname1, const string &surname2, const string &date, const string &id,
             const string &address, const string &cp, const string &mobile, const string &landLine);

    const string &getAddress() const;

    const string &getCp() const;

    const string &getMobile() const;

    const string &getLandLine() const;

};


#endif //AGENDALION_CONTACTO_H
