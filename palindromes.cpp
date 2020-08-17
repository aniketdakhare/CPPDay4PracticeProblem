#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int num;
    cout << "Enter the Number: \n";
    cin >> num;
	int r,sum ,temp;
	temp=num;
	sum=0;
	while(temp>0)
	{
		r = temp%10;
		sum = sum*10+r;
		temp= temp/10;
	}    
    cout << "Given number: " << num << endl;
    cout << "Reversed number: " << sum << endl;
	if(num==sum)
        cout << "Given number is Palindrome." << endl;
    else
        cout << "Given number is not a Palindrome." << endl;
}