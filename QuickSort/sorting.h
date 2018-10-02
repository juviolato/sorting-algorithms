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

void le_arquivo(string nome_arquivo, vector<int>& lista);

void escreve_arquivo(string saida, vector<int>& lista);

int particiona(vector<int>& lista, int min, int max);

void quick_sort(vector<int>& lista, int pos_inicial, int pos_final);
