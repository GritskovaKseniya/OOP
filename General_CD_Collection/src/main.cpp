#include <iostream>

#include "CDcollection.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    /// объявляем переменные и присваиваем им значения.
    int nPerson = 6;
    int nCD = 15;
    int i;
    CDcollection lib(nPerson, nCD);
    /// CDcollection lib(nPerson, nCD); тоже самое, что и в строке выше.

    lib.add("Abra", 0);
    lib.add("Iooio", 1);
    lib.add("lala", 1);

    //lib.nameCD(1, 1);
    //lib.print();
    // Abra : 0
    // Iooio: 1

    lib.amount(1);
    //lib.where ("Abra");
    //lib.transfer("Abra", 0, 2);
    //lib.print();
    //lib.where ("Abra");
    //lib.print();
    // Abra : 1
    // Iooio : 1

    
    // "Abra"

    return 0;
}