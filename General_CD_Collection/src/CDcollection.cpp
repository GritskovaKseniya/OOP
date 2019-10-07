#include "heder.h"
#include <iostream>

using namespace std;

CDcollection::CDcollection(int nPerson, int nCD){
    this->nPerson = nPerson;
    this->nCD = nCD;
    disk_name = new char*[nCD];
    disk_owner = new int[nCD]; 
    for(int i; i < nCD; ++i){
        disk_owner[i] = -1; /// Диск никому не принадлежит.
    }
}

/*
CDcollection::CDcollection(){
}
*/

void CDcollection::add(char *CDname, int idPerson){
    this->idPerson = idPerson;
    this->CDname = CDname;
    disk_owner[idPerson] = idPerson;

}

void CDcollection::transfer(char *CDname, int idParent, int idChild){
    this->idParent = idParent;
    this->idChild = idChild;
    this->CDname = CDname;
}

int CDcollection::where (char *CDname){
    this->CDname = CDname;
}

int CDcollection::amount(int idPerson){
    this->idPerson = idPerson;
}

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