#include "sorting.h"

int main()
{
	try
	{
		vector<int> lista;
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
		quick_sort(lista, 0, lista.size() - 1);
		escreve_arquivo(saida, lista);
	}
	catch(exception& e)
	{
		cerr << e.what() << endl;  // trata erros (exceções)
	}

	return 0;
}
