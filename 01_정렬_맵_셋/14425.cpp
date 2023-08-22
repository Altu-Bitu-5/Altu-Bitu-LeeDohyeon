#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void){
    //입츌력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int count = 0;
    string str;

    vector<string> s;

    //입력
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin>>str;
        s.push_back(str);
    }

    //정렬 필요 (탐색 시간 줄이기 위해 이진 탐색 사용)
    sort(s.begin(), s.end());

    //포함되는 문자열 개수 세기
    for(int j=0; j<m; j++){
        cin>>str;
        //이진탐색
        if(binary_search(s.begin(),s.end(), str))
            count++;
    }

    //출력
    cout<<count<<'\n';
    return 0;
}