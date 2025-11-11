#include <bits/stdc++.h>
using namespace std;

char s[120000];
int n;

int main(){
	cin >> s;
	n = strlen(s);
	for (int i = 0 ; i < n ; ++ i){
		if (s[i] == '0'){
			for (int j = i + 1 ; j < n ; ++ j){
				s[j-1] = s[j];
			}
			s[--n] = 0;
			break;
		}
		if (i == (n-1)){
			s[i] = 0;
			-- n;
		}
	}
	for (int i = 0 ; i < n ; ++ i){
		cout << s[i];
	}
}
