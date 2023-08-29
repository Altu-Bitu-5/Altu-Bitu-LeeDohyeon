#include <iostream>
#include <set>
#include <algorithm>

using namespace std;


int main(void){
    //입츌력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //변수 선언
    int n, m;
    int count = 0;
    string str;

    set<string> s;

    //입력
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin>>str;
        s.insert(str);
    }

    //포함되는 문자열 개수 세기
    for(int j=0; j<m; j++){
        cin>>str;
        //이진탐색
        if(s.find(str)!=s.end()){
            count++;
        }
    }

    //출력
    cout<<count<<'\n';
    return 0;
}