#include <stdio.h>
#define N 10
#define M 3

typedef struct {
    int gun;
    char ay[N];
    int yil;
} tarih;

tarih tarihiAl(void);
void tarihiBastir(tarih);

int main(void) {
    tarih date = tarihiAl();
    tarihiBastir(date);
    
    tarih dates[M];
    for(int i=0; i<M; ++i){
        if(i==0){dates[i]=date;}
        else{dates[i]=tarihiAl();}
    }
    for(int i=0; i<M; ++i){
        tarihiBastir(dates[i]);
    }
    return 0;
}

tarih tarihiAl(void){
    tarih temp;
    printf("Gun(1-31) Ay(Ocak-Aralik) Yil olarak bir tarih giriniz:\n");
    scanf("%d %s %d", &temp.gun, temp.ay, &temp.yil);
    return temp;
}

void tarihiBastir(tarih t) {
    printf("Girilen tarih: %d %s %d\n", t.gun, t.ay, t.yil);
}