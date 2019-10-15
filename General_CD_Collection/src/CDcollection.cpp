#include "CDcollection.h"
#include <iostream>
#include <cstring>

using namespace std;

CDcollection::CDcollection(int nPerson, int nCD){
    this->nPerson = nPerson;
    this->nCD = nCD;
    int idPerson;
    char* CDname;
    disk_name = new char*[nCD]; /// Массив имен дисков. (размер = количество дисков) Заполняется постепенно, изначально пуст.
    disk_owner = new int[nCD]; /// Массив владельцев дисков. (размер = количество дисков) 

    int k = 0;
    /// Заполняем массивы (наличие владельца у диска, наличие имени)
    for(int i = 0; i < nCD; ++i){
        disk_owner[i] = -1; /// Диск никому не принадлежит.
        disk_name[i] = 0;
        k = i;
    }

    ///disk_owner[idPerson] = idPerson;
    disk_owner[k] = idPerson;
    disk_name[k] = CDname;
}

CDcollection::CDcollection(){

}

CDcollection::~CDcollection(){
    delete[] disk_name;
    delete[] disk_owner;
}

void CDcollection::add(char *CDname, int idPerson){
    int k = 0;
    for(int i = 0; i < nCD; ++i){
       if(disk_owner[i] == -1){
           k = i;
           break;
       }
    }
    disk_owner[k] = idPerson; /// Записываем владельца в свободную ячейку массива.
    disk_name[k] = CDname; /// Записываем имя диска в свободную ячейку массива.
    
    /*cout << "Function add: " << endl;
    cout << "OWNER " << disk_owner[k] << endl;
    cout << "NAME " << disk_name[k] << endl;
    cout << " " << endl;*/
}

char *CDcollection::nameCD(int idPerson, int i){
    int m = 0;
    while (m < nCD)
    {
        if(disk_owner[m] == idPerson){ /// Если номер владельца и значение в массиве совпадают
            if(i == 0){

                /*cout << "Function nameCD: " << endl;
                cout << "NAME " << disk_name[m] << endl;  
                cout << " " << endl;*/
                
                return disk_name[m]; /// Возвращаем имя диска.
            }else i--; /// Уменьшаем номер диска
        }
        m++;
    }
    return 0;
}

int CDcollection::where (char *CDname){
    for(int i = 0; i < nCD; ++i){
        if(disk_name[i] == CDname){ /// Сравниваем строки.

            /*cout << "Function where: " << endl;
            cout << CDname << endl;
            cout << "disk owner " << disk_owner[i] << endl;
            cout << " " << endl;*/
        
            return disk_owner[i]; /// Возвращаем номер владельца диска
        }
    }
    return 0;
}

void CDcollection::transfer(char *CDname, int idParent, int idChild){
    int k = index_name(CDname); /// Проверка наличия имени диска в коллекции.
    int n = index_owner(idParent);
    if(k == n){ /// Проверка принадлежности данного диска к данному владельцу. 
        
        /*cout << "Function transfer: " << endl;
        cout << "OLD OWNER " << disk_owner[n] << endl;*/

        disk_owner[n] = idChild; /// Передача диска новому владельцу.
        
        /*cout << "NEW OWNER " << disk_owner[n] << endl;
        cout << " " << endl;*/
    }    
}

void CDcollection::transfer(char *CDname, int idChild){

}

int CDcollection::index_name (char *CDname){
    for(int i = 0; i < nCD; ++i){
        if(disk_name[i] == CDname){ /// Сравниваем строки.     
            return i; /// Возвращаем индекс массива, в котором лежит имя. оно = индексу владельца.
        }
    }
    return 0;
}

int CDcollection::index_owner (int idParent){
    for(int i = 0; i < nCD; ++i){
        if(disk_owner[i] == idParent){  /// Сравниваем числа.   
            return i; /// Возвращаем индекс массива, в котором лежит имя. оно = индексу владельца.
        }
    }
    return 0;
}

int CDcollection::amount(int idPerson){
    int count_disk = 0; /// Счетчик дисков.
    int m = 0;
    /*for(int k = 0; k < nCD; k++){
        while (disk_owner[k]== idPerson){
            count_disk++;
        }
    }*/
    while (m < nCD)
    {
        while (disk_owner[m]== idPerson){
            ++count_disk;
        }
        m++;
    }
    

/*    cout << "Function amount: " << endl;
    cout << "disk owner " << idPerson << endl;
    cout << count_disk << " disks " << endl;
    cout << " " << endl;
*/

    return count_disk;
}


void CDcollection::print(){
    int m = 0;
    while (m < nCD)
    {
        if(disk_owner[m] != -1){
            cout << disk_name[m] << " : " << disk_owner[m] << endl;
        }
        m++;
    }
}


