#include <iostream>
#include <time.h>
#include <string>
using namespace std;
struct element {
    int number;
    element* next;
};
struct csingle_list {
    element* current;
};
void add_after(csingle_list&, int);
void add_before(csingle_list&, int);
void delete_after(csingle_list&);
void delete_before(csingle_list&);
void delete_current(csingle_list&);
void show(csingle_list);
bool isEmpty(csingle_list);
int main () {
    srand(time(NULL));
    csingle_list l;
    l.current = nullptr;
    int menu = 0, pos = 0, temp;
    while (menu != 9) {
        cout<<"Wybierz opcje:"<<endl;
        cout<<"1 --> Sprawdzenie czy lista jest pusta"<<endl;
        cout<<"2 --> Dodanie elementu za element biezacy"<<endl;
        cout<<"3 --> Dodanie elementu przed element biezacy"<<endl;
        cout<<"4 --> Usuniecie elementu za elementem biezacym"<<endl;
        cout<<"5 --> Usuniecie elementu przed elementem biezacym"<<endl;
        cout<<"6 --> Usuniecie elementu biezacego"<<endl;
        cout<<"7 --> Wyswietlenie calej listy"<<endl;
        cout<<"8 --> Usuniecie calej listy i zwolnienie pamieci"<<endl;
        cout<<"9 --> Wyjscie z programu"<<endl;
        cin>>menu;
        system("cls");
        cout<<endl;
        if (menu == 1) {
            if (isEmpty(l)) cout<<"Lista jest pusta."<<endl;
            else cout<<"Lista nie jest pusta."<<endl;
        }
        if (menu == 2) {
            cout<<"Dodano element za element biezacy"<<endl;
            add_after(l, 1+rand()%50);
        }
        if (menu == 3) {
            cout<<"Dodano element przed element biezacy"<<endl;
            add_before(l, 1+rand()%50);
        }
        if (menu == 4) {
            if (isEmpty(l)) cout<<"Lista jest pusta. Brak elementu do usuniecia."<<endl;
            else {
                cout<<"Usunieto z listy element za elementem biezacym"<<endl;
                delete_after(l);
            }
        }
        if (menu == 5) {
            if (isEmpty(l)) cout<<"Lista jest pusta. Brak elementu do usuniecia."<<endl;
            else {
                cout<<"Usunieto z listy element przed elementem biezacym"<<endl;
                delete_before(l);
            }
        }
        if (menu == 6) {
            if (isEmpty(l)) cout<<"Lista jest pusta. Brak elementu do usuniecia."<<endl;
            else {
                cout<<"Usunieto z listy element biezacy"<<endl;
                delete_current(l);
            }
        }
        if (menu == 7) {
            if (isEmpty(l)) cout<<"Lista jest pusta. Brak elementow do wyswietlenia."<<endl;
            else {
                cout<<"Elementy listy: ";
                show(l);
            }
        }
        if (menu == 8) {
            if (isEmpty(l)) cout<<"Lista jest pusta. Brak elementow do usuniecia."<<endl;
            else while (!isEmpty(l)) delete_current(l);
        }
        if (menu < 1 || menu > 9) cout<<"Nieprawidlowy wybor!"<<endl;
        cout<<endl;
    }
    cin.ignore();
    cin.get();
    return 0;
}
void add_before(csingle_list &l, int v) {
    element *temp = new element;
    if (l.current == nullptr) {
        temp->number = v;
        l.current = temp;
        temp->next = l.current;
    }
    else {
        temp->number = v;
        temp->next = l.current->next;
        l.current->next = temp;
    }
}
void add_after(csingle_list &l, int v) {
    element *el = new element;
    element *temp = new element;
    if (l.current == nullptr) {
        temp->number = v;
        l.current = temp;
        temp->next = l.current;
    }
    else {
        if (l.current->next == nullptr) {
            temp->number = v;
            temp->next = l.current->next;
            l.current->next = temp;
        }
        else {
            el->number = v;
            temp = l.current;
            while (temp->next != l.current) temp = temp->next;
            el->next = temp->next;
            temp->next = el;
        }
    }
}
void delete_after(csingle_list &l) {
    element *temp = new element;
    element *temp2 = new element;
    if (l.current->next != l.current) {
        temp2 = l.current;
        while (temp2->next != l.current) temp2 = temp2->next;
        if (l.current->next != temp2) {
            temp = l.current;
            while (temp->next != temp2) temp = temp->next;
            temp->next = l.current;
            temp2->next = nullptr;
        }
        else {
            temp = l.current;
            l.current->next = temp;
            temp2->next = nullptr;
        }
    }
}
void delete_before(csingle_list &l) {
    element *temp = new element;
    if (l.current->next != l.current) {
        temp = l.current->next;
        l.current->next = temp->next;
        temp->next = nullptr;
    }
}
void delete_current(csingle_list &l) {
    if (l.current->next == l.current) {
        l.current = nullptr;
    }
    else {
        element *temp = new element;
        element *temp2 = new element;
        temp = l.current;
        temp2 = l.current->next;
        while (temp->next != l.current) temp = temp->next;
        l.current = temp;
        temp->next = temp2;
    }
}
void show(csingle_list l) {
    element *temp = new element;
    element *temp2 = new element;
    temp2 = l.current;
    while (temp2->next != l.current) temp2 = temp2->next;
    temp = temp2;
    do {
        if (temp == l.current) cout<<"("<<temp->number<<") ";
        else cout<<temp->number<<" ";
        temp = temp->next;
    } while (temp != temp2);
    cout<<endl<<"(n) - Element biezacy"<<endl;
}
bool isEmpty(csingle_list l) {
    return l.current==nullptr;
}
