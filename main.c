#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
double sinif_ortalamasini_hesapla(double HBN[],int N);
double standart_sapma_hesapla(double ortalama, double HBN[], int N);
int main()
{
    int S;
    char cevaplar[S];
    cevap_anahtari_uret(cevaplar,S);
    return 0;
}
 void cevap_anahtari_uret(char cevap_anahtari[],int S){
    printf("Soru sayisini giriniz(max 100):\n");
    scanf("%d",&S);
    int N;
    printf("Ogrenci sayisini giriniz(max 100):\n");
    scanf("%d",&N);
    double B;
    printf("Bos birakma ihtimalini giriniz(0.0~1.0):\n");
    scanf("%lf",&B);
    double D;
    printf("Dogru cevap verme ihtimalini giriniz(0.0~1.0):\n");
    scanf("%lf",&D);
    char ogrencilervecevaplari[N][100];
    int i=1;
    char cevap[100];
    while (i<=S){
    srand(time(0));
    int j=rand()%6;
        if(j==1){
            cevap[i]=1;
            Sleep(1000);
            i++;}
        else if (j==2){
            cevap[i]=2;
            Sleep(1000);
            i++;}
        else if(j==3){
            cevap[i]=3;
            Sleep(1000);
            i++;}
        else if(j==4){
            cevap[i]=4;
            Sleep(1000);
            i++;}
        if(j==5){
            cevap[i]=5;
            Sleep(1000);
            i++;}}
    cevap_anahtari_yazdir(cevap,S);
    sinavi_uygula(ogrencilervecevaplari,cevap,N,S,B,D);
}
void cevap_anahtari_yazdir(char cevap_anahtari[],int S){
    printf("Cevap Anahtari:\n");
    for(int i=1;i<=S;i++){
        if(cevap_anahtari[i]==1)
            printf("%.3d.soru=A | ",i);
        else if(cevap_anahtari[i]==2)
            printf("%.3d.soru=B | ",i);
        else if(cevap_anahtari[i]==3)
            printf("%.3d.soru=C | ",i);
        else if(cevap_anahtari[i]==4)
            printf("%.3d.soru=D | ",i);
        else if(cevap_anahtari[i]==5)
            printf("%.3d.soru=E | ",i);}
        printf("\n\n");
}
void sinavi_uygula(char ogrenci_cevaplari[][100],char cevap_anahtari[],int N,int S,double B,double D){
    double HBN[N];
    int rastgele;
    char ogrenciler[100][100];
    int i,j;
    float t,z;
    for(i=1;i<=N;i++){
        for(j=1;j<=S;j++){
            do{
            srand(time(0));
            t=rand()%11;
            }while(t==0||t==11);
            t=t/10;
            Sleep(250);
            if (t>=B){
                do{
                srand(time(0));
                z=rand()%11;
                }
                while(z==0||t==11);
                z=z/10;
                if (z<D){
                ogrenciler[i][j]=cevap_anahtari[j];}
                else{
                do{
                srand(time(NULL));
                rastgele=rand()%6;
                }while(rastgele==cevap_anahtari[j]||rastgele==0);
                ogrenciler[i][j]=rastgele;}}
            else  {
                ogrenciler[i][j]=7;}}}
                ogrenci_cevabini_yazdir(ogrenciler,N,S);
                ogrencileri_puanla(ogrenciler,cevap_anahtari,HBN,N,S);
}
void ogrenci_cevabini_yazdir(char ogrenci_cevaplari[][100],int ogrenci_ID,int S){
    for (int i=1;i<=ogrenci_ID;i++){
        printf("\n%d.ogrencinin cevaplari:\n",i);
        for (int j=1;j<=S;j++){
            printf("%.3d:",j);
            if (ogrenci_cevaplari[i][j]==1)
                printf("A | ");
            if (ogrenci_cevaplari[i][j]==2)
                printf("B | ");
            if (ogrenci_cevaplari[i][j]==3)
                printf("C | ");
            if (ogrenci_cevaplari[i][j]==4)
                printf("D | ");
            if (ogrenci_cevaplari[i][j]==5)
                printf("E | ");
            if (ogrenci_cevaplari[i][j]==7)
                printf("X | ");
}}}
 void ogrencileri_puanla(char ogrenci_cevaplari[][100],char cevap_anahtari[],double HBN[],int N,int S){
    double ogrencilerinTskoru[N];
    for(int i=1;i<=N;i++){
    double dogru=0,yanlis=0,sonuc=0;
        for(int j=1;j<=S;j++){
            if (ogrenci_cevaplari[i][j]==cevap_anahtari[j])
                dogru=dogru+1;
            if (ogrenci_cevaplari[i][j]!=cevap_anahtari[j])
                yanlis=yanlis+0.25;
            }
    sonuc=(dogru-yanlis)*100/S;
    if(sonuc<0.0){
        HBN[i]=0.0;}
    else HBN[i]=sonuc;
}
double sinifortalamasi=sinif_ortalamasini_hesapla(HBN,N);
printf("\n\nSinif Ortalamasi:%.2lf",sinifortalamasi);
    double standart_sapma=standart_sapma_hesapla(sinifortalamasi,HBN,N);
    printf("\t\tStandart Sapma:%.2lf",standart_sapma);
    printf("\nSinif Duzeyi:");
        if(sinifortalamasi<=42.5)
            printf("Kotu\n");
        if(sinifortalamasi>42.5&&sinifortalamasi<=47.5)
            printf("Zayif\n");
        if(sinifortalamasi>47.5&&sinifortalamasi<=52.5)
            printf("Orta\n");
        if(sinifortalamasi>52.5&&sinifortalamasi<=57.5)
            printf("Ortanin Ustu\n");
        if(sinifortalamasi>57.5&&sinifortalamasi<=62.5)
            printf("Iyi\n");
        if(sinifortalamasi>62.5&&sinifortalamasi<=70.0)
            printf("Cok Iyi\n");
        if(sinifortalamasi>70.0&&sinifortalamasi<=80.0)
            printf("Mukemmel\n");
        if(sinifortalamasi>80.0&&sinifortalamasi<=100.0)
            printf("Ustun Basari\n");
        T_skoru_hesapla(sinifortalamasi,HBN,N,standart_sapma,ogrencilerinTskoru);
}
 double sinif_ortalamasini_hesapla(double HBN[],int N){
    double toplam=0;
    for(int i=1;i<=N;i++){
    toplam=toplam+HBN[i];}
    toplam=toplam/N;
    if (toplam<=0.0)
        toplam=0.0;
    return toplam;}
 double standart_sapma_hesapla(double ortalama, double HBN[], int N){
     double toplam=0,aratoplam=0;
     for (int i=1;i<=N;i++){
        aratoplam=ortalama-HBN[i];
        toplam=aratoplam*aratoplam+toplam;
        aratoplam=0;}
     toplam=toplam/(N-1);
     double sonuc;
     sonuc=sqrt(toplam);
     return sonuc;
}
  void T_skoru_hesapla(double ortalama,double HBN[],int N,double std,double T_skoru[]){
      for (int i=1;i<=N;i++){
        T_skoru[i]=60+(10*((HBN[i]-ortalama)/std));
        printf("\n%d.ogrencinin HBN:%.2lf, T-skoru:%.2lf, harf notu:",i,HBN[i],T_skoru[i]);
    if (ortalama>80.0&&ortalama<=100.0&&32.0>T_skoru[i])
        printf("FF");
    else if (ortalama>80.0&&ortalama<=100.0&&T_skoru[i]>=32.0&&T_skoru[i]<36.99)
        printf("FD");
    else if (ortalama>80.0&&ortalama<=100.0&&T_skoru[i]>=37.0&&T_skoru[i]<41.99)
        printf("DD");
    else if (ortalama>80.0&&ortalama<=100.0&&T_skoru[i]>=42.0&&T_skoru[i]<46.99)
        printf("DC");
    else if (ortalama>80.0&&ortalama<=100.0&&T_skoru[i]>=47.0&&T_skoru[i]<51.99)
        printf("CC");
    else if (ortalama>80.0&&ortalama<=100.0&&T_skoru[i]>=52.0&&T_skoru[i]<56.99)
        printf("CB");
    else if (ortalama>80.0&&ortalama<=100.0&&T_skoru[i]>=57.0&&T_skoru[i]<61.99)
        printf("BB");
    else if (ortalama>80.0&&ortalama<=100.0&&T_skoru[i]>=62.0&&T_skoru[i]<66.99)
        printf("BA");
    else if (ortalama>80.0&&ortalama<=100.0&&67.0<=T_skoru[i])
        printf("AA");

    else if (ortalama>70.0&&ortalama<=80.0&&34.0>T_skoru[i])
        printf("FF");
    else if (ortalama>70.0&&ortalama<=80.0&&T_skoru[i]>=34.0&&T_skoru[i]<38.99)
        printf("FD");
    else if (ortalama>70.0&&ortalama<=80.0&&T_skoru[i]>=39.0&&T_skoru[i]<43.99)
        printf("DD");
    else if (ortalama>70.0&&ortalama<=80.0&&T_skoru[i]>=44.0&&T_skoru[i]<48.99)
        printf("DC");
    else if (ortalama>70.0&&ortalama<=80.0&&T_skoru[i]>=49.0&&T_skoru[i]<53.99)
        printf("CC");
    else if (ortalama>70.0&&ortalama<=80.0&&T_skoru[i]>=54.0&&T_skoru[i]<58.99)
        printf("CB");
    else if (ortalama>70.0&&ortalama<=80.0&&T_skoru[i]>=59.0&&T_skoru[i]<63.99)
        printf("BB");
    else if (ortalama>70.0&&ortalama<=80.0&&T_skoru[i]>=64.0&&T_skoru[i]<68.99)
        printf("BA");
    else if (ortalama>70.0&&ortalama<=80.0&&69.0<=T_skoru[i])
        printf("AA");

    else if (ortalama>62.5&&ortalama<=70.0&&36.0>T_skoru[i])
        printf("FF");
    else if (ortalama>62.5&&ortalama<=70.0&&T_skoru[i]>=36.0&&T_skoru[i]<40.99)
        printf("FD");
    else if (ortalama>62.5&&ortalama<=70.0&&T_skoru[i]>=41.0&&T_skoru[i]<45.99)
        printf("DD");
    else if (ortalama>62.5&&ortalama<=70.0&&T_skoru[i]>=46.0&&T_skoru[i]<50.99)
        printf("DC");
    else if (ortalama>62.5&&ortalama<=70.0&&T_skoru[i]>=51.0&&T_skoru[i]<55.99)
        printf("CC");
    else if (ortalama>62.5&&ortalama<=70.0&&T_skoru[i]>=56.0&&T_skoru[i]<60.99)
        printf("CB");
    else if (ortalama>62.5&&ortalama<=70.0&&T_skoru[i]>=61.0&&T_skoru[i]<65.99)
        printf("BB");
    else if (ortalama>62.5&&ortalama<=70.0&&T_skoru[i]>=66.0&&T_skoru[i]<70.99)
        printf("BA");
    else if (ortalama>62.5&&ortalama<=70.0&&71.0<=T_skoru[i])
        printf("AA");

    else if (ortalama>57.5&&ortalama<=62.5&&38.0>T_skoru[i])
        printf("FF");
    else if (ortalama>57.5&&ortalama<=62.5&&T_skoru[i]>=38.0&&T_skoru[i]<42.99)
        printf("FD");
    else if (ortalama>57.5&&ortalama<=62.5&&T_skoru[i]>=43.0&&T_skoru[i]<47.99)
        printf("DD");
    else if (ortalama>57.5&&ortalama<=62.5&&T_skoru[i]>=48.0&&T_skoru[i]<52.99)
        printf("DC");
    else if (ortalama>57.5&&ortalama<=62.5&&T_skoru[i]>=53.0&&T_skoru[i]<57.99)
        printf("CC");
    else if (ortalama>57.5&&ortalama<=62.5&&T_skoru[i]>=58.0&&T_skoru[i]<62.99)
        printf("CB");
    else if (ortalama>57.5&&ortalama<=62.5&&T_skoru[i]>=63.0&&T_skoru[i]<67.99)
        printf("BB");
    else if (ortalama>57.5&&ortalama<=62.5&&T_skoru[i]>=68.0&&T_skoru[i]<72.99)
        printf("BA");
    else if (ortalama>57.5&&ortalama<=62.5&&73.0<=T_skoru[i])
        printf("AA");

    else if (ortalama>52.5&&ortalama<=57.5&&40.0>T_skoru[i])
        printf("FF");
    else if (ortalama>52.5&&ortalama<=57.5&&T_skoru[i]>=40.0&&T_skoru[i]<44.99)
        printf("FD");
    else if (ortalama>52.5&&ortalama<=57.5&&T_skoru[i]>=45.0&&T_skoru[i]<49.99)
        printf("DD");
    else if (ortalama>52.5&&ortalama<=57.5&&T_skoru[i]>=50.0&&T_skoru[i]<54.99)
        printf("DC");
    else if (ortalama>52.5&&ortalama<=57.5&&T_skoru[i]>=55.0&&T_skoru[i]<59.99)
        printf("CC");
    else if (ortalama>52.5&&ortalama<=57.5&&T_skoru[i]>=60.0&&T_skoru[i]<64.99)
        printf("CB");
    else if (ortalama>52.5&&ortalama<=57.5&&T_skoru[i]>=65.0&&T_skoru[i]<69.99)
        printf("BB");
    else if (ortalama>52.5&&ortalama<=57.5&&T_skoru[i]>=70.0&&T_skoru[i]<74.99)
        printf("BA");
    else if (ortalama>52.5&&ortalama<=57.5&&75.0<=T_skoru[i])
        printf("AA");

    else if (ortalama>47.5&&ortalama<=52.5&&42.0>T_skoru[i])
        printf("FF");
    else if (ortalama>47.5&&ortalama<=52.5&&T_skoru[i]>=42.0&&T_skoru[i]<46.99)
        printf("FD");
    else if (ortalama>47.5&&ortalama<=52.5&&T_skoru[i]>=47.0&&T_skoru[i]<51.99)
        printf("DD");
    else if (ortalama>47.5&&ortalama<=52.5&&T_skoru[i]>=52.0&&T_skoru[i]<56.99)
        printf("DC");
    else if (ortalama>47.5&&ortalama<=52.5&&T_skoru[i]>=57.0&&T_skoru[i]<61.99)
        printf("CC");
    else if (ortalama>47.5&&ortalama<=52.5&&T_skoru[i]>=62.0&&T_skoru[i]<66.99)
        printf("CB");
    else if (ortalama>47.5&&ortalama<=52.5&&T_skoru[i]>=67.0&&T_skoru[i]<71.99)
        printf("BB");
    else if (ortalama>47.5&&ortalama<=52.5&&T_skoru[i]>=72.0&&T_skoru[i]<76.99)
        printf("BA");
    else if (ortalama>47.5&&ortalama<=52.5&&77.0<=T_skoru[i])
        printf("AA");

    else if (ortalama>42.5&&ortalama<=47.5&&44.0>T_skoru[i])
        printf("FF");
    else if (ortalama>42.5&&ortalama<=47.5&&T_skoru[i]>=44.0&&T_skoru[i]<48.99)
        printf("FD");
    else if (ortalama>42.5&&ortalama<=47.5&&T_skoru[i]>=49.0&&T_skoru[i]<53.99)
        printf("DD");
    else if (ortalama>42.5&&ortalama<=47.5&&T_skoru[i]>=54.0&&T_skoru[i]<58.99)
        printf("DC");
    else if (ortalama>42.5&&ortalama<=47.5&&T_skoru[i]>=59.0&&T_skoru[i]<63.99)
        printf("CC");
    else if (ortalama>42.5&&ortalama<=47.5&&T_skoru[i]>=64.0&&T_skoru[i]<68.99)
        printf("CB");
    else if (ortalama>42.5&&ortalama<=47.5&&T_skoru[i]>=69.0&&T_skoru[i]<73.99)
        printf("BB");
    else if (ortalama>42.5&&ortalama<=47.5&&T_skoru[i]>=74.0&&T_skoru[i]<78.99)
        printf("BA");
    else if (ortalama>42.5&&ortalama<=47.5&&79.0<=T_skoru[i])
        printf("AA");

    else if (ortalama<=42.5&&46.0>T_skoru[i])
        printf("FF");
    else if (ortalama<=42.5&&T_skoru[i]>=46.0&&T_skoru[i]<50.99)
        printf("FD");
    else if (ortalama<=42.5&&T_skoru[i]>=51.0&&T_skoru[i]<55.99)
        printf("DD");
    else if (ortalama<=42.5&&T_skoru[i]>=56.0&&T_skoru[i]<60.99)
        printf("DC");
    else if (ortalama<=42.5&&T_skoru[i]>=61.0&&T_skoru[i]<65.99)
        printf("CC");
    else if (ortalama<=42.5&&T_skoru[i]>=66.0&&T_skoru[i]<70.99)
        printf("CB");
    else if (ortalama<=42.5&&T_skoru[i]>=71.0&&T_skoru[i]<75.99)
        printf("BB");
    else if (ortalama<=42.5&&T_skoru[i]>=76.0&&T_skoru[i]<80.99)
        printf("BA");
    else if (ortalama<=42.5&&81.0>=T_skoru[i])
        printf("AA");
    }
  }




















