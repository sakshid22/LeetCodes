//157

int read4 (char *buf);

class Solution
{
public:
	int read(char *buf, int n)
	{
	int i=0, readlen;
	char temp[4];
		while(n>0 && (raedlen = read4(temp)) > 0)
		{
		int start = 0;
			while( start < raedlen && n-- > 0)
			buf[i++] == temp[start++];
		}
		return i;
	}
};