#include <iostream>

#include "heder.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    /// объявляем переменные и присваиваем им значения.
    int nPerson = 6;
    int nCD = 15;
    int i;
    CDcollection *lib = new CDcollection(nPerson, nCD);
    /// CDcollection lib(nPerson, nCD); тоже самое, что и в строке выше.
  /*  char m = 'A';
    char *z;
    z = &m;
    cout << *z << endl;
*/
    (*lib).add("Abra", 0);
   // lib.add('I', 1);

    (*lib).print();
    // Abra : 0
    // Iooio: 1

 //   lib.transfer("Abra", 0, 1);
 //   lib.print();
    // Abra : 1
    // Iooio : 1

  //  lib.nameCD(1, 0);
    // "Abra"
    delete lib;

    return 0;
}