#include <stdio.h>
#include <string.h>

char art[1000];

void dreieck(int anzahl_zeilen) {
    char arr[anzahl_zeilen];
    for (int i=0; i<anzahl_zeilen; i++) {
        arr[i] = i*'X' +'\n';
        arr[anzahl_zeilen-1] = i*'X' +'\0';
    }
}

int quad(char art[], int width) {
    for (int i=0; i<width; i++) {
        printf("%.*s", i, 'X');
        printf("\n");
    }
    printf("\0");
    return strlen(art);
}


int main() {
    // dreieck(7);
    printf("%s", quad(art, 5));
}