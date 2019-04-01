#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
using namespace std;

void putKanji( int a )
{
	char l = a&0xff;
	char h = (a&0xff00)>>8;
	cout.write(&h,1);
	cout.write(&l,1);
}
int main( int argc , char* argv[] )
{
	string fn = "jistest.txt";
//	ifstream fi("JIS第一水準漢字.txt");
//	ifstream fi("JIS常用漢字.txt");
	if ( argc == 2 )
	{
		fn = string( argv[1] );
	}

	ifstream fi(fn);
	

	vector<string> tbl;

	string line;
	while ( getline( fi, line ) )
	{
 		if( *(line.end()-1) == 0x0d ) line.pop_back();

		{
			vector<string> tmp;
			boost::split( tmp, line, boost::is_space() );
			{
				int n = 0 ;
				if ( tmp.size() == 2 )
				{
					string s = tmp.begin()[1];
					n = atoi(s.c_str());
				}
				if ( n <=10 )
				{
					tbl.push_back( tmp.begin()[0] );
				}
			}
		}

	}
	
//	for ( string& s2 : tbl ) cout << s2.c_str() << endl;

	for ( string& s1 : tbl )
	for ( string& s2 : tbl )
	{
		cout << s1.c_str() << s2.c_str() << endl;
	}

}

