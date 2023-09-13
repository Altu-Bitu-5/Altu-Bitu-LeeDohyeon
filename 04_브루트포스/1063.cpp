#include <iostream>
#include <vector>

using namespace std;

pair<int, int> direction(string s) {
    int dx[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
    int dy[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };
    if (s == "R") {
        return { dx[0], dy[0] };
    }
    else if (s == "L") {
        return { dx[1], dy[1] };
    }
    else if (s == "B") {
        return { dx[2], dy[2] };
    }
    else if (s == "T") {
        return { dx[3], dy[3] };
    }
    else if (s == "RT") {
        return { dx[4], dy[4] };
    }
    else if (s == "LT") {
        return { dx[5], dy[5] };
    }
    else if (s == "RB") {
        return { dx[6], dy[6] };
    }
    else {
        return { dx[7], dy[7] };
    }
}

void lastLocation(vector<string> move, int loc[]) {
    int nkx, nky, nsx, nsy;

    for (int i = 0; i < move.size(); i++) {
        pair<int, int> dir = direction(move[i]);
        //킹과 돌의 다음 위치 계산
        nkx = loc[0] + dir.first; nky = loc[1] + dir.second;
        nsx = loc[2]; nsy = loc[3];

        //1. king이 체스판을 벗어나는지 확인
        if (nkx < 1 || nkx > 8 || nky < 1 || nky > 8) {
            continue; //킹이 체스판을 벗어나는 경우 해당 이동은 건너뛴다.
        }
        //2. king의 위치가 돌과 같은 경우 돌 이동 -> 돌이 체스판을 벗어나는지 학인
        if (nkx == nsx && nky == nsy) {
            nsx += dir.first; nsy += dir.second;
            if (nsx < 1 || nsx > 8 || nsy < 1 || nsy > 8) {
                continue; //돌이 체스판을 벗어나는 경우 해당 이동은 건너뛴다.
            }
        }
        //1과 2의 조건에 해당하지 않는 경우 킹과 돌 위치 갱신
        loc[0] = nkx; loc[1] = nky; loc[2] = nsx; loc[3] = nsy;

    }

}


int main()
{
    string king, stone, input;
    int loc[4]; //king과 stone의 x,y좌표
    vector<string> move;
    int n;


    //입력
    cin >> king >> stone;
    //좌표를 숫자로 변환
    loc[0] = king[0] - 'A' + 1; loc[1] = king[1] - '1' + 1;
    loc[2] = stone[0] - 'A' + 1; loc[3] = stone[1] - '1' + 1;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >>input;
        move.push_back(input);
    }

    lastLocation(move, loc);

    //출력 (좌표 변환)
    cout << (char)(loc[0] + 'A' - 1) << loc[1] << "\n";
    cout << (char)(loc[2] + 'A' - 1) << loc[3] << "\n";

    return 0;
}