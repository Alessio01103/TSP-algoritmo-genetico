
#include <iostream>
#include <Cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(NULL));

	const int numero_localita = 10; //numero di località
	const int numero_cromosomi = 5;

#if 0
	int coordinate[n][2];
	double distanze[n][n];

	for (int i = 0; i < n; i++) {
		cout << "coordinata x luogo n. " << i + 1 << ": ";
		cin >> coordinate[i][1];

		cout << "coordinata y luogo n. " << i + 1 << ": ";
		cin >> coordinate[i][2];
	}

	for (int i = 0; i < n; i++) {
		int dx = 0;
		int dy = 0;
		for (int j = 0; j < n; j++) {
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


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << distanze[i][j] << " ";
		}
		cout << endl;
	}
#endif

	//Creazione di 5 "cromosomi" random contenenti tutte le località senza ripetizione

	int gen1[numero_cromosomi][numero_localita];

	for (int i = 0; i < numero_cromosomi; i++) {
		for (int j = 0; j < numero_localita; j++) {
			gen1[i][j] = rand() % 10;
			for (int a = 0; a < j; a++) {
				if (gen1[i][j]==gen1[i][a]) {
					j--;
					break;
				}
			}
		}
	}
	for (int i = 0; i < numero_cromosomi; i++) {
		for (int j = 0; j < numero_localita; j++) {
			cout << gen1[i][j] << " ";
		}
		cout<<endl;
	}
	return 0;
}

