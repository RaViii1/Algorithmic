#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

struct element{
	int number;
	element *next;
	element *prev;
};

struct double_list{
	element *head;
	element *tail;
	int counter;
};
void add_tail(double_list &l, int value){
	element *el = new element;
	el->number = value;
	el->next = nullptr;
	el->prev = nullptr;
	if(l.tail != nullptr){
		l.tail->next = el;
		el->prev = l.tail;
	}
	else l.head=el;
	l.tail=el;
	l.counter++;
}

void add_head(double_list &l, int value){  // dodanie na poczatek listy
    element *el = new element;
	el->number = value;
	el->next = nullptr;
	el->prev = nullptr;
	if(l.head != nullptr){
		l.head->prev=el;
		el->next=l.head;
	}
	else l.tail=el;
	l.head=el;
	l.counter++;
}

void add_pozycja(double_list &l, int value, int pozycja){  // dodanie na okreslona pozycje
	element *temp = new element;
	temp = l.head;
	for(int i=0; i<pozycja-1; i++){
		temp = temp->next;
	}
	element *el = new element;
	el->number=value;
	el->prev=temp;
	el->next=temp->next;
	temp->next->prev=el;
	temp->next = el;
	l.counter++;
}

int delete_tail(double_list &l){  // usuniecie z konca listy
	element *temp = new element;
	temp = l.tail;
	int liczba = l.tail->number;
	if(l.counter == 0){
		l.tail = nullptr;
		l.head = nullptr;
	}
	else {
		l.tail=l.tail->prev;
		l.tail->next=nullptr;
	}
	delete temp;
	l.counter--;
	return liczba;
}

int delete_head(double_list &l){  // usuniecie z poczatku listy
	element *temp = new element;
	temp = l.head;
	int liczba = l.head->number;
	if(l.counter == 0){
		l.tail = nullptr;
		l.head = nullptr;
	}
	else{
		l.head=l.head->next;
		l.head->prev=nullptr;
	}
	delete temp;
	l.counter--;
	return liczba;
}

int delete_pozycja(double_list &l, int pozycja){  // usuniecie z okreslonej pozycji
	element *temp = new element;
	element *temp_us = new element;
	int liczba;
	temp = l.head;
	for(int i=0; i<pozycja-1; i++){
		temp=temp->next;
	}
	temp_us=temp->next;
	liczba = temp_us->number;
	temp->next=temp_us->next;
	temp->next->prev=temp;
	delete temp_us;
	l.counter--;
	return liczba;
}
bool isEmpty(double_list l) {
    return l.counter==0;
}
void showPoczDoKon(double_list l) {
    element* temp = new element;
    temp = l.head;
    for (int i=0; i<l.counter; i++) {
        cout<<temp->number<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void showKonDoPocz(double_list l) {
    element* temp = new element;
    temp = l.tail;
    for (int i=0; i<l.counter; i++) {
        cout<<temp->number<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}
int getMinimum (double_list l, int *pozycja) {
	element* temp = new element;
    temp = l.head;
	int MIN = l.head->number;
    for (int i=0; i<l.counter; i++) {
        if (temp->number < MIN) {
			*pozycja = i;
			MIN = temp->number;
		}
        temp = temp->next;
    }
	return MIN;
}
int main(){
    double_list l;
    l.head = nullptr;
    l.tail = nullptr;
	l.counter = 0;
    int wybor, liczba, pozycja;
    srand(time(NULL));
    bool exit = false;
    while(!exit){
        cout<<"Menu: "<<endl;
        cout<<"1. Czy lista jest pusta"<<endl;
        cout<<"2. Dodaj element na koniec listy"<<endl;
        cout<<"3. Dodaj element na poczatek listy"<<endl;
        cout<<"4. Dodaj element na okreslina pozycje listy"<<endl;
        cout<<"5. Usun element z konca listy"<<endl;
        cout<<"6. Usun element z poczatku listy"<<endl;
        cout<<"7. Usuniecie elementu z okreslonej pozycji listy"<<endl;
        cout<<"8. Wyswietlenie elementow od poczatku do konca"<<endl;
        cout<<"9. Wyswietlenie elementow od konca do poczatku"<<endl;
        cout<<"10. Element minimalny listy"<<endl;
        cout<<"11. Usuniecie calej listy oraz zwolnienie pamieci"<<endl;
        cout<<"12. Wyjscie z programu"<<endl;
        cout<<"Podaj wybor: "<<endl;
        cin>>wybor;
        //system("CLS");
    switch(wybor){
        case 1:{
            if(isEmpty(l)){
                cout<<"Lista jest pusta"<<endl;
            }
            else{
                cout<<"Lista nie jest pusta"<<endl;
            }
            break;
        }
        case 2:{
        	liczba = rand()%50+1;
        	add_tail(l, liczba);
            cout<<"Dodano element na koniec listy: "<<liczba<<endl;
            break;
        }
        case 3:{
        	liczba = rand()%50+1;
        	add_head(l, liczba);
            cout<<"Dodano element na poczatek listy: "<<liczba<<endl;
            break;
        }
        case 4:{
        	cout<<"Podaj pozycje w liscie na ktora chcesz dodac element: ";
        	cin>>pozycja;
        	liczba = rand()%50+1;
        	add_pozycja(l, liczba, pozycja);
            cout<<"Dodano element na okreslona pozycje lsity: "<<liczba<<endl;
            break;
        }
        case 5:{
            if (!isEmpty(l)) cout<<"Usunieto ostatni element z listy: "<<delete_tail(l)<<endl;
            break;
        }
        case 6:{
            if (!isEmpty(l)) cout<<"Usunieto pierwszy element z listy: "<<delete_head(l)<<endl;
            break;
        }
        case 7:{
			if (!isEmpty(l)) {
				cout<<"Podaj pozycje w liscie z ktorej chcesz usunac element: ";
				cin>>pozycja;
				if (pozycja < 0 || pozycja >= l.counter) cout<<"Podana pozycja nie istnieje."<<endl;
				else {
					if (pozycja == 0) cout<<"Usunieto pierwszy element z listy: "<<delete_head(l)<<endl;
					else {
						if (pozycja == l.counter-1) cout<<"Usunieto ostatni element z listy: "<<delete_tail(l)<<endl;
						else cout<<"Usunieto "<<pozycja+1<<". element z listy: "<<delete_pozycja(l,pozycja)<<endl;
					}
				}
			}
			break;
        }
        case 8:{
			if (!isEmpty(l)) showPoczDoKon(l);
        	break;
        }
        case 9:{
			if (!isEmpty(l)) showKonDoPocz(l);
        	break;
		}
        case 10:{
			if (!isEmpty(l)) cout<<"Najmniejszy element listy: "<<getMinimum(l, &pozycja)<<", Pozycja: "<<pozycja<<endl;
        	break;
		}
		case 11:{
			while (!isEmpty(l)) liczba = delete_tail(l);
		    break;
		}
        case 12:{
            exit = true;
            break;
        }
        default:{
        cout<<"Nieprawidlowy numer operacji!"<<endl;
        exit = true;
        break;
        }
    }
    }
    cin.ignore();
    cin.get();
    return 0;
}

