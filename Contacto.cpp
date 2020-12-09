//
// Created by Juanu on 28/11/2020.
//

#include "Contacto.h"
Contacto::Contacto():Persona() {

}

Contacto::Contacto(const string &name, const string &surname1, const string &surname2, const string &date,
                   const string &id, const string &address, const string &cp, const string &mobile,
                   const string &landLine) : Persona(name, surname1, surname2, date, id){

    this->address = address;
    this->cp = cp;
    this->mobile = mobile;
    this->landLine = landLine;



}

const string &Contacto::getAddress() const {
    return address;
}

const string &Contacto::getCp() const {
    return cp;
}

const string &Contacto::getMobile() const {
    return mobile;
}

const string &Contacto::getLandLine() const {
    return landLine;
}

void Contacto::setAddress(const string &address) {
    Contacto::address = address;
}

void Contacto::setCp(const string &cp) {
    Contacto::cp = cp;
}

void Contacto::setMobile(const string &mobile) {
    Contacto::mobile = mobile;
}

void Contacto::setLandLine(const string &landLine) {
    Contacto::landLine = landLine;
}



