#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	for(int j=1; j<=n; j++){
		int servnum; cin >> servnum;
		char server = 'A';
		int Awins = 0;
		int Bwins = 0;
		int num = servnum;
		for(int i=0; i<servnum; i++){
			char winner;
			cin >> winner;
			num--;
			if(winner == server){
				if(winner == 'A'){
					Awins++;
          //if Team A has won stop the game
					if((Awins >= 15) and (Awins - Bwins >= 2)){
						break;
					}
				} else if (winner == 'B'){
          //if Team B has won stop the game
					Bwins++;
					if((Bwins >= 15) and (Bwins - Awins >= 2)){
						break;
					}
				}
			} else {
				server = winner;
			}
		}
		while(num--){
			char trash; cin >> trash;
		}
    //output end of game string
		if(((Awins >= 15) or (Bwins >= 15)) and (abs(Awins - Bwins) >= 2)){
			if(Awins > Bwins){
				cout << "Match " << j << ": Team A has won the match with a score of " << Awins << "-" << Bwins << "." << endl;
			} else if (Bwins > Awins){
				cout << "Match " << j << ": Team B has won the match with a score of " << Awins << "-" << Bwins << "." << endl;
			}
		} else { 
			cout << "Match " << j << ": The score is " << Awins << "-" << Bwins << "." << endl;
		}
		
	}
}
