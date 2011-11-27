<?php

class SortingAlgorithm
{

    private function partition(&$v, $left, $right)
    {
        $i     = $left;
        $j     = $right - 1;
        $pivot = $v[$right];

        while($i < $j)
        {
            while($v[$i] <= $pivot && $i < $right)
                $i++;
            while($v[$j] >= $pivot && $j > $left)
                $j--;

            if($i < $j)
            {
                $tmp   = $v[$i];
                $v[$i] = $v[$j];
                $v[$j] = $tmp;
            }

            if($v[$i] > $pivot)
            {
                $tmp       = $v[$i];
                $v[$i]     = $v[$right];
                $v[$right] = $tmp;
            }
        }

        return $i;
    }


    public function quickSort(&$v, $left, $right)
    {
        if($left < $right)
        {
            $index = $this->partition($v, $left, $right);
            $this->quickSort($v, $left, $index - 1);
            $this->quickSort($v, $index + 1, $right);
        }
        return 0;
    }


    public function shellSort(&$v)
    {
        for($gap = count($v) / 2;$gap >= 1;$gap = (int)ceil((float)$gap / 3))
        {
            for($i = $gap;$i < count($v);$i++)
            {
                for($j = $i - $gap;$j >= 0 && $v[$j] > $v[$j + $gap];$j -= $gap)
                {
                    $tmp = $v[$j];
                    $v[$j] = $v[$j + $gap];
                    $v[$j + $gap] = $tmp;
                }
           }
           if($gap == 1)
                break;
        }
    }


    public function selectionSort(&$v)
    {
        for($i = 0;$i < count($v);$i++)
        {
            $posMin = $i;
            for($j = $i + 1;$j < count($v);$j++)
                if($v[$j] < $v[$posMin])
                    $posMin = $j;
            $tmp        = $v[$i];
            $v[$i]      = $v[$posMin];
            $v[$posMin] = $tmp;
        }
    }

    public function insertionSort(&$v)
    {
        for($i = 1;$i < count($v);$i++)
        {
            for($j = $i;$v[$j] < $v[$j - 1];)
            {
               $tmp       = $v[$j];
               $v[$j]     = $v[$j - 1];
               $v[$j - 1] = $tmp;
               $j--;
               if($j == 0) break;
            }
        }
    }

    public function bubbleSort(&$v)
    {
        for($i = 0;$i < count($v);$i++)
        {
            for($j = 0;$j < count($v) - 1;$j++)
            {
                if($v[$j] > $v[$j + 1])
                {
                    $tmp       = $v[$j];
                    $v[$j]     = $v[$j + 1];
                    $v[$j + 1] = $tmp;
                }
            }
        }
    }

}
?>
