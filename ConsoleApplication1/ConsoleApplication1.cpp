

#include <iostream>
#include <Cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int main() {

	srand(time(NULL));

	const int numero_localita = 10; //numero di localit?
	const int numero_cromosomi = 5;

	//inserimento coordinate delle localit? e calcolo della matrice con le distanze tra ogni singola localit?
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
			int a = rand() % numero_localita;
			distanze[j][i] = a;
			distanze[i][j] = a;
			if (i == j) {
				distanze[i][i] = 0;
			}
		}
	}

#endif

	//stampo le coordinate
#if 0
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < numero_localita; j++) {
			cout << coordinate[j][i] << " ";
		}
		cout << endl;
	}
#endif
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
	cout << "matrice distanze: " << endl;

	for (int i = 0; i < numero_localita; i++) {
		for (int j = 0; j < numero_localita; j++) {
			cout << distanze[i][j] << "\t";
		}
		cout << endl;
	}

	//Creazione di 5 "cromosomi" random contenenti tutte le localit? senza ripetizione

	int gen1[numero_cromosomi][numero_localita];

	for (int i = 0; i < numero_cromosomi; i++) {
		for (int j = 0; j < numero_localita; j++) {
			gen1[i][j] = rand() % numero_localita; //genero un numero random compreso tra 0 e 9
			for (int a = 0; a < j; a++) { //controllo che non ci siano ripetizioni
				if (gen1[i][j] == gen1[i][a]) {
					j--; //se ci sono ripetizioni torno indietro di una cella e esco dal ciclo, altrimenti vado avanti
					break;
				}
			}
		}
	}

	//stampa la matrice di cromosomi
	cout << "cromosomi: " << endl;
	for (int i = 0; i < numero_cromosomi; i++) {
		for (int j = 0; j < numero_localita; j++) {
			cout << gen1[i][j] << " ";
		}
		cout << endl;
	}

	//funzione di fitness

	double somma = 0;
	int a_cromosoma_temp[numero_localita];
	int a;
	int b;
	for (int i = 0; i < numero_localita; i++) {
		a_cromosoma_temp[i] = gen1[0][i];
	}

	for (int i = 0; i < numero_localita; i++) {
		if (i < numero_localita - 1) {
			a = a_cromosoma_temp[i];
			b = a_cromosoma_temp[i + 1];
			somma = distanze[a][b] + somma;
		}
		else if(i=numero_localita-1){
			a = a_cromosoma_temp[i];
			b = a_cromosoma_temp[0];
			somma = distanze[a][b] + somma;
		}
	}
	cout << "Somma delle distanze: " << somma << endl;


	int cromosoma_ricombinante = 0;
	int cromosoma_riferimento = 0;

	do {
		cromosoma_ricombinante = rand() % numero_cromosomi;
		cromosoma_riferimento = rand() % numero_cromosomi;
	} while (cromosoma_ricombinante == cromosoma_riferimento);

	int a_cromosoma_ricombinante[numero_localita];
	int a_cromosoma_riferimento[numero_localita];

	for (int i = 0; i < numero_localita; i++) {
		a_cromosoma_ricombinante[i] = gen1[cromosoma_ricombinante][i];
		a_cromosoma_riferimento[i] = gen1[cromosoma_riferimento][i];
	}
	//selezione del punto di slice
	int punto_di_slice = 2;/*
	while (punto_di_slice == 0) {
		punto_di_slice = rand() % (numero_localita / 2);
	}*/

	cout << "punto di slice: ";
	cout << punto_di_slice << endl;
	cout << "numero cromosoma ricombinante: " << endl;
	cout << cromosoma_ricombinante << endl << "numero cromosoma di riferimento: " << endl << cromosoma_riferimento << endl;
	cout << "cromosoma ricombinante: " << endl;
	for (int i = 0; i < numero_localita; i++) {
		cout << a_cromosoma_ricombinante[i];
	}
	cout << endl << "cromosoma di riferimento: " << endl;
	for (int i = 0; i < numero_localita; i++) {
		cout << a_cromosoma_riferimento[i];
	}
	cout << endl;
	cout << endl;
	cout << endl;

	vector<int> temp_dx;
	vector<int> vettore_da_ricombinare;
	vector<int> parte_centrale;

	//trovo l'estremo finale del cromosoma
	for (int i = 0; i < punto_di_slice; i++) {
		temp_dx.push_back(a_cromosoma_ricombinante[i]);
	}

	//trovo l'estremo iniziale del cromosoma
	for (int i = numero_localita - 1; i >= numero_localita - punto_di_slice; i--) {
		vettore_da_ricombinare.push_back(a_cromosoma_ricombinante[i]);
	}

	for (int i = punto_di_slice; i < numero_localita - punto_di_slice; i++) {
		parte_centrale.push_back(a_cromosoma_ricombinante[i]);
	}

	//stampa vector temp_dx
	cout << "parte iniziale:" << endl;

	for (int i = 0; i < temp_dx.size(); i++) {
		cout << temp_dx[i];
	}
	cout << endl;

	//stampa vector temp_sx
	cout << "parte finale:" << endl;

	for (int i = 0; i < vettore_da_ricombinare.size(); i++) {
		cout << vettore_da_ricombinare[i];
	}
	cout << endl;

	//stampa vector temp_sx
	cout << "parte centrale:" << endl;

	for (int i = 0; i < parte_centrale.size(); i++) {
		cout << parte_centrale[i];
	}
	cout << endl;

	vettore_da_ricombinare.insert(vettore_da_ricombinare.end(), temp_dx.begin(), temp_dx.end());

	//stampa vector concatenato
	cout << "parte iniziale e finale concatenata:  " << endl;
	for (int i = 0; i < punto_di_slice * 2; i++) {
		cout << vettore_da_ricombinare[i];
	}

	//bisogna prendere il vettore da ricombinare e riordinarlo in base al cromosoma numero 2

	int j = 0;
	int temp;
	while (j < punto_di_slice * 2) {
		for (int i = 0; i < numero_localita - 1; i++) {
			for (int k = j; k < punto_di_slice * 2; k++) {
				if (a_cromosoma_riferimento[i] == vettore_da_ricombinare[k]) {
					temp = vettore_da_ricombinare[j];
					vettore_da_ricombinare[j] = vettore_da_ricombinare[k];
					vettore_da_ricombinare[k] = temp;
					j++;
				}
			}
		}
	}

	cout << endl << "parte iniziale e finale riordinata:  " << endl;
	for (int i = 0; i < punto_di_slice * 2; i++) {
		cout << vettore_da_ricombinare[i];
	}
#if 1
	cout << endl;

	int a_cromosoma_ricombinato[numero_localita];

	for (int i = 0; i < punto_di_slice; i++) {
		a_cromosoma_ricombinato[i] = vettore_da_ricombinare[i];
	}

	for (int i = 0; i < parte_centrale.size(); i++) {
		a_cromosoma_ricombinato[i + punto_di_slice] = parte_centrale[i];
	}

	for (int i = punto_di_slice; i < punto_di_slice * 2; i++) {
		a_cromosoma_ricombinato[i + parte_centrale.size()] = vettore_da_ricombinare[i];
	}

	cout << "cromosoma riordinato" << endl;
	for (int i = 0; i < numero_localita; i++) {
		cout << a_cromosoma_ricombinato[i];
	}
#endif

	return 0;
}






















