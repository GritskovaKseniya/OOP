#include "CDcollection.h"
#include <iostream>
#include <cstring>

using namespace std;

CDcollection::CDcollection(int nPerson, int nCD){
    this->idPerson = idPerson;
    this->CDname = CDname;
    disk_name = new char*[nCD]; /// Массив имен дисков. (размер = количество дисков) Заполняется постепенно, изначально пуст.
    disk_owner = new int[nCD]; /// Массив владельцев дисков. (размер = количество дисков) 

    /// Заполняем массивы (наличие владельца у диска, наличие имени)
    for(int i = 0; i < nCD; ++i){
        disk_owner[i] = -1; /// Диск никому не принадлежит.
        disk_name[i] = 0;
    }
}

CDcollection::~CDcollection(){
    delete[] disk_name;
    delete[] disk_owner;
}

/*
перегрузка функции
CDcollection::CDcollection(){
}
*/

