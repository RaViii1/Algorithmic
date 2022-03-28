#include <iostream>
#include <stdlib.h>

using namespace std;

struct element
{
    int number;
    element* next;
};


void push(element*& stack, int value );
void pop(element*& stack);
bool isEmpty(element*stack);
int top(element* stack);


int main()
{

int wybor;
element* stack = nullptr; //=nullptr
do{
    cout << endl <<"Wybierz dzaialnie:\n1 - pusty?\n2 - dodaj element\n3 - usun element\n4 - wierzcholek\n5 - usuniecie stosu\n6- wyjscie" << endl;
    cin >> wybor;

switch(wybor)
    {
    case 1:
        cout << endl;
        cout << (isEmpty(stack) ? "Stos jest pusty\n" : "Stos nie jest pusty\n");
        break;
    case 2:
        cout << endl;
        push(stack, rand() % 10+1 );
        cout << "Dodany element: " << top(stack) << endl;
        break;
    case 3:
        cout << endl;
        if(!isEmpty(stack))
            {
                pop(stack);
                cout << "Usunieto element" << endl;
            }else cout << "Stos jest pusty" << endl;
        break;
    case 4:
        cout << endl;
        if(!isEmpty(stack))
            {
                cout << "wierzcholek: " << top(stack) << endl;
            }else cout << "Stos jest pusty" << endl;
        break;
    case 5:
        while(!isEmpty(stack)) pop(stack);
        cout << "Usunieto stos" << endl;
        break;

    }
}while( wybor != 6);
    return 0;
}


void push(element*& stack, int value )
{
    element* el = new element;
    el->number = value;
    el->next = stack;
    stack = el;
}

void pop(element*& stack)
{
    element* temp = stack;
    stack = stack-> next;
    delete temp;
}

bool isEmpty(element*stack)
{
    if(stack == nullptr) return 1;
    else return 0;
}

int top(element* stack)
{
    if(!isEmpty(stack))
    return stack -> number;
}
