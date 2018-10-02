#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<list>
#include<vector>
#include<algorithm>
#include<stdexcept>
using namespace std;

/*
ATIVIDADE 2
1. Foram necessárias 3 iterações para ordenar o vetor.
2. Na primeira iteração foram 13 seguimentos, na segunda 4 e na terceira somente 1.
3. Na primeira iteração foram realizadas 3 trocas, na segunda 12 trocas e na última 45 trocas.
*/

class Window
{
public:
	void h_inicial(int n);
	void decrementa_h();
	
private:
	int h;
}

void Window::h_inicial(int n)
{
	int h = 1;
	while (h < n/3)
		h = 3*h + 1;
}

void Window::decrementa_h()
{
	if (h != 1)
	{
		h /= 3;
		if (h < 1)
			h = 1;
	}
	else
		h = 0;
}

vector<int> le_arquivo(string nome_arquivo)
{
	vector<int> sequencia;
	int temp;
	fstream arquivo;
	char joga_fora;

	arquivo.open(nome_arquivo.c_str());

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

void escreve_arquivo(string saida, vector<int> ordenados)
{
	ofstream arquivo;
	
	arquivo.open(saida.c_str());

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

vector<int> shell_sort(vector<int> sequencia)
{
	Window gap;
	//int h = h_inicial(sequencia.size());
	int trocas = 0, iteracoes = 0;
	
	gap.h_inicial(sequencia.size());
	while (gap.h >= 1)
	{
		for (int i = 0; i < gap.h; i++)
		{
			for (int j = i + gap.h; j < sequencia.size(); j += gap.h)
			{
				int temp = sequencia[j];
				int k = j - gap.h;
				while (k >= 0 && sequencia[k] > temp)
				{
					sequencia[k + gap.h] = sequencia[k];
					k -= gap.h;
					trocas++;
				}
				sequencia[k + gap.h] = temp;
			}
		}
		gap.decrementa_h();
		iteracoes++;
	}
	
	cout << "\n\nForam realizadas " << trocas << " trocas e " << iteracoes << " iteracoes. \n\n";
	
	return sequencia;
}

void gera_aleatorios()
{
	vector<int> seq;
	
	for (int i = 0; i < 100; i++)
	{
		int temp = rand()%1000;
		seq.push_back(temp);
	}
	
	escreve_arquivo("entradaaleatorio.csv", seq);
}

void gera_ordenados()
{
	vector<int> seq;
	
	int temp = 0;
	for (int i = 0; i < 30; i++)
	{
		seq.push_back(temp);
		temp += 30;
	}
	
	escreve_arquivo("entradaordenado.csv", seq);
}

void gera_inverso()
{
	vector<int> seq;
	
	int temp = 1000;
	for (int i = 0; i < 120; i++)
	{
		seq.push_back(temp);
		temp -= 8;
	}
	
	escreve_arquivo("entradainversa.csv", seq);
}

int main()
{
	string nome_arquivo, arquivo_saida;
	vector<int> sequencia;
	char expect;

	cout << "Informe o nome do arquivo a ser lido: ";
	getline(cin, nome_arquivo);
	if (nome_arquivo.find(".csv") == nome_arquivo.npos)
		nome_arquivo = nome_arquivo + ".csv";  // Adiciona a extensão ao nome do arquivo se for necessário

	cout << "\nE o nome do arquivo de saida: ";
	getline(cin, arquivo_saida);
	if (arquivo_saida.find(".csv") == arquivo_saida.npos)
		arquivo_saida = arquivo_saida + ".csv";
	
	sequencia = le_arquivo(nome_arquivo);
	sequencia = shell_sort(sequencia);
	escreve_arquivo(arquivo_saida, sequencia);
	
	gera_aleatorios();
	sequencia = le_arquivo("entradaaleatorio.csv");
	sequencia = shell_sort(sequencia);
	escreve_arquivo("saidaaleatorio.csv", sequencia);
	
	gera_ordenados();
	sequencia = le_arquivo("entradaordenado.csv");
	sequencia = shell_sort(sequencia);
	escreve_arquivo("saidaordenada.csv", sequencia);
	
	gera_inverso();
	sequencia = le_arquivo("entradainversa.csv");
	sequencia = shell_sort(sequencia);
	escreve_arquivo("saidainversa.csv", sequencia);
	
	cin >> expect;
	
    return 0;
}