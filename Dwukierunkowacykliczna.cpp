#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;
struct element {
	int number;
	element *next;
	element *prev;
};
struct cdouble_list {
	element *current;
};
void add_after(cdouble_list&,int);
void add_before(cdouble_list&,int);
int delete_after(cdouble_list&);
int delete_before(cdouble_list&);
int delete_current(cdouble_list&);
bool isEmpty(cdouble_list);
void show(cdouble_list);
int main() {
    cdouble_list l;
    l.current = nullptr;
    int wybor, liczba;
    srand(time(NULL));
    bool exit = false;
    while(!exit){
        cout<<endl<<"Menu: "<<endl;
        cout<<"1 --> Czy lista jest pusta"<<endl;
        cout<<"2 --> Dodanie elementu za element biezacy"<<endl;
        cout<<"3 --> Dodanie elementu przed element biezacy"<<endl;
        cout<<"4 --> Usuniecie elementu za elementem biezacym"<<endl;
        cout<<"5 --> Usuniecie elementu przed elementem biezacym"<<endl;
        cout<<"6 --> Usuniecie elementu biezacego"<<endl;
        cout<<"7 --> Wyswietlenie elementow listy"<<endl;
        cout<<"8 --> Usuniecie calej listy"<<endl;
        cout<<"9 --> Wyjscie z programu"<<endl;
        cout<<"Podaj wybor: ";
        cin>>wybor;
        system("cls");
        cout<<endl;
        switch(wybor){
            case 1: {
                if(isEmpty(l)) cout<<"Lista jest pusta."<<endl;
                else cout<<"Lista nie jest pusta."<<endl;
                break;
            }
            case 2: {
                liczba = rand()%50+1;
                add_after(l, liczba);
                cout<<"Dodano element za element biezacy: "<<liczba<<endl;
                break;
            }
            case 3: {
                liczba = rand()%50+1;
                add_before(l, liczba);
                cout<<"Dodano element przed element biezacy: "<<liczba<<endl;
                break;
            }
            case 4: {
                if (!isEmpty(l)) cout<<"Usunieto element za elementem biezacym: "<<delete_after(l)<<endl;
                else cout<<"Lista jest pusta. Brak elementow do usuniecia."<<endl;
                break;
            }
            case 5: {
                if (!isEmpty(l)) cout<<"Usunieto element przed elementem biezacym: "<<delete_before(l)<<endl;
                else cout<<"Lista jest pusta. Brak elementow do usuniecia."<<endl;
                break;
            }
            case 6: {
                if (!isEmpty(l)) cout<<"Usunieto biezacy element z listy: "<<delete_current(l)<<endl;
                else cout<<"Lista jest pusta. Brak elementow do usuniecia."<<endl;
                break;
            }
            case 7: {
                if (!isEmpty(l)) {
                    cout<<"Elementy listy: ";
                    show(l);
                }
                else cout<<"Lista jest pusta. Brak elementow do wyswietlenia."<<endl;
                break;
            }
            case 8: {
                while (!isEmpty(l)) liczba = delete_current(l);
                cout<<"Lista jest pusta."<<endl;
                break;
            }
            case 9: {
                exit = true;
                break;
            }
            default: {
                cout<<"Nieprawidlowy wybor!"<<endl;
                exit = true;
                break;
            }
        }
    }
    cin.ignore();
    cin.get();
    return 0;
}
void add_after(cdouble_list &l, int value) {
    element *temp = new element;
    element *temp2 = new element;
    element *el = new element;
    if (l.current == nullptr) {
        temp->number = value;
        l.current = temp;
        temp->next = l.current;
        temp->prev = l.current;
    }
    else {
        el->number = value;
        temp = l.current->prev;
        temp2 = l.current;
        temp->next = el;
        el->prev = temp;
        el->next = temp2;
        temp2->prev = el;
    }
}
void add_before(cdouble_list &l, int value) {
    element *temp = new element;
    element *temp2 = new element;
    element *el = new element;
    if (l.current == nullptr) {
        temp->number = value;
        l.current = temp;
        temp->next = l.current;
        temp->prev = l.current;
    }
    else {
        el->number = value;
        temp = l.current;
        temp2 = l.current->next;
        temp->next = el;
        el->prev = temp;
        el->next = temp2;
        temp2->prev = el;
    }
}
int delete_after(cdouble_list &l) {
    element *temp = new element;
    element *temp2 = new element;
    element *el = new element;
    int liczba;
    if (l.current->prev != l.current) {
        el = l.current->prev;
        liczba = el->number;
        temp = l.current;
        temp2 = el->prev;
        temp2->next = temp;
        temp->prev = temp2;
        return liczba;
    }
    return -1;
}
int delete_before(cdouble_list &l) {
    element *temp = new element;
    element *temp2 = new element;
    element *el = new element;
    int liczba;
    if (l.current->next != l.current) {
        el = l.current->next;
        liczba = el->number;
        temp = l.current;
        temp2 = el->next;
        temp2->prev = temp;
        temp->next = temp2;
        return liczba;
    }
    return -1;
}
int delete_current(cdouble_list &l) {
    element *temp = new element;
    element *temp2 = new element;
    element *el = new element;
    int liczba;
    if (l.current->next != l.current) {
        el = l.current;
        liczba = el->number;
        temp = l.current->prev;
        l.current = temp;
        temp2 = el->next;
        temp2->prev = temp;
        temp->next = temp2;
        return liczba;
    }
    else {
        el = l.current;
        liczba = el->number;
        l.current = nullptr;
        el = nullptr;
        return liczba;
    }
    return -1;
}
bool isEmpty(cdouble_list l) {
    return l.current == nullptr;
}
void show(cdouble_list l) {
    element *temp = new element;
    element *temp2 = new element;
    temp2 = l.current->prev;
    temp = temp2;
    do {
        if (temp == l.current) cout<<"("<<temp->number<<") ";
        else cout<<temp->number<<" ";
        temp = temp->next;
    } while (temp != temp2);
    cout<<endl<<"(n) - Element biezacy"<<endl;
}
