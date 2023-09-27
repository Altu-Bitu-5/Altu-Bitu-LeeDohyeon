#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll minSpeed(int n, vector<ll>& speed){
    for(int i=n-2; i>=0; i--){
        //현재 속도가 다음 행성까지의 최소 속도보다 느리면
        if(speed[i]<speed[i+1]){
            //다음 행성까지의 속도 < 현재속도 * n을 만족하는 최소값
            //시간 초과 문제 발생 -> 반복문으로 계산하지 않는다.
            if(speed[i+1]%speed[i]==0){ //배수관계인 경우
                speed[i] = speed[i+1];
            }
            else{ //배수관계가 아닌 경우
                speed[i] = speed[i] * (speed[i+1] / speed[i] + 1);
            }
            
        }
    }
    return speed[0];
}

int main() {
    int n;
    cin >> n;
    vector<ll> speed(n, 0);
    for(int i=0; i<n; i++){
        cin >> speed[i];
    }
    
    cout << minSpeed(n, speed);
    return 0;
}