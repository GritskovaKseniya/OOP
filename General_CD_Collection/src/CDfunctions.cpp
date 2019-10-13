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
        if(disk_name[i] == CDname){ ///Функция сравнивает слова

            /*cout << "Function where: " << endl;
            cout << "disk owner " << disk_owner[i] << endl;
            cout << " " << endl;*/
        
            return disk_owner[i]; /// Возвращаем номер владельца диска
        }
    }
    return 0;
}

void CDcollection::transfer(char *CDname, int idParent, int idChild){
    /// Проверка наличия имени диска в коллекции. Если false, выводим на экран сообщение об ошибке.
    /// Проверка принадлежности данного диска к данному владельцу. Если false, выводим сообщение об ошибке.
    /// Передача диска новому владельцу.

    int k = index_name(CDname);
    int n = index_owner(idParent);
    if(k == n){
        
        /*cout << "Function where: " << endl;
        cout << "OLD OWNER " << disk_owner[n] << endl;*/
        disk_owner[n] = idChild;
        /*cout << "NEW OWNER " << disk_owner[n] << endl;
        cout << " " << endl;*/
    }    
}

int CDcollection::index_name (char *CDname){
    for(int i = 0; i < nCD; ++i){
        if(disk_name[i] == CDname){ ///Функция сравнивает слова        
            return i; /// Возвращаем индекс массива, в котором лежит имя. оно = индексу владельца.
        }
    }
    return 0;
}

int CDcollection::index_owner (int idParent){
    for(int i = 0; i < nCD; ++i){
        if(disk_owner[i] == idParent){ ///Функция сравнивает слова        
            return i; /// Возвращаем индекс массива, в котором лежит имя. оно = индексу владельца.
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



