#include "simplemath.h"
#include <iostream>
#include <string>
#include <sstream> 
#include <stdio.h>
#include <string.h>
#include <vector>

// This is a general C++ file which is used to make simple functional tests 

using std::cout; // Equivalent to "using namespace std;", however the first will import the entire namespace and this implementation imports only cout as needed 
using std::string;
using std::vector;
using std::endl;

namespace SomeMath{
	int sum(int a, int b){
		return a,b;
	}
}

using namespace SomeMath;

int main()
{
	cout<< "0***Using stringstream***"<<"\n";
	std::stringstream astream;
	std::string dummy;
	astream << "Hello";
	astream >> dummy;
	cout << dummy << "\n";

	cout<< "1***using templates and function calls defined in classes ***"<<"\n";
	int a = SimpleMaths::cubic(10);
    cout << "10 cubed is = " << a << "\n";
	cout << "The max of 2 and 4 is : " << SimpleMaths::findMax(2,4) << "\n";
	cout << "The max of a and f is : " << SimpleMaths::findMax('a','f') << "\n";
	cout << "The max of hello and hell is : " << SimpleMaths::findMax("hello","hell") << "\n";

	cout<<"2***learning functionality of c_str()***" <<"\n";
	std::string str = "Please split this sentence into tokens";
	char cstr[str.length() + 1];
	strcpy(cstr, str.c_str());
	int i = 0;
	while (cstr[i]!='\0'){
		cout<<cstr[i]<<" ";
		i++;
	}
	cout << "\n";

	cout<<"3***learning the functionality of vectors***" <<"\n";
	vector<int> newvec;
	newvec.push_back(1);
	newvec.push_back(2);
	newvec.push_back(3);
	newvec.push_back(4);
	newvec.push_back(5);
	cout << "The vector contains: ";
	for (int x : newvec)
		cout << x << " ";
	cout << "\n";
	cout<<"I modified the vector to: ";
	for(vector<int>::iterator it = newvec.begin(); it != newvec.end(); it++){
		*it += 2;
		cout<< *it << " ";
	}
	cout << "using iterators" << "\n";
	cout<<"3***learning namespaces***" <<endl;
	cout<<SomeMath::sum(1,2)<<endl;

	return 0;
	
}