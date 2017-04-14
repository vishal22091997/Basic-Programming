#include <bits/stdc++.h>

using namespace std;

int main(){
    char a[101];
    // Print 'Yes' if the word is beautiful or 'No' if it is not.
    cin>>a;
    int len = strlen(a);
    bool be = true;
    for(int i=0;i<len-1;i++){
        if(a[i]==a[i+1]){
            be = false;
            break;
        }else if((a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='y')&&(a[i=1]=='a'||a[i=1]=='e'||a[i+1]=='i'||a[i+1]=='o'||a[i+1]=='u'||a[i+1]=='y')){
            be = false;
            break;
        }
    }
    if(be){
        cout<<"yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}

