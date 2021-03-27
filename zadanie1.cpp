#include <iostream>
#include <exception>

namespace ek {

    struct pair {

        pair() {
            this->key = NULL;
            this->value = nullptr;

        }

        pair(unsigned klucz, char *tekst) {
            this->key = klucz;
            this->value = tekst;
        }

        long key;
        char *value;

        bool is_empty = true;
    };
}

void add(ek::pair *tab, int tab_size);

void print(ek::pair *tab, int size);

void del(ek::pair *tab, int size);

bool parser(char *polecenie, ek::pair *tab, int size);

int main() {
    int l_przypadkow = 0;
    int size = 0;
    bool kon;
    char polecenie[20];

    ek::pair *tab;

    std::cin >> l_przypadkow;

    for (int i = 0; i < l_przypadkow; i++) {
        std::cin >> polecenie;
        std::cin >> size;

        tab = new ek::pair[size];
        do {
            std::cin >> polecenie;

            kon = parser(polecenie, tab, size);


        } while (kon);

        delete[] tab;
    }


    return 0;
}

void add(ek::pair *tab, int tab_size, ek::pair data) {
    int index = data.key % tab_size;

    if (tab[index].is_empty || tab[index].key == data.key) {
        tab[index] = data;

    } else {

        do {
            if (index >= tab_size) throw std::bad_alloc();
            else index++;
        } while (!tab[index].is_empty);

        tab[index] = data;

    }


}

void print(ek::pair *tab, int size) {
    for (int i = 0; i < size; i++) {
        if (!tab[i].is_empty) {
            std::cout << i           << " "
                      << tab[i].key  << " "
                      << tab[i].value<<std::endl; //todo zamiast imienia wywala smieci z pamieci << std::endl;
        }


    }
    std::cout << std::endl;
}

void del(ek::pair *tab, int size, int klucz) //pozniej bo nie umiem
{


    int index = klucz % size;

    while (tab[index].is_empty || tab[index].key != klucz) {
        if (index >= size) return;  // nothing to delete
        ++index;
    }

    while(!tab[index].is_empty) {
        tab[index] = tab[index + 1];
        if (index == size-1) tab[size -1] = ek::pair();
        ++index;
    }
}

bool parser(char *polecenie, ek::pair *tab, int size) {
    switch (polecenie[0]) {
        case 'a': {
            ek::pair to_add;
            std::cin >> to_add.key;
            std::cin >> to_add.value;
            to_add.is_empty = false;
            add(tab, size, to_add);
            break;
        }
        case 'p': {
            print(tab, size);
            break;

        }
        case 'd': {
            int key;
            std::cin>>key;
            del(tab, size,key);
            break;
        }
        case 's': {

            return false;
        }
        default :
            // throw bad polecenie or something
            break;

    }

    return true;
}
