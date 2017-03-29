#include <iostream>
#include <set> // Sets are containers that store unique elements following a specific order.

using namespace std;
int main(){
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		set<string> visitedCities;
		for(int j =0; j < n; j++){
			string city;
			cin >> city;
			visitedCities.insert(city);
		}
		cout << visitedCities.size() << endl;
	}
	return 0;
}