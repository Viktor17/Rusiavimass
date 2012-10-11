#include <iostream>
#include <stdlib.h>
template <class T> void exch(T &, T &, int&);
template <class T> void compexch(T &, T &, int&);
template <class T> void selection(T *, int, int, int&, int&);
template <class T> void insertion(T *, int, int, int&, int&);
template <class T> void bubble(T *, int, int, int&, int&);
using namespace std;
int main(int argc, char *argv[])
{
    int i, rus, N = 1000;
    int kiekS = 0;
    int kiekL =0;
    //atoi(argv[1]), KaDaryt = atoi(argv[2]);
    int *a = new int[N];
    //if (KaDaryt) // Atsitiktinai sugeneruoja N skaiÄ?iÅ³ intervale: 1,...,1000.
      for (i = 0; i < N; i++)
        a[i] = 1000*(1.0*rand()/RAND_MAX);
  //    for (i = 0; i < N; i++)
    //    a[i] = i;
    int j=N;
    for (i = 0; i < N; i++){
        a[i] = j ;
        --j;
        }
   // else // Savo nuoÅ¾iÅ«ra Ä¯vedame skaiÄ?ius. NorÄ—dami baigti Ä¯vedimÄ…, Ä¯vedame bet kokÄ¯ simbolÄ¯ - ne skaiÄ?iÅ³.
   //   { N = 0; while (cin >> a[N]) N++; }
    cout << "Ivestas skaiciu masyvas yra:" << endl;
    for (i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;
    cout << "pasirinkite rusiavima: "<< endl;
    cout << "Isrinkimo algoritmas spauskite   1"<< endl;
    cout << "Iterpimo algoritmas spauskite    2"<< endl;
    cout << "Burbuliuko algoritmas spauskite  3"<< endl;
    cin >> rus;
    switch(rus){
     case 1 :
          selection(a, 0, N-1, kiekS, kiekL);
          break;
     case 2 :
           insertion(a, 0, N-1, kiekS,  kiekL);
          break;
     case 3 :
           bubble(a, 0, N-1, kiekS, kiekL);
          break;

    default:
       cout << "?vesta reik?m? n?ra 1, 2 arba 3'";
       break;
       }
    cout << "Surusiuotas skaiciu masyvas yra:" << endl;
    for (i = 0; i < N; i++) cout << a[i] << " ";
    cout <<  endl;
    cout << "Sukeitimo kiekis: " << kiekS << endl;
    cout << "Lyginimo kiekis: " << kiekL << endl;
    system("PAUSE");
}
// SukeiÄ?ia elementus vietomis
template <class T>
  void exch(T &A, T &B, int &kiekS)
    { T t = A ; A = B; B = t; kiekS++; }
// SukeiÄ?ia elementus vietomis tik jei patenkinta sÄ…lyga
template <class T>
  void compexch(T &A, T &B, int &kiekS)
    { if (B < A) exch(A, B, kiekS); }
// IÅ?rinkimo algoritmo realizacija
template <class T>
void selection(T a[], int l, int r, int &kiekS, int &kiekL)
  { for (int i = l; i < r; i++)
      { int min = i;
        for (int j = i+1; j <= r; j++)
            if (a[j] < a[min]){
                      min = j;
                      kiekL++; //Lyginimas
                      }
        exch(a[i], a[min], kiekS); //sukeitimas
      }

  }
// Ä®terpimo algoritmo realizacija
template <class T>
void insertion(T a[], int l, int r, int &kiekS, int &kiekL)
  { int i;
    for (i = r; i > l; i--) {
    compexch(a[i-1], a[i],kiekS );
    kiekL++;//palyginimas
}
    for (i = l+2; i <= r; i++)
      { int j = i; T v = a[i];
        while (v < a[j-1])
          { a[j] = a[j-1]; j--; }
        a[j] = v;
      }
  }
// Burbulo algoritmas
template <class T>
void bubble(T a[], int l, int r,  int &kiekS, int &kiekL)
  { for (int i = l; i < r; i++)
      for (int j = r; j > i; j--){
        compexch(a[j-1], a[j], kiekS);
        kiekL++;//Lyginimas
        }
  }

