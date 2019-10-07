#include <iostream>

#include "heder.h"

using namespace std;

int main() {
    return 0;
    /// объявляем переменные и присваиваем им значения.
    int nPerson = 6;
    int nCD = 15;
    int i;
    CDcollection lib = CDcollection(nPerson, nCD);


    lib.add("Abra", 0);
    lib.add("Iooio", 1);

    lib.print();
    // Abra : 0
    // Iooio: 1

    lib.transfer("Abra", 0, 1);
    lib.print();
    // Abra : 1
    // Iooio : 1

    lib.nameCD(1, 0);
    // "Abra"


    /// CDcollection lib(nPerson, nCD); тоже самое, что и в строке выше.
    /// тест
}