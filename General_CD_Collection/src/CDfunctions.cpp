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
    /*cout << "Function add: " << endl;
    cout << "OWNER " << disk_owner[k] << endl;
    cout << "NAME " << disk_name[k] << endl;
    cout << " " << endl;*/
}

/// По факту выводим имя конкретного диска по имени владельца и номеру диска 
char *CDcollection::nameCD(int idPerson, int i){
    int m = 0;
    while (m < nCD)
    {
        if(disk_owner[m] == idPerson){
            if(i == 0){
                /*cout << "Function nameCD: " << endl;
                cout << "NAME " << disk_name[m] << endl;  
                cout << " " << endl;*/
                return disk_name[m];
            }else i--;
        }
        m++;
    }
    return 0;
}

int CDcollection::where (char *CDname){
    for(int i = 0; i < nCD; ++i){
        if(disk_name[i] == CDname){ ///Функция сравнивает слова
            cout << "Function where: " << endl;
            cout << "disk owner " << disk_owner[i] << endl;
            cout << " " << endl;
            return disk_owner[i];
        }
    }
    return 0;
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
            cout << "OWNER " << i << " = " << disk_owner[i] << endl;
        }
    }
    disk_owner[k] == idChild;
    cout << "NEW OWNER " << disk_owner[k] << endl;

}

int CDcollection::amount(int idPerson){
    int m = 0;  /// Число дисков владельца.
    
    for(int k = 0; k < nCD; k++){
        cout << "m1 " << m << endl;
        if(disk_owner[k]== idPerson){
            m++;
            cout << "m2 " << m << endl;
        }
        cout << "m3 " << m << endl;
    }
    //cout << " owner " << idPerson << " have " << m << "disks";
    return m;

    /*while (m < nCD)
    {
        if(disk_owner[m] == idPerson){
            i++;
            cout << i;
        }
        m++;
    }
    cout << i << " DISKS" ;
    return i;*/
}



