sub quickSort
{
    @v     = @{$_[0]};
    $left  = $_[1];
    $right = $_[2];

    if($left < $right)
    {
        my $index = partition(\@v, $left, $right);
        quickSort(\@v, $left, $index - 1);
        quickSort(\@v, $index + 1, $right);
    }
    return 0;
}

sub partition
{
    @v     = @{$_[0]};
    $left  = $_[1];
    $right = $_[2];

    my $i = $left;
    my $j = $right - 1;
    my $pivot = $v[$right];
    my $tmp = 0;

    while($i < $j)
    {
        while($v[$i] <= $pivot and $i < $right)
        {
            $i++;
        }
        while($v[$j] >= $pivot and $j > $left)
        {
            $j--;
        }
        if($i < $j)
        {
            $tmp   = $v[$i];
            $v[$i] = $v[$j];
            $v[$j] = $tmp;
        }
        if($v[$i] > $pivot)
        {
            $tmp       = $v[$i];
            $v[$i]     = $v[$rigth];
            $v[$right] = $tmp;
        }
    }
    return $i;
}


sub shellSort
{
    my @v = @_;
    my $gap = scalar(@v) / 2;
    my $i = $gap;
    my $tmp = 0;

    while($gap >= 1)
    {
        while($i < scalar(@v))
        {
            $j = $i - $gap;
            while($j >= 0 and $v[$j] > $v[$j + $gap])
            {
                $tmp          = $v[$j];
                $v[$j]        = $v[$j + $gap];
                $v[$j + $gap] = $tmp;
                $j -= $gap;
            }
            $i++;
        }
        if($gap == 1)
        {
            return 0;
        }
        $gap = int(($gap / 3) + 0.99);
        $i = $gap;
    }
}


sub selectionSort
{
    my @v = @_;
    for(my $i = 0;$i < scalar(@v);$i++)
    {
        my $posMin = $i;
        for(my $j = $i + 1;$j < scalar(@v);$j++)
        {
            if($v[$j] < $v[$posMin])
            {
                $posMin = $j;
            }
        }
        my $tmp     = $v[$i];
        $v[$i]      = $v[$posMin];
        $v[$posMin] = $tmp;
    }
}


sub insertionSort
{
    my @v = @_;
    for(my $i = 1;$i < scalar(@v);$i++)
    {
        for(my $j = $i;$v[$j] < $v[$j - 1] && $j != 0;$j--)
        {
            my $tmp    = $v[$j];
            $v[$j]     = $v[$j - 1];
            $v[$j - 1] = $tmp
        }  
    }
}


sub bubbleSort
{
    my @v = @_;
    for(my $i = 0;$i < scalar(@v);$i++)
    {
        for(my $j = 0;$j < scalar(@v) - 1;$j++)  
        {
            if($v[$j] > $v[$j+1])
            {
                my $tmp = $v[$j];
                $v[$j] = $v[$j+1];
                $v[$j+1] = $tmp;
            }
        }
    }
}
