/* Title  : Advent Code Chanllenge 2023 - Day1
 * https  ://adventofcode.com/2023/day/1
 * Input  : Text file named inputs.txt - should be located in same folder of source
 * Output : integer Total 
 * Author : Dilip Shirke
 * Date   : 01/12/2023
 * Build Instrution : g++ Trebuchet.cpp
 */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int getDigit(string Str)
{
    int first=-1, second=-1;
    int length = Str.length();
    map<char, int> mp;
    mp['0']= 0; 
    mp['1']= 1;
    mp['2']=2;
    mp['3']=3;
    mp['4']=4;
    mp['5']= 5;
    mp['6']=6;
    mp['7']=7;
    mp['8']=8;
    mp['9']=9;  
    
    map<string, int> mp1;
    mp1["zero"]=0;
    mp1["one"]=1;
    mp1["two"]=2;
    mp1["three"]=3;
    mp1["four"]=4;
    mp1["five"]=5;
    mp1["six"]=6;
    mp1["seven"]=7;
    mp1["eight"]=8;
    mp1["nine"]=9;

     
    	
    for(int i=0; i<length; i++)
    {
       if(Str[i] >= '0' && Str[i] <= '9')
       {
	     if(first == -1)
	         first = mp[Str[i]];
             else
	         second = mp[Str[i]];

       }
       else
       {
	    string key0 = Str.substr(i, 3);    
       	    string key1 = Str.substr(i, 4);
	    string key2 = Str.substr(i, 5);
	    //cout << "key0 = " << key0 << " key1 = " << key1 << " key2 = " << key2 << endl;
	    if(mp1[key0] || mp1[key1] || mp1[key2])
	    {
	    	if(first == -1)
		{
		    first = mp1[key0] | mp1[key1] | mp1[key2];
		    i = (mp1[key0]) ? (i+2) : ((mp1[key1]) ? (i+3) : (i+4));
		}
		else
		    second = mp1[key0] | mp1[key1] | mp1[key2];

		//i = (mp1[key0]) ? (i+2) : ((mp1[key1]) ? (i+3) : (i+4));
                //cout << Str << " = " << first  << " " << second << " " << endl;
 
	    }

       }
    } 

    int total = 0;
    if(first != -1)
    	total += 10*first;

    if(second != -1)
        total += second;
    else
	total += first;
    //cout << Str << " = " << first  << " " << second << " " << total << endl;	
    return total;
}

int main()
{
    unsigned int total = 0;
    string line;
    ifstream fin;

    fin.open("inputs2.txt");

    while(getline(fin, line))
    {
    	total += getDigit(line);
    }

	
    cout << "Total = " << total << endl;
    return 0;
}
