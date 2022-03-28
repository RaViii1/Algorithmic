#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

struct element{
char character;
element* next;
};


struct queue{
element* head;
element* tail;
};



int isEmpty(queue q);
void push(queue &q,char value);
void pop(queue &q);
char first(queue q);
float zpliku(queue &q);
void wczytajPlik(queue &q);
void wyswietl(queue &q);

//////////////////////////////////

int main()
{
    srand(time(NULL));
    queue q;
    int j;
    char value;
    q.head=nullptr;
    q.tail=nullptr;

     bool exit=false;
        while (exit==false)
        {
            cout << "MENU GLOWNE KOLEJKI:"<<endl;
            cout << ""<<endl;
            cout << "1. EMPTY (czy kolejka jest pusta?) "<<endl;
            cout << "2. PUSH (dodaje element na koniec kolejki) "<<endl;
            cout << "3. POP (usuwa element z poczatku kolejki) "<<endl;
            cout << "4. Pierwszy element w kolejce"<<endl;
            cout << "5. Usuniecie calej kolejki"<<endl;
            cout << "6. Wczytanie z pliku"<<endl;//
            cout << "7. Wyswietl kolejke"<<endl;
            cout << ""<<endl;
            cout << "8. Koniec programu "<<endl;

            cout << ""<<endl;
            cout << "Wybor: ";
    int zad;
    cin>>zad;
    switch(zad)
{
case 1:
{
    if(isEmpty(q)==1)
    {
        cout<<"Kolejka jest pusta"<<endl;
    }
    else
    {
        cout<<"Kolejka nie jest pusta"<<endl;
    }
    break;
}
case 2:
{
        int ile;
        cout<<"Ile elementow chcesz wprowadzic?"<<endl;
        cin>>ile;
        cout<<"--------------"<<endl;
        for(j=0;j<ile;j++)
        {
            value=rand()%(100-5+1)+100;
            cout<<value<<endl;
            push(q, value);
        }
        j=ile;
    break;
}
case 3:
    {
        pop(q);
        break;
    }
case 4:
    {
            if(!isEmpty(q))
            {
                cout << "Pierwszy element kolejki - " << first(q) << endl;
            }
            else
            cout << "Kolejka jest pusta, nie ma pierwszego elementu" << endl;
            break;
    }
case 5:
    {
    if(!isEmpty(q))
        {
            cout << "Zostaly usuniete: \n";
            while(true){
                if(!isEmpty(q))
                {
                    cout << first(q) << " ";
                    pop(q);
                }
                else
                    break;
            }
            cout << endl;
        }
            else
                cout << "Kolejka jest pusta!" << endl;
            break;
    }
case 6:
    {
        wczytajPlik(q);
        cout << "Wczytano duze litery  z pliku" << endl;
        break;
    }
case 7:
    {
       if(isEmpty(q))
        {
            cout << "Kolejka jest pusta!" << endl;
        }
        else
            {
                wyswietl(q);
            }
        cout << endl;
        break;
    }
case 8:
    {
        exit=true;
        break;
    }
default:
    {
        cout<<"Nie ma takiego numeru zadania!\n\n"<<endl;
        break;
    }
}
    }
return 0;
    }

 /////////////////////////////////////////

int isEmpty(queue q)
{
    if(q.head == nullptr)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push(queue &q,char value)
{
    element *el = new element;
    el->character=value;
    el->next=nullptr;
    if(q.tail!=nullptr)
    {
        q.tail->next=el;
    }
    else{
        q.head=el;
    }
    q.tail=el;
}
void pop(queue &q)
{
    element *temp = q.head;
    q.head=q.head->next;
    delete temp;
    if(q.head == nullptr)
        q.tail = nullptr;
}

char first(queue q)
{
    return q.head->character;
}

void wyswietl(queue &q)
{
    queue tempQ;
    tempQ.head=nullptr;
    tempQ.tail=nullptr;
    char znak;
    cout << "Kolejka: \n"<<endl;
    while(!isEmpty(q))
    {
        znak = first(q);
        cout << znak << " ";
        push(tempQ, znak);
        pop(q);
    }

    cout <<endl;
    q = tempQ;
}

void wczytajPlik(queue &q)
{
    ifstream plik;
    char x;
    plik.open("znaki2.txt");
    while (plik.get(x))
        if((65 <= x) && (90 >= x))
            push(q,x);
    plik.close();
}
