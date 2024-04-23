/**********************************************************/
/* Autor: Kasim Mermer                                    */
/* Datum: 19.11.2016									  */
/* Projekt: P8A2										  */
/* Beschreibung: Häufigkeit der eingegebenen Zeichen	  */
/**********************************************************/
#include <stdio.h>		// Bibliotheken einbinden
#include <string.h>

#define zeichen_laenge 81	// laenge definieren

int main(void) {		// Hauptprogramm
	char eingabe[zeichen_laenge];		// Arrays deklarieren
	char zeichen[zeichen_laenge];
	int anzahl[zeichen_laenge] = { 0 };		// Array initalisieren
	int laenge = 0, beenden = 1, index = 0, index2 = 0, index3 = 0, counter = 0, counter2 = 0, counter3 = 0;		// initialisierungen

	while (beenden != 0) {		// solange beenden ungleich 0 ist
		laenge = 0;			// Variablen wieder auf 0 setzen
		index3 = 0;		
		counter3 = 0;
		printf("Geben sie einen String ein: \t");		// textausgabe
		fgets(eingabe, zeichen_laenge, stdin);		// Stringeingabe
		laenge = strlen(eingabe);		// überprüft wieviele zeichen in dem string vorhanden sind
		laenge -= 1;		// rechnet die laenge - 1 und setzt es gleich wegen dem \n bzw. \0 am ende. die soll er nciht mitberücksichtigen
		for (index = 0; index < laenge; index++) {		// zum überprüfen ob eine variable mehr als einmal vorkommt und speichert die variable(wenn nciht vorhanden) in zeichen[]
			for (index2 = 0; index2 < laenge; index2++) {
				if (eingabe[index] == eingabe[index2]) {	// überprüft wie oft das zeichen vorhanden ist
					counter++;		// zaehler für die häufigkeit des zeichens
				}
				if (zeichen[index2] == eingabe[index]) {	// pruefen ob das Zeichen bereits vorhanden ist in dem array. wenn ja zaehlt er counter 2 hoch damit er unten
					counter2++;				// nicht die Variable noch einmal speichern muss
				}
			}
			counter3++;		// für den zweiten teil der aufgabe. zählt wie viele zeichen vorhanden ist
			if (counter2 == 0) {	// wenn counter2 = 0 ist führt er die folgenden befehle aus. das ist damit es das zeichen nciht ncoh einmal speichert. also doppelt speichert.
				zeichen[index3] = eingabe[index];		// speichert die index.te stelle des arrays in die index3.te stelle des zeichen- arrays rein.
				anzahl[index3] = counter;		// das gleiche wie davor nur mit einer zahl und dem zaehler. also counter damit man weiß wie oft das zeichen vorhanden ist.
				index3++;		// zaehlt index3 hoch damit beim nächsten durchlauf nicht die werte/zeichen überschrieben werden
			}
			counter = 0;		// setzt counter und counter2 auf 0 weil es nun die zweite stelle der eingabe überprüft
			counter2 = 0;
		}
		for (index = 0; index < index3; index++) {		// ist da um die zeichen und die anzahl auszugeben
			printf("Die Variable \"%c\" ist %i mal in ihrem String vorhanden.\n", zeichen[index], anzahl[index]);
		}
		printf("\nLaenge des Strings:\t%i Zeichen,\naus meiner rechnung: \t%i Zeichen.\n\n\n", laenge, counter3);		// textausgabe
		for (index = 0; index < laenge; index++) {		// alle arrays auf 0 setzen.
			eingabe[index] = 0;
			anzahl[index] = 0;
			zeichen[index] = 0;
		}
	}
	return 0;	// rückgabewert
}