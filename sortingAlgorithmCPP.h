#include <cmath>

#define RECORD_SIZE 1000

class sortingAlgorithm
{
    public:

        int quickSort(int *, int, int);
        void shellSort(int *);
        void selectionSort(int *);
        void insertionSort(int *);
        void bubbleSort(int *);


    private:

        int partition(int *, int, int);
};

int sortingAlgorithm::quickSort(int *v, int left, int right)
{
    int index;
    if(left < right)
    {
        index = this->partition(v, left, right);
        this->quickSort(v, left, index - 1);
        this->quickSort(v, index + 1, right);
    }
    return 0;
}


int sortingAlgorithm::partition(int *v, int left, int right)
{
    int i     = left;
    int j     = right - 1;
    int pivot = *(v + right);
    int tmp;

    while(i < j)
    {
        while(*(v + i) <= pivot && i < right)
            i++;

        while(*(v + j) >= pivot && j > left)
            j--;

        if(i < j)
        {
            tmp = *(v + i);
            *(v + i) = *(v + j);
            *(v + j) = tmp;
        }

        if(*(v + i) > pivot)
        {
            tmp          = *(v + i);
            *(v + i)     = *(v + right);
            *(v + right) = tmp;
        }
    }
    return i;
}


void sortingAlgorithm::shellSort(int *v)
{
    int gap;
    int i, j;
    int tmp;

    for(gap = RECORD_SIZE / 2;gap >= 1;gap = (int)std::ceil((float)gap / 3))
    {
        for(i = gap;i < RECORD_SIZE;i++)
        {
            for(j = i - gap;j >= 0 && *(v + j) > *(v + j + gap);j -= gap)
            {
                tmp           = *(v + j);
                *(v + j)      = *(v + j + gap);
                *(v +j + gap) = tmp;
            }
        }
        if(gap == 1)
            break;
    }
}


void sortingAlgorithm::selectionSort(int *v)
{
    int i, j, posMin, tmp;

    for(i = 0;i < RECORD_SIZE;i++)
    {
        posMin = i;
        for(j = i + 1;j < RECORD_SIZE;j++)
            if(*(v + j) < *(v + posMin))
                posMin = j;
        tmp           = *(v + i);
        *(v + i)      = *(v + posMin);
        *(v + posMin) = tmp;
    }
}


void sortingAlgorithm::insertionSort(int *v)
{
    int i, j, tmp;

    for(i = 1;i < RECORD_SIZE;i++)
    {
        for(j = i;*(v + j) < *(v + j - 1);)
        {
            tmp          = *(v + j);
            *(v + j)     = *(v + j - 1);
            *(v + j - 1) = tmp;
            j--;
            if(j == 0)
                break;
        }
    }
}


void sortingAlgorithm::bubbleSort(int *v)
{
    int i, j, tmp;

    for(i = 0;i < RECORD_SIZE;i++)
    {
       for(j = 0;j < RECORD_SIZE - 1;j++)
       {
           if(*(v + j) > *(v + j + 1))
           {
               tmp          = *(v + j);
               *(v + j)     = *(v + j + 1);
               *(v + j + 1) = tmp;
           }
       }
    }
}
