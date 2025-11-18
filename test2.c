#include <stdio.h>

int main() {
	//code
    int i=0;
	char a[50], ch;
	printf("enter a string: ");
	scanf("%s", a);
    
	printf("\n");
	printf("enter the character to be searched in the string: ");
	scanf("%c", &ch);
    printf("%c",ch);

	int c=0;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]==ch)
		c++;
	}
	printf("\n");
	if(c==0)
	printf("%c not found in the string", ch);
	else
	printf("%c found in the string", ch);
	printf("\n\n");
	printf("number of occurences of %c - %d", ch, c);
	
	return 0;
}