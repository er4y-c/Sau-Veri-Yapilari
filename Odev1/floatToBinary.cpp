#include <iostream>
#include <stdlib.h>

using namespace std;

void intToBinary(int );
void floatToBinary(float );

int main() {
    float sayi,kalan;
    int sayi2;
    cout<<"Cevrilecek sayiyi giriniz : ";
    cin>>sayi;
    sayi2 = sayi;
    intToBinary(sayi2);
    kalan = sayi - sayi2;
    cout<<'.';
    floatToBinary(kalan);
    return 0;
}
void intToBinary(int sayi1) {
    int sayi2,sayac,i;
    sayi2 = sayi1;
    for (sayac = 0;;sayac++)
    {
        if(sayi1<2) 
        {
            break;
        }
        sayi1 /= 2;
    }
    int dizi[sayac];
    for (i = 0;; i++)
    {
        if (sayi2<2)
        {
            dizi[i] = sayi2 % 2;
            break;
        }
        dizi[i] = sayi2 % 2;
        sayi2 /= 2;
    }
    for (int j = i; j>=0; j--)
    {
        cout<<dizi[j];
    }
}
void floatToBinary(float kalan) {
    int* ptr = (int*) malloc(sizeof(int) * 23);
    int i = 0;
    while (true)
    {
        if(kalan==1) {
            ptr[i] = 0;
            break;
        }
        else if(kalan>1) {
            kalan -= 1;
            ptr[i] = 1;
        }
        else if (kalan<1)
        {
            ptr[i] = 0;
        }
        kalan *= 2;
        i++;
        if (i==23)
        {
            break;
        }    
    }
    for (i=0; i<23; i++)
    {
        if (ptr[i] !=0 && ptr[i]!=1)
        {
            break;
        }
        cout<<ptr[i];
    }  
    free(ptr);  
}