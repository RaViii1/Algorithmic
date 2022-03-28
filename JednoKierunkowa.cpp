#include <iostream>
#include <time.h>
#include <string>
using namespace std;
struct element {
    int number;
    element* next;
};
struct single_list {
    element* head;
    element* tail;
    int counter;
};
void add_tail(single_list&, int);
void add_head(single_list&, int);
void add_position(single_list&, int, int);
void delete_tail(single_list&);
void delete_head(single_list&);
void delete_position(single_list&, int);
void show(single_list);
bool isEmpty(single_list);
int get_head(single_list);
int get_tail(single_list);
double count_avg(single_list);
int find_max(single_list,int*);
int main () {
    srand(time(NULL));
    single_list l;
    l.head = nullptr;
    l.tail = nullptr;
    l.counter = 0;
    int menu = 0, pos = 0, temp;
    while (menu != 15) {
        cout<<"Wybierz opcje:"<<endl;
        cout<<"1 --> Sprawdzenie czy lista jest pusta"<<endl;
        cout<<"2 --> Dodanie elementu na koniec listy"<<endl;
        cout<<"3 --> Dodanie elementu na poczatek listy"<<endl;
        cout<<"4 --> Dodanie elementu na okreslona pozycje"<<endl;
        cout<<"5 --> Usuniecie elementu z konca listy"<<endl;
        cout<<"6 --> Usuniecie elementu z poczatku listy"<<endl;
        cout<<"7 --> Usuniecie elementu znajdujacego sie na okreslonej pozycji"<<endl;
        cout<<"8 --> Pobranie i wyswietlenie pierwszego elementu z listy"<<endl;
        cout<<"9 --> Pobranie ostatniego elementu z listy"<<endl;
        cout<<"10 --> Wyswietlenie ostatniego elementu z listy"<<endl;
        cout<<"11 --> Policzenie i wyswietlenie sredniej arytm. elementow listy"<<endl;
        cout<<"12 --> Znalezienie i wyswietlenie elementu maksymalnego listy"<<endl;
        cout<<"13 --> Wyswietlenie calej listy"<<endl;
        cout<<"14 --> Usuniecie calej listy i zwolnienie pamieci"<<endl;
        cout<<"15 --> Wyjscie z programu"<<endl;
        cin>>menu;
        system("cls");
        cout<<endl;
        if (menu == 1) {
            if (isEmpty(l)) cout<<"Lista jest pusta."<<endl;
            else cout<<"Lista nie jest pusta."<<endl;
        }
        if (menu == 2) {
            cout<<"Dodano element na koniec listy"<<endl;
            add_tail(l, 1+rand()%50);
        }
        if (menu == 3) {
            cout<<"Dodano element na poczatek listy"<<endl;
            add_head(l, 1+rand()%50);
        }
        if (menu == 4) {
            cout<<"Podaj pozycje: ";
            cin>>pos;
            if (pos < 0) pos = 0;
            if (pos >= l.counter) pos = l.counter - 1;
            if (pos == 0) add_head(l, 1+rand()%50);
            else {
                if (pos == l.counter-1) add_tail(l, 1+rand()%50);
                else add_position(l, 1+rand()%50, pos);
            }
            cout<<"Dodano element na pozycje "<<pos<<" listy."<<endl;
        }
        if (menu == 5) {
            if (isEmpty(l)) cout<<"Lista jest pusta. Brak elementu do usuniecia."<<endl;
            else {
                cout<<"Usunieto ostatni element z listy"<<endl;
                delete_tail(l);
            }
        }
        if (menu == 6) {
            if (isEmpty(l)) cout<<"Lista jest pusta. Brak elementu do usuniecia."<<endl;
            else {
                cout<<"Usunieto pierwszy element z listy"<<endl;
                delete_head(l);
            }
        }
        if (menu == 7) {
            cout<<"Podaj pozycje: ";
            cin>>pos;
            if (pos < 0 && pos >= l.counter) cout<<"Podana pozycja nie istnieje w liscie."<<endl;
            else {
                if (pos == 0) delete_head(l);
                else {
                    if (pos == l.counter-1) delete_tail(l);
                    else delete_position(l,pos);
                }
                cout<<"Usunieto element z pozycji "<<pos<<" listy."<<endl;
            }
        }
        if (menu == 8) {
            if (isEmpty(l)) cout<<"Lista jest pusta. Brak elementu do wyswietlenia."<<endl;
            else cout<<"Pierwszy element listy: "<<get_head(l)<<endl;
        }
        if (menu == 9) {
            if (isEmpty(l)) cout<<"Lista jest pusta. Brak elementu do wyswietlenia."<<endl;
            else {
                temp = get_tail(l);
                cout<<"Pobrano ostatni element listy."<<endl;
            }
        }
        if (menu == 10) {
            if (isEmpty(l)) cout<<"Lista jest pusta. Brak elementu do wyswietlenia."<<endl;
            else cout<<"Ostatni element listy: "<<get_tail(l)<<endl;
        }
        if (menu == 11) {
            if (isEmpty(l)) cout<<"Lista jest pusta. Brak elementow do policzenia sredniej."<<endl;
            else cout<<"Srednia arytmetyczna elementow listy: "<<count_avg(l)<<endl;
        }
        if (menu == 12) {
            if (isEmpty(l)) cout<<"Lista jest pusta. Brak elementow do wyznaczenia maksimum."<<endl;
            else {
                cout<<"Wartosc maksymalna z listy: "<<find_max(l,&pos);
                cout<<", Pozycja: "<<pos<<endl;
            }
        }
        if (menu == 13) {
            if (isEmpty(l)) cout<<"Lista jest pusta. Brak elementow do wyswietlenia."<<endl;
            else {
                cout<<"Lista: ";
                show(l);
            }
        }
        if (menu == 14) {
            if (isEmpty(l)) cout<<"Lista jest pusta. Brak elementow do usuniecia."<<endl;
            else {
                while(!isEmpty(l)) delete_head(l);
                cout<<"Lista zostala usunieta."<<endl;
            }
        }
        if (menu < 1 || menu > 15) cout<<"Nieprawidlowy wybor!"<<endl;
        cout<<endl;
    }
    cin.ignore();
    cin.get();
    return 0;
}
void add_tail(single_list &l, int v) {
    element* el = new element;
    el->number = v;
    el->next = nullptr;
    if (l.tail != nullptr) l.tail->next = el;
    else l.head = el;
    l.tail = el;
    l.counter++;
}
void add_head(single_list &l, int v) {
    element* el = new element;
    el->number = v;
    el->next = l.head;
    l.head = el;
    if (l.tail == nullptr) l.tail = el;
    l.counter++;
}
void add_position(single_list &l, int v, int pos) {
    element* el = new element;
    element* temp = new element;
    el->number = v;
    temp = l.head;
    for (int i=0; i<pos-1; i++) temp = temp->next;
    el->next = temp->next;
    temp->next = el;
    l.counter++;
}
void delete_tail(single_list &l) {
    element* temp = new element;
    element* bef_temp = new element;
    temp = l.tail;
    if (l.counter == 0) {
        l.tail = nullptr;
        l.head = nullptr;
    }
    else {
        bef_temp = l.head;
        for (int i=0; i<l.counter-1; i++) bef_temp = bef_temp->next;
        l.tail = bef_temp;
        l.tail->next = nullptr;
        l.counter--;
    }
    delete temp;
}
void delete_head(single_list &l) {
    element* temp = new element;
    temp = l.head;
    l.head = l.head->next;
    if (l.counter == 0) l.tail = nullptr;
    else l.counter--;
    delete temp;
}
void delete_position(single_list &l, int pos) {
    element* prev = new element;
    element* temp = new element;
    prev = l.head;
    for (int i=0; i<pos-1; i++) prev = prev->next;
    temp = prev->next;
    prev->next = temp->next;
    l.counter--;
    delete temp;
}
void show(single_list l) {
    element* temp = new element;
    temp = l.head;
    for (int i=0; i<l.counter; i++) {
        cout<<temp->number<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
bool isEmpty(single_list l) {
    return l.counter==0;
}
int get_head(single_list l) {
    return l.head->number;
}
int get_tail(single_list l) {
    return l.tail->number;
}
double count_avg(single_list l) {
    double x = 0;
    element* temp = new element;
    temp = l.head;
    for (int i=0; i<l.counter; i++) {
        x += temp->number;
        temp = temp->next;
    }
    x /= (l.counter*1.0);
    return x;
}
int find_max(single_list l, int* pos) {
    int MAX = l.head->number;
    element* temp = new element;
    temp = l.head;
    for (int i=0; i<l.counter; i++) {
        if (temp->number > MAX) {
            MAX = temp->number;
            *pos = i;
        }
        temp = temp->next;
    }
    return MAX;
}
