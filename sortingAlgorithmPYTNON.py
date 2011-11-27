import math



class algorithms:


    def partition(self, v, left, right):

        i     = left
        j     = right - 1
        pivot = v[right]
 
        while i < j:

            while v[i] <= pivot and i < right:
                i += 1
            while v[j] >= pivot and j > left:
                j -= 1
 
            if i < j:
                tmp  = v[i]
                v[i] = v[j]
                v[j] = tmp
 
            if v[i] > pivot:
                tmp      = v[i]
                v[i]     = v[right]
                v[right] = tmp
    
        return i
 

    def quickSort(self, v, left, right):
        if left < right:
            index = self.partition(v, left, right)
            self.quickSort(v, left, index - 1)
            self.quickSort(v, index + 1, right)
        return 0


    def shellSort(self, v):
   
        gap = len(v) / 2
        i = gap

        while gap >= 1:
            
            while i < len(v):

                j = i - gap

                while j >= 0 and v[j] > v[j + gap]:

                    tmp        = v[j]
                    v[j]       = v[j + gap]
                    v[j + gap] = tmp

                    j -= gap

                i += 1
            if gap == 1:
                break

            gap = int(math.ceil(float(gap) / 3))
            i = gap


    def selectionSort(self, v):
        for i in range(0, len(v)):
            posMin = i;
            for j in range(i + 1, len(v)):
                if v[j] < v[posMin]:
                    posMin = j;
            tmp       = v[i];
            v[i]      = v[posMin]
            v[posMin] = tmp


    def insertionSort(self, v):
        for i in range(1, len(v)):
            j = i
            while v[j] < v[j - 1] and j != 0:
                tmp      = v[j]
                v[j]     = v[j - 1]
                v[j - 1] = tmp
                j -= 1 


    def bubbleSort(self, v):
        for i in range(0, len(v)):
            for j in range(0, len(v) - 1):
                if v[j] > v [j+1]:
                    tmp = v[j]
                    v[j] = v[j+1]
                    v[j+1] = tmp
