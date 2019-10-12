#include "CDcollection.h"
#include <iostream>
#include <cstring>

using namespace std;

void CDcollection::add(char *CDname, int idPerson){
    int k = 0;
    for(int i = 0; i < nCD; ++i){
       if(disk_owner[i] == -1){
           k = i;
           break;
       }
    }
    disk_owner[k] = idPerson;
    disk_name[k] = CDname;
}

void CDcollection::print(){
    for(int i = 0; i <  nCD; ++i){
        if(disk_owner[i] != -1){
            cout << disk_name[i] << " : " << disk_owner[i] << endl;
        }
    }
}

///НЕ ВЕРНО!
void CDcollection::transfer(char *CDname, int idParent, int idChild){
    /// Проверка наличия имени диска в коллекции. Если false, выводим на экран сообщение об ошибке.
    /// Проверка принадлежности данного диска к данному владельцу. Если false, выводим сообщение об ошибке.
    /// Передача диска новому владельцу.
    int k = 0;
    for(int i = 0; i < nCD; i++){
        if(disk_owner[i] == idParent){
            k = i;
        }
    }
    disk_owner[k] == idChild;

}

int CDcollection::where (char *CDname){
    int k = 0;
    for(int i = 0; i < nCD; i++){
        if(strcmp(disk_name[i], CDname)){ ///Функция сравнивает слова
            k = i;
        }
    }
    disk_owner[k];
}

int CDcollection::amount(int idPerson){
    int m = 0;  /// Число дисков владельца.

    for(int k = 0; k < nCD; ++k){
        if(disk_owner[k]== idPerson){
            m++;
        }
    }
    return m;
}

/// По факту выводим имя конкретного диска по имени владельца и номеру диска 
char *CDcollection::nameCD(int idPerson, int i){
    int m = 0;
    do{
        for(int k = 0; k < nCD; ++k){
            if(disk_owner[k]== idPerson){
                m++;
            }
        }
    }while(m == i);
    cout << CDname << endl;  
}

