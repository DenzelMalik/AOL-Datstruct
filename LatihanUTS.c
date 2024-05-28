#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, j;

struct penumpang{
    char name[30];
    int id;
    struct penumpang *next;
};

struct penerbangan{
    char destination[20];
    int flightID;
    struct penumpang *penumpang;
};

struct penumpang *newnode, *head, *pp; //pointer buat data penumpang
// struct penerbangan *fnewnode, *fhead, *fp; // pointer buat data penerbangan

struct penerbangan flight[5];

void inputFlight() {
    strcpy(flight[0].destination, "Bandung");
    strcpy(flight[1].destination, "Jakarta");
    strcpy(flight[2].destination, "Surabaya");
    strcpy(flight[3].destination, "Medan");
    strcpy(flight[4].destination, "Bali");

    flight[0].flightID = 001;
    flight[1].flightID = 002;
    flight[2].flightID = 003;
    flight[3].flightID = 004;
    flight[4].flightID = 005;
}

void booking() {
    puts("");
    puts("= Booking =");
    char book[20];
    newnode = malloc(sizeof(struct penumpang));
    printf("Pilih Destinasi Penerbangan : ");
    scanf("%s", book);
    printf("Nama : ");
    scanf("%s", newnode->name); getchar();
    printf("ID : ");
    scanf("%d", &newnode->id); getchar();
    
    for(i=0; i<5; i++){
        if(strcmp(book, flight[i].destination) == 0) {
            pp = flight[i].penumpang;
            if(pp != NULL) {
                while(pp->next != NULL) {
                    pp = pp->next;
                }
                pp->next = newnode;
            } else {
                flight[i].penumpang = newnode;
            }
        } else {
            continue; // do nothing
        }
    }
}

void displayList() {
    int opt;
    for(i=0; i<5; i++) {
        printf("- %s : ", flight[i].destination);
        if(flight[i].penumpang != NULL) {
            pp = flight[i].penumpang;
            while(pp != NULL) {
                printf("%s (%d), ", pp->name, pp->id);
                pp = pp->next;
            }
            printf("\n");
        } else {
            puts("");
            continue;
        }
    }
    puts("");
    puts("Opsi");
    puts("1. Book a Flight");
    puts("2. Back to Menu");
    printf(">> ");
    scanf("%d", &opt);
    switch(opt) {
        case 1:
            booking();
            break;
        case 2:
            break;
    }
}

void cancel() { // cari dari nama penerbangan dulu, baru cari id

}

void menu() {
    int opt;
    do {
        puts("");
        puts("MENU");
        puts("1. Jadwal Penerbangan");
        puts("2. Booking");
        puts("3. Display Data Penumpang pada Penerbangan");
        puts("4. Cancel Booking");
        puts("5. EXIT");
        printf(">> ");
        scanf("%d", &opt); getchar();
        switch(opt){
            case 1:
                displayList();
                break;
            case 2:
                booking();
                break;
            case 3:
                break;
            case 4:
                cancel();
                break;
        }
    } while(opt != 5);
}

int main() {
    puts("");
    puts("=== FLIGHT MANAGEMENT ===");
    inputFlight();
    menu();
}