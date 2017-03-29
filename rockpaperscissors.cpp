#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main(void){
    int n, k;
	int p1, p2;
    string m1, m2;
	string rock = "rock";
	string paper = "paper";
	string scissors = "scissors";
    int win[100],lost[100];
	cin >> n;
	if(n == 0){
		return 0;
	}
    while(n != 0){
        cin >> k;

        memset(win, 0, sizeof(win));
        memset(lost, 0, sizeof(lost));
		
		int numberOfGames = (k*n*(n - 1))/2;
        for(int i = 0; i < numberOfGames; i++){
            cin >> p1 >> m1 >> p2 >> m2;
            if(m1 == rock && m2 == paper){
                win[p2]++;
                lost[p1]++;
            } 
			else if(m1 == rock && m2 == scissors ){
                win[p1]++;
                lost[p2]++;
            }
            else if(m1 == paper && m2 == rock){
                win[p1]++;
                lost[p2]++;
            } 
			else if(m1 == paper && m2 == scissors ){
                win[p2]++;
                lost[p1]++;
            }	
			else if(m1 == scissors && m2 == paper){
                win[p1]++;
                lost[p2]++;
            } 
			else if (m1 == scissors && m2 == rock){
                win[p2]++;
                lost[p1]++;
            }
			else if (m1.compare(m2) == 0){
				continue;
			}
        }

        for(int i = 1; i <= n; i++){
            if(win[i] + lost[i] == 0){
				puts("-");
			} 
            else{
                double winAvg = win[i] / (1.0 * (win[i] + lost[i]));
                printf("%.3lf\n",winAvg);
            }
        }
        cout << "";
		cin >> n;
    }

    return 0;
}