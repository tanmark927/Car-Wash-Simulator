// Mark Tan
// CECS 282 FINAL PART I
#include <iostream>
#include <cstdlib>
#include "CarWash.h"
using namespace std;

/**
 * Constructs a washer with a given time allotted to wash one car
 */
Washer::Washer(int secs): wash_secs(secs), wash_time_left(0) {}

/**
 * Allows the washer to start washing
 */
void Washer::start_washing() { wash_time_left = wash_secs; }

/**
 * Decrements time left if washer is busy
 */
void Washer::one_second() { if(is_busy()) { wash_time_left--; } }

/**
 * Determines if a washer is still running
 */
bool Washer::is_busy() { return wash_time_left > 0; }

/**
 * Returns the number of cars washed
 */
int Average::getCar() { return car_sum; }

/**
 * Returns the time the cars were washed
 */
int Average::getTotalTime() { return total_wash_time; }

/**
 * Returns the average wait time
 */
double Average::getAverage() { return getTotalTime()/getCar(); }

/**
 * Adds a car to be washed
 */
void Average::nextCar(double wait_time) { car_sum++; total_wash_time += wait_time; }

/**
 * Constructs the probability with a given number
 */
Probability::Probability(float p): prob(p) {}

/**
 * Determines whether a car will be present for washing
 */
bool Probability::query() { return rand() < prob * RAND_MAX; }
