#include <iostream>
#include <string>

using namespace std;

int find666(int n) {
	int ans = 666;
	string s;
	int c = 0; // 몇 번째 작은 종말의 수인지 저장하는 변수
	while (1) {
		s = to_string(ans); //숫자를 문자로 변환
		for (int i = 0; i <= s.length() - 3; i++) {
			if (s [i]== '6' && s[i + 1] == '6' && s[i + 2] == '6') { //6이 세번 연속되는지 확인
				c++; //연속된다면 c를 증가
				if (c == n) { //c가 n번째이면 해당 수를 반환한다.
					return ans;
				}
				else { //아니면 반복문을 빠져나와 다음 종말의 수를 찾는다.
					break;
				}
			}
		}
		ans++;
	}
}

int main() {
	int n;

	//입력
	cin >> n;
	cout << find666(n);

	return 0;
}