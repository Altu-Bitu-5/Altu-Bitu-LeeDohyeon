#include <iostream>

using namespace std;

int getGCD(int a, int b){
    //유클리드 호제법 : a%b와 b의 최대공약수를 구한다
    while(b!=0){ //b가 0이면 gcd는 a
        a %= b;
        swap(a, b);
    }
    return a;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력 변수선언
    int a, b, c, d; 
    int parent, child, gcd;

    cin >> a >> b >> c >> d;

    parent = b * d; //분모
    child = a * d + c * b; //분자

    //분모와 분자의 최대공약수를 구한 후 최대공약수로 나누어 기약분수로 만든다.
    gcd = getGCD(child, parent);
    parent /= gcd, child /= gcd;

    //출력
    cout << child << " " << parent << '\n';

    return 0;

    
}