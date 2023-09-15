#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

char* itoa(int a)
{
	char* buffer = (char*)malloc(10*sizeof(char));
	int i = 0;
	if(a == 0){
		buffer[0] = 48;
	} else{
		while(a!=0){
			buffer[i] = a%10 + 48;
			i++;
			a/=10;
		}
	}
	return strrev(buffer);
}

int main(int argc, char* argv[])
{
	FILE* ptr;
	char a;
	ptr = fopen ("numbers.txt", "w");
	assert(0!=ptr);
	for(int i = 0; i <= atoi(argv[1]); i++){
		fputs(itoa(i),ptr);
		fputc(13,ptr);
	}
}
