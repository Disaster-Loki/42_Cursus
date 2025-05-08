#include <iostream>
#include <vector>
#include <algorithm>

void printvec(std::vector<int> vec)
{
    int i = 0;
    while (i < vec.size())
    {
        std::cout << vec[i++] << " ";
    }
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
        {
            array[i] = left[j];
            i++;
            j++;
        }
        else if (left[j] > right[k])
        {
            array[i] = right[k];
            k++;
            i++;
        }
    }

    while (j < left.size())
    {
        array[i] = left[j];
        i++;
        j++;
    }

    while (k < right.size())
    {
        array[i] = right[k];
        i++;
        k++;
    }
}

void mergeSort(std::vector<int> & vec)
{
   if (vec.size() > 1)
   {
        if (is_sorted(vec))
            return ;
        int mid = (vec.size() / 2);
        std::cout << "Mid: " << mid << std::endl;
        std::vector<int> left = dividy_by_range(vec, 0, mid);
        std::cout << "Left: "; printvec(left); std::cout << std::endl;
        std::vector<int> right = dividy_by_range(vec, mid, vec.size());
        std::cout << "Right: "; printvec(right); std::cout << std::endl;
        mergeSort(left);
        mergeSort(right);
        
        std::cout << "Realiazndo o merge" << std::endl;
        std::cout << "Left: "; printvec(left); std::cout << std::endl;
        std::cout << "Right: "; printvec(right); std::cout << std::endl;
        std::cout << "Vec: "; printvec(vec); std::cout << std::endl;
        merge(vec, left, right);
   }
}

void swap(std::vector<int> & vec, int & j)
{
    int tmp = vec[j];
    vec[j] = vec[j - 1];
    vec[j - 1] = tmp;
    j = j - 1;
}

void insertionSort(std::vector<int> & vec)
{
    int i = 1, j = 0;
    int len = vec.size() - 1;
    std::cout << "Before: "; printvec(vec); std::cout << std::endl;
    for (; i <= len; i++)
    {
        j = i;
        while (j > 0 && vec[j - 1] > vec[j])
            swap(vec, j);
    }
    std::cout << "After: "; printvec(vec); std::cout << std::endl;
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
    //mergeSort(vec);
    insertionSort(vec);
    return (0);
}