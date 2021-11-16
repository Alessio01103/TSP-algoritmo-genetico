
#include <iostream>
#include <Cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
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

	int cromosoma1=0;
	int cromosoma2=0;

	do {
		cromosoma1 = rand() % numero_cromosomi;
		cromosoma2 = rand() % numero_cromosomi;
	} while (cromosoma1 == cromosoma2);

	int a_cromosoma1[numero_localita];
	int a_cromosoma2[numero_localita];

	for (int i = 0; i < numero_localita; i++) {
		a_cromosoma1[i] = gen1[cromosoma1][i];
		a_cromosoma2[i] = gen1[cromosoma2][i];
	}

	int punto_di_slice = 0;
	while (punto_di_slice == 0) {
		punto_di_slice = rand() % (numero_localita / 2);
	}

	cout << punto_di_slice << endl;




	cout << cromosoma1 << "  " << cromosoma2 << endl;

	for (int i = 0; i < numero_localita; i++) {
		cout<<a_cromosoma1[i];
	}
	cout << endl;
	for (int i = 0; i < numero_localita; i++) {
		cout << a_cromosoma2[i];
	}
	cout << endl;
	cout << endl;
	cout << endl;

	vector<int> temp_dx;
	vector<int> temp_sx;

	//trovo l'estremo finale del cromosoma
	for (int i = 0; i < punto_di_slice; i++) {
		temp_dx.push_back(a_cromosoma1[i]);
	}
	
	//trovo l'estremo iniziale del cromosoma
	for (int i = numero_localita-1; i >= numero_localita - punto_di_slice; i--) {
		temp_sx.push_back(a_cromosoma1[i]);
	}

	//stampa vector temp_dx
	cout << "parte iniziale:" << endl;

	for (int i = 0; i < temp_dx.size(); i++) {
		cout << temp_dx[i];
	}
	cout << endl;

	//stampa vector temp_sx
	cout << "parte finale:" << endl;

	for (int i = 0; i < temp_sx.size(); i++) {
		cout << temp_sx[i];
	}
	cout << endl;

	temp_sx.insert(temp_sx.end(), temp_dx.begin(), temp_dx.end());

	//stampa vector concatenato
	for (int i = 0; i < punto_di_slice * 2; i++) {
		cout << temp_sx[i];
	}

	return 0;
}

