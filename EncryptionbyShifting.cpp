#include <bits/stdc++.h>
using namespace std;

int main() {
	string cipher, secret; cin >> cipher >> secret;
	string answer; 
	int cipherlen, secretlen;
	cipherlen = cipher.length(); secretlen = secret.length();
	int len_dif = cipherlen - secretlen;
	if(len_dif > 0){
		for(int i=0; i<cipherlen; i++){
			char ch1 = cipher[i] - secret[i];
//subtract the characters to get new character
			if(ch1 >= 0){
        //shift normally if the ASCII difference is greater than 0: add 65 to get ASCII of new
				ch1 = ch1 + 65;
				secret += ch1;
				answer += ch1;
			} else if(ch1 < 0){
        //cycle back if ASCII difference less than 0
				ch1 = 91 + ch1;
				secret += ch1;
				answer += ch1;
			}
		}
//if key is longer than ciphertext directly change answer(i.e original message)
	} else if(len_dif <= 0){
		for(int i=0; i<cipherlen; i++){
			char ch1 = cipher[i] - secret[i];
			if(ch1 >= 0){
				ch1 = ch1 + 65;
				answer += ch1;
			} else if(ch1 < 0){
				ch1 = 91 + ch1;
				answer += ch1;
			}
		}
	}
	cout << answer;
}
