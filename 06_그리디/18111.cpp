#include <iostream>
#include <vector>

using namespace std;


pair<int, int> plainGround(int n, int m, int b, vector<vector<int>>& ground, int vmin, int vmax){
    int mintime = 256*500*500*2, maxheight = 0;
    for(int h=vmin; h<=vmax; h++){ //땅의 높이는 vmin~vmax까지 가능
        int add = 0, rm = 0; //더하는 블록의 수, 빼는 블록의 수
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int height = ground[i][j] - h;
                if(height>=0){ //블록을 제거하는 경우
                        rm += height;
                }
                else { //블록을 추가하는 경우
                    add += -height;
                }
            }
        }
        //더하는 블록의 총 개수, 빼는 블록의 총 개수를 가지고 시간 계산
        if(rm+b-add>=0){//사용하는 총 블록의 수가 음수가 되면 안됨
            int time = add + rm * 2;
            if(mintime >= time){ 
                //최소시간 갱신되는 경우 (동일한 최소시간인 경우 최대높이인 답을 반환하도록 조건에 '등호' 사용)
                mintime = time;
                maxheight = h;
            }
            
        }
    }
    
    return {mintime, maxheight};
}

int main() {
    int n, m, b, input;
    int vmin = 257, vmax = 0;
    cin >> n >> m >> b;
    vector<vector<int>> ground (n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> input;
            //높이 중 최소와 최대를 구함
            vmin = min(vmin, input);
            vmax = max(vmax, input);
            ground[i][j] = input;
            
        }
    }
    pair<int, int> ans = plainGround(n, m, b, ground, vmin, vmax);
    cout << ans.first << " " << ans.second;
    
    return 0;
}