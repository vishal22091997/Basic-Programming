#include<iostream>
using namespace std;
int main(){
	int lena, lenb;
	cin>>lena>>lenb;
	int* a = new int[lena];
	int* b = new int[lenb];
	for(int i=0;i<lena;i++){
		cin>>a[i];
	}
	for(int i=0;i<lenb;i++){
		cin>>b[i];
	}
	int array[lena+1][lenb+1];
	for(int i=0;i<=lena;i++){
		array[i][0] = 0;
	}
	for(int i=0;i<=lenb;i++){
		array[0][i] = 0;
	}
	
	int dir[lena+1][lenb+1];
	for(int i=0;i<lena;i++){
		for(int j=0;j<lenb;j++){
			if(a[i]==b[j]){
				array[i+1][j+1] = array[i][j]+1;
				dir[i+1][j+1] = 2;
			}else{
				if(array[i][j+1]>array[i+1][j]){
					array[i+1][j+1] = array[i][j+1];
					//point to upward direction
					dir[i+1][j+1] = 1;
					 
				}else if(array[i][j+1]<array[i+1][j]){
					array[i+1][j+1] = array[i+1][j];
					//point to left
					dir[i+1][j+1] = 3; 
				}else{
					array[i+1][j+1] = array[i][j+1];
					//point upward our generic position
					dir[i+1][j+1] = 1; 
				}
				
			}
		}
	}
	 
	int i=lena, j = lenb;
	int ans[100];
	int index = 0;
	while(i>0&&j>0){
		if(dir[i][j] == 2){
			ans[index++] = a[i-1];
			i--;j--;
		}else if(dir[i][j] == 1){
			i--;
		}else if(dir[i][j] == 3){
			j--;
		}
	}
	for(int x=index-1;x>=0;x--){
		
		cout<<ans[x]<<" ";
	}
	
	
	
	
	
}
