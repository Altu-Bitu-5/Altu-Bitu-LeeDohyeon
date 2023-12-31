#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, input;
    priority_queue<int, vector<int>, greater<int>> pq; //max heap
    
    //입력
    cin >> n;
    
    for(int i =0; i<n*n; i++){
        cin>>input;
        pq.push(input);
        //메모리 초과 문제 발생
        //max heap이 아닌 min heap으로 수정
        //원소를 push 할 때마다 queue의 크기가 5를 넘지 않도록 수정
        // = 상위값 5개만 남기고 가장 작은 값을 pop한다.
        if(pq.size()>n){
            pq.pop();
        }
    }
    
    cout << pq.top();

    
    return 0;
}