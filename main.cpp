/*******************************************/
/**		Juan Victor González Mársico      **/
/**               HLC c++                 **/
/**             08-12-2020                **/
/*******************************************/
/**                Agenda                 **/
/*******************************************/

#include <iostream>
#include <fstream>
#include "Btree.h"

using namespace std;

int main() {
    Btree agenda;
    int opcion;
    string name, surname1, surname2, birthday, id, address, cp, mobile, landLine, basu;
    Contacto *temp;
    ofstream file_out;
    ifstream filein;

    cout << "\nBienvenidos a la Agenda (Ahora en c++! yiujuuu)" << endl;

    do {
        cout << "Introduce una opcion:\n";
        cout << "\t1- Anadir Contacto\n";
        cout << "\t2- Eliminar Contacto\n";
        cout << "\t3- Listar Contactos \n";
        cout << "\t4- Consultar Contacto\n";
        cout << "\t5- Editar Contacto\n";
        cout << "\t6- ?Cuantos Contactos? \n";
        cout << "\t7- Guardar\n";
        cout << "\t8- Cargar\n";
        cout << "\t9- Cargar el arbol para pruebas\n";
        cout << "\t10- Salir\n";

        cin >> opcion;

        if (opcion < 1 || opcion > 10){
            cout << "opcion fuera de rango";
            continue;
        }else{

            switch (opcion) {

                case 1:
                    cout << "Introduce el nombre del contacto" << endl;
                    cin >> name;

                    cout << "Introduce el primer apellido\n";
                    cin >> surname1;

                    cout << "Introduce el segundo apellido \n";
                    cin >> surname2;

                    cout << "Introduce la fecha de nacimiento (dd/mm/aa)\n";
                    cin >> birthday;

                    cout << "Introduce el DNI\n";
                    cin >> id;

                    cout << "Introduce la direccion\n";
                    cin >> address;

                    //aqui se me llena el buffer de mierda y no se por que
                    cin.clear();
                    fflush(stdin);


                    cout << "Introduce el codigo postal\n";
                    cin >> cp;

                    cout << "Introduce el numero de movil\n";
                    cin >> mobile;

                    //aqui se me llena el buffer de mierda y no se por que
                    cin.clear();
                    fflush(stdin);

                    cout << "Introduce el numero fijo\n";
                    cin >> landLine;

                    temp = new Contacto(name, surname1,surname2, birthday, id, address, cp, mobile, landLine);
                    agenda.insert(*temp);
                    break;
                case 2:
                    cout << "introduce el DNI el contacto a eliminar\n";
                    cin >> id;
                    agenda.delete_node( agenda.search_by_id(id) );
                    break;
                case 3:
                    agenda.print();
                    break;
                case 4:
                    cout << "introduce el DNI el contacto a buscar\n";
                    cin >> id;
                    cout << *agenda.search_by_id(id);
                    break;
                case 5:
                    cout << "introduce el DNI el contacto a editar\n";
                    cin >> id;

                    //aqui se me llena el buffer de mierda y no se por que
                    cin.clear();
                    fflush(stdin);

                    cout << "introduce la nueva direccion:\n";
                    cin >> address;

                    //aqui se me llena el buffer de mierda y no se por que
                    cin.clear();
                    fflush(stdin);

                    cout << "introduce el nuevo CP\n";
                    cin >> cp;

                    //aqui se me llena el buffer de mierda y no se por que
                    cin.clear();
                    fflush(stdin);

                    cout << "Introduce el nuevo movil\n";
                    cin >> mobile;

                    //aqui se me llena el buffer de mierda y no se por que
                    cin.clear();
                    fflush(stdin);

                    cout << "Introduce el nuevo fijo\n";
                    cin >> landLine;

                    //aqui se me llena el buffer de mierda y no se por que
                    cin.clear();
                    fflush(stdin);

                    temp = agenda.search_by_id(id);
                    temp->setAddress(address);
                    temp->setCp(cp);
                    temp->setMobile(mobile);
                    temp->setLandLine(landLine);
                    break;
                case 6:
                    cout << "Dentro de la agenda tenemos " << agenda.count() << " contactos\n";
                    break;
                case 7:
                    //TODO
                case 8:
                    //TODO

                    break;
                case 9:
                    Contacto a("Juan", "gonzalez","Sergio", "26/10/84", "21241392R", "Calle jorobado", "29220", "654654564", "666666666");
                    agenda.insert(a);
                    Contacto b("Victor", "gonzalez","Bini", "16/12/52", "26543412R", "Benalmadena", "29045", "654564654", "666666666");
                    agenda.insert(b);
                    Contacto c("Ali", "Sergio","Forcinitti", "24/11/53", "54214892A", "Calle flores", "29111", "681116207", "666666666");
                    agenda.insert(c);
                    Contacto d("Carmen", "Falcon","Ramirez", "25/06/81", "26801761E", "Calle jorobado", "29120", "627123635", "666666666");
                    agenda.insert(d);
                    Contacto e("Pole", "Blanco","Amarillo", "26/10/04", "564654a", "Calle asd", "29120", "691207744", "666666666");
                    agenda.insert(e);
                    Contacto f("menta", "Manta","Bini", "16/12/52", "gdasg5", "Benalmadena", "29045", "654564654", "666666666");
                    agenda.insert(f);
                    Contacto g("Mate", "Matematicas","Forcinitti", "24/11/53", "asda2", "Calle flores", "29111", "644486207", "666666666");
                    agenda.insert(g);
                    Contacto h("Duna", "Fara","Ramirez", "25/06/81", "qwrqwqwr0", "Calle jorobado", "29120", "621222225", "666666666");
                    agenda.insert(h);
                    break;




            }


        }


    }while (opcion != 10);


    return 0;
}

