#include "gera.h"

const int listSize = 1000;

int main()
{
	try
	{
		vector<int> lista, aleatoria, ordenada, inversa;
        int trocas{0};
		string entrada, saida;

		cout << "Insira o nome do arquivo de entrada: ";
		getline(cin, entrada);
		if (entrada.find(".csv") == entrada.npos)
			entrada += ".csv";

		cout << "Insira o nome do arquivo de saida: ";
		getline(cin, saida);
		if (saida.find(".csv") == saida.npos)
			saida += ".csv";								// garante que os nomes dos arquivos terminarão com .csv

		le_arquivo(entrada, lista);
		mergesort(lista, 0, lista.size() - 1, trocas);
		escreve_arquivo(saida, lista);
        cout << "\nForam realizadas " << trocas << " trocas para ordenar a lista lida do arquivo " << entrada << ".";

        trocas = 0;
        gera_aleatorios("entradaaleatorio.csv", aleatoria, listSize);
        mergesort(aleatoria, 0, aleatoria.size() - 1, trocas);      // gera e ordena 1000 numeros aleatorios
        escreve_arquivo("saidaaleatorio.csv", aleatoria);
        cout << "\nForam realizadas " << trocas << " trocas para ordenar a lista de 1000 numeros aleatoriamente gerados.";

        trocas = 0;
        gera_ordenados("entradaordenado.csv", ordenada, listSize);
        mergesort(ordenada, 0, ordenada.size() - 1, trocas);        // gera e ordena 1000 numeros ja ordenados
        escreve_arquivo("saidaordenado.csv", ordenada);
        cout << "\nForam realizadas " << trocas << " trocas para ordenar a lista de 1000 numeros ordenados.";

        trocas = 0;
        gera_inverso("entradainversa.csv", inversa, listSize);
        mergesort(inversa, 0, inversa.size() - 1, trocas);          // gera e ordena 1000 numeros em ordem inversa
        escreve_arquivo("saidainversa.csv", inversa);
        cout << "\nForam realizadas " << trocas << " trocas para ordenar a lista de 1000 numeros em ordem inversa.";
	}
	catch(exception& e)
	{
		cerr << e.what() << endl;  // trata erros (exceções)
	}

	return 0;
}
