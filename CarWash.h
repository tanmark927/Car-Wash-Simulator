// Mark Tan
// CECS 282 FINAL PART I
#ifndef CARWASH_H_
#define CARWASH_H_

class Washer
{
	int wash_secs, wash_time_left;
public:
	Washer(int);
	void start_washing();
	void one_second();
	bool is_busy();
};

class Average
{
	int car_sum;
	double total_wash_time;
public:
	int getCar();
	int getTotalTime();
	double getAverage();
	void nextCar(double);
};

class Probability
{
	float prob;
public:
	Probability(float);
	bool query();
};

#endif /* CARWASH_H_ */
