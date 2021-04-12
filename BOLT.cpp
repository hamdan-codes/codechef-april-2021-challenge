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
	int t;
	float k1, k2, k3, v, product, final, value, va;
	cin>>t;
	while(t--){
	cin>>k1>>k2>>k3>>v;
    product=k1*k2*k3*v;
    final=100/product;
    value = (int)(final * 100 + .5);
    va=(float)value / 100;
    //cout<<va;
    if(va<9.58f){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
	}
	return 0;
}