#include<stdlib.h>
#include<malloc.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>

int My_strcmp(char*str1, char*str2)
{
	int res = 0;
	while (*str1 != '\0' || *str2 != '\0')
	{
		res = *str1 - *str2;
		if (res != 0)
			break;
		str1++;
		str2++;
	}
	if (res>0)
		return 1;
	else if (res<0)
		return -1;
	return 0;
}
 int my_strcmp(char*str1, char*str2)
{
	while (*str1 != '\0'&&*str2 != '\0')
	{
		if (*str1 > *str2)
			return 1;
		else if(*str1 < *str2)
			return -1;
		str1++;
		str2++;
	}
	if (*str1 != '\0')
		return 1;
	else if(*str2 != '\0')
		return -1;
	return 0;
}
void main()
{
	char ar[] = "hellobiteaaaaaaaaaaaaaaaaaa";
	char*st = "hellobite";
	printf("strcmp=%d\n", strcmp(ar, st));
	printf("strcmp=%d\n", my_strcmp(ar, st));
	printf("strcmp=%d\n", My_strcmp(ar, st));
	system("pause");
}


/*

char* my_strcat(char*destination, char*sourcedestination)
{
	assert(destination != NULL&&sourcedestination);
	char*pst = destination;
	while (*pst != '\0')
		pst++;
	while (*sourcedestination != '\0')
	{
		*pst++ = *sourcedestination++;
	}
	*pst = '\0';
	return destination;
}
void main()
{
	char ar[20] = "ÄãºÃ£¬";
	char*st = "ÌÙ¾®Ê÷";
	//strcat(ar, st);
	//printf("ar=%s\n", ar);
	//printf("\0");
	//my_strcat(ar, st);
	//printf("ar=%s\n", ar);
	//printf("\0");
	char*res = my_strcat(ar, st);
	printf("ar=%s\n", res);
	printf("\0");
	system("pause");
}



char*my_strcpy(char*destination, char*sourcedestion)
{
	assert(destination != NULL&&sourcedestion != NULL);
	char*st = destination;
	while (*sourcedestion != '\0')
	{
		*st++ = *sourcedestion++;
	}
	*st = '\0';
	return destination;
}
void main()
{
	char ar[] = "ÄãºÃ,ÌÙ¾®Ê÷";
	char*st = "hello";
	printf("ar=%s\n", ar);
	strcpy(ar, st);
	printf("ar=%s\n", ar);
	my_strcpy(ar, st);
	printf("ar=%s\n", ar);
	char*res = my_strcpy(ar, st);
	printf("ar=%s\n", res);
	system("pause");
}

size_t my_strlen(const char*string)
{
	assert(string != NULL);
	size_t count = 0;
	while (*string != '\0')
	{
		count++;
		string++;
	}
	return count;
}
size_t my_strlen1(const char*string)
{
	assert(string != NULL);
	if (*string == '\0')
		return 0;
	else
		return my_strlen1(string + 1) + 1;
}

void main()
{
	char*str = "hello.";
	printf("str len=%d \n", strlen(str));
	printf("str len=%d \n", my_strlen(str));
	printf("str len=%d \n", my_strlen1(str));
	system("pause");
}
*/