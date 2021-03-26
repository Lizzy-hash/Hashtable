#include <iostream>


struct para {

    para() {
        this->klucz = NULL;
        this->value = nullptr;
    }
    para(unsigned klucz, char* tekst) {
        this->klucz = klucz;
        this->value = tekst;
    }

    long klucz;
    char* value;

    bool is_empty = true;
};


//void add(std::pair<int, char*> *tab,int size);
//void print(std::pair<int, char*>* tab, int size);
//void del(std::pair<int, char*>* tab, int size);
//
//bool parser(char* pol, std::pair<int, char*> *tab,int size);

void add(para * tab, int size);
void print(para* tab, int size);
void del(para* tab, int size);

bool parser(char* pol, para* tab, int size);

int main()
{
    int l_przypadkow=0;
    int size = 0;
    bool kon;
    char polecenie[20];
    //std::pair<int, char*> *tab; 

    para* tab;

    std::cin >> l_przypadkow;

    for (int i = 0; i < l_przypadkow; i++)
        {
        std::cin >> polecenie;
        std::cin >> size;

       // tab = new std::pair<int, char*>[size];

        tab = new para[size];

      //  memset(tab, true, size * sizeof(std::pair<int, char*>)); //trzeba zmienić, bo klucz może równać się 0;

            do
                {
                std::cin >> polecenie;

                kon = parser(polecenie, tab,size);


            } while (kon == true);

            delete[] tab;
        }

    
   
    return 0;
}

void add(para* tab, int size) 
{
    long klucz;
    char wartosc[9];

    std::cin >> klucz;
    std::cin >> wartosc;

    int index = klucz % size;

    if (tab[index].is_empty || tab[index].klucz == klucz) {
             tab[index] = para(klucz, wartosc);
             tab[index].is_empty = false;
        }
    else
        {
            while(!tab[index].klucz)
            { 
                if (index > size - 1) index = 0;
                else index++;
            }
            
            tab[index] = para(klucz, wartosc);
            tab[index].is_empty = false;
        }
    

}

void print(para* tab, int size)
{

  

    for (int i = 0; i < size; i++)
    {
        if (!tab[i].is_empty)
            {
            std::cout << i << " " << tab[i].klucz << " " << tab[i].value; //zamiast imienia wywala smieci z pamieci TO DO 
            std::cout << std::endl;
            }
        
       
    }
    std::cout << std::endl;
}

void del(para* tab, int size) //pozniej bo nie umiem
{
    int klucz;
    std::cin >> klucz;

    int index = klucz % size;

    while (tab[index].is_empty|| tab[index].klucz != klucz)
        {
            if (index > size - 1) index = 0;
            else index++;// zrobic zapetlenie
        }


    tab[index] = tab[index + 1]; //przesunac trzeba wszystko o jeden w lewo, tam gdzie indexy się nie zgadzaja z wyliczonym
                                 //stop jak znajdziemy zero lub wrocimy do tego samego miejsca
    //TO DO co jeżeli index==size?

    //alternatywnie znajdujemy ostatni element, ktory pasuje i przesuwamy go na powstale puste miejsce <- ma mniej przesuniec 
    //rekurencja, jak dziurka to porzadkujemy nizej
    //sprawdzamy kolejne pozycje od delete czy pasuja na pusty index, jak tak to oznaczamy i sprawdzamy, az napotkamy dziurke
    //uzyc albo algorytmu przesypujacego albo przenoszacego ostatni element
}

bool parser(char* pol, para* tab, int size)
{
    if (pol[0] == 'a') add(tab, size);
    if (pol[0] == 'p') print(tab,size);
    if (pol[0] == 'd') del(tab,size);
    if (pol[0] == 's' && pol[1] == 't') return false;
    
    return true;
}
