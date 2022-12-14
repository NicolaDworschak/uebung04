#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

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

//Aufgabe C
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

//Aufgabe D
int quad(char art[], int width) {
    // returns length of string with 'X' in it
    for (int i=0; i<width; i++) {
        for(int j=0; j<width; j++) {
            art[(i*(width+1)+j)] = 'X';
            // printf(" | %d, %d", i, j);
        }
        art[(i*(width+1)+width)] = '\n';
    }
    art[(width+1)*width] = '\0';

    //output
    printf("%s", art);
    return strlen(art);
}

// Aufgabe E
void quad2(char art[][1], int width) {
    // returns length of twodimensional string
    // TODO
}

//Aufgabe F
unsigned string_length(char str[]) {
    // returns length of string
    unsigned length=0;
    while (str[length] != '\0') {
        length += 1;
    }
    return length;
}

// Aufgabe G
bool palindrom(char str[]) {
    // checks wether string is a palindrom
    unsigned len = string_length(str);
    for (int i=0; i<(len/2); i++){
        if (str[i] != str[len-1-i]) 
        return false;
    }
    return true;
}

//Aufgabe H
void entferne(char str[], char c) {
    // removes given char from string on first occourance
    unsigned len = string_length(str);
    for (int i=0; i<len; i++) {
        if (str[i] == c) {
            for (int j=i; j<len; j++) {
                str[j] = str[j+1];
            }
            break;
        }
    }
    printf("%s\n", str);
}

//Aufgabe I
int pwAbfrage(char pass[]) {
    // checks wether global list contains given string
    // returns index if string is found + msg box
    for (int i=0; i<NUM_PASSWDS; i++) {
        if (strcmp(pass, passwd[i]) == 0)
        return i;
    }
    return -1;
}

void aufgabeI() {
    char eingabe[40];
    int tmp;
    for (int i=0; i<3; i++) {
        printf("Bitte geben Sie Ihr Passwort ein: ");
        scanf("%s", eingabe);
        tmp = pwAbfrage(eingabe);
        if (tmp != -1) {
            printf("Sie haben das Passwort korrekt eingegeben! Es lautet: %s\n", eingabe);
            break;
        }
        else if (i==2 && tmp == -1) {
            printf("Sie haben die maximale Anzahl an Versuchen erreicht.\n");
        }
    }
}

/*
unsigned long highest_client_number(kunde kdb[], int index) {
    for (int i=0; i<index; i++) {
        int highest_client_number = kdb[0].nummer;
        if (!kdb[0].nummer) {
            return 1;
        }
        else if (kdb[i].nummer > highest_client_number) {
            highest_client_number = kdb[i].nummer;
        }
    }
    return highest_client_number;
} 
*/

//Aufgabe J
int einfuegen(kunde kdb[], int index) {
    // inserts one client in the database at position 'index'
    // returns new highest index of db

    unsigned long new_number;
    char new_name[80];
    short new_geb_jahr;
    unsigned short new_geschlecht;

    // get new client number
    new_number = kdb[index].nummer + 1;

    printf("Bitte geben Sie den Namen des Kunden, welcher hinzugefuegt werden soll, ein: ");
    scanf("%s", new_name);
    printf("Bitte geben Sie das Geburtsjahr des Kunden, welcher hinzugefuegt werden soll, ein: ");
    scanf("%hi", &new_geb_jahr);
    printf("Bitte geben Sie das Geschlecht (0 - d, 1 - w, 2 - m) des Kunden, welcher hinzugefuegt werden soll, ein: ");
    scanf("%hu", &new_geschlecht);

    kdb[index].nummer = new_number;
    strcpy(kdb[index].name, new_name);
    kdb[index].geb_jahr = new_geb_jahr;
    kdb[index].geschlecht = new_geschlecht;

    return (index += 1);
}

void anzeigen(kunde kdb[], int index) {
    // shows data at index in kdb
    int show;
    printf("Bitte geben Sie den zu zeigenden Index an: ");
    scanf("%d", &show);

    printf("Kundennummer: %u\n", kdb[show].nummer);
    printf("Name: %s\n", kdb[show].name);
    printf("Geburtsjahr: %hi\n", kdb[show].geb_jahr);
    printf("Geschlecht (0 - d, 1 - w, 2 - m): %u\n", kdb[show].geschlecht);    
}

void menu(kunde kdb[], int index) {
    while (true) {
        int wahl;
        printf("<1> Neuen Datensatz anlegen\n");
        printf("<2> Vorhanden Datensatz abrufen\n");
        printf("<0> Ende\n");
        printf("Ihre Wahl: ");
        scanf("%d", &wahl);
        
        if (wahl == 0) {
            break;;
        }
        else if (wahl == 1) {
            index = einfuegen(kdb, index);
        }
        else {
            anzeigen(kdb, index);
        }
    }
}

//Aufgabe K
void begruessung() {
    // ask for name and say hello via dynamic string
    // insert 'Hallo' + name in dynamic string and return
    char *text = (char*)malloc(sizeof(char));
    printf("Bitte geben Sie Ihren Namen ein: ");
    scanf(" %s", text);

    printf("Hallo %s!\n", text);

    free (text);
}

int main() {
    char art[1000];
    kunde kdb[1000]; // Kundendatenbank
    char str[] ={"Hello World!"};
    char pal[] ={"anna"};
    int index=0;

    char eingabe;
    while (eingabe != 'x') {
        
        printf("Bitte geben Sie die Aufgabe an: ");
        scanf(" %c", &eingabe);
        
        switch (eingabe) {
        case 'a': break;
        case 'b': break;
        case 'c': dreieck(5); break;
        case 'd': printf("%d\n", quad(art, 10)); break;
        case 'e': break;
        case 'f': printf("%u\n", string_length(str)); break;
        case 'g': printf("%d\n", palindrom(pal)); break;
        case 'h': entferne(str, 'l'); break;
        case 'i': aufgabeI(); break;
        case 'j': menu(kdb, index); break;
        case 'k': begruessung(); break;
        case 'x': break;
        default : eingabe =' ';
        }
    }
    return 0;
}
