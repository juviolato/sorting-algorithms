#include "arquivos.h"

void le_arquivo(string nome_arquivo, vector<int>& lista)
{
	int temp;
	char joga_fora;
	fstream arquivo;

	arquivo.open(nome_arquivo);

	if (arquivo.is_open())
	{
		while (!arquivo.fail())
		{
			if (arquivo >> temp)
				lista.push_back(temp);
			arquivo >> joga_fora;			// ignora vírgulas
		}
		arquivo.close();
	}
	else
		cout << "\nErro ao abrir o arquivo!\n";
}

void escreve_arquivo(string saida, vector<int>& lista)
{
	ofstream arquivo;

	arquivo.open(saida);

	if (arquivo.is_open())
	{
		for (int i = 0; i < lista.size(); i++)
		{
			arquivo << lista[i];
			arquivo << ", ";						// escreve arquivo no formato comma-separated values
		}
		arquivo.close();
	}
	else
		cout << "\nErro ao escrever arquivo!\n";
}
