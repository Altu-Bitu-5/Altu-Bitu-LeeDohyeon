#include <iostream>
#include <stack>
#include <string>

using namespace std;

//덧셈 함수
void add(stack<int>& s1, stack<int>& s2, stack<int>& ans)
{
    int n;
    int c = 0; //carry

    //둘 중 한 스택이 비워질 때까지 덧셈
    while(!s1.empty() and !s2.empty())
    {
        n = s1.top()+s2.top()+c;
        c = n/10; 
        n = n%10;

        ans.push(n);
        s1.pop(); s2.pop();
    }
    //s1 스택이 비워진 경우
    if(!s2.empty()){
        while(!s2.empty()){
            n = s2.top()+c;
            c = n/10; 
            n = n%10;

            ans.push(n);
            s2.pop();
        }
    }
    //s2 스택이 비워진 경우
    else if(!s1.empty()){
        while(!s1.empty()){
            n = s1.top()+c;
            c = n/10; 
            n = n%10;

            ans.push(n);
            s1.pop();
        }
    }
    if(c!=0){
        ans.push(c);
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //변수 선언
    string n1, n2; 
    stack<int> s1, s2,ans; 

    //입력
    cin >> n1 >> n2;

    //스택에 저장
    for(int i=0; i<n1.length(); i++){
        s1.push(n1[i]-'0');
    }
    for (int i=0; i<n2.length(); i++){
        s2.push(n2[i]-'0');
    }

    //연산
    add(s1, s2, ans);

    //출력
    while(!ans.empty())
    {
        cout << ans.top();
        ans.pop();
    }

    return 0;
}