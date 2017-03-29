#include <iostream>
// created by Simon Hsu for COMP321 contest 0 and assignment 7
// Date: 2017.03.22
using namespace std;
int main(){
	int h;
	string path;
    cin >> h;
    getline(cin, path);
		
    long long nodeLabel = (1 << (h + 1)) - 1, d = 1;
    for (int i = 0; i < path.length(); ++i) {
        if(path[i] != 'L' && path[i] != 'R'){
			continue;
		}
		
        long long left = 0, right = 0;
        if(nodeLabel & 1){
            right = nodeLabel - 2 * d;
            left = right + 1;
        } 
		else{
            left = nodeLabel - 2 * d;
            right = left - 1;
        }
        if(path[i] == 'L'){
            d = nodeLabel - left;
            nodeLabel = left;
        } 
		else{
            d = nodeLabel - right;
            nodeLabel = right;
        } 
    }

	cout << nodeLabel << endl;
    return 0;
}