
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N = 20; // Liczebnoœæ zbioru.

int d[N];

// Procedura sortowania szybkiego
//-------------------------------

void Sortuj_szybko(int lewy, int prawy, int tryb);

int main()
{
  int i, tryb;

  srand((unsigned)time(NULL));

  while (tryb != 0 && tryb != 1) {
        cout << "Podaj tryb sortowania\n1 - rosnaco\n0 - malejaco\nTryb: ";
        cin >> tryb;
    }
    return 0;

  for(i = 0; i < N; i++) d[i] = rand() % 100;
  for(i = 0; i < N; i++) cout << setw(4) << d[i];
  cout << endl;

// Sortujemy

  Sortuj_szybko(0,N - 1,tryb);

// Wyœwietlamy wynik sortowania

  cout << "Po sortowaniu:\n\n";
  for(i = 0; i < N; i++) cout << setw(4) << d[i];
  cout << endl;
  return 0;
}


void Sortuj_szybko(int lewy, int prawy, int tryb)
{
    int i, j, piwot;

    i = (lewy + prawy) / 2;
    piwot = d[i]; d[i] = d[prawy];
    for (j = i = lewy; i < prawy; i++)

        if (tryb == 1)
        {
        if (d[i] < piwot)
        {
            swap(d[i], d[j]);
            j++;
        }
    d[prawy] = d[j]; d[j] = piwot;
    if (lewy < j - 1)  Sortuj_szybko(lewy, j - 1);
    if (j + 1 < prawy) Sortuj_szybko(j + 1, prawy);
        }
    if (tryb == 0)

    {
        if (d[i] < piwot)
        {
            swap(d[i], d[j]);
            j++;
        }
    d[prawy] = d[j]; d[j] = piwot;
    if (lewy > j - 1)  Sortuj_szybko(lewy, j - 1);
    if (j + 1 > prawy) Sortuj_szybko(j + 1, prawy);
    }
}
