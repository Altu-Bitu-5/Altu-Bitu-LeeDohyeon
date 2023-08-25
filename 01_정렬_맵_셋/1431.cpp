#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int digitSum(string s){
    int sum=0;
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])){
            sum+=s[i]-'0';
        }
    }
    return sum;
}

//정렬 기준
bool cmp(string s1, string s2){
    //문자열 길이 비교 - 길이가 짧을수록 먼저
    if(s1.length()!=s2.length())
        return s1.length() < s2.length();
    
    //길이가 같다면 자리수 합 비교 - 작은 값이 먼저
    int sum1 = digitSum(s1);
    int sum2 = digitSum(s2);

    if(sum1!=sum2)
        return digitSum(s1) < digitSum(s2);
    
    //자리수 합이 같다면 사전순 비교
    return s1 < s2;


}


int main(void){
    int n;
    cin>>n;
    vector<string> v(n, "");
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    //정렬
    sort(v.begin(), v.end(), cmp);

    //출력
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<'\n';
    }
    return 0;
}