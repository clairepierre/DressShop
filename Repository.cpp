#include "Repository.h"
#include <string>
#include <algorithm>  
#include <fstream>
#include "Utils.h"
#include "RepositoryExceptions.h"

using namespace std;


Repository::Repository()
{
}

Repository::Repository(const std::string & filename)
{
	this->filename = filename;
	this->readFromFile();
}

Repository::Repository(std::vector<Dress>& v)
{
	this->dresses = v;
}

Repository::Repository(Repository & repo)
{
	this->dresses = repo.dresses;
}

Repository & Repository::operator=(const Repository & repo)
{
	if (this == &repo)
		return *this;
	this->dresses = repo.dresses;
	return *this;
}

int Repository::getCapacity()
{
	return this->dresses.size();
}

int Repository::addDress(const Dress & d)
{
	vector<Dress>::iterator it = find(this->dresses.begin(), this->dresses.end(), d);
	if (it != this->dresses.end())
		return -1;
	this->dresses.push_back(d);
	this->writeToFile();
}

int Repository::removeDress(Dress d)
{
	vector<Dress>::iterator it = find(this->dresses.begin(), this->dresses.end(), d);
	if (it == this->dresses.end())
		throw - 1;
	this->dresses.erase(it);
	this->writeToFile();
}
int Repository::updateDress(const Dress & d)
{
	try
	{
		Dress r = findByPhoto(d.getPhoto());
		removeDress(r);
		addDress(d);
		return 1;
	}
	catch (int)
	{
		throw - 1;
	}

}

Dress Repository::findByPhoto(const std::string & photo)
{
	auto it = this->dresses.begin();
	for (Dress d : this->dresses)
	{
		
		if (d.getPhoto()==photo) 
			return d;
	}
	throw - 2;
}


Dress Repository::findBySize(const std::string & size)
{
	auto it = this->dresses.begin();
	for (Dress d: this->dresses)
	{
		//Dress d = this->repo[i];
		if (d.getSize()==size) 
			return d;
	}
	Dress null;
	return null;
}


Dress Repository::getOnPosition(int i)
{
	return this->dresses[i];
}
bool Repository::isEmpty()
{
	return this->dresses.empty();
}

void Repository::readFromFile()
{
	ifstream file(this->filename);

	if (!file.is_open())
		throw FileException("The file could not be opened!");

	Dress d;
	while (file >> d)
		this->dresses.push_back(d);

	file.close();
}

void Repository::writeToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
		throw FileException("The file could not be opened!");

	for (auto s : this->dresses)
	{
		file << s<<"\n";
	}

	file.close();
}