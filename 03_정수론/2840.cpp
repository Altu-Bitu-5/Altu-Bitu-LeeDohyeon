#include <iostream>
#include <vector>

using namespace std;
const int ALPHA = 26;

//바퀴에 있는 문자의 유효성 검사 & 중복 체크
bool isValid(vector<char>& wheel, int s, char c, vector<bool>alphabet){
    if(wheel[s] == c){ //해당 칸이 이미 c인 경우
        return true;
    }

    if(wheel[s] != '?' || alphabet[c - 'A']){ // 칸에 있는 문자가 ?이 아닌 다른 글자거나 이미 사용도니 알파벳인 경우
        return false;
    }

    else {
        wheel[s] = c;
        alphabet[c - 'A'] = true;
        return true;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력변수 선언
    int n, k, s; 
    char c;
    bool flag;
    int index = 0;

    cin >> n >> k;
    vector<char> wheel(n, '?'); //선언 동시에 초기화
    vector<bool> alphabet(ALPHA, false); //문자열 중복 체크를 위한 벡터
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
        flag = isValid(wheel, index, c, alphabet);
        if(!flag){
            cout << "!";
            return 0;
        }
    }

    //출력
    for(int i = 0; i<n; i++){
        //마지막 화살표 위치부터 시계방향으로 출력
        cout<<wheel[(index + i) % n];
    }
    
    return 0;
}