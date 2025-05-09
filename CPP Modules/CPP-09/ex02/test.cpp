#include <iostream>
#include <vector>
#include <utility>
#include <deque>
#include <algorithm>

void printvec(std::vector<int> vec)
{
    int i = 0;
    while (i < vec.size())
        std::cout << vec[i++] << " ";
}

bool is_sorted(std::vector<int> vec)
{
    int i = -1;
    while (++i < vec.size())
    {
        if (vec[i] > vec[i + 1])
            return (false);
    }
    return (true);
}

std::vector<int> dividy_by_range(std::vector<int> vec, int start, int end)
{
    int i = start;
    std::vector<int> array;
    while (i < end)
        array.push_back(vec[i++]);
    return (array);
}

void merge(std::vector<int> & array, std::vector<int> & left, std::vector<int> & right)
{
    int i, j, k; i = j = k = 0;

    while (j < left.size() && k < right.size())
    {
        if (left[j] < right[k])
            array[i++] = left[j++];
        else if (left[j] > right[k])
            array[i++] = right[k++];
    }

    while (j < left.size())
        array[i++] = left[j++];

    while (k < right.size())
        array[i++] = right[k++];
}

void mergeSort(std::vector<int> & vec)
{
   if (vec.size() > 1)
   {
        if (is_sorted(vec))
            return ;
        int mid = (vec.size() / 2);
        std::vector<int> left = dividy_by_range(vec, 0, mid);
        std::vector<int> right = dividy_by_range(vec, mid, vec.size());
        mergeSort(left);
        mergeSort(right);

        merge(vec, left, right);
   }
}

void insertionSort(std::vector<int> & vec)
{
    int i = 1, j = 0;
    int len = vec.size() - 1;
    for (; i <= len; i++)
    {
        j = i;
        while (j > 0 && vec[j - 1] > vec[j])
        {
            int tmp = vec[j];
            vec[j] = vec[j - 1];
            vec[j - 1] = tmp;
            j = j - 1;
        }
    }
}

int binarySearch(std::vector<int> vec, int key)
{
    int left = 0;
    int right = vec.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (key == vec[mid])
            return (mid);
        else if (key > vec[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return (-1);
}

void printPares(std::pair<int, int> p[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << "Pairs: "
                  << p[i].first << ", "
                  << p[i].second << std::endl;
    }
}

std::pair<int, int> formPares(int x, int y)
{
    std::pair<int, int> p;
    p.first = x;
    p.second = y;
    return (p);
}

void insertionContainer(std::vector<int> & M, std::vector<int> & m)
{
    int i = -1;
    std::deque<int> list;

    while (++i < M.size())
        list.push_back(M[i]);
    i = -1;
    while (++i < m.size())
    {

    }
}


void mergeInsertionSort(std::vector<int> & vec)
{
    if (vec.size() > 1)
    {
        int len = vec.size() / 2;
        std::pair<int, int> p[len];
        int i = -1, j = 0;
        std::cout << "Fase 1 - Formar Pares" << std::endl;
        if (vec.size() % 2 == 0)
        {
            while (++i < len)
            {
                p[i] = formPares(vec[j], vec[j + 1]);
                j += 2;
            }
        }
        printPares(p, len);
        std::cout << "Fase 2 - Ordenar os pares e separar os numeros > e <" << std::endl;
        i = -1;
        while (++i < len)
        {
            if (p[i].first > p[i].second)
            {
                int tmp = p[i].first;
                p[i].first = p[i].second;
                p[i].second = tmp;
            }
        }
        std::cout << "Ordenado" << std::endl;
        printPares(p, len);
        std::cout << "Len: " << len << std::endl;
        std::vector<int> M;
        std::vector<int> m;
        i = -1;
        while (++i < len)
        {
            m.push_back(p[i].first);
            M.push_back(p[i].second);
        }
        std::cout << "m: "; printvec(m); std::cout << std::endl;
        std::cout << "M: "; printvec(M); std::cout << std::endl;
        std::cout << "Fase 3 - Ordenar o vector M" << std::endl;
        mergeSort(M);
        std::cout << "M: "; printvec(M); std::cout << std::endl;
        std::cout << "Fase 4 - Inserir m em M um por um" << std::endl;
        //insertionContainer();
    }
}

int main(void)
{
    std::vector<int> vec;
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(7);
    vec.push_back(9);
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(8);
    vec.push_back(2);
    //vec.push_back(6);
    //vec.push_back(0);
    //mergeSort(vec);
    //insertionSort(vec);
    std::cout << "Vec: "; printvec(vec); std::cout << std::endl;
    //std::sort(vec.begin(), vec.end());
    //std::cout << "BinarySearch: " << binarySearch(vec, 10) << std::endl;


    mergeInsertionSort(vec);
    return (0);
}