// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
const int MAXNUM = 10e5+1;
int main() {
	int seqnum = 1;
	int rolls;
  //since no number indicates number of rounds continues until there is no valid input
	while(cin >> rolls){
	int arr[MAXNUM];
	arr[0] = rolls;
	int roll_value = MAXNUM; 
	int n = 1;
	while(roll_value != 0){
		int rolls; cin >> rolls;
		roll_value = rolls;
		arr[n] = rolls;
		n++;
	}
	int money_won = 0;
	for(int i=0; i<n; i++){
	int roll = arr[i];
	if((roll == 7) or (roll == 11)){
		money_won++;
	} else if((roll == 2) or (roll == 3) or (roll == 12)){
		money_won--;
	} else if((roll >= 4) and (roll <= 10) and (roll != 7)){
		for(int j=i+1; j<n; j++){
			int nextroll = arr[j];
			if(nextroll == 7){
				money_won--;
				break;
			} else if(nextroll == roll){
				money_won++;
				break;
			}
		}
	}
	}
  //output final string
	if(money_won == 0){
		cout << "Sequence " << seqnum << ": Break even." << endl;
	} else if (money_won > 0){
		cout << "Sequence " << seqnum << ": Win of $" << money_won << "." << endl;
	} else if (money_won < 0){
		cout << "Sequence " << seqnum << ": Loss of $" << money_won << "." << endl;
	}
	seqnum++;
	}
}
