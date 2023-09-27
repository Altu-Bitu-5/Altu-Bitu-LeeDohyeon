#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

//사전순으로 앞서는 것을 출력 
//-> 알파벳 배열의 앞에서부터 순서대로 접근하여 문자열에 넣어주면 된다.
//별도의 정렬이 필요하지 않음
pair<int, int> canNotPalindrome(vector<int>& alpha){
    int cnt = 0;
    int mid_index=-1;
    for(int i = 0; i < 26; i++)
        if(alpha[i] % 2 == 1) {
            cnt++;
            mid_index=i;
            alpha[i]--;
        }
    return {cnt, mid_index};

}


string palindrome(const vector<int>& alpha, int mid_idex){
    string ans = "";
    for(int i = 0; i < 26; i++){
        if(alpha[i]>0){
            for(int j = 0; j < alpha[i]/2; j++){
                ans += i + 'A';
            }
        }
    }
    string reverse_ans = ans;
    reverse(reverse_ans.begin(), reverse_ans.end());    
    if(mid_idex!= -1){
         ans += 'A'+mid_idex;
    }
    ans+= reverse_ans;
    return ans;
}

int main() {
    string s;
    vector<int> alpha(26, 0);
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        alpha[s[i]-'A']++;
    }
    pair<int, int> odd_info = canNotPalindrome(alpha);
    
    if(odd_info.first>1) {
        cout << "I'm Sorry Hansoo"; 
        return 0;
    }

    cout<< palindrome(alpha, odd_info.second);

    return 0;
}