#include <stdio.h>
#include <stdlib.h>
#define boyut 50

typedef struct stack
{
    int deger;
    struct stack *sonraki;    
}Stack;

int *bas,*son,*kuyruk;
Stack *basl,*bit;
void insert(int );
void list();
int ort();
void push(int ,Stack*);
int pop(Stack*);

int main() {
    char ch;
    int sayi = 0,sayac = 1;
    int dizi[5];
    kuyruk = (int*) malloc(sizeof(int)*boyut);
    bas = kuyruk;
    son = kuyruk;
    FILE* filePtr = fopen("sayilar.txt","r");
    if (filePtr == NULL)
    {
        printf("\nDosya yolu bulunamadi.\n");
        exit(0);
    }
    while((ch=fgetc(filePtr)) != EOF ){
        if(sayac%2==1){
            sayi +=(ch - '0') * 10;
        }
        if(sayac%2==0) {
            sayi += (ch- '0');
            insert(sayi);
            sayi = 0;
        }
        sayac++;
    }
    fclose(filePtr);
    list();
    basl = (Stack*) malloc(sizeof(Stack));
    bit = (Stack*) malloc(sizeof(Stack));
    basl->sonraki = bit;
    int ortalama = ort();
    int *temp = bas;
    while(temp<son) {
        if(*temp<ortalama) {
            push(*temp,basl);
        }
        temp++;
    }
    for (int i=0; i<5; i++)
    {
        dizi[i] = pop(basl);
    }
    printf("\n=======[DIZI]=======\n");
    for (int i=0; i<5; i++)
    {
        printf("%d\n",dizi[i]);
    }
    
    free(kuyruk);
    free(basl);
    free(bit);

    return 0;
}
void insert(int deger) {
    *son = deger;
    son++;
}
void list(){
    printf("\n=======[KUYRUKTAKI ELEMANLAR]=======\n");
    int *temp = bas;
    while(temp<son) {
        printf("%d\n", *temp);
        temp++;
    }
}
int ort() {
    int sayac = 0,toplam = 0;
    int *temp = bas;
    while(temp<son) {
        toplam += *temp;
        sayac++;
        temp++;
    }
    int ortalama = toplam / sayac;
    return ortalama;
}
void push(int deger,Stack* yigin) {
    Stack *stc;
    stc = (Stack*)malloc(sizeof(Stack));
    stc->deger = deger;
    stc->sonraki = yigin->sonraki;
    yigin->sonraki = stc;
}
int pop(Stack* yigin) {
    Stack *gecici;
    int val = yigin->sonraki->deger;
    gecici = yigin->sonraki;
    yigin->sonraki = yigin->sonraki->sonraki;
    free(gecici);
    return val;
}