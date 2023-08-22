#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


//정렬 기준
bool cmp(string s1, string s2){
    //문자열 길이 비교 - 길이가 짧을수록 먼저
    if(s1.length()!=s2.length())
        return s1.length() < s2.length();
    //길이가 같다면 자리수 합 비교 - 작은 값이 먼저
    int sum1=0, sum2=0;
    for(int i=0;i<s1.length();i++)
    {
        if(s1[i]>='0' && s1[i]<='9')
            sum1 += s1[i]-'0';
        if(s2[i]>='0' && s2[i]<='9')
            sum2 += s2[i]-'0';
    }
    if(sum1!=sum2)
        return sum1 < sum2;
    
    //자리수 합이 같다면 사전순 비교
    return s1 < s2;


}


int main(void){
    int n;
    string serial;
    vector<string> v;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>serial;
        v.push_back(serial);
    }

    //정렬
    sort(v.begin(), v.end(), cmp);

    //출력
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<'\n';
    return 0;
}