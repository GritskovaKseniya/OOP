#include "CDcollection.h"
#include <iostream>
#include <cstring>

using namespace std;

/*CDcollection::CDcollection(int nPerson, int nCD){
   /* this->nPerson = nPerson;
    this->nCD = nCD;
    disk_name = new char*[nCD]; /// Массив имен дисков. (размер = количество дисков) Заполняется постепенно, изначально пуст.
    disk_owner = new int[nCD]; /// Массив владельцев дисков. (размер = количество дисков) 
    /// Заполняем массивы (наличие владельца у диска, наличие имени)
    for(int i = 0; i < nCD; ++i){
        disk_owner[i] = -1; /// Диск никому не принадлежит.
        disk_name[i] = 0; /// У диска нет имени.
    }
    initialize(nPerson, nCD);
}*/

void CDcollection::initialize(int nPerson, int nCD){
    this->nPerson = nPerson;
    this->nCD = nCD;
    disk_name = new char*[nCD]; /// Массив имен дисков. (размер = количество дисков) Заполняется постепенно, изначально пуст.
    disk_owner = new int[nCD]; /// Массив владельцев дисков. (размер = количество дисков) 
    /// Заполняем массивы (наличие владельца у диска, наличие имени)
    for(int i = 0; i < nCD; ++i){
        disk_owner[i] = -1; /// Диск никому не принадлежит.
        disk_name[i] = 0; /// У диска нет имени.
    }
}

CDcollection::~CDcollection(){
    delete[] disk_name;
    delete[] disk_owner;
}

void CDcollection::add(char *CDname, int idPerson){
    bool exists = exists_name (CDname);
    if(exists == false){
        if((idPerson < nPerson)&&(idPerson >= 0)){ /// Если номер владельца больше или равен нулю и меньше колчества владельцев
            for(int i = 0; i < nCD; ++i){
                if(disk_owner[i] == -1){ /// Если диск никому не принадлежит.
                    disk_owner[i] = idPerson; /// Записываем владельца в свободную ячейку массива.
                    disk_name[i] = CDname; /// Записываем имя диска в свободную ячейку массива.
                    break;
                }
            } 
        }else cerr << "Incorrect idPerson\n";
    } cerr << "That name already exists\n";
 
}

char *CDcollection::nameCD(int idPerson, int i){
    for(int m = 0; m < nCD; ++m){
        if(disk_owner[m] == idPerson){ /// Если номер владельца и значение в массиве совпадают
            if(i == 0){
                return disk_name[m]; /// Возвращаем имя диска.
            }else i--; /// Уменьшаем номер диска
        }
    }
    return 0;
}

int CDcollection:: where (char *CDname){
    bool name = exists_name(CDname);
    if(name == true){
        cout << "NAME = TRUE, I AM IN WHERE\n";
        int i = index_name (CDname);
        return disk_owner[i]; /// Возвращаем номер владельца диска
    }else if(name == false) {
        cerr << "Incorrect disk name\n";
        return -1;
    }
}

void CDcollection::transfer(char *CDname, int idParent, int idChild){
    bool exists = owner_exists(idChild); /// Проверка idChild на существование.
    int index = index_name(CDname); /// Проверка наличия имени диска в коллекции.
    if(exists == true){
        if(index != -1 && disk_owner[index] == idParent){ /// Проверка принадлежности данного диска к данному владельцу. 
            disk_owner[index] = idChild; /// Передача диска новому владельцу.
        }else cerr << "ERROR: disk name or owner wrong.\n"; 
    }else cerr << "ERROR: new owner don't exists.\n";

}

/// Перегрузка функции.
void CDcollection::transfer(char *CDname, int idChild){
    int idParent = where(CDname);
    transfer(CDname, idParent, idChild);
}

int CDcollection::index_name (char *CDname){
    for(int i = 0; i < nCD; ++i){
        if(disk_name[i] == CDname){ /// Сравниваем строки.     
            return i; /// Возвращаем индекс элемента массива, в котором лежит имя. оно = индексу владельца.
        } 
    }
    return -1;
}

bool CDcollection::exists_name (char *CDname){
    for(int i = 0; i < nCD; ++i){
        if(disk_name[i] == CDname){ /// Сравниваем строки.     
            //cout << "exists_name disk_name [i] " << disk_name [i] << endl;
            return true;
        } 
    }
    return false;
}

/// Проверяем idChaild на существование.
bool CDcollection::owner_exists(int idChaild){
    if(idChaild < nPerson){
        return true;
    }
    return false;
}

int CDcollection::amount(int idPerson){
        int count_disk = 0; /// Счетчик дисков.
        for(int k = 0; k < nCD; k++){
            if (disk_owner[k]== idPerson){
                count_disk++;
            }
        }
        return count_disk;

}

void CDcollection::print(){
    for(int k = 0; k < nCD; ++k){
        if(disk_owner[k] != -1){
            cout << disk_name[k] << " : " << disk_owner[k] << endl;
        }
    }
    cout << " " << endl;
}


