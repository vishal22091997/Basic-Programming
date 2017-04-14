#include <bits/stdc++.h>

using namespace std;

int main(){
    int g;
    cin >> g;
    for(int a0 = 0; a0 < g; a0++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int sequence_i = 0; sequence_i < n; sequence_i++){
           cin >> a[sequence_i];
        }
        int count = 0;
        while(true){
            int tempCount = 0;
            for(int i=1;i<n-1;i++){
                int left,right,cur;
                if(a[i]!=-1){
				if(a[i-1]==-1){
                    for(int j=i-2;j>=0;j--){
                        if(a[j]!=-1){
                            left = a[j];
                            break;
                        }
                    }
                }else{
                    left = a[i-1];
                }
                if(a[i+1]==-1){
                    for(int j=i+2;j<n;j++){
                        if(a[j]!=-1){
                            right = a[j];
                            break;
                        }
                    }
                }else{
                    right = a[i+1];
                }
            }
                if(right==0&&left==0){
                    a[i] = -1;
                    tempCount++;
                }
            }
            if(tempCount==0){
                break;
                
            }else{
                count+=tempCount;
            }
            
            
            
        }
        if(count%2==0){
                cout<<"Bob"<<endl;
            }else{
                cout<<"Alice"<<endl;;
            }
        
        
        
        
        
        // If Alice wins, print 'Alice' on a new line; otherwise, print 'Bob'
    }
    return 0;
}

