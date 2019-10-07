#include "heder.h"

CDcollection::CDcollection(int nPerson, int nCD){
    this->nPerson = nPerson;
    this->nCD = nCD;
}

/*
CDcollection::CDcollection(){
}
*/

void CDcollection::add(char *CDname, int idPerson){
    this->idPerson = idPerson;
    this->CDname = CDname;
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
    
}

void CDcollection::print(){

}