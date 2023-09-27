#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int similarWord(string w1, string w2, vector<int>& alphabet){
    //비슷한 단어 조건
    //1. 길이가 같은 경우 -> 모든 문자가 동일하거나(0), 한 문자만 다름(0 -> 2)
    //2. 길이가 -1인 경우 -> 문자 중 한 문자가 모자라고 나머진 동일(1)
    //3. 길이가 +1인 경우 -> 문자가 다 동일하고 한 문자 더 많음(-1 -> 1)
    //그냥 더했더니 오류 발행(한 문자만 다른 경우와 두 문자 이상 다른 경우 똑같이 0이 나옴) -> 절대값으로 더해준다.
    int cnt = 0;
    vector<int> cmp = alphabet;
    for(int i=0; i<w2.size(); i++){
        //문자 하나씩 비교하며 제거
        cmp[w2[i]-'A'] -= 1;
    }
    
    for(int i=0; i<cmp.size(); i++){
        cnt += abs(cmp[i]);
    }
    
    if(w1.size() == w2.size()){ // 1번
        if(cnt==0 || cnt==2){
            return 1;
        }
    }
    else if(w1.size() == w2.size()+1){ //2번
        if(cnt==1){
            return 1;
        }
    }
    else if(w1.size()+1 == w2.size()){ //3번
        if(cnt==1){
            return 1;
        }
        
    }
    return 0;
    
}

int main(){
    /*
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);*/
    
    int n, ans = 0;
    vector<int> alphabet(26,0);
    string w1, w2;
    
    cin >> n;
    
    //첫 번째 단어 입력
    cin >> w1;
    n--;
    for(int i = 0; i<w1.size(); i++){
        alphabet[w1[i]-'A'] += 1;
    }
    
    for(int i = 0 ; i<n; i++){
        cin >> w2;
        ans += similarWord(w1, w2, alphabet);
        
    }
    cout << ans;
    
    return 0;
}