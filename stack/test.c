#include <stdio.h>

int main() {
	//code
	
	char ch;
	int c=0,i=0;
	char str[50];
	scanf("%c",&c);
	gets(str);
	
	for( i=0;i<50;i++){
	    if(ch==str[i]){
	        c++;
	       
	    }
	}
	
	if(c==1)
	{
	    printf("Found");
	}
	else
	{
	    printf("Not Found");
	}
	
	return 0;
}