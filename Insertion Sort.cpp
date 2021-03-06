#include "stdafx.h"

vector<int> le_arquivo(string nome_arquivo)
{
	vector<int> sequencia;
	int temp;
	fstream arquivo;
	char joga_fora;

	arquivo.open(nome_arquivo);

	if (arquivo.is_open())
	{
		while (!arquivo.fail())
		{
			if (arquivo >> temp)
				sequencia.push_back(temp);
			arquivo >> joga_fora;
		}
		arquivo.close();
	}
	else
		cout << "\nErro ao abrir o arquivo!\n";
	
	return sequencia;
}

void escreve_arquivo (string saida, vector<int> ordenados)
{
	ofstream arquivo;
	
	arquivo.open(saida);

	if (arquivo.is_open())
	{
		for (int i = 0; i < ordenados.size(); i++)
		{
			arquivo << ordenados[i];
			arquivo << ", ";
		}
		arquivo.close();
	}
	else
		cout << "\nErro ao escrever arquivo!\n";
}

vector<int> insertion_sort(vector<int> sequencia)
{
	for (int i = 1; i < sequencia.size(); i++)
	{
		int temp = sequencia[i];
		int j = i - 1;
		while (j >= 0 && sequencia[j] > temp)
		{
			sequencia[j + 1] = sequencia[j];
			j--;
		}
		sequencia[j + 1] = temp;
	}

	return sequencia;
}

int main()
{
	string nome_arquivo, arquivo_saida;
	vector<int> sequencia;

	cout << "Informe o nome do arquivo a ser lido: ";
	getline(cin, nome_arquivo);
	if (nome_arquivo.find(".csv") == nome_arquivo.npos)
		nome_arquivo = nome_arquivo + ".csv";  // Adiciona a extensão ao nome do arquivo se for necessário

	cout << "\nE o nome do arquivo de saida: ";
	getline(cin, arquivo_saida);
	if (arquivo_saida.find(".csv") == arquivo_saida.npos)
		arquivo_saida = arquivo_saida + ".csv";
	
	sequencia = le_arquivo(nome_arquivo);
	sequencia = insertion_sort(sequencia);
	escreve_arquivo(arquivo_saida, sequencia);

	cout << "\n\n";
	keep_window_open();
	
    return 0;
}

