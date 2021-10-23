#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int* ptr;
int* dizi;
int* usPtr;

int intToBinary(int ,int*,int);
void floatToBinary(float);
void yazdir(int,int*,int*);

int main() {
    float sayi,kalan;
    int sayi2,isaretBiti,us,usluSayi,boyut_usPtr,i;
    cout<<"Cevrilecek sayiyi giriniz : ";
    cin>>sayi;
    sayi2 = sayi;
    if(sayi>0) {
        isaretBiti = 0;
    }else if(sayi<0) {
        isaretBiti = 1;
    }
    cout<<isaretBiti<<'.';
    us = intToBinary(sayi2,dizi,0);
    kalan = sayi - sayi2;
    usluSayi = (pow(2,7)-1)+us;
    boyut_usPtr = intToBinary(usluSayi,usPtr,1);
    cout<<'.';
    intToBinary(sayi2,dizi,1);
    floatToBinary(kalan);
    free(ptr);
    free(dizi);
    free(usPtr);
    return 0;
}
int intToBinary(int sayi1, int *dizi, int isaret) {
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
    dizi = (int *) malloc(sizeof(int)* sayac);
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
    if(isaret == 1) {
        for (int j = i-1; j>=0; j--)
        {
            cout<<dizi[j];
        }
    }
    return sayac;
}
void floatToBinary(float kalan) {
    ptr = (int*) malloc(sizeof(int) * 23);
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
        for (i=0; i<12; i++)
        {
            if (ptr[i] !=0 && ptr[i]!=1)
            {
                break;
            }
            cout<<ptr[i];
        }  
}
