// COMP 321 A5 Q2 Bank Queue
// Name: Simon Hsu
// ID: 260610820
// Date: 2017.03.07
#include <stdio.h>  
#include <vector>
#include <algorithm> // sort function

using namespace std; // for declaring string or vector

struct Person{
    int money;
    int time;
    
    Person(int m, int w){
        money = m;
        time = w;
    }
};

// compares the Person by their money.
bool compareMoney(const Person &a, const Person &b){
        return a.money >= b.money;
}

// put the person into the queue, 
// if the person's spot and all spots below him are occupied,
// stop the loop, cannot serve him.
void queuePerson(vector<int> &v, Person c){
    int i = c.time;
    
    while(i >= 0){
        if(v[i] == 0){
            v[i] = c.money;
            return;
        }  
        i--; // loop stops after no more person in queue
    }
}

int main(){ 
	// N = the number of people in the queue
	// T = the time in minutes until Oliver closes the bank
	// ci = the amount of cash in Swedish crowns person i has
	// ti = the time in minutes from now after which person i leaves if not served
    int N, T, ci, ti;
    int sum = 0;
    int i = 0;
	
    scanf("%d %d", &N, &T);
    
    // declair bQueue and money
    vector<int> bQueue(T);
    vector<Person> money;
    
    for(int i = 0; i < N; i++){
        scanf("%d %d", &ci, &ti);
        Person c(ci, ti);
        
		// adds a new element at the end of the vector, after its current last element. The content of c is copied to the new element.
        money.push_back(c); 
    }
    
	// sorts the elements in the range [first,last) into ascending order.
    sort(money.begin(), money.end(), compareMoney);
    
    // queue the person's time with money
    while(i < money.size()){
        queuePerson(bQueue, money[i]);
        i++;
    }
    
    // serve eveyone inside the bQueue.
    for(int i = 0; i < bQueue.size(); i++){
        sum += bQueue[i];
    }
    
    printf("%d", sum); // print out the maximum amount of money you can get from the people in the queue before the bank closes.
    return 0; // end of program
}