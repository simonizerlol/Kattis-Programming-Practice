#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int points[1000][2];
int main (){
    int n, x, y;
    cin >> n;
    while(n != 0){
        for(int i = 0; i < n; i++){
            cin >> x;
            cin >> y;
            points[i][0] = x;
            points[i][1] = y;
        }
        long double area = 0.0;
        for(int i = 0; i < n -1; i++){
            area += ((points[i][0]*points[i+1][1]) - (points[i+1][0]*points[i][1]));  
        }
        area = area + points[n -1][0]*points[0][1] - points[0][0]*points[n-1][1];
        area = (0.5)*area;
        if(area < 0){
            cout << "CW";
        } 
		else{
            cout << "CCW";
        }
        printf(" %.1LF\n", abs(area));
        cin >> n;
    }
}