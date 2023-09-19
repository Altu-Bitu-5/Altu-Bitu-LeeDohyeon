#include <iostream>

using namespace std;

bool isValid(int ans){
	while(ans>=666){
		if(ans%1000==666){
			return true;
		}
		ans/=10;
	}
	return false;

}


int find666(int n) {
	int ans = 666;
	int c = 0; // 몇 번째 작은 종말의 수인지 저장하는 변수
	while (1) {
		//1000으로 나눈 나머지가 666인지 확인한다.
		//666이 아니라면 10으로 나누어 확인을 반복한다.
		if(isValid(ans)){
			c++;
		}
		if(c==n){
			return ans;
		}
		ans++;
	}
	return ans;
}

int main() {
	int n;

	//입력
	cin >> n;
	cout << find666(n);

	return 0;
}