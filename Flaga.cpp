#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <cstdlib>


using namespace std;

struct student
{
    string imie;
    string nazwisko;
    int punkty;
};

void WczytajDane(string x, student*& tab, int &liczbaStudentow);
//////
void wyswietlStudentow(student* tab, int l, int p);
void wyswietlStudentow_2(student* tab, int i, int n);
void wyswietlStudentow3(student* tab, int i, int k, int n);
//////
void zadanie4_2(student*  tab, int n, int granica);
void zadanie4_3(student*  tab, int n);

void UsunTablice(student *&tab, int liczbaStudentow);

int main()
{
    student *tab;
    int liczbaStudentow, y;
    while(1)
    {
        cout <<"Podaj co chcesz zrobic:\n" << endl;
        cout <<"1) Zadanie 4.1 wczytaj dane" << endl;
        cout <<"2) Zadanie 4.2" << endl;
        cout <<"3) Zadadanie 4.3" << endl;
        cout <<"4) Wyjscie z programu" << endl;
        cin >> y;
        switch(y)
        {
            case 1:
            {
                WczytajDane("studenci.csv", tab, liczbaStudentow);
                cout << "\nDane zostaly wczytane.\n" << endl;
                break;
            }
            case 2:
            {
                zadanie4_2(tab, liczbaStudentow, 10);
                UsunTablice(tab, liczbaStudentow);
                break;
            }
            case 3:
            {
                zadanie4_3(tab, liczbaStudentow);
                UsunTablice(tab, liczbaStudentow);
                break;
            }
            case 4:
                return 0;
        }
    }
}




void WczytajDane(string x, student*& tab, int &liczbaStudentow)
{
    ifstream plik;
    char srednik;
    string linia, punkty;

    plik.open("studenci.csv");
    plik>>liczbaStudentow;
    plik>>srednik;
    plik>>srednik;

    tab = new student[liczbaStudentow];

    for(int i=0; i<liczbaStudentow; i++)
    {
        plik >> linia;
        istringstream ss(linia);

        getline(ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        getline(ss, punkty);

        tab[i].punkty=atoi(punkty.c_str());
    }

    plik.close();
}

//////////////wyswietlanie

void wyswietlStudentow(student* tab, int l, int p)
{
    for(int i=l; i<p; i++)
    {
        cout << tab[i].imie << " " << tab[i].nazwisko << " " << tab[i].punkty << endl;
    }
    cout <<"\n"<< endl;
}



void wyswietlStudentow_2(student* tab, int i, int n)
{
    cout << endl;
    cout << "tablica po podziale:"<<endl;
    cout <<"\nStudenci, ktorzy otrzymali <=10 punktow"<<endl;
    wyswietlStudentow(tab, 0, i);
    cout <<"\nStudenci, ktorzy otrzymali >10 punktow"<<endl;
    wyswietlStudentow(tab, i, n);
}



void wyswietlStudentow3(student* tab, int i, int k, int n)
{
    cout << endl;
    cout << "tablica po podziale:"<<endl;

    cout << "Studenci, ktorzy otrzymali liczbe punktow podzielnych przez 3:\n";
    wyswietlStudentow(tab, 0, i);
    cout << "Studenci, ktorzy otrzymali liczbe punktow podzielnych przez 3 z reszta 1:\n";
    wyswietlStudentow(tab, k, n);
    cout << "Studenci, ktorzy otrzymali liczbe punktow podzielnych przez 3 z reszta 2:\n";
    wyswietlStudentow(tab, i, k);
}


/////////Zadania

void zadanie4_2(student*  tab, int n, int granica)
{
    cout << "tablica przed podzialem:"<<endl;
    wyswietlStudentow(tab, 0, n);
    int i=0;
    for(int j=n-1; i<j; )
    {
        while (tab[i].punkty <= granica && i<j)
        {
            i++;
        }
        while (tab[j].punkty > granica && i<j)
        {
           j--;
        }
        if(i<j)
        {
            swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }
    if (tab[i].punkty<=granica)
    {
        i++;
    }
    wyswietlStudentow_2(tab, i, n);

}

void zadanie4_3(student*  tab, int n)
{
    cout << "tablica przed podzialem:"<<endl;

    wyswietlStudentow(tab, 0, n);

    int i=-1;
    int j=0;
    int k=n; //liczba studentow
    while(j<k)
    {
        if(tab[j].punkty%3==0)
        {
            i++;
            swap(tab[i], tab[j]);
            j++;
        }
        else if(tab[j].punkty%3==1)
        {
            k--;
            swap(tab[k], tab[j]);
        }
        else
            j++;
    }
    wyswietlStudentow3(tab, i+1, k, n);
}

void UsunTablice(student *&tab, int liczbaStudentow)
{
    delete []tab;
}
