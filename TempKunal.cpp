#include<stdio.h>
#include<string.h>
#define scan1(n) scanf("%d",&n);
#define scan2(n1,n2) scanf("%d%d",&n1,%n2);
#define scan3(n) scanf("%d",&n);
#define scan4(n) scanf("%d",&n);
#define print(n) printf("%d",n);
typedef long long int ll;

int main(){
	int n,k;	
	 
	char a[10];
	char b[10];
	
	printf("vis%cvis%d%d", a[0],n,k);
	int i;
	for(i = 0;i<6;i++){
		scanf("%c", &a[i]);
	}
	printf("%s\nlength is:%s", a,strlen(a));
	
	if(strcmp(a,b)==0){
		printf("Strings are same");
	}else{
		printf("Strings are not same");
	}
 	
 	
	
	
	return 0;
}
