#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
bool check(char a,char b){
	//true if a has greater precedence
	if(a==42||a==47){
		return true;
	}else if(b==43||b==45){
		return true;
	}else {
		return false;
	}
}
int main(){
	char a[50];
	char b[50];
	cin>>a;	
	int len = strlen(a);
	stack<char> s;
	int k = 0;
	for(int i=0;i<len;i++){
		if(a[i]=='('){
			s.push(a[i]);
		}else if(a[i]=='+'||a[i]=='-'||a[i]=='/'||a[i]=='*'){
			char c = a[i];
			if(!s.empty()){
				
			if(s.top()!='(')
			while(check(s.top(),c)){
				if(s.top()){
					b[k] = s.top();
					s.pop();
					k++;
				}
			}
			}
			s.push(c);
		}else if(a[i]==')'){
			while(s.top()!='('){
				b[k++] = s.top();
				s.pop();
			}
			s.pop();
		}else {
			b[k++] = a[i];
		}
		
	}
	for(int i=0;i<k;i++){
		cout<<b[i];
	}
}
