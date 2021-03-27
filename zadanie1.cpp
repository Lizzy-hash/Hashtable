#include <iostream>


namespace em {

    struct pair {

        pair() {
            this->key = 0;
            this->value = nullptr;

        }

        pair(long klucz, char* tekst) {
            this->key = klucz;
            this->value = tekst;
        }

        pair(const pair& other){
            key = other.key;
            value = other.value;
            is_empty = other.is_empty;
        }


        pair& operator=(const pair& other) {
            if (this == &other) return *this;
            key = other.key;
            value = other.value;
            is_empty = other.is_empty;
            return *this;
        }

      
        long key;
        char* value;

        bool is_empty = true;  
        

    };
}

void add(em::pair* tab, int tab_size, em::pair data);


void print(em::pair* tab, int size);

void del(em::pair* tab, int size, int klucz);

bool parser(const char* polecenie, em::pair* tab, int size);

int main() {
    int l_przypadkow = 0;
    int size = 0;

    char polecenie[20];

    std::cin >> l_przypadkow;

    for (int i = 0; i < l_przypadkow; i++) {
        std::cin >> polecenie;
        std::cin >> size;

        auto* tab = new em::pair[size];
        for (int j = 0; j < size; j++) tab[j] = em::pair();

        do {
            std::cin >> polecenie;
        } while (parser(polecenie, tab, size));

        delete[] tab;
    }

    return 0;
}

void add(em::pair* tab, int tab_size, em::pair data) {
    int index = data.key % tab_size;

    while (!tab[index].is_empty && tab[index].key != data.key) {
        if (index == tab_size - 1) index = 0;
        ++index;
        //if (index == data.key % tab_size) throw std::bad_alloc();

    }

    data.is_empty = false;
    tab[index] = data;

}

void print(em::pair* tab, int size) {
    for (int i = 0; i < size; i++) {
        if (!tab[i].is_empty) {
            std::cout << i << " " << tab[i].key << " " << tab[i].value << std::endl; 
        }


    }
    std::cout << std::endl;
}

void del(em::pair* tab, int size, int klucz) 
{
    int index = klucz % size;

    while (tab[index].is_empty || tab[index].key != klucz) {
        if (index >= size) return;  // nothing to delete
        ++index;
    }

    while (!tab[index].is_empty) { 
        tab[index] = tab[index + 1];
        if (index == size - 1) tab[size - 1] = em::pair();
        ++index;
    }
}

bool parser(const char* polecenie, em::pair* tab, int size) {
    switch (polecenie[0]) {
    case 'a': {
        long temp_l;
        char* temp_str = new char[9];

        std::cin >> temp_l;
        std::cin >> temp_str;

        em::pair to_add(temp_l, temp_str);
        add(tab, size, to_add);
        break;
    }

    case 'p': {
        print(tab, size);
        break;
    }

    case 'd': {
        int key;
        std::cin >> key;
        del(tab, size, key);
        break;
    }

    case 's': {

        if (polecenie[1] == 't') return false;
    }
   }

    return true;
}