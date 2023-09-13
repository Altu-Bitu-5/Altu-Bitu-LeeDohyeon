#include <iostream>
#include <vector>
#include <cmath>

const int MAX = 1000000; //정수 입력 최대값

using namespace std;


//소수만 남은 배열 반환
vector<bool> getPrimes() {
    vector<bool> primes(MAX+1, true);
    primes[0] = primes[1] = false;
    for(int i=2;i<=sqrt(MAX);i++){ // 루트 1000000까지 검사
        if(primes[i]){ //i가 소수면
            for(int j=i*i; j<=MAX; j+=i){
                primes[j] = false;
            }
        }
    }
    return primes;

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<bool> primes = getPrimes();
    int n;
    bool flag = false; // 두 홀수 소수의 합을 찾았는지 확인하는 변수

    while(true){
        cin >> n;
        if(n==0){ //반복문 종료
            break;
        } 

        // 홀수 i가 소수이고, n - i가 소수인지 확인한다.
        for(int i = 3; i<=n/2; i+=2){//홀수만 탐색
            if(primes[i]&&primes[n-i]){
                flag = true;
                cout << n << " = " << i << " + " << n-i << "\n";
                break;
            }
        }
        if(!flag){ //두 홀수 소수의 합을 찾지 못한 경우
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }


    return 0;
}