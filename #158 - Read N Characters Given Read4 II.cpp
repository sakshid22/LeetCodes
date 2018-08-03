//158

int remainSize = 0;
int reaminIndex = 0;
char[] remainBuf = new char[4];

public int read(char[] buf, int n)
{
	if(n<=0)
	return 0;


int index =0;
	while(index < n)
	{
		while(remainIndex < remainSize)
		{
		buf[index++] = remainBuf [remainIndex++];
		}
		
		if(remainIndex >= remainSize)
		{
		remainIndex = 0;
		remainSize = read4(remainBuf);
		}
		if(remainSize == 0)
		break;
	}
return index;
}