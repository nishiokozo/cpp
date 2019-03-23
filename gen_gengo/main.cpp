#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

void putKanji( int a )
{
	char l = a&0xff;
	char h = (a&0xff00)>>8;
	cout.write(&h,1);
	cout.write(&l,1);
	cout << endl;	
}
int main()
{
	vector<string> tbl;

	ifstream fi("JIS第一水準漢字_u8.txt");

	string buf;
	while ( getline( fi, buf ) )
	{
		if( *(buf.end()-1) == 0x0d ) buf.pop_back();
		tbl.push_back(buf);
	}
	
	for ( string& s1 : tbl )
	for ( string& s2 : tbl )
	{
		cout << s1.c_str() << s2.c_str() << endl;
	}
	

}

