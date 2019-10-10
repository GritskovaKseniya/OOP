#include "heder.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

CDcollection::CDcollection(int nPerson, int nCD){
    this->nPerson = nPerson;
    this->nCD = nCD;
    disk_name = new char*[nCD]; /// Массив имен дисков. (размер = количество дисков) Заполняется постепенно, изначально пуст.
    disk_owner = new int[nCD]; /// Массив владельцев дисков. (размер = количество дисков) 

    // Не будет ли конфликта, если владельцев меньше, чем дисков или наоборот?
    // Продумать состояние владельца, которому не пренадлежит никакой диск.

    /// Заполняем массив, в котором говорится, что диск принадлежит кому-то.
    for(int i = 0; i < nCD; ++i){
        disk_owner[i] = -1; /// Диск никому не принадлежит.
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

void CDcollection::add(char *CDname, int idPerson){
    this->idPerson = idPerson;
    this->CDname = CDname;
    int k = 0;
    for(int i = 0; i < nCD; ++i){
       if(disk_owner[i] == -1){
           k = i;
           break;
       }
    }
    disk_owner[k] = idPerson;
    disk_name[k] = CDname;
    cout << "OWNER " << disk_owner[k] << endl;
    cout << "NAME " << disk_name[k] << endl;
}

void CDcollection::transfer(char *CDname, int idParent, int idChild){
    this->idParent = idParent;
    this->idChild = idChild;
    this->CDname = CDname;
    /// Проверка наличия имени диска в коллекции. Если false, выводим на экран сообщение об ошибке.
    /// Проверка принадлежности данного диска к данному владельцу. Если false, выводим сообщение об ошибке.
    /// Передача диска новому владельцу.
}

int CDcollection::where (char *CDname){
    this->CDname = CDname;
    int idCD = 0;
    if(strcmp(disk_name[idCD], CDname) != 0){  ///Функция сравнивает слова
        idCD++;
    }
    disk_owner[idCD] = idPerson;

    return idPerson;
    cout << "Этот диск у " << idPerson << " владельца. "<< endl;
}

int CDcollection::amount(int idPerson){
    this->idPerson = idPerson;
    int m = 0;  /// Число дисков владельца.

    for(int k = 0; k < nCD; ++k){
        if(disk_owner[k]== idPerson){
            m++;
        }
    }
    cout << " У " << idPerson << " владельца " << m << " дисков" << endl;
}

/// По факту выводим имя конкретного диска по имени владельца и номеру диска 
char *CDcollection::nameCD(int idPerson, int i){
    int m = 0;
    do{
        for(int k; k < nCD; ++k){
            if(disk_owner[k]== idPerson){
                m++;
            }
        }
    }while(m == i);
    cout << CDname << endl;  
}

void CDcollection::print(){
    for(int i = 0; i <  nCD; ++i){
        cout << disk_name[i] << " : " << disk_owner[i] << endl;
    }
}