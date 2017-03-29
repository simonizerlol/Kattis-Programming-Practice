#include <iostream> // cin cout
#include <string.h>  // include for memset
using namespace std;
// created by Simon Hsu for COMP321 contest 0 and assignment 7
// Date: 2017.03.22
int main(){
	// n = number of stones on the table
	// m = number of different moves
    int n, m;
	
    while(scanf("%d %d", &n, &m) != EOF){
        bool win[n + 1];
        memset(win, 0, sizeof win);

        int moves[m];

        for(int i = 0; i < m; i++) {
            cin >> moves[i]; // get the moves
        }

        for(int i = 0; i < (n + 1); i++){
            if(!win[i]){
                for(int j = 0; j < m; j++){
                    if(i + moves[j] < (n + 1)){
                        win[i + moves[j]] = true;
                    }
                }
            }
        }

        if(win[n]){
            cout << "Stan wins" << endl;
        } 
		else{
            cout << "Ollie wins" << endl;
        }
    }
    return 0;
}