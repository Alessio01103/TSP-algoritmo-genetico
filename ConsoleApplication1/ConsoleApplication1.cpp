
#include <iostream>
#include <Cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

	srand(time(NULL));

	const int numero_localita = 10; //numero di località
	const int numero_cromosomi = 5;

//inserimento coordinate delle località e calcolo della matrice con le distanze tra ogni singola località
	int coordinate[numero_localita][2];
	double distanze[numero_localita][numero_localita];

	//con questi #if posso decidere se inserire io le coordinate o se farle generare al programma
	//o se far generare al programma direttamente le distanze
	//!!! ATTENZIONE !!! se faccio generare al programma direttamente le distanze devo ricordarmi di rimuovere anche il blocco sotto che le calcola

#if 0
	for (int i = 0; i < numero_localita; i++) {
		cout << "coordinata x luogo n. " << i + 1 << ": ";
		cin >> coordinate[i][1];

		cout << "coordinata y luogo n. " << i + 1 << ": ";
		cin >> coordinate[i][2];
	}
#elif 0
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < numero_localita; j++) {
			coordinate[j][i] = rand() % 10;
		}
	}

#elif 1

	for (int i = 0; i < numero_localita; i++) {
		for (int j = 0; j < numero_localita; j++) {
			int a = rand() % 10;
			distanze[j][i] = a;
			distanze[i][j] = a;
			if (i==j) {
				distanze[i][i] = 0;
			}
		}
	}

#endif

	//stampo le coordinate

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < numero_localita; j++) {
			cout<<coordinate[j][i] << " ";
		}
		cout << endl;
	}

	//calcolo le distanze
#if 0
	for (int i = 0; i < numero_localita; i++) {
		int dx = 0;
		int dy = 0;
		for (int j = 0; j < numero_localita; j++) {
			if (i != j) {
				dx = (coordinate[i][1] - coordinate[j][1]);
				dy = (coordinate[i][2] - coordinate[j][2]);
				distanze[i][j] = sqrt((dx * dx) + (dy * dy));
			}
			else {
				distanze[i][j] = 0;
			}
		}
	}
#endif
	//stampo la matrice con le distanze

	for (int i = 0; i < numero_localita; i++) {
		for (int j = 0; j < numero_localita; j++) {
			cout << distanze[i][j] << "\t";
		}
		cout << endl;
	}

//Creazione di 5 "cromosomi" random contenenti tutte le località senza ripetizione

	int gen1[numero_cromosomi][numero_localita];

	for (int i = 0; i < numero_cromosomi; i++) {
		for (int j = 0; j < numero_localita; j++) {
			gen1[i][j] = rand() % 10; //genero un numero random compreso tra 0 e 9
			for (int a = 0; a < j; a++) { //controllo che non ci siano ripetizioni
				if (gen1[i][j]==gen1[i][a]) {
					j--; //se ci sono ripetizioni torno indietro di una cella e esco dal ciclo, altrimenti vado avanti
					break;
				}
			}
		}
	}

	//stampa la matrice di cromosomi

	for (int i = 0; i < numero_cromosomi; i++) {
		for (int j = 0; j < numero_localita; j++) {
			cout << gen1[i][j] << " ";
		}
		cout<<endl;
	}

//funzione di fitness


	return 0;
}

