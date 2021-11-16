#include <iostream>
using namespace std;

//insert sort
int main() {
	int a[]; //abbiamo bisogno di un vettore per l�ordinamento quindi lo dichiariamo
	int temp; //variabile per lo scambio
	int i; //variabile per l�indice �i�
	int j; //variabile per l�indice �j�
	int n; //variabile che dice di quanti elementi � il nostro vettore
	cout << "Quanti numeri?: "; //con la cout chiediamo quanti numeri vogliamo
	cin >> n; //con la cin questi numeri li memorizziamo in �n�
	for (i = 0; i < n; i++){
		cin >> a[i];
		cout << endl;
	}
	for (i = 1; i < n; i++) //per l�ordinamento utilizziamo un ciclo for esterno con indice �i� che
	//parte da 1, cio� i=1, perch� la parte costituita dal solo primo elemento a[0] � gi� ordinata, quindi
	//iniziamo dal secondo elemento
	{
		temp = a[i]; //una variabile temporanea temp nella quale memorizziamo il secondo valore
		//a[1].
		j = i - 1; //l�indice �j� parte da 0, quindi inizialmente �i� punta al secondo elemento,
		//mentre �j� al primo.
		while ((a[j] > temp) && (j >= 0)) //il ciclo while si ripete finch� � vera questa condizione:il
		//valore puntato dall�indice �j� � > di temp e j>=0.
		{
			a[j + 1] = a[j]; //Nel while memorizziamo il valore puntato dall�indice �j� nella
			//posizione successiva a[j]
			j = j - 1; //e decrementiamo j di 1.
		}
		a[j + 1] = temp; //quando si finisce il ciclo pi� interno (while), allora nella posizione
		//j+1 memorizziamo il valore di temp. Continuiamo finch� si verifica la condizione, cio� i<n
	}
	cout << "La lista ordinata � la seguente: " << endl;
	// dopo l�ordinamento facciamo un for per l�output
	for (i = 0; i < n; i++){
		cout << a[i] << "";
	}
	return 0;
}