#include <iostream>
#include <cmath>
using namespace std;


int main(void){
    int w, in_energy, t; //체중, 일일 에너지 섭취량, 여치
    int d, d_in_energy, d_out_energy; // 다이어트 기간, 다이어트 기간 일일 에너지 섭취량, 다이어트 기간 일일 활동 대사량
    int leftover; // 일일 에너지 섭취량 - 일일 에너지 소비량(활동량+기초대사량)
    int base; //기초대사량
    int w1, w2; //예상 체중 1, 예상 체중 2

    //입력
    cin >> w >> in_energy >> t >> d >> d_in_energy >> d_out_energy;
    leftover = in_energy;
    base = in_energy;
    w1 = w2 = w;
    

    //기초 대사량 변화 고려하지 않았을 때 연산 & 출력
    for(int i=0; i<d; i++){
        leftover = d_in_energy - (d_out_energy+base);
        w1 += leftover;
    }
    if(w1 <= 0 || base <= 0)
            cout<<"Danger Diet"<<'\n';
    else
        cout << w1 << " " << base << '\n';

    //기초 대사량 변화 고려했을 때 연산 & 출력
    for(int i=0; i<d; i++){
        leftover = d_in_energy - (d_out_energy+base);
        w2 += leftover;
        if(abs(d_in_energy-(d_out_energy+base))>t)
            base += floor((d_in_energy-(d_out_energy+base))/2.0);
    }
    if(w2 <= 0 || base <= 0)
            cout<<"Danger Diet"<<'\n';
    else {
        cout << w2 << " " << base << " ";
        if(in_energy > base) 
        //다이어트 후 원래의 일일 에너지 섭취량 > 일일 소비량(활동량=0이므로 기초대사량만 고려)
             cout << "YOYO" <<'\n';
        else
            cout << "NO" << '\n';

    }
    
    

    return 0;
} 