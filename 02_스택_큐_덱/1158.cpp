#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    queue<int> q, ans;
    int temp;

    //입력
    cin >> n >> k;

    for(int i =1; i<=n; i++){
        q.push(i);
    }

    //연산
    while(!q.empty()){
        //k-1번쨰까지 pop후 다시 push
        //k번째는 ans 큐에 넣는다.
        for(int i=0;i<k-1;i++){
            q.push(q.front());
            q.pop();
        }

        ans.push(q.front());
        q.pop();
    }

    //출력
    cout << "<";
    while(ans.size()!=1){
        cout<<ans.front()<<", ";
        ans.pop();
    }
    cout<<ans.front()<< ">\n";
    ans.pop();

    return 0;
}