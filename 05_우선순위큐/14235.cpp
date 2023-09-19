#include <iostream>
#include <queue>

using namespace std;

void printGift(int a, priority_queue<int>& gift){
    if(a == 0){
        if(gift.empty()){
            cout << -1 << "\n";
        }
        else{
            cout << gift.top()<<"\n";
            gift.pop();
        }
    }
    else{
        int value;
        while(a--){
            cin >> value;
            gift.push(value);
        }
        
    }
    return;
}

int main() {
    int n, a;
    priority_queue<int> gift;
    
    
    //입력
    cin >> n;
    while(n--){
        cin >> a;
        printGift(a, gift);
    }
    
    return 0;
}