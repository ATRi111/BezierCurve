#pragma once
#include<iostream>
#include<fstream>
#include<ios>
#include<string>
#include"TestSet.h"

class TestSerializer
{
protected:
	virtual void Serialize(std::ofstream& stream, const TestSet& set) const = 0;
	virtual TestSet Deserialize(std::ifstream& stream) const = 0;
public:
	void SerializeTo(std::string path, const TestSet& set) const;
	TestSet DeserializeFrom(std::string path) const;
};

std::vector<std::string> Split(std::string s, char seperator);