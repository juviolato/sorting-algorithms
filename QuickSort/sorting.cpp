#include "sorting.h"

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

int particiona(vector<int>& lista, int min, int max)
{
	int aux, i{min}, j{max+1};

	while (i < j)
	{
		do{
			i++;
		} while (lista[i] <= lista[min] && i < max);

		do{
			j--;
		} while (lista[j] > lista[min] && j >= min);

		if (i < j)
			iter_swap(lista.begin() + i, lista.begin() + j);
	}

	iter_swap(lista.begin() + min, lista.begin() + j); //troca o primeiro (p) com j pois j será menor que p

	return j;
}

void quick_sort(vector<int>& lista, int pos_inicial, int pos_final)
{
	int pivo;
	if (pos_final > pos_inicial) //se o array tiver tamanho 1 (f==1) já é considerado ordenado
	{
		pivo = particiona(lista, pos_inicial, pos_final);
		quick_sort(lista, pos_inicial, pivo-1);				//ordena o segmento à esquerda do pivô
		quick_sort(lista, pivo+1, pos_final);				//ordena o segmento à direita
	}
}
