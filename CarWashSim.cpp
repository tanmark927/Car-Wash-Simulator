// Mark Tan
// CECS 282 FINAL PART I
#include <iostream>
#include <queue>
#include <stdlib.h>
#include "CarWash.h"
using namespace std;

int main()
{
	queue<int> arrive_time;
	int sim_time, wash_time, next;
	float prob_cust;

	cout << "Seconds to wash one car: "; cin >> wash_time;
	cout << "Probability of customer arrival during a second: "; cin >> prob_cust;
	cout << "Total simulation seconds: "; cin >> sim_time;

	Average a;
	Probability p(prob_cust);
	Washer w(wash_time);
	srand(time(NULL));

	for(int curr_secs = 1; curr_secs <= sim_time; curr_secs++)
	{
		if(p.query())
			arrive_time.push(curr_secs);
		if(!w.is_busy() && !arrive_time.empty())
		{
			next = arrive_time.front();
			arrive_time.pop();
			a.nextCar(curr_secs - next);
			w.start_washing();
		}
		w.one_second();
	}
	while(!arrive_time.empty())
		arrive_time.pop();

	cout << "Customers served: "<< a.getCar() << endl;
	cout << "Average wait: " << a.getAverage() << endl;

	return 0;
}
