package sortingalgorithms;
import java.lang.Math;

public class SortingAlgorithm
{
    public static Integer quickSort(Integer v[], Integer left, Integer right)
    {
        Integer index;

        if(left < right)
        {
            index = partition(v, left, right);
            quickSort(v, left, index - 1);
            quickSort(v, index + 1, right);
        }
        return 0;
    }

    private static Integer partition(Integer v[], Integer left, Integer right)
    {
        Integer i = left;
        Integer j = right - 1;
        Integer pivot = v[right];
        Integer tmp;

        while(i < j)
        {
            while(v[i] <= pivot && i < right)
                i++;
            while(v[j] >= pivot && j > left)
                j--;

            if(i < j)
            {
                tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }

            if(v[i] > pivot)
            {
                tmp = v[i];
                v[i] = v[right];
                v[right] = tmp;
            }
        }
        return i;
    }

    public static void shellSort(Integer v[])
    {
        Integer gap;
        Integer i;
        Integer j;
        Integer tmp;

        for(gap = v.length / 2;gap >= 1;gap = (int)(Math.ceil((double)gap / 3)))
        {
            for(i = gap;i < v.length;)
            {
                j = i - gap;

                if(v[j + gap] == null)
                        break;

                while(j >= 0 && v[j] > v[j + gap])
                {
                    tmp = v[j];
                    v[j] = v[j + gap];
                    v[j + gap] = tmp;

                    j -= gap;

                    if(v[j + gap] == null)
                        break;
                }
                i += 1;
            }
            if(gap == 1)
                break;
            i = gap;
        }
    }


    public static void selectionSort(Integer[] v)
    {
        Integer i, j, tmp;
        Integer posMin;

        for(i = 0;i < v.length;i++)
        {
            posMin = i;
            for(j = i + 1;j < v.length;j++)
                if(v[j] < v[posMin])
                    posMin = j;
            tmp = v[i];
            v[i] = v[posMin];
            v[posMin] = tmp;
        }
    }


    public static void insertionSort(Integer[] v)
    {
        Integer i, j, tmp;
        Integer posMin;

        for(i = 1;i < v.length;i++)
        {
            try
            {
                for(j = i;v[j] < v[j-1] && j != 0;j--)
                {
                    tmp = v[j];
                    v[j] = v[j-1];
                    v[j-1] = tmp;
                }
            }
            catch(ArrayIndexOutOfBoundsException e)
            {
                // To prevent the index -1
            }
        }
    }


    public static void bubbleSort(Integer[] v)
    {
        Integer i, j, tmp;

        for(i = 0;i < v.length;i++)
        {
            for(j = 0;j < v.length - 1;j++)
            {
                if(v[j] > v[j+1])
                {
                    tmp = v[j];
                    v[j] = v[j+1];
                    v[j+1] = tmp;
                }
            }
        }
    }
}
