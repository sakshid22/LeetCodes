// 281
Iterator<Integer> cur_iterator;
Iterator<Integer> iterator1;
Iterator<Integer> itertaor2;

public ZigzagIterator(List <Integer> v1, List <Integer> v2)
{
this.iterator1 = v1.iterator();
this.iterator2 = v2.iterator();
this.cur_iterator = (this.iterator1.hasNext() ? this.iterator1 :this.iterator2
}
public int next()
{
int ret = cur_iterator.next();
if(cur_iterator == iterator1)
    {
        if(itertator2.hasNext())
    cur_iterator = iterator2;
    }
else
    {
        if(iterator1.hasNext())
        cur_itertaor = iterator1;
    }
return ret;
}
public boolean hasNext()
{
return cur_iterator.hasNext();
}

