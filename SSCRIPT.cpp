/*
 * Author Chaudhary Hamdan
 * C++ Template for Competitive Programming
 * Github link : https://github.com/hamdan-codes
 */

/*
 * Template available at my Github
 * Repository Link :-
 * https://github.com/hamdan-codes/templates-for-CP/
 */




#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,k,pos, flag, n,c;
    string str;
    string var;
    cin>>t;
    while(t--){
        c=0;
        flag=0;
        cin>>n;
        
        cin>>k;
        cin>>str;
        for(int i=0;i<n;i++){
            if(str[i]=='*'){
                c++;
                if(c>=k){
                    cout<<"YES"<<endl;
                    break;
                }
            }
            else{
                c=0;
            }
        }
            if(c<k){
                cout<<"NO"<<endl;
            }
        }
	return 0;
}