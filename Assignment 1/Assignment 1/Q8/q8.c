#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_prime(int a)
{
	int i;
	for(i=2;i<a;i++)
		if(a%i==0) return 0;
	return 1;
}

void main(){
    int *name_int;
    char name[50];
    int P=1000;
    int loop = 7;
    int tmp=0, length_str, len; 
    char str[512];
    char *s1, *s2;  


    printf("Enter your name : ");
    scanf(" %[^\n]",name);


    len=strlen(name);
    name_int=(int*)malloc(len*sizeof(int));
    for(int i=0;i<len;i++)
    {
        *(name_int+i)=(int)name[i]; 
    }
    
    

     
    for (int i=0; i<len; i++){
        tmp += snprintf(&str[tmp], 512-tmp, "%d", *(name_int+i));
    }

    length_str=strlen(str);
    s1=(char*)malloc((length_str/2)*sizeof(char));
    s2=(char*)malloc((length_str-length_str/2)*sizeof(char));

    memcpy(s1,str,length_str/2);
    memcpy(s2,str+length_str/2,length_str-length_str/2);

    
    printf("Integer after juxtaposing : %s \n", str);
    // printf("%s \n", s1);
    // printf("%s \n", s2);
    // printf("%d \n", atoi(s1)+atoi(s2));

    while (loop--)
    {
        while(is_prime(P)==0)
        {
            P++;
        }

        printf("Prime number : %d Remainder : %d \n", P, (atoi(s1)+atoi(s2))%P);

        P++;
    }
    
    
   
    free(name_int);
}
