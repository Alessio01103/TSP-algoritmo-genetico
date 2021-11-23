#include <iostream>
#include <Cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int main() {

	srand(time(NULL)); //inizializzo la funzione di generazione di numeri casuali

	const int numero_localita = 10; //numero di localita'
	const int numero_cromosomi = 10; //numero di cromosomi per ogni generazione
	const int numero_generazioni = 20; //numero di generazioni
	int probabilita_mutazione = 50; //percentuale di probabilità che avvenga una mutazione all'interno di un cromosoma, compresa tra 0 e 100
	int coordinate[numero_localita][2]; //matrice delle coordinate dei singoli punti
	double distanze[numero_localita][numero_localita]; //matrice delle distanze tra ogni punto
	int isRandom = 0;

	//ASCII art
	cout << "	180 150W  120W  90W   60W   30W  000   30E   60E   90E   120E  150E 180" << endl;
	cout << "|    |     |     |     |     |    |     |     |     |     |     |     |" << endl;
	cout << "+90N-+-----+-----+-----+-----+----+-----+-----+-----+-----+-----+-----+" << endl;
	cout << "|          . _..::__:  ,----._       |7       ,     _,.__             |" << endl;
	cout << "|  _.___ _ _<_>`!(._`.`-.    /        _._     `_ ,_/  '  '-._.---.-.__|" << endl;
	cout << "|.{         `-==,',._\{  \  / {)     / _  >_,-' `                mt-2_|" << endl;
	cout << "+ \_.:--.       `._ )`^-. '      , [_/(                       __,/-'  +" << endl;
	cout << "|' '     \              _L       oD_,--'                )     /. (|   |" << endl;
	cout << "|         |           ,'         _)_.\\._<> 6              _,' /  '   |" << endl;
	cout << "|         `.         /          [_/_'` ` (                <'}  )      |" << endl;
	cout << "+30N       \\    .-. )          /   `-' ..' `:._          _)  '       +" << endl;
	cout << "|   `        \  (  `(          /         `:\  > \  ,-^.  /' '         |" << endl;
	cout << "|             `._,   ""        |           \`'   \|   ?_)  {\         |" << endl;
	cout << "|                `=.---.       `._._       ,'      `  |' ,- '.        |" << endl;
	cout << "+000               |    `-._        |     /          `:`<_|h--._      +" << endl;
	cout << "|                  (        >       .     | ,          `=.__.`-'\     |" << endl;
	cout << "|                   `.     /        |     |{|              ,-.,\     .|" << endl;
	cout << "|                    |   ,'          \   / `'            ,      \     |" << endl;
	cout << "+30S                 |  /             |_'                |  __  /     +" << endl;
	cout << "|                    | |                                 '-'  `-'   \.|" << endl;
	cout << "|                    |/                                             / |" << endl;
	cout << "|                    \.                                            '  |" << endl;
	cout << "+60S                                                                  +" << endl;
	cout << "|                     ,/           ______._.--._ _..---.---------._   |" << endl;
	cout << "|    ,----- -..?----_/ )      _,-'"             "                  (  |" << endl;
	cout << "|.._(                  `-----'                                      `-|" << endl;
	cout << "+90S-+-----+-----+-----+-----+----+-----+-----+-----+-----+-----+-----+" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "" << endl;
	cout << "" << endl;

	cout << "Quante localita' si desidera visitare?  " << endl;
	cin >> numero_localita; //input numero localita'
	cout << "Quanti cromosomi vuoi considerare?  " << endl;
	cin >> numero_cromosomi; //input numero di cromosomi per generazione
	cout << "Quante interazioni si desidera fare?  " << endl;
	cin >> numero_generazioni; //input numero di generazioni
	cout << "Qual e' la probabilita' che avvengano delle mutazioni?  " << endl;
	cin >> probabilita_mutazione;
	cout << "" << endl;

	cout << "vuoi inserire le coordinate di ogni singolo punto o vuoi che vengano generate in maniera randomica?" << endl;
	cout << "0 = inserimento manuale" << endl << "1= generazione randomica" << endl << "risposta: " << endl;
	cin >> isRandom;

	//inserimento coordinate delle localita'

	if (isRandom == 0) { //se è stato scelto l'inserimento manuale
		//inserisco le coordinate x e y
		for (int i = 0; i < numero_localita; i++) {
			cout << "coordinata x luogo n. " << i + 1 << ": ";
			cin >> coordinate[i][1];

			cout << "coordinata y luogo n. " << i + 1 << ": ";
			cin >> coordinate[i][2];
		}
		//calcolo le distanze tra tutti i punti
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
	} else { //se è stata scelta la generazione randomica
		//genero random le distanze
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
	}

	//stampo la matrice con le distanze
	cout << "matrice distanze: " << endl;

	for (int i = 0; i < numero_localita; i++) {
		for (int j = 0; j < numero_localita; j++) {
			cout << distanze[i][j] << "\t";
		}
		cout << endl;
	}

	//Creazione di n "cromosomi" random contenenti tutte le localita senza ripetizione

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
	double somme[numero_cromosomi][2];
	for (int j = 0; j < numero_cromosomi; j++) {
		for (int i = 0; i < numero_localita; i++) {
			a_cromosoma_temp[i] = gen1[j][i];
		}
		//sommo tutte le distanze tra una localita e la successiva
		for (int i = 0; i < numero_localita; i++) {
			if (i < numero_localita - 1) {
				a = a_cromosoma_temp[i];
				b = a_cromosoma_temp[i + 1];
				somma = distanze[a][b] + somma;
			}//se arrivo all'ultima localita' sommo la sua distanza con la prima, visto che devo "tornare indietro"
			else if (i == numero_localita - 1) {
				a = a_cromosoma_temp[i];
				b = a_cromosoma_temp[0];
				somma = distanze[a][b] + somma;
			}
		}
		somme[j][0] = j;
		somme[j][1] = somma;
		cout << "cromosoma " << somme[j][0] << " distanza totale: " << somme[j][1] << endl;
		somma = 0;
	}
	//ordino i cromosomi con la lunghezza totale del percorso decrescente
	for (int i = 0; i < numero_cromosomi - 1; i++) {
		for (int j = i + 1; j < numero_cromosomi; j++) {
			if (somme[i][1] > somme[j][1]) {
				double temp1 = somme[i][0];
				double temp2 = somme[i][1];
				somme[i][1] = somme[j][1];
				somme[i][0] = somme[j][0];
				somme[j][0] = temp1;
				somme[j][1] = temp2;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < numero_cromosomi; i++) {
		cout << "cromosoma " << somme[i][0] << " distanza totale: " << somme[i][1] << endl;
	}

	int gen_ordinata[numero_cromosomi][numero_localita];
	//riscrive i geni in ordine
	for (int i = 0; i < numero_cromosomi; i++) {
		for (int j = 0; j < numero_localita; j++) {
			int f = somme[i][0];
			gen_ordinata[i][j] = gen1[f][j];
		}
	}
	//trascrivo i geni ordinati sulla matrice originale
	for (int i = 0; i < numero_cromosomi; i++) {
		for (int j = 0; j < numero_localita; j++) {
			gen1[i][j] = gen_ordinata[i][j];
		}
		cout << endl;
	}
	//stampo i cromosomi
	cout << "cromosomi ordinati: " << endl;
	for (int i = 0; i < numero_cromosomi; i++) {
		for (int j = 0; j < numero_localita; j++) {
			cout << gen1[i][j] << " ";
		}
		cout << endl;

	}
	cout << endl;
	cout << "-----------------------------" << endl;
	cout << endl;

	//selezione del punto di slice random
	int punto_di_slice = 0;
	while (punto_di_slice == 0) {
		punto_di_slice = rand() % (numero_localita / 2);
	}

	vector<int> temp_dx0;
	vector<int> vettore_da_ricombinare0;
	vector<int> parte_centrale0;

	vector<int> temp_dx1;
	vector<int> vettore_da_ricombinare1;
	vector<int> parte_centrale1;

	int primo_cromosoma = 0;
	int secondo_cromosoma = 1;

	int a_cromosoma_ricombinante0[numero_localita];
	int a_cromosoma_riferimento0[numero_localita];
	int a_cromosoma_ricombinante1[numero_localita];
	int a_cromosoma_riferimento1[numero_localita];
	int a_cromosoma_ricombinato0[numero_localita];
	int a_cromosoma_ricombinato1[numero_localita];

	for (int k = 0; k <= numero_generazioni; k++) {

		for (int i = 0; i < numero_localita; i++) {
			a_cromosoma_ricombinante0[i] = gen1[primo_cromosoma][i];
			a_cromosoma_riferimento0[i] = gen1[secondo_cromosoma][i];
		}

		for (int i = 0; i < numero_localita; i++) {
			a_cromosoma_ricombinante1[i] = gen1[secondo_cromosoma][i];
			a_cromosoma_riferimento1[i] = gen1[primo_cromosoma][i];
		}


		// inizio primo ciclo
	
		// sezionamento del cromosoma in iniziale centrale e finale
#if 1
		//trovo l'estremo finale del cromosoma
		for (int i = 0; i < punto_di_slice; i++) {
			temp_dx0.push_back(a_cromosoma_ricombinante0[i]);
		}

		//trovo l'estremo iniziale del cromosoma
		for (int i = numero_localita - 1; i >= numero_localita - punto_di_slice; i--) {
			vettore_da_ricombinare0.push_back(a_cromosoma_ricombinante0[i]);
		}
		//trovo la parte centrale
		for (int i = punto_di_slice; i < numero_localita - punto_di_slice; i++) {
			parte_centrale0.push_back(a_cromosoma_ricombinante0[i]);
		}
#endif

#if 1
		//stampa vector temp_dx
		cout << "parte iniziale0:" << endl;

		for (int i = 0; i < temp_dx0.size(); i++) {
			cout << temp_dx0[i];
		}
		cout << endl;

		//stampa vector temp_sx
		cout << "parte finale0:" << endl;

		for (int i = 0; i < vettore_da_ricombinare0.size(); i++) {
			cout << vettore_da_ricombinare0[i];
		}
		cout << endl;

		//stampa vector temp_sx
		cout << "parte centrale0:" << endl;

		for (int i = 0; i < parte_centrale0.size(); i++) {
			cout << parte_centrale0[i];
		}
		cout << endl;
#endif
		vettore_da_ricombinare0.insert(vettore_da_ricombinare0.end(), temp_dx0.begin(), temp_dx0.end());

#if 1
		//stampa vector concatenato
		cout << "parte iniziale e finale concatenata0:  " << endl;
		for (int i = 0; i < punto_di_slice * 2; i++) {
			cout << vettore_da_ricombinare0[i];
		}
#endif


		//bisogna prendere il vettore da ricombinare e riordinarlo in base al cromosoma numero 2

		int j = 0;
		int temp0;
		while (j < punto_di_slice * 2) {
			for (int i = 0; i < numero_localita; i++) {
				for (int k = j; k < punto_di_slice * 2; k++) {
					if (a_cromosoma_riferimento0[i] == vettore_da_ricombinare0[k]) {
						temp0 = vettore_da_ricombinare0[j];
						vettore_da_ricombinare0[j] = vettore_da_ricombinare0[k];
						vettore_da_ricombinare0[k] = temp0;
						j++;
					}
				}
			}
		}

		cout << endl << "parte iniziale e finale riordinata0:  " << endl;
		for (int i = 0; i < punto_di_slice * 2; i++) {
			cout << vettore_da_ricombinare0[i];
		}
#if 1
		cout << endl;

		for (int i = 0; i < punto_di_slice; i++) {
			a_cromosoma_ricombinato0[i] = vettore_da_ricombinare0[i];
		}

		for (int i = 0; i < parte_centrale0.size(); i++) {
			a_cromosoma_ricombinato0[i + punto_di_slice] = parte_centrale0[i];
		}

		for (int i = punto_di_slice; i < punto_di_slice * 2; i++) {
			a_cromosoma_ricombinato0[i + parte_centrale0.size()] = vettore_da_ricombinare0[i];
		}

		//mutazione
		int mut0 = rand() % 100;
		if (mut0 > 100 - probabilita_mutazione) {
			int nucleotide = rand() % numero_localita;
			a_cromosoma_ricombinato0[nucleotide] = rand() % numero_localita;
		}
			
		cout << "cromosoma riordinato0" << endl;
		for (int i = 0; i < numero_localita; i++) {
			cout << a_cromosoma_ricombinato0[i];
		}
		cout << "" << endl;
#endif

		cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;

// inizio secondo ciclo


		// sezionamento del cromosoma in iniziale centrale e finale
#if 1
		//trovo l'estremo finale del cromosoma
		for (int i = 0; i < punto_di_slice; i++) {
			temp_dx1.push_back(a_cromosoma_ricombinante1[i]);
		}

		//trovo l'estremo iniziale del cromosoma
		for (int i = numero_localita - 1; i >= numero_localita - punto_di_slice; i--) {
			vettore_da_ricombinare1.push_back(a_cromosoma_ricombinante1[i]);
		}
		//trovo la parte centrale
		for (int i = punto_di_slice; i < numero_localita - punto_di_slice; i++) {
			parte_centrale1.push_back(a_cromosoma_ricombinante1[i]);
		}
#endif

#if 1
		//stampa vector temp_dx
		cout << "parte iniziale1:" << endl;

		for (int i = 0; i < temp_dx1.size(); i++) {
			cout << temp_dx1[i];
		}
		cout << endl;

		//stampa vector temp_sx
		cout << "parte finale1:" << endl;

		for (int i = 0; i < vettore_da_ricombinare1.size(); i++) {
			cout << vettore_da_ricombinare1[i];
		}
		cout << endl;

		//stampa vector temp_sx
		cout << "parte centrale1:" << endl;

		for (int i = 0; i < parte_centrale1.size(); i++) {
			cout << parte_centrale1[i];
		}
		cout << endl;
#endif
		vettore_da_ricombinare1.insert(vettore_da_ricombinare1.end(), temp_dx1.begin(), temp_dx1.end());

#if 1
		//stampa vector concatenato
		cout << "parte iniziale e finale concatenata1:  " << endl;
		for (int i = 0; i < punto_di_slice * 2; i++) {
			cout << vettore_da_ricombinare1[i];
		}
#endif


		//bisogna prendere il vettore da ricombinare e riordinarlo in base al cromosoma numero 2

		int h = 0;
		int temp1;
		while (h < punto_di_slice * 2) {
			for (int i = 0; i < numero_localita; i++) {
				for (int k = h; k < punto_di_slice * 2; k++) {
					if (a_cromosoma_riferimento1[i] == vettore_da_ricombinare1[k]) {
						temp1 = vettore_da_ricombinare1[h];
						vettore_da_ricombinare1[h] = vettore_da_ricombinare1[k];
						vettore_da_ricombinare1[k] = temp1;
						h++;
					}
				}
			}
		}

		cout << endl << "parte iniziale e finale riordinata1:  " << endl;
		for (int i = 0; i < punto_di_slice * 2; i++) {
			cout << vettore_da_ricombinare1[i];
		}
#if 1
		cout << endl;

		for (int i = 0; i < punto_di_slice; i++) {
			a_cromosoma_ricombinato1[i] = vettore_da_ricombinare1[i];
		}

		for (int i = 0; i < parte_centrale0.size(); i++) {
			a_cromosoma_ricombinato1[i + punto_di_slice] = parte_centrale1[i];
		}

		for (int i = punto_di_slice; i < punto_di_slice * 2; i++) {
			a_cromosoma_ricombinato1[i + parte_centrale1.size()] = vettore_da_ricombinare1[i];
		}

		//mutazione

		int mut1 = rand() % 100;
		if (mut1 > 100 - probabilita_mutazione) {
			int nucleotide = rand() % numero_localita;
			a_cromosoma_ricombinato1[nucleotide] = rand() % numero_localita;
		}

		cout << "cromosoma riordinato1" << endl;
		for (int i = 0; i < numero_localita; i++) {
			cout << a_cromosoma_ricombinato1[i];
		}
		cout << "" << endl;
#endif

		for (int i = 0; i < numero_localita; i++) {
			gen1[primo_cromosoma][i] = a_cromosoma_ricombinato0[i];
			gen1[secondo_cromosoma][i] = a_cromosoma_ricombinato1[i];
		}

		//funzione di fitness
#if 1
		double somma = 0;
		int a_cromosoma_temp[numero_localita];
		int a;
		int b;
		double somme[numero_cromosomi][2];
		for (int j = 0; j < numero_cromosomi; j++) {
			for (int i = 0; i < numero_localita; i++) {
				a_cromosoma_temp[i] = gen1[j][i];
			}

			for (int i = 0; i < numero_localita; i++) {
				if (i < numero_localita - 1) {
					a = a_cromosoma_temp[i];
					b = a_cromosoma_temp[i + 1];
					somma = distanze[a][b] + somma;
				}
				else if (i == numero_localita - 1) {
					a = a_cromosoma_temp[i];
					b = a_cromosoma_temp[0];
					somma = distanze[a][b] + somma;
				}
			}
			somme[j][0] = j;
			somme[j][1] = somma;
			cout << "cromosoma " << somme[j][0] << " distanza totale: " << somme[j][1] << endl;
			somma = 0;
		}

		for (int i = 0; i < numero_cromosomi - 1; i++) {
			for (int j = i + 1; j < numero_cromosomi; j++) {
				if (somme[i][1] > somme[j][1]) {
					double temp1 = somme[i][0];
					double temp2 = somme[i][1];
					somme[i][1] = somme[j][1];
					somme[i][0] = somme[j][0];
					somme[j][0] = temp1;
					somme[j][1] = temp2;
				}
			}
		}
		cout << endl;
		for (int i = 0; i < numero_cromosomi; i++) {
			cout << "cromosoma " << somme[i][0] << " distanza totale: " << somme[i][1] << endl;
		}

		double gen_ordinata[numero_cromosomi][numero_localita];

		for (int i = 0; i < numero_cromosomi; i++) {
			for (int j = 0; j < numero_localita; j++) {
				int f = somme[i][0];
				gen_ordinata[i][j] = gen1[f][j];
			}
		}

		for (int i = 0; i < numero_cromosomi; i++) {
			for (int j = 0; j < numero_localita; j++) {
				gen1[i][j] = gen_ordinata[i][j];
			}
			cout << endl;
		}

		cout << "cromosomi ordinati: " << endl;
		for (int i = 0; i < numero_cromosomi; i++) {
			for (int j = 0; j < numero_localita; j++) {
				cout << gen1[i][j] << " ";
			}
			cout << endl;
				
		}
		cout << endl;
		cout << "-----------------------------" << endl;
		cout << endl;

		temp_dx0.clear();
		vettore_da_ricombinare0.clear();
		parte_centrale0.clear();

		temp_dx1.clear();
		vettore_da_ricombinare1.clear();
		parte_centrale1.clear();
#endif
	}
	return 0;
}





















