#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define SIZE 20

void BIGzone(char zone[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int k = 0; k < SIZE; k++){
            printf("%c",zone[k][i]);
        }
        printf("\n");
    }
}

int main(){
    char zone[SIZE][SIZE]; // oyin maydoni so'nini chaqiramiz
    int zone_x, zone_y; // zonada R harakatga tushirish uchun elemen ochiib o'zgaruvchilarni berdim
    
    srand(time(NULL)); // bu 1970 yildan to hozirgacha bo'lgan so'ni olib rand()da joylaydi
    
    // bu oyin zonedagi bosh joylarni '.' to'ldiradi
    for(int i = 0; i < SIZE; i++){
        for(int k = 0; k < SIZE; k++){
            zone[i][k] = '.';
        }
    }
    
    zone_x = rand() % SIZE; // tasodifiy tarzda tushadi faqat x qatorida
    zone_y = rand() % SIZE; // tasodifiy tarzda tushadi faqat z qatorida
    zone[zone_x][zone_y] = 'R'; // bu zona ichida joylashtirish masalan 14X14
    
    char key; // bu kinopka vazifasni bajarishi uchun function ochdim to'g'ri pashda ham birgalikda ochsam bo'lardi!! lekin profsional!!
    int maqsad_x, maqsad_y;   // zonada maqsadni qoyishi uchun elemen ochiib o'zgaruvchilarni berdim
    
    maqsad_x = rand() % SIZE; // tasodifiy tarzda tushadi faqat x qatorida
    maqsad_y = rand() % SIZE; // tasodifiy tarzda tushadi faqat y qatorida
    zone[maqsad_x][maqsad_y] = 'G'; // bu ham R kabi faqat maqsadga erishish uchun G qoydim
    
    while(1){
        system("cls"); // echki zoneni boshatib berishi uchun qoydik bu faqat linux macoslar uchun ishlamaydi windows uchun ishlaydi
        BIGzone(zone); // yangi zone ni kiritish
        printf("O'yini maqsadga yetaklang sunda yutasiz harakat tugmalar uchun: 'w' 's' 'a' 'd' yoki o'q ko'rsatgich tugmalardan ham foydalansangiz ham bo'ladi\n");
        key = getch(); // bu kinopkaniga mosh kodlar mavjud bo'ladi 
        zone[zone_x][zone_y] = '.'; // bu bosh qolgan joyni to'ldirib ketishi uchun
        if((key == 'w' || key == 'W' || key == 72) && zone_y > 0) zone_y--; // bera shart bergan mang agar w ni yoki ko'rsatgichini bo'sha tepada ko'tarilshin va 0 borganda ozi chegara qoyilshin!!
        else if((key == 's' || key == 'S' || key == 80) && zone_y < SIZE - 1) zone_y++; // bera es pastda 
        else if((key == 'a' || key == 'A' || key == 75) && zone_x > 0) zone_x--;
        else if((key == 'd' || key == 'D' || key == 77) && zone_x < SIZE - 1) zone_x++;
        else if(key == 'q' || key == 'Q')break;
        if(zone_x == maqsad_x && zone_y == maqsad_y){
            system("cls");
            printf("maqsadingizda erishdingiz\n");
            break;
        }
        zone[zone_x][zone_y] = 'R';
    }
    printf("O'yin tugadi!\n");
    return 0;
}