#include <iostream>

#include "CDcollection.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    /// объявляем переменные и присваиваем им значения.
    /*int nPerson = 6;
    int nCD = 15;
    CDcollection lib(nPerson, nCD);*/
    CDcollection lib;

    lib.add("Abra", 15); 
    lib.add("Iooio", 1);
    lib.add("lala", 1);
    lib.add("CDA", 2);
    lib.add("MRA", 3);
    lib.print();
    char* name = lib.nameCD(1, 0);
    if(name != 0){
        cout << "Owner " << 1 << " have " << name << " disk.\n";
        cout << " " << endl;
    }else cout << " There is no such disk. \n";
    int number = lib.amount(8);
    if(number > 0){
        cout << "Owner " << 1 << " have " << number << " disks.\n";
        cout << " " << endl;
    }else if (number = 0){
        cout << "Owner " << 1 << " have " << number << " disk.\n";
        cout << " " << endl;
    }else cout << "There is no such owner. \n";
    int owner = lib.where ("MRaa");
    if(owner != -1){
        cout << "Disk " << " MRA " << " depends owner " << owner << endl;
        cout << " " << endl;
    }else cout << "There is no such disk. \n";
    lib.transfer("MRA", 1);
    lib.print();
    return 0;
}