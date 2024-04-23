/**********************************************************/
/* Autor: Kasim Mermer                                    */
/* Datum: 16.11.2016									  */
/* Projekt: P8A1										  */
/* Beschreibung: Lottozahlen / Zufallszahlen			  */
/**********************************************************/
#include <stdio.h>
#include <stdlib.h>		// für atoi- Funktion
#include <string.h>		// für strlen- Funktion
#include <ctype.h>		// für isDigit- Funktion
#include <time.h>		// für Zeit bzw.: time(0)- Funktion
#define Lottozahlen 6	// Definition der Zahlen
#define Groesse 10
#define max_Lottozahlen 49
#define min_Lottozahlen 1
#define versuche 5		// wann wieviele richtig sind soll es ausgeben
#define versuche2 4
#define versuche3 3

int pruefen(char[Groesse]);		// Funktionsdeklaration

int main(void) {		// Hauptprogramm
	char eingabe[Groesse] = { 0 };		// charakter array. für string eingabe
	int zahlen_selber[Lottozahlen] = { 0 };	// integer array. für zahlen die man selber eingibt
	int zahlen_zufall_int[Lottozahlen] = { 0 };
	int index = 0, index2 = 0, beenden = 1, ausgeben = 0, ausgeben1 = 0, ausgeben2 = 0;	// initialisierungen
	long int counter = 0;
	int richtig = 0;
	srand(time(NULL));	// initialisiert den zufallsgenerator. und die zeit ist der initialisierungswert des zufallsgenerators.

	while (beenden != 0) {		// solange die Variable beenden nciht den Wert 0 hat soll es die endlosschleife nciht verlassen
		for (index = 0; index < Lottozahlen; index++) {		// index = 0 setzen. solange index < lottozahlen(definiert) soll es ausführen. nach jedem durchgang soll es index um 1 erhöhen
			printf("Geben sie die %i.te Zahl ein:\t", index + 1);		// Textausgabe
			fgets(eingabe, Groesse, stdin);		// stringeingabe
			zahlen_selber[index] = pruefen(eingabe);		// prüft die eingabe(string) und setzt es mit der ersten stelle des gegebenen arrays gleich
			if (zahlen_selber[index] == 0) {		// kontrolliert ob eine 0 eingegeben wurde. oder eine ungültige zahl/variable etc.
				index--;		// dekrementiert index. damit der user für die stelle des arrays eine neue variable eingeben kann
				printf("\nUngueltige Zahl.\n");		// texteingabe. für fehler
			}
			for (index2 = 0; index2 < index; index2++) {	// setzt index2 = 0. solange index2 kleiner index ist führt er die schleife aus. nach jedem durchgang erhöht es einmal index2
				if (zahlen_selber[index] == zahlen_selber[index2]) {	// kontrolliert für fehlerabfangen ob der wert von dem array die man eingegeben hat schon vorhanden ist
					index--;			// um einen neuen wert zu verlangen für die stelle des arrays
					printf("Geben sie eine neue Zahl ein.\n\n");		// textausgabe
				}
			}
		}
		printf("\nIhre Lottozahlen:	");		// textausgabe
		for (index = 0; index < Lottozahlen; index++) {		// dient dazu um die ganzen zahlen des arrays(die zahlen die man eingegeben hat) auszugeben
			printf("%i\t", zahlen_selber[index]);		// textausgabe
		}
		ausgeben = 1;	// setzt ausgeben auf 1 damit das programm die zahlen für die zufallszahlen ausgeben kann. damit das also einmalig erfolgt.
		ausgeben1 = 1;
		ausgeben2 = 1;
		richtig = 0;	// setzt die variable richtig auf 0 damit es beim nächsten durchgang nochmal die schleife ausführt
		counter = 0;	// setzt die variable counter auf 0 damit es nicht von der stelle welches sie ausgegeben hat wieder hochzählt
		while (richtig < versuche) {	// solange die variable richtig kleiner als versuche(definiert) ist führt er die schleife aus. die zahl kann man oben ändern. zb.: auf 4 oder 5
			richtig = 0;		// setzt richtig auf 0 damit das programm nicht frühzeitig die schleife verlässt. zb wenn 1 zahl einmal richtig war und beim zweiten durchlauf sind es 2.
								// aber es muss bei einem durchlauf (wenn versuche auf 3 gesetzt wurde) auch die nötigen richtigkeiten vorhanden sein
			for (index = 0; index < Lottozahlen; index++) {	// führt die schleife solange aus bist index den wert von lottozahlen(definiert) erreicht hat
				zahlen_zufall_int[index] = rand() % 49 + 1;	// rand() erzeugt eine Zufallszahl zwischen 0 und maximal random oder so. 
						// wenn ich diese zahl nicht + eine zufallszahl mache gibt er die gleichen werte für die zufallszahlen wieder weil der zufallsgenerator mit den werten von der
						// zeit arbeitet und der debugger sehr schnell ist. das heißt es counter erhält ungültige werte.
				for (index2 = 0; index2 < index; index2++) {	// dient zur kontrolle ob der wert der ausgerechnet wurde bereits vorhanden ist.
					if (zahlen_zufall_int[index] == zahlen_zufall_int[index2] && index != index2) {	// vergleicht ob eine zahl schon vorhanden ist. es darf aber nicht mit sich selbst vergleichen
						zahlen_zufall_int[index] = 0;		// wenn die obige bedingung erfüllt wird, dann setzt er die stelle des arrays auf 0 und
						index--;					// dekrementiert index um eine stelle für einen neuen wert
					}
				}
			}
			counter++;		// zählt counter hoch um zu gucken wie viele versuche gemacht wurden um x. richtige zu haben
			for (index = 0; index < Lottozahlen; index++) {	// dient dazu um die zahlen die man selber eingegeben hat an der index.te stelle mit den zufallszahlen zu überprüfen
				for (index2 = 0; index2 < Lottozahlen; index2++) {	// die index.te stelle der eingegebenen zahlen werden mit den ganzen zufallszahlen überprüft ob eines davon gleich ist
					if (zahlen_zufall_int[index] == zahlen_selber[index2]) {	// wenn eines davon gleich ist dann
						richtig++;		// inkrementiert es die variable counter
					}
				}
			}
			if (ausgeben == 1 || richtig >= versuche) {		// wenn die variable ausgeben auf 1 ist oder richtig >= versuche(definiert) ist führt er die schleife aus
				printf("\nZufallszahlen:		");		// textausgabe
				for (index = 0; index < Lottozahlen; index++) {		// dient dazu die ganzen zufallszahlen auszugeben
					printf("%i\t", zahlen_zufall_int[index]);	// textausgabe
				}
				if (ausgeben == 1) {
					printf("\nBeim %i.ten mal hast du %i richtige.\n",counter, richtig);	// textausgabe
				}
				if (ausgeben != 1) {
					printf("\n");	// zeilensprung
				}
				ausgeben = 0;	// ausgeben wird auf 0 gesetzt, damit es die zufallszahlen nicht bei jedem durchlauf ausgeben muss.
			}
			if (ausgeben1 == 1 && richtig == versuche2) {		// wenn die variable ausgeben auf 1 ist oder richtig >= versuche2(definiert) ist führt er die schleife aus
				printf("\nZufallszahlen:		");		// textausgabe
				for (index = 0; index < Lottozahlen; index++) {		// dient dazu die ganzen zufallszahlen auszugeben
					printf("%i\t", zahlen_zufall_int[index]);	// textausgabe
				}
				printf("\nBeim %i.ten mal hast du %i richtige.\n", counter, richtig);	// textausgabe
				ausgeben1 = 0;	// ausgeben wird auf 0 gesetzt, damit es die zufallszahlen nicht bei jedem durchlauf ausgeben muss.
			}
			if (ausgeben2 == 1 && richtig == versuche3) {		// wenn die variable ausgeben auf 1 ist oder richtig >= versuche3(definiert) ist führt er die schleife aus
				printf("\nZufallszahlen:		");		// textausgabe
				for (index = 0; index < Lottozahlen; index++) {		// dient dazu die ganzen zufallszahlen auszugeben
					printf("%i\t", zahlen_zufall_int[index]);	// textausgabe
				}
				printf("\nBeim %i.ten mal hast du %i richtige.\n", counter, richtig);	// textausgabe
				ausgeben2 = 0;	// ausgeben wird auf 0 gesetzt, damit es die zufallszahlen nicht bei jedem durchlauf ausgeben muss.
			}
		}
		printf("Beim %i.ten mal hast du %i richtige.\n\n\n", counter, richtig);	// textausgabe
	}
	return 0;		// rückgabewert.
}			// ende........


// funktionsaufruf für pruefen
int pruefen(char eingabe[Groesse]) {		// ein string wurde übergeben. ein integer wert wird übergeben
	int laenge = 0, fehler = 0, index = 0;	// initialisierungen
	laenge = strlen(eingabe);		// um herauszufinden wie groß der string ist
	if (eingabe[0] == '+') {		// überprüft ob ein + am anfang steht um es abzufangen
		laenge -= 2;		// wenn ja dann dekrementiert er die länge um 2
		for (index = 0; index < laenge; index++) {		// dient dazu um den + weg zu machen und um die zahlen zu vertauschen
			eingabe[index] = eingabe[index + 1];		// tauscht den ersten wert des arrays mit dem nächsten
			eingabe[index + 1] = 0;		// setzt den nächsten wert des arrays auf 0
		}
	}
	else {		// wenn die obige bedingung nicht erfüllt wurde dann führt er das aus
		laenge -= 1;	// länge wird um 1 dekrementiert. (länge--)
	}
	for (index = 0; index < laenge; index++) {		// dient dazu um alle string- zeichen zu überprüfen ob auch alle zahlen sind
		if (isdigit(eingabe[index]) == 0) {	// wenn eine 0 zurückgegeben wurde(also false) dann ist die stelle des arrays KEINE zahl und
			fehler++;		// die variable fehler wird incrementiert
		}
	}
	index = 0;		// index wird auf 0 gesetzt
	if (fehler == 0) {		// wenn fehler = 0 ist dann führt er die schleife aus
		index = atoi(eingabe);		// wandelt den string in einen integer wert um und setzt es mit index gleich
		if (index > max_Lottozahlen) {	// wenn der wert größer als max_lottozahlen(definiert) ist dann führt er die schleife aus
			printf("Die Zahl war groesser als 49, Rest(%i %% 49) wird uebergeben.\n\n", index);		// textausgabe
			index = index % 49;		// setzt index mit dem rest gleich. also index modolo 49 = rest.
		}
		if (index < min_Lottozahlen) {	// wenn index kleiner min_lottozahlen(definiert) ist dann führt es die schleife aus
			index = 0;		// setzt index = 0
		}
	}
	fehler = 0;	// setzt fehler = 0
	return index;	// gibt index wieder zurück
}			// ende........