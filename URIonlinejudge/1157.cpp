#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    for(int n=1; n<=a; n++){
        if(a%n==0){
          cout << n << endl;       
        }
    }
    return 0;
}