#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct kunde {
    unsigned long nummer;
    char name[80];
    short geb_jahr;
    unsigned short geschlecht; // 0 - d, 1 - w, 2 - m
}

#define NUM_PASSWDS 3
const char *passwd[NUM_PASSWDS] = {
    "123foo", "bar456", "bla_blubb"
};

void dreieck(int anzahl_zeilen) {
    // print out triangle with 'X'
    char arr[anzahl_zeilen];
    for (int i=0; i<anzahl_zeilen; i++) {
        arr[i] = i*'X' +'\n';
        arr[anzahl_zeilen-1] = i*'X' +'\0';
    }
}

int quad(char art[], int width) {
    // returns length of string with 'X' in it
    for (int i=0; i<width; i++) {
        char buff[] = {'X'};
        char *ptr = buff;
        art[i] = width* *ptr;
    }
    art[width] = '\0';
    return strlen(art);
}

void quad2(char art[][7], int width) {
    // returns length of twodimensional string
    // TODO
}

unsigned string_length(char str[]) {
    // returns length of string
    int length=0;
    char next;
    while (next != '\0') {
        next = str[length];
        length += 1;
    }
    return length;
}

bool palindrom(char str[]) {
    // checks wether string is a palindrom
    // TODO
}

void entferne(char str[], char c) {
    // removes given char from string on first occourance
    // TODO 
}

int pwAbfrage(char pass[]) {
    // checks wether global list contains given string
    // returns index if string is found + msg box
    // TODO
}

int einfuegen(struct kunde kdb[], int index) {
    // inserts one client in the database at position 'index'
    // returns new highest index of db
    // TODO
}

void anzeigen(struct kunde kdb[], int index) {
    // shows data at index in kdb
    // TODO
}

void begruessung() {
    // ask for name and say hello via dynamic string
    // insert 'Hallo' + name in dynamic string and return
    // TODO
}

int main() {
    char art[1000];

    /*
    switch (*expression*)
    {
    case *constant-expression*:
        *code*
        break;
    
    default:
        break;
    }*/
}