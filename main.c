#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    unsigned long nummer;
    char name[80];
    short geb_jahr;
    unsigned short geschlecht; // 0 - d, 1 - w, 2 - m
} kunde;

#define NUM_PASSWDS 3
const char *passwd[NUM_PASSWDS] = {
    "123foo", "bar456", "bla_blubb"
};

void dreieck(int anzahl_zeilen) {
    // print out triangle with 'X'
    char arr[1000];
    int index=0;
    for (int i=1; i<=anzahl_zeilen; i++) {
        for (int j=1; j<=i; j++) {
            arr[index] = 'X';
            index++;
        }
        arr[index] = '\n';
        index++;
    }
    arr[index] = '\0';
    printf("%s", arr);
}

int quad(char art[], int width) {
    // returns length of string with 'X' in it
    for (int i=0; i<width; i++) {
        for(int j=0; i<width; j++) {
            art[(i*(width+1)+j)] = 'X';
        }
        art[(i*(width+1)+width)] = '\n';
    }
    art[(width+1)*width] = '\0';
    return strlen(art);
}

void quad2(char art[][7], int width) {
    // returns length of twodimensional string
    // TODO
}

unsigned string_length(char str[]) {
    // returns length of string
    unsigned length=0;
    char next;
    while (str[length] != '\0') {
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

int einfuegen(kunde kdb[], int index) {
    // inserts one client in the database at position 'index'
    // returns new highest index of db
    // TODO
}

void anzeigen(kunde kdb[], int index) {
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
    kunde kdb[1000];

    char eingabe;
    while (eingabe != 'x') {
        
        printf("Bitte geben Sie die Aufgabe an: ");
        scanf(" %c", &eingabe);
        switch (eingabe) {
        case 'a': break;
        case 'b': break;
        case 'c': dreieck(5); break;
        case 'd': quad(art, 5); break;
        case 'e': break;
        case 'f': break;
        case 'g': break;
        case 'h': break;
        
        case 'x': break;
        default : eingabe =' ';
        }
    }
    return 0;
}