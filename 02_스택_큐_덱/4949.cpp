#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isbalance(string str){
    stack<char> s;
    char c;
    for(int i=0;i<str.length();i++){
        c = str[i];

        if(c=='(' || c=='['){
            s.push(c);
        }
        else if(c==')'){
            if(!s.empty()&&s.top()=='('){
                s.pop();
            }
            else{
                return false;
            }
        }
        else if(c==']'){
            if(!s.empty()&&s.top()=='['){
                s.pop();
            }
            else{
                return false;
            }
        } 
    }

    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    string str;
    bool balance;

    //line 단위로 입력받음
    while(true){
        getline(cin, str);
        if(str=="."){ //종료 조건
            break;
        }

        //균형 여부 판단
        balance = isbalance(str);

        //출력
        if(balance){
            cout<<"yes"<<'\n';
        }
        else{
            cout<<"no"<<'\n';
        }
    }
    return 0;
}