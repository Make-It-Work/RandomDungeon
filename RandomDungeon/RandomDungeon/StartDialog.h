#pragma once
#include <string>
#include <vector>
class StartDialog
{
private:
	std::string description;
	std::vector<std::string> choices;
public:
	StartDialog();
	~StartDialog();
	std::string activate();
	int setSize();
};

