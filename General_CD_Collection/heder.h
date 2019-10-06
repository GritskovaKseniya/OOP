using namespace std;

class CDcollection
{
    public:
      CDcollection(int nPerson, int nCD);
      ~CDcollection();
      void add(char *CDname, int idPerson); // добавить новый диск.
      void transfer(char *CDname, int idParent, int idChild); // дать дсик idPerson.
      int where (char *CDname); // У кого диск.
      int amount(int idPerson); // сколько дисков у idPerson.
      char *nameCD(int idPerson, int i); // название i-того диска у idPerson.
      void print(); // распечатать состояние объекта.
};