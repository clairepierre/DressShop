#pragma once
#include "Dress.h"
#include "DynamicArray.h"
#include <vector>
#define CAP 10

class Repository
{
private:
	std::vector<Dress> dresses;
	std::string filename;
	void writeToFile();
	void readFromFile();
public:
	Repository();
	Repository(const std::string& filename);
	Repository::Repository(std::vector<Dress>& v);
	Repository(Repository& repo);
	Repository& Repository::operator= (const Repository &repo);
	int getCapacity();
	int addDress(const Dress& d);
	int removeDress(Dress d);
	int updateDress(const Dress & d);
	Dress getOnPosition(int i);
	Dress findByPhoto(const std::string & photo);
	Dress findBySize(const std::string& size);
	bool isEmpty();
	std::vector<Dress> getDresses() { return dresses; }
};
