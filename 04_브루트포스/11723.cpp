#include <iostream>

using namespace std;

const int ALL = (1<<20)-1;

void add(int &set, int x) {
	set |= 1<<(x-1);
}
void remove(int &set, int x) {
	set &= ~(1<<(x-1));
}
void check(int set, int x) {
	if (set & (1<<(x-1))) { //set과 x가 모두 1인 경우만 결과값이 1로 true 
		cout << 1 << '\n';
	}
	else {
		cout << 0 << '\n';
	}
}

void toggle(int &set, int x) {
	set ^= 1 << (x - 1);
}


int main() {

	//입출력 향상
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//입력
	int m, x; 
	string op; 
	int set = 0;


	cin >> m;
	while (m--) {
		cin >> op;
		if (op == "add") {
			cin >> x;
			add(set, x);

		}
		else if (op == "remove") {
			cin >> x;
			remove(set, x);
		}
		else if (op == "check") {
			cin >> x;
			check(set, x);
		}
		else if (op == "toggle") {
			cin >> x;
			toggle(set, x);
		}
		else if (op == "all") {
			set = ALL;
		}
		else if (op == "empty") {
			set = 0;
		}
		else {
			continue;
		}
	}
	return 0;
}