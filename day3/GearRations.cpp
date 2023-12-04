#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <map>

using namespace std;

struct data 
{
	string digits;
	int num;
	int left;
	int right;
};

int AreValidPartsInLine(string prv, string line, string next)
{
	// Check all part numbers in line and add-up, ignore invalid parts
	int sum = 0;
	int index = 0;
	int left_index = 0;
	int right_index = 0;
	int offset = 0;
	bool Lvalid = false, Rvalid=false, Uvalid=false, Dvalid=false;
	smatch substr;
	string num="";
	string temp_line=line;
	
	vector <data> slist;

	regex r("[0-9]+");

	//cout << "line = " << line << endl;

	while(regex_search(temp_line, substr, r))
	{
	      data details;
      	      details.digits = substr.str(0);
	      details.num = stoi(substr.str(0));
	      details.left = substr.position(0) + offset; 
	      details.right = substr.position(0) + (substr.str(0).length()-1) + offset;
	      offset += temp_line.length() - substr.suffix().str().length();
	      slist.push_back(details);
	      temp_line = substr.suffix().str();
	      //cout << line.length() << " = " << temp_line.length()  << "=" << offset << endl;
	     // cout << "num =" << details.num << " left=" << details.left << " right=" << details.right << " offset=" << offset << endl;
      		      
	}

	
	for(auto& ele: slist)
	{
		//cout << "num =" << ele.num << " left=" << ele.left << " right=" << ele.right << " " ;
		Lvalid = Rvalid = Dvalid = Uvalid = false;
		//Left
		if(ele.left > 0)
                        Lvalid = (line[ele.left-1] != '.') ? true : false;

		//Right
		if(ele.right < line.length())
                        Rvalid = (line[ele.right+1] != '.') ? true : false;
		//UP
		if(!prv.empty())
                {
                        int i = (ele.left > 0) ? ele.left-1 : 0;

                        for(; i<ele.right+2; i++)
                        {
                                Uvalid = (prv[i] != '.');
                                if(Uvalid)
                                        break;
                        }
                }

		//Down
		if(!next.empty())
                {
                        int i = (ele.left < 0) ? 0 : ele.left-1;
                        ele.right = (ele.right >= (next.length()-1)) ? (next.length()-1) : ele.right;
                        for(; i<=ele.right+1; i++)
                        {
                                Dvalid = (next[i] != '.');
                                if(Dvalid)
                                       break;
                        }
                }
		//cout << ele.num << " Valid =" << (Lvalid | Rvalid | Uvalid | Dvalid) << endl;
		if (Lvalid | Rvalid | Uvalid | Dvalid)
		{
			sum += ele.num;
			cout << "   " << ele.num ;
		}

	}

	return sum;
}

int driverCode()
{
	int sum = 0;
	string prv = "";
	string present ="";
	string next = "";

	fstream fin;

	//fin.open("inputs.txt");
	fin.open("test.txt");	
	getline(fin, present);
	getline(fin, next);
	do
	{
			// Read Next line
			sum += AreValidPartsInLine(prv, present, next);
			// Update Previous line
			prv = present;
			present = next;
			//cout << "driver code Sum = " << sum << endl;

	}while(getline(fin, next));

	next = "";
	sum += AreValidPartsInLine(prv, present, next);
	//cout << "driver code Sum = " << sum << endl;
	return sum;
}

int main()
{
        driverCode();
	//cout << "Sum of all the parts number in the engine = " << driverCode() << endl;
	return 0;
}


