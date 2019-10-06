using namespace std;

class CDcollection
{
    public:
        /// Хранилище двух массивов: владельцев и колекции дисков.
        CDcollection(int nPerson, int nCD);

        /// Деструктор.
        ~CDcollection();

        /// Добавить новый диск.
        void add(char *CDname, int idPerson);

        /// Дать дсик idPerson.
        void transfer(char *CDname, int idParent, int idChild); 

        /// У кого находится диск.
        int where (char *CDname); 

        /// Сколько дисков у idPerson.
        int amount(int idPerson); 

        /// Название i-того диска у idPerson.
        char *nameCD(int idPerson, int i); 

        /// Распечатать состояние объекта.
        void print(); 
    
    private:
        /// Количество человек, которые владеют коллекцией. (Известно заранее)
        int nPerson;

        /// Количество дисков. (Может меняться)
        int nCD;

        /// Название диска.
        char CDname;

        /// Номер человека.
        int idPerson;

        /// Номер человека, который отдает диск.
        int idParent;

        ///Номер человека, который принимает диск.
        int idChild;

        /// Индекс i-того диска.
        int i;

};