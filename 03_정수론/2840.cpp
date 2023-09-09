#include <iostream>
#include <vector>

using namespace std;

//바퀴 초기화
void wheelInit(vector<char>& wheel){
    for(int i=0; i<wheel.size(); i++){
        wheel[i] = '?';
    }
}

//바퀴에 있는 문자의 유효성 검사
bool isValid(vector<char>& wheel, int s, char c){
    if(wheel[s] != '?' && wheel[s] != c){ // 칸에 있는 문자가 ?이 아니거나 입력받은 문자와 다른 경우
        return false;
    }
    else {
        wheel[s] = c;
        return true;
    }
}

// 문자 중복 검사
bool isDuplicate(vector<char>& wheel, int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(wheel[i]== wheel[j] && wheel[i]!= '?'){
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력변수 선언
    int n, k, s; 
    char c;
    bool flag1, flag2;
    int index = 0;

    cin >> n >> k;
    vector<char> wheel(n);
    wheelInit(wheel);
    while(k--){
        cin >> s >> c;

        // 시작할 때 화살표가 위치하는 index를 0으로 두고 시계방향 회전한다.
        // 1. 인덱스 구하기
        s %= n;
        index = (index - s);
        if(index < 0){
            index += n;
        }
        // 2. 문자 유효성 검사
        flag1 = isValid(wheel, index, c);
        if(!flag1){
            cout << "!";
            return 0;
        }
    }
    
    flag2 = isDuplicate(wheel, n);
    if(!flag2){
            cout << "!";
            return 0;
        }

    //출력
    for(int i = 0; i<n; i++){
        //마지막 화살표 위치부터 시계방향으로 출력
        cout<<wheel[(index + i) % n];
    }
    cout<<'\n';
    

    return 0;
}