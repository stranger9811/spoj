#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int i, n;
	double a, b;
	cin >> n;
	while(n != 0){
		for(i = 0; i < 15; i++){
			a = pow(2.0, double(i));
			b = pow(2.0, double(i+1));
			if(a <= n && b > n){
				cout << i << endl;
				break;
			}
		}
		cin >> n;
	}
	return 0;
}

