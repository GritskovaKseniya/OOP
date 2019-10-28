#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class CDcollection
{
    public:
        /// Хранилище двух массивов: владельцев и колекции дисков.
        CDcollection(int nPerson, int nCD){initialize(nPerson, nCD);}
        CDcollection(){
            int nPerson = 5; int nCD = 15;
            initialize(nPerson, nCD);
        }
        /// Деструктор. Освобождает использованные объектом ресурсов и удаление нестатических переменных объекта.
        ~CDcollection();
        /// Добавить новый диск.
        void add(char *CDname, int idPerson);
        /// Дать дсик idPerson.
        void transfer(char *CDname, int idParent, int idChild); 
        void transfer(char *CDname, int idChild);
        /// У кого находится диск.
        int where (char *CDname);
        /// Сколько дисков у idPerson.
        int amount(int idPerson); 
        /// Читает у кого какой диск находится. Название i-того диска у idPerson. Выводим имя конкретного диска по имени владельца и номеру диска.
        char* nameCD(int idPerson, int i); 
        /// Распечатать состояние объекта.
        void print(); 
    
    private:
        /// Количество владельцев коллекции.
        int nPerson;
        /// Количество дисков в коллекции.
        int nCD;
        /// Массив индексов владельцев дисков.
        int* disk_owner;
        /// Массив имен дисков.
        char** disk_name;
        /// Возвращаем индекс по имени.
        int index_name (char *CDname);
        /// Проверка существования владельца.
        bool owner_exists(int idChaild);
        /// Проверка существования имени.
        bool exists_name (char *CDname);
        /// Функция для конструкторов.
        void initialize(int nPerson, int nCD);
};
