#include "random.h"

RandomNumbers::RandomNumbers(unsigned long int s) : seed(s)
{
	if(seed==0) {
		std::random_device rd;
		seed = rd();
		};
	rng = std::mt19937(seed);
}

void RandomNumbers::uniform_double(std::vector<double>& numbers, double lower, double upper)
{
	for(size_t i(0); i< numbers.size(); ++i) {
		numbers[i] = uniform_double(lower, upper);
	}
}

double RandomNumbers::uniform_double(double lower, double upper)
{
	std::uniform_real_distribution<double> duniform(lower, upper);
	return duniform(rng);
}

void RandomNumbers::normal(std::vector<double>& numbers, double mean, double sd)
{
	for(size_t i(0); i< numbers.size(); ++i) {
		numbers[i] = normal(mean, sd);
	}
}

double RandomNumbers::normal(double mean, double sd)
{
	std::normal_distribution<double> dnormal(mean, sd);
	return dnormal(rng);
}

void RandomNumbers::poisson(std::vector<int>& numbers, double mean)
{
	for(size_t i(0); i< numbers.size(); ++i) {
		numbers[i] = poisson(mean);
	}
}
int RandomNumbers::poisson(double mean)
{
	 std::poisson_distribution<int> dpoisson(mean);
	 return dpoisson(rng);
}
