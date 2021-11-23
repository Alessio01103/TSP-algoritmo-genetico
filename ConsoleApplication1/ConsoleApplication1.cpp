#include <iostream>
#include <Cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int main() {

	srand(time(NULL)); //inizializzo la funzione di generazione di numeri casuali

	int numero_localita = 10; //numero di localita'
	int numero_cromosomi = 10; //numero di cromosomi per ogni generazione
	int numero_generazioni = 20; //numero di generazioni
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

	int generazione_corrente[numero_cromosomi][numero_localita];

	for (int i = 0; i < numero_cromosomi; i++) {
		for (int j = 0; j < numero_localita; j++) {
			generazione_corrente[i][j] = rand() % numero_localita; //genero un numero random compreso tra 0 e 9
			for (int a = 0; a < j; a++) { //controllo che non ci siano ripetizioni
				if (generazione_corrente[i][j] == generazione_corrente[i][a]) {
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
			cout << generazione_corrente[i][j] << " ";
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
			a_cromosoma_temp[i] = generazione_corrente[j][i];
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

	int gen_ordinata[numero_cromosomi][numero_localita];
	//riscrive i geni in ordine
	for (int i = 0; i < numero_cromosomi; i++) {
		for (int j = 0; j < numero_localita; j++) {
			int f = somme[i][0];
			gen_ordinata[i][j] = generazione_corrente[f][j];
		}
	}
	//trascrivo i geni ordinati sulla matrice originale
	for (int i = 0; i < numero_cromosomi; i++) {
		for (int j = 0; j < numero_localita; j++) {
			generazione_corrente[i][j] = gen_ordinata[i][j];
		}
	}

	//selezione del punto di slice random
	int punto_di_slice = 0;
	while (punto_di_slice == 0) {
		punto_di_slice = rand() % (numero_localita / 2);
	}

	vector<int> temp_dx_primo;
	vector<int> vettore_da_ricombinare_primo;
	vector<int> parte_centrale_primo;

	vector<int> temp_dx_secondo;
	vector<int> vettore_da_ricombinare_secondo;
	vector<int> parte_centrale_secondo;

	int primo_cromosoma = 0;
	int secondo_cromosoma = 1;

	int a_cromosoma_ricombinante_primo[numero_localita];
	int a_cromosoma_riferimento_primo[numero_localita];
	int a_cromosoma_ricombinante_secondo[numero_localita];
	int a_cromosoma_riferimento_secondo[numero_localita];
	int a_cromosoma_ricombinato_primo[numero_localita];
	int a_cromosoma_ricombinato_secondo[numero_localita];

	//inizio il ciclo che verrà ripetuto per il numero di generazioni che ho deciso in precedenza
	for (int k = 0; k <= numero_generazioni; k++) {

		//seleziono i primi due geni, il primo come cromosoma da ricombinare e il secondo come cromosoma di riferimento per il primo ciclo
		for (int i = 0; i < numero_localita; i++) {
			a_cromosoma_ricombinante_primo[i] = generazione_corrente[primo_cromosoma][i];
			a_cromosoma_riferimento_primo[i] = generazione_corrente[secondo_cromosoma][i];
		}

		//seleziono i primi due geni, il primo come cromosoma di riferimento e il secondo come cromosoma da ricombinare per il secondo ciclo
		for (int i = 0; i < numero_localita; i++) {
			a_cromosoma_ricombinante_secondo[i] = generazione_corrente[secondo_cromosoma][i];
			a_cromosoma_riferimento_secondo[i] = generazione_corrente[primo_cromosoma][i];
		}

//INIZIO PRIMO CICLO
	
		// sezionamento della parte iniziale e finale del cromosoma
		
		//trovo l'estremo finale del cromosoma
		for (int i = 0; i < punto_di_slice; i++) {
			temp_dx_primo.push_back(a_cromosoma_ricombinante_primo[i]);
		}

		//trovo l'estremo iniziale del cromosoma
		for (int i = numero_localita - 1; i >= numero_localita - punto_di_slice; i--) {
			vettore_da_ricombinare_primo.push_back(a_cromosoma_ricombinante_primo[i]);
		}
		//trovo la parte centrale
		for (int i = punto_di_slice; i < numero_localita - punto_di_slice; i++) {
			parte_centrale_primo.push_back(a_cromosoma_ricombinante_primo[i]);
		}

		vettore_da_ricombinare_primo.insert(vettore_da_ricombinare_primo.end(), temp_dx_primo.begin(), temp_dx_primo.end());

		//bisogna prendere il vettore da ricombinare e riordinarlo in base al cromosoma numero 2

		int j = 0;
		int temp_primo;
		while (j < punto_di_slice * 2) {
			for (int i = 0; i < numero_localita; i++) {
				for (int k = j; k < punto_di_slice * 2; k++) {
					if (a_cromosoma_riferimento_primo[i] == vettore_da_ricombinare_primo[k]) {
						temp_primo = vettore_da_ricombinare_primo[j];
						vettore_da_ricombinare_primo[j] = vettore_da_ricombinare_primo[k];
						vettore_da_ricombinare_primo[k] = temp_primo;
						j++;
					}
				}
			}
		}

		//"ricostruisco" il cromosoma, unendo gli estremi con le parti centrali

		for (int i = 0; i < punto_di_slice; i++) {
			a_cromosoma_ricombinato_primo[i] = vettore_da_ricombinare_primo[i];
		}

		for (int i = 0; i < parte_centrale_primo.size(); i++) {
			a_cromosoma_ricombinato_primo[i + punto_di_slice] = parte_centrale_primo[i];
		}

		for (int i = punto_di_slice; i < punto_di_slice * 2; i++) {
			a_cromosoma_ricombinato_primo[i + parte_centrale_primo.size()] = vettore_da_ricombinare_primo[i];
		}

		//mutazione
		int mut0 = rand() % 100;
		if (mut0 > 100 - probabilita_mutazione) {
			int nucleotide = rand() % numero_localita;
			a_cromosoma_ricombinato_primo[nucleotide] = rand() % numero_localita;
		}

		cout << "" << endl;

//INIZIO SECONDO CICLO

		// sezionamento del cromosoma in iniziale centrale e finale

		//trovo l'estremo finale del cromosoma
		for (int i = 0; i < punto_di_slice; i++) {
			temp_dx_secondo.push_back(a_cromosoma_ricombinante_secondo[i]);
		}

		//trovo l'estremo iniziale del cromosoma
		for (int i = numero_localita - 1; i >= numero_localita - punto_di_slice; i--) {
			vettore_da_ricombinare_secondo.push_back(a_cromosoma_ricombinante_secondo[i]);
		}
		//trovo la parte centrale
		for (int i = punto_di_slice; i < numero_localita - punto_di_slice; i++) {
			parte_centrale_secondo.push_back(a_cromosoma_ricombinante_secondo[i]);
		}

		vettore_da_ricombinare_secondo.insert(vettore_da_ricombinare_secondo.end(), temp_dx_secondo.begin(), temp_dx_secondo.end());

		//bisogna prendere il vettore da ricombinare e riordinarlo in base al cromosoma numero 2

		int h = 0;
		int temp1;
		while (h < punto_di_slice * 2) {
			for (int i = 0; i < numero_localita; i++) {
				for (int k = h; k < punto_di_slice * 2; k++) {
					if (a_cromosoma_riferimento_secondo[i] == vettore_da_ricombinare_secondo[k]) {
						temp1 = vettore_da_ricombinare_secondo[h];
						vettore_da_ricombinare_secondo[h] = vettore_da_ricombinare_secondo[k];
						vettore_da_ricombinare_secondo[k] = temp1;
						h++;
					}
				}
			}
		}

		cout << endl;

		for (int i = 0; i < punto_di_slice; i++) {
			a_cromosoma_ricombinato_secondo[i] = vettore_da_ricombinare_secondo[i];
		}

		for (int i = 0; i < parte_centrale_primo.size(); i++) {
			a_cromosoma_ricombinato_secondo[i + punto_di_slice] = parte_centrale_secondo[i];
		}

		for (int i = punto_di_slice; i < punto_di_slice * 2; i++) {
			a_cromosoma_ricombinato_secondo[i + parte_centrale_secondo.size()] = vettore_da_ricombinare_secondo[i];
		}

		//mutazione

		int mut1 = rand() % 100;
		if (mut1 > 100 - probabilita_mutazione) {
			int nucleotide = rand() % numero_localita;
			a_cromosoma_ricombinato_secondo[nucleotide] = rand() % numero_localita;
		}

		for (int i = 0; i < numero_localita; i++) {
			generazione_corrente[primo_cromosoma][i] = a_cromosoma_ricombinato_primo[i];
			generazione_corrente[secondo_cromosoma][i] = a_cromosoma_ricombinato_secondo[i];
		}

		//funzione di fitness

		double somma = 0;
		int a_cromosoma_temp[numero_localita];
		int a;
		int b;
		double somme[numero_cromosomi][2];
		for (int j = 0; j < numero_cromosomi; j++) {
			for (int i = 0; i < numero_localita; i++) {
				a_cromosoma_temp[i] = generazione_corrente[j][i];
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
				gen_ordinata[i][j] = generazione_corrente[f][j];
			}
		}

		for (int i = 0; i < numero_cromosomi; i++) {
			for (int j = 0; j < numero_localita; j++) {
				generazione_corrente[i][j] = gen_ordinata[i][j];
			}
			cout << endl;
		}

		cout << endl;
		cout << "-----------------------------" << endl;
		cout << endl;

		temp_dx_primo.clear();
		vettore_da_ricombinare_primo.clear();
		parte_centrale_primo.clear();

		temp_dx_secondo.clear();
		vettore_da_ricombinare_secondo.clear();
		parte_centrale_secondo.clear();

	}
	return 0;
}