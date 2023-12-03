#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <regex>

using namespace std;

map<string, int> parseLine(string line)
{
	map<string, int> lineDetails;
	
	//lineDetails["id"] = getId(line);
	vector<string> list = {"red", "green", "blue"};

	for(auto& it: list)
        {
		size_t pos = line.find(it, 0);
		size_t pos1;

        	if (pos == string::npos)
                	cout << "NONE";

	        while (pos != string::npos)
		{
			pos1 = pos-2;
			while((line[pos1--]) != ' ');

                	//cout << it << "= " << stoi(&line[pos1+2]) << endl;
			lineDetails[it] = max(lineDetails[it], stoi(&line[pos1+2]));
	                pos = line.find(it, pos + 1);
        	}
	
	}

	return lineDetails;
}

bool possiblityCheck(string line, map<string, int> possible)
{
	bool possibility = true;
	map<string, int> local;
	// find why it is impossible
	
	//cout << line << endl;
	local = parseLine(line);
	vector<string> keys;
        for(auto const& element : possible) 
	{
		keys.push_back(element.first);
  		//std::cout << "Key: " << element.first << "=" << local[element.first] << std::endl;
		possibility = (local[element.first] <= possible[element.first]) ? true : false;
		if(!possibility)
		{
			cout << "Not possible = "<< stoi(&line[(line.find(": ", 0)) - (line.find("me ", 0))]) << endl;	
			break;
		}

	} 
	return possibility;
}

int driverCode(map<string, int> possible)
{
	// open file
	// get next line 
	// possibility check
	// if true add to count
	// loop till end of file
	
	unsigned int count = 0;
	string line;
	fstream fin;

	fin.open("inputs.txt");

	while(getline(fin, line))
	{
		if(possiblityCheck(line, possible))		
		{
			//cout << "here =" << line << endl;
			count += stoi(&line[(line.find(": ", 0)) - (line.find("me ", 0))]);// << endl;
			//count += stoi(&line[(line.find(": ", 0) - (line.find("me ", 0))]);
			//count += stoi(line);
		}
	}
	return count;
}

int main()
{
	map <string, int> possible;
	possible["red"] = 12;
	possible["green"] = 13;
	possible["blue"] = 14;
	cout << "Sum = \n" << driverCode(possible) << endl;
	return 0;
}
