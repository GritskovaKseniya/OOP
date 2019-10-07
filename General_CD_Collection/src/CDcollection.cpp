#include "heder.h"
#include <iostream>

using namespace std;

CDcollection::CDcollection(int nPerson, int nCD){
    this->nPerson = nPerson;
    this->nCD = nCD;
    disk_name = new char*[nCD]; /// Массив имен дисков. (размер = количество дисков) Заполняется постепенно, изначально пуст.
    disk_owner = new int[nCD]; /// Массив владельцев дисков. (размер = количество дисков) 

    // Не будет ли конфликта, если владельцев меньше, чем дисков или наоборот?
    // Продумать состояние владельца, которому не пренадлежит никакой диск.

    /// Заполняем массив, в котором говорится, что диск принадлежит кому-то.
    for(int i; i < nCD; ++i){
        disk_owner[i] = -1; /// Диск никому не принадлежит.
    }
}

/*
перегрузка функции
CDcollection::CDcollection(){
}
*/

void CDcollection::add(char *CDname, int idPerson){
    this->idPerson = idPerson;
    this->CDname = CDname;
    disk_owner[idPerson] = idPerson;
    /// Проверка введенного имени диска на уникальность. Если false, вывести сообщение об ошибке.

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
    // Некая логика, результат которой - номер владельца диска.
    cout << idPerson << endl;
}

int CDcollection::amount(int idPerson){
    this->idPerson = idPerson;
    int k; /// Число дисков владельца.
    //логика, которая вычисляет количество дисков у данного владельца.
    cout << " У " << idPerson << " владельца " << k << " дисков" << endl;
}

/// Передаем номер владельца и номер дска (для этого у каждого владельца долен быть массив дисков?)
/// По факту выводим имя конкретного диска по имени владельца и позиции диска 
char *CDcollection::nameCD(int idPerson, int i){
    for(int j; j < i; ++j){
        cout << CDname << endl;  
    }
}

void CDcollection::print(){
    for(int i; i <  nPerson; ++i){
        cout << CDname << " : " << idPerson << endl;
    }
}