#include "sorting.h"

void merge(vector<int>& list, const int low, const int mid, const int high, int& trocas)
{
    int auxList[list.size()-1];
    int i{low}, j{low}, k{mid+1};
    // j percorre a lista do início ao meio, e k do meio ao fim

    while (j <= mid && k <= high)
    {
        if (list[j] <= list[k])
        {
            auxList[i] = list[j];       // copia o elemento do primeiro segmento para a lista ordenada
            j++;                        //  e analisa próximo elemento no segmento
        }
        else
        {
            auxList[i] = list[k];       // copia o elemento do segundo segmento
            k++;
            trocas++;
        }
        i++;
    }
    // para terminar de copiar os elementos em ordem:
    if (j > mid)    // se o primeiro segmento já tiver sido copiado por inteiro
    {
        for (int m = k; m <= high; m++)
        {
            auxList[i] = list[m];       // termina de copiar o segundo
            i++;
        }
    }
    else            // se o segundo segmento for o que terminou de ser copiado (ou ambos)
    {
        for (int m = j; m <= mid; m++)
        {
            auxList[i] = list[m];       // termina de copiar o primeiro
            i++;
        }
    }

    for (i = low; i <= high; i++)
        list[i] = auxList[i];       // copia elementos ordenados de volta para a lista original
}

void mergesort(vector<int>& list, int low, int high, int& trocas)
{
    if (high > low)
    {
        int mid = low + ((high - low)/2);

        mergesort(list, low, mid, trocas);          // ordena segmento da esquerda
        mergesort(list, mid+1, high, trocas);       // ordena segmento da direita
        merge(list, low, mid, high, trocas);
    }
}
