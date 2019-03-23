#include <iostream>
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
	for ( int h = 0x81 ; h <=0xff ; h++ )
	for ( int l = 0x40 ; l <=0xfc ; l++ )
	{
		if ( h > 0x9f && h< 0xe0 ) continue;
		if ( l == 0x7f ) continue;
		int a =  (h<<8)+l;

		if ( a <= 0x889e ) continue;
		if ( a >= 0xfc4c ) continue;
		if ( a >= 0xeeed && 0xfa5b ) continue;
		if ( a >= 0xeaa5 && 0xedfc ) continue;
		if ( a >= 0x9873 && 0x989e ) continue;

		cout << hex << a << " ";
		putKanji( a );
	}

}

