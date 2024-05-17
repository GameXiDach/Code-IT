#include <iostream>
#include <string>
#include <fstream>

using namespace std;


char mahoa(char ch, int k)
{
	if(ch == ' ') return ' ';
	char rs = (ch - 97 + k) %26;
	return rs+97;	
}
char giaima(char ch, int k)
{
	if(ch == ' ') return ' ';
	char rs = (ch - 97 - k +26) %26;
	return rs+97;
}


int main() {
	
	int k,option;
	string mess;
	cout <<"--------------------------MA HOA VA GIA MA CAESER------------------------------"<<endl;
	while(true)
	{
		
		cout <<"0. Nhap so 0 ket thuc chuong trinh"<<endl;
		cout <<"1. Ma hoa mot thong diep "<<endl;
		cout <<"2. Giai ma mot thong diep"<<endl;
		
		cout <<">>Moi ban nhap lua chon:"; cin >>option;
		switch(option)
		{
			case 0: return 0;
			case 1:
			
				cout <<"Nhap k(k > 0):"; cin >>k;
				cin.ignore();
				cout <<"Nhap thong diep:"; getline(cin,mess);
				cout <<"Thong diep da duoc ma hoa:";
				
				for(int i=0; i < mess.length(); i++)
				{
					cout<<mahoa(mess[i],k);
				}
				cout <<endl;
			 	break;
			case 2:
			
				cout <<"Nhap k(k > 0):"; cin >>k;
				cin.ignore();
				cout <<"Nhap thong diep giai ma:"; getline(cin,mess);
				cout <<"Thong diep da duoc gia ma:";
				
				for(int i=0; i < mess.length(); i++)
				{
					cout<<giaima(mess[i],k);
				}
				cout <<endl;
				break;
			
		}
	}

    return 0;
}

