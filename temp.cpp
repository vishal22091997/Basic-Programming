#include <bits/stdc++.h>
using namespace std;
void AALO(int count, char c){
    if(c=='2'){
        if(count%3==0){
            cout<<"c";
        }
        else if(count%3==1){
            cout<<"a";
        }
        else
            cout<<"b";
    }
    else if(c=='3'){
         if(count%3==0){
            cout<<"f";
        }
        else if(count%3==1){
            cout<<"d";
        }
        else
            cout<<"e";
    }
    else if(c=='4'){
         if(count%3==0){
            cout<<"i";
        }
        else if(count%3==1){
            cout<<"g";
        }
        else
            cout<<"h";
    }
    else if(c=='5'){
         if(count%3==0){
            cout<<"l";
        }
        else if(count%3==1){
            cout<<"j";
        }
        else
            cout<<"k";
    }
    else if(c=='6'){
         if(count%3==0){
            cout<<"o";
        }
        else if(count%3==1){
            cout<<"m";
        }
        else
            cout<<"n";
    }
    else if(c=='7'){
         if(count%4==0){
            cout<<"s";
        }
        else if(count%4==1){
            cout<<"p";
        }
        else if(count%4==2){
            cout<<"q";
        }
        
        else
            cout<<"r";
    }
    else if(c=='8'){
         if(count%3==0){
            cout<<"v";
        }
        else if(count%3==1){
            cout<<"t";
        }
        else
            cout<<"u";
    }
    else if(c=='9'){
         if(count%4==0){
            cout<<"z";
        }
        else if(count%4==1){
            cout<<"w";
        }
        else if(count%4==2){
            cout<<"x";
        }
        
        else
            cout<<"y";
    }
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string a;
    cin>>a;
     int count=0;
    for(int i=0;i<a.length();i++){
       count=0;
        while(a[i]==a[i+1]){
            count++;
            i++;
        }
        AALO(count+1,a[i]);
        continue;
        
    }
    return 0;
}
