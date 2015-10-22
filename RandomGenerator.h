#pragma once
class RandomGenerator
{
private:
	static RandomGenerator* instance;
	static bool instanceFlag;
	RandomGenerator(){}
public:
	static RandomGenerator* getInstance();
	int getRandom(int min, int max);
	~RandomGenerator() {
		instanceFlag = false;
	}
};

