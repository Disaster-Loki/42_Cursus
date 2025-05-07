#include <iostream>
#include <vector>
#include <algorithm>

void printvec(std::vector<int> vec, int low, int high)
{
    int i = low;
    int size = high;
    while (i <= size)
    {
        std::cout << vec[i++] << " ";
    }
}

bool is_sorted(std::vector<int> vec)
{
    int i = -1;
    int size = vec.size();
    while (++i < size)
    {
        if (vec[i] > vec[i + 1])
        {
            std::cout << "Nao esta sorteada" << std::endl;
            return (false);
        }
    }
    std::cout << "Esta sorteada" << std::endl;
    return (true);
}

void mergeSort(std::vector<int> & vec, int low, int high)
{
    if (is_sorted(vec))
        return ;
    if (low + high == 1)
    {
        std::cout << "Tem dois" << std::endl;
        if (vec[low] > vec[high])
        {
            int tmp = vec[low];
            vec[low] = vec[high];
            vec[high] = tmp;
        }
        return ;
    }
    std::cout << "Low: " << low << std::endl;
    std::cout << "High: " << high << std::endl;
    std::cout << "Fazendo a metade" << std::endl;
    int mid = (int)((low + high) / 2);
    std::cout << "Mid: " << mid << std::endl;
    mergeSort(vec, low, mid);
    mergeSort(vec, mid + 1, high);
}

int main(void)
{
    std::vector<int> vec;
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(7);
    vec.push_back(9);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(0);
    vec.push_back(6);
    vec.push_back(8);

    printvec(vec, 0, vec.size() - 1);
    std::cout << "\nIniciando o MergeSort" << std::endl;
    int low = 0;
    int high = vec.size() - 1;
    mergeSort(vec, low, high);
    std::cout << "Sera que esta organizado MergeSort" << std::endl;
    printvec(vec, 0, vec.size() - 1);
    std::cout << std::endl;
    return (0);
}