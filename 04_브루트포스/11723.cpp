#include <iostream>

using namespace std;

int add(int set, int x) {
	set |= 1<<(x-1);
	return set;
}
int remove(int set, int x) {
	set &= ~(1<<(x-1));
	return set;
}
void check(int set, int x) {
	if (set & (1<<(x-1))) { //set과 x가 모두 1인 경우만 결과값이 1로 true 
		cout << 1 << '\n';
	}
	else {
		cout << 0 << '\n';
	}
}

int toggle(int set, int x) {
	set ^= 1 << (x - 1);
	return set;
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
			set = add(set, x);

		}
		else if (op == "remove") {
			cin >> x;
			set = remove(set, x);
		}
		else if (op == "check") {
			cin >> x;
			check(set, x);
		}
		else if (op == "toggle") {
			cin >> x;
			set = toggle(set, x);
		}
		else if (op == "all") {
			set = (1 << 20) - 1;
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