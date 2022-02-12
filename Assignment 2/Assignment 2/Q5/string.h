# include <stdio.h>
# include <stdlib.h>
# define Maxlen 20


// For input of string
void  readstr(char **str){
	*str=(char *)(malloc(Maxlen*sizeof(char)));
	printf("Enter String(Maxlen=%d):",Maxlen-1);
	scanf("\n%[^\n]s",*str);
}

// Length of string
int lenstr(char * str){
	int i=0;
	while(str[i]!='\0'){
		i++;
	}
	return i;
}

// Comparing the strings
int compare_str(char * str1,char * str2){
	int i=0;

	while(str1[i]!='\0' && str2[i]!='\0'){
		if(str1[i]!=str2[i])
 			return str1[i]-str2[i];
		i++;
	}

	if(str1[i]=='\0' && str2[i]=='\0')
    	return 0;
	else if(str1[i]=='\0' && str2[i]!='\0')
		return -1;
	else
		return 1;
}

// Join two strings
char * concatstr(char * str1,char *str2){
	char * str;
	int len1=lenstr(str1),len2=lenstr(str2);
	str=(char *)(malloc((len1+len2+1)*sizeof(char)));
	int i=0,j=0;
	while(str1[j]!='\0'){
		str[i]=str1[j];
		i++;
		j++;
	}
	j=0;
	while(str2[j]!='\0'){
		str[i]=str2[j];
		i++;
		j++;
	}
	str[i]='\0';
	return str;
}

// Copy String
void copystr(char *str1,char *str2){
	int i=0;
	while(str2[i]!='\0'){
		str1[i]=str2[i];
		i++;
	}
	str1[i]='\0';
}

// check for substring
int is_substring(char *str1,char *str2){
	int i,j,k,len1=lenstr(str1),len2=lenstr(str2),flag=0;
	if(len1>len2){
		return 0;
	}
	else{
		for(i=0;i<len2;i++){
			k=i;
			flag=1;
			for(j=0;j<len1;j++){
				if(str2[k]!=str1[j]){
					flag=0;
					break;
				}
				k++;
			}
			if(flag){
				return 1;
			}
		}
		return 0;
	}
}


// Count the number of words
int countword(char * str){
	int i=0,count=0;
	while(str[i]!='\0'){
		if(str[i]==' '){
			count++;
		}
		i++;
	}
	return count+1;
}

// Remove spaces
char *remove_space(char *str){
	char *strsp;
	int len=lenstr(str),i=0,j=0;
	strsp=(char *)(malloc(len * sizeof(char))); 
	while(str[i]!='\0'){
		if(str[i]!=' '){
			strsp[j]=str[i];
			j++;
		}
		i++;
	}
	strsp[i]='\0';
	return strsp;
}

// Reverse a string
char * revstr(char * str){
	int i,len=lenstr(str);
	char * revstr;
	revstr=(char *)(malloc((len+1)*sizeof(char)));
	for(i=0;i<len;i++){
		revstr[i]=str[len-i-1];
	}
	revstr[len]='\0';
	return revstr;
}