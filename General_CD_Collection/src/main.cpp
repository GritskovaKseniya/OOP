#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "CDcollection.h"

using namespace std;

int main() {
    int answer = -1;
    int nPerson;
    int nCD;
    char CDname[50], *name;
    int idPerson, idParent, idChild, i, owner, number;
    cout << "Input number of disks (more than 0): "; 
    cin >> nCD;
    cout << "Input number of owner (more than 0): "; 
    cin >> nPerson;
    CDcollection* lib = new CDcollection(nPerson, nCD);    

    while (answer != 0) {
        cout << "0 -- Exit" << endl;
        cout << "1 -- Add" << endl;
        cout << "2 -- Transfer" << endl;
        cout << "3 -- Where" << endl;
        cout << "4 -- Amount" << endl;
        cout << "5 -- Name" << endl;
        cout << "6 -- Print" << endl;

        std::cin >> answer;

        switch (answer) {
            case 1:
                cout << "Input disk name: "; cin >> CDname;
                cout << "Input owner: "; cin >> idPerson;
                lib->add(CDname, idPerson);
                break;

            case 2:
                cout << "Input disk name: "; cin >> CDname;
                cout << "Input disk owner: "; cin >> idParent;
                cout << "Input disk new owner: "; cin >> idChild;
                lib->transfer(CDname, idParent, idChild);
                break;
            
            case 3:
                cout << "Input disk name: ";cin >> CDname;
                owner = lib->where(CDname);
                if(owner != -1){
                    cout << "Disk " << CDname << " depends owner " << owner << endl; cout << " " << endl;
                }else if(owner = -1){
                    cout << "The disk doesn't exist. \n";
                }else cout << "UNKNOWN ERROR\n";
                break;
            
            case 4:
                cout << "Input owner number: "; cin >> idPerson;
                number = lib->amount(idPerson);
                if(number > 0){
                    cout << "Owner " << idPerson << " have " << number << " disks.\n"; cout << " " << endl;
                }else if (number = 0){
                    cout << "Owner " << 1 << " have " << number << " disk.\n"; cout << " " << endl;
                }else cout << "There is no such owner. \n";
                break;
            
            case 5:
                cout << "Input owner number: "; cin >> idPerson;
                cout << "Input number disk: "; cin >> i;
                name = lib->nameCD(idPerson, i);
                if(name != 0){
                    cout << "Owner " << idPerson << " have " << name << " disk.\n"; cout << " " << endl;
                }else cout << " There is no such disk. \n";
                break;
            
            case 6:
                lib->print();
                break;
        
            default:
                break;
        }
    }
    
    delete lib;
    return 0;
}
