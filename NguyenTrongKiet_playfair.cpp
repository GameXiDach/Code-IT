#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool arrDS[26];

void finishCreate(char matrixKey[5][5],int n,bool arrDS[26])
{

	// take number column and row current, it means position of a column and row is empty
	// and after complete table matrix
	int row = n/5 , col=(n%5);
	
		for(int k=0; k < 26; k++)
		{
			
			if(col == 5) {
				col=0;
				row++;
			}
			// if charater check yet, add in table 
			if(arrDS[k] == false)
			{
				// 106 = j because continue
				if(k+97 == 106) continue;
				
				matrixKey[row][col] = k + 97;
				col++;
			}
		}

}
int createMatrix(char matrixKey[5][5], bool arrDS[26], string s)
{
	
	int row=0,incre=0, col=0, countSpace=0;
	for(int k=0; k < s.length(); k++)
	{	
		// if charater is space jump to new charater	
		if (s[k] == ' ') continue;
		
		// convert charater sang charater match array arrDS 	
		int index=s[k]-97;
		
		// if column = 5 change row continue 
		if(col == 5) {
			row++;
			col=0;	
		}
		
		// 	if element in array arrDS = false, it means charater its check yet 
		//  then addition charater in table matrix.  
		// variable incre  to check have many charater was addition on table
		if(arrDS[index] == false)
		{
			matrixKey[row][col] = s[k];
			col++;
			incre++;		
		}
		
		// checked charater was addition
		arrDS[index] = true;
		
	}
	return incre;
}
void print(char matrixKey[5][5])
{

	for(int i=0; i < 5 ; i++)
	{
		for(int j=0; j < 5; j++)
		{					
			cout <<matrixKey[i][j]<<" ";
		}
		cout <<endl;
	}
}
void print(char arr[], int n)
{
		cout <<endl;
		for(int j=0; j < n; j++)
		{	
						
			cout <<arr[j];
			if(j%2==1) cout<<" ";
		}
	
}
void print(char arr[], int n, vector<int> arrSpace)
{
//		cout <<endl;
		int k=0,count=1;
		for(int i=0; i < n; i++)
		{
			cout <<arr[i];
			for(k=0; k < arrSpace.size(); k++)		
			if(arrSpace[k]-count == i){
					count++;
					cout<<" ";
			} 
			
		}	
	
}

int removeSpace(char tmp[], string s, int n,vector<int> &arrSpace)
{
	
	int in = 0;
	for(int i=0; i < n ; i++)
	{
		if(s[i] <= 'z' && s[i] >= 'a') {
			if(s[i] == 106) 
				tmp[in] = 'i';
			else 
				tmp[in]=s[i];
			in++;
		} else {
			arrSpace.push_back(i);
		}
		
	}
//	cout<<"check:";
//	print(tmp,n);
	return in;
}

int convertPT(char arrPText[], string s, int n,char tmp[], int len)
{


	int i=0, j ,k=0, count=0;

	// check array tmp
	// compare site i and i+1. if equal insert 'x' between ours
	while(i < len){
		
		j=i+1;
		if(tmp[i] == tmp[j])
		{	
			arrPText[k] = tmp[i];
			k++;
			arrPText[k] = 'x';
			k++;
			// change site i+1. it means j
			i++;
			continue;	
		}
		if(tmp[i] != ' ')
		{
			arrPText[k] = tmp[i];
			k++;
		}
		if(tmp[j] != ' ')
		{
			arrPText[k] = tmp[j];
			k++;
		}
		// change charater next
		i=j+1;	
	}
	// take number element arrPText was add
	for(int dem=0;dem <= k; dem++)
	{
		if(arrPText[dem] >= 'a' && arrPText[dem] <= 'z') 
			count++;
	}

	if(count % 2 == 1){
		arrPText[count] = 'x';
		count++;
		return count;
	}

	return count;
}


void mahoa(char matrixKey[5][5],char arrPText[], int n,char arrCipher[])
{
		int col,row,col1,row1, k=0,count=0;		
		while(k < n)
		{
				//	cout<<"hi"<<k;
				
			// find site col and row k and k+1
			for(int i=0; i < 5 ; i++)
			for(int j=0; j < 5 ; j++)
			{
				if(matrixKey[i][j] == arrPText[k])
				{
					col = j;
					row = i;			
				}
				if(matrixKey[i][j] == arrPText[k+1])
				{
					col1 = j;
					row1 = i;			
				}
					
			}
			
			// if char site k and k+1 equal col change char site column col+1			
			if(col == col1)
			{		
				// if char in the last column then back the start site. 		
				if(row+1 < 5)
					arrCipher[count] = matrixKey[row+1][col];
				else
					arrCipher[count] = matrixKey[0][col];			
				count++;
				
				if(row1+1 < 5)
					arrCipher[count] = matrixKey[row1+1][col];
				else
					arrCipher[count] = matrixKey[0][col];
				count++;
							
			}
			
			if(row == row1)
			{
				if(col+1 < 5)
					arrCipher[count] = matrixKey[row][col+1];
				else
					arrCipher[count] = matrixKey[row][0];
				count++;
				
				if(col1+1 < 5)
					arrCipher[count] = matrixKey[row][col1+1];
				else
					arrCipher[count] = matrixKey[row][0];
				count++;
			}
			
			if(row != row1 && col != col1)	
			{
				arrCipher[count] = matrixKey[row][col1];
				count++;
				arrCipher[count] = matrixKey[row1][col];
				count++;
			}
				
			k=k+2;	
		}
}

int deleteX(char arrCPed[],int n, char arrPTOri[])
{
	int k=0;
	for(int i=0; i < n ; i++)
	{
		// loai bo x
		if(arrCPed[i] == 'x' && arrCPed[i-1] == arrCPed[i+1])
		{
			arrPTOri[k] = arrCPed[i+1];
			k++;
			// vi index i-1, i, i+1 duoc duyet roi. Nen +1 den chuyen tiep vi tri i+2
			i++;
		}
		else{
			arrPTOri[k] = arrCPed[i];
			k++;
		} 	
	}
	
	return k;
}
string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return "";
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}
void giaima(char matrixKey[5][5], int n,char arrCPed[],char arrCipher[])
{
	int col,row,col1,row1, k=0,count=0;	
	while(k < n)
	{
		for(int i=0; i < 5 ; i++)
		for(int j=0; j < 5 ; j++)
		{
			if(matrixKey[i][j] == arrCipher[k])
			{
					col = j;
					row =i;
						
			}
			if(matrixKey[i][j] == arrCipher[k+1])
			{
				col1 = j;
				row1 =i;
						
			}
					
		}
		
		if(col == col1)
		{						
			if(row-1 >= 0)
				arrCPed[count] = matrixKey[row-1][col];
			else
				arrCPed[count] = matrixKey[4][col];				
			count++;
			if(row1-1 >= 0)
				arrCPed[count] = matrixKey[row1-1][col];
			else
				arrCPed[count] = matrixKey[4][col];
			count++;						
		}
		
		if(row == row1)
		{
			if(col-1 >= 0)
				arrCPed[count] = matrixKey[row][col-1];
			else
				arrCPed[count] = matrixKey[row][4];	
			count++;
			if(col1-1 >= 0)
				arrCPed[count] = matrixKey[row][col1-1];
			else
				arrCPed[count] = matrixKey[row][4];
			count++;	
		}
		
		if(row != row1 && col != col1)	
		{
			arrCPed[count] = matrixKey[row][col1];
			count++;
			arrCPed[count] = matrixKey[row1][col];
			count++;
		}
		k=k+2;
	}
}

int main(){
	
	// ma tran key
	char matrixKey[5][5];
	int option;
	string mess;
	cout <<"--------------------------MA HOA PLAYFAIR------------------------"<<endl;
	
	
	while(true)
	{

		cout <<"0. Nhap so 0 ket thuc chuong trinh"<<endl;
		cout <<"1. Ma hoa mot thong diep "<<endl;
		cout <<"2. Giai ma mot thong diep"<<endl;
		
		cout <<">>Moi ban nhap lua chon(0-2):"; cin >> option;
		cin.ignore();
		cout <<endl;
		switch(option)
		{
	
			case 0: return 0;
			case 1:
			
				{	
					cout <<"Nhap khoa:"; getline(cin,mess);
				
					// highlight table check yet
					for(int i=0; i < 26 ; i++) 
					{
						arrDS[i] = false;
										
					}
					// create matrix with a keys, it was insert 
					int current = createMatrix(matrixKey,arrDS,mess), option;
							
					// finish creation with table hight check yet
					finishCreate(matrixKey,current,arrDS);
								
					cout <<"BANG MA HOA";
					cout <<endl;
					print(matrixKey);
					cout <<endl;
					
					string ptext, plaintext;
					cout <<">>Nhap thong diep:"; getline(cin,ptext);
				
					plaintext = trim(ptext);
					int n = plaintext.length(), m = n*2;
					// arrPText is array contains list a charater from variable plaintext
					// tmp is array contains list a charater but it was remove space.
					char arrPText[m]={' '}, tmp[n]={' '};
					

					vector<int> arrSpace;
					// take array charaters (not space) move tmp and return number member of array
					// lenTrue is length after remove space
					int lenTrue = removeSpace(tmp,plaintext,n,arrSpace);
					

					
					// add charater 'x' in array arrPText
					// lenCVPT is length after add char 'x'
					int lenCVPT = convertPT(arrPText,plaintext,n,tmp,lenTrue);
					
					
					
					//-------------------------MA HOA-----------------------
					
					// arrCipher contains charaters was encrypt
					char arrCipher[lenCVPT] = {' '};
					mahoa(matrixKey,arrPText,lenCVPT,arrCipher);
					cout <<endl<<"Thong diep sau khi ma hoa: ";

					print(arrCipher,lenCVPT,arrSpace);
					cout <<endl;
				 	break;
				}
			 	
			case 2:
			
				cout <<"Nhap khoa:"; getline(cin,mess);
				
				// highlight table check yet
				for(int i=0; i < 26 ; i++) 
				{
					arrDS[i] = false;
									
				}
				// create matrix with a keys, it was insert 
				int current = createMatrix(matrixKey,arrDS,mess), option;
						
				// finish creation with table hight check yet
				finishCreate(matrixKey,current,arrDS);
							
				cout <<"BANG MA HOA";
				cout <<endl;
				print(matrixKey);
				cout <<endl;
				
				string text,cipertext;
				
				cout <<"Nhap thong diep giai ma:";  getline(cin,text);
				
				cipertext = trim(text);
				int n = cipertext.length()*2, lenBegin = cipertext.length();
				char  tmp[n]={' '};
				
				vector<int> arrSpace;
        		int lenAfterDeleteSpace = removeSpace(tmp,cipertext,lenBegin,arrSpace);
        		
				char arrCPed[lenBegin], arrPTOri[lenBegin];
				giaima(matrixKey,lenAfterDeleteSpace,arrCPed,tmp);
			
				int lenFact = lenBegin-arrSpace.size();
				int lenAfterDeleteX = deleteX(arrCPed,lenAfterDeleteSpace,arrPTOri);
	
				cout <<"Thong diep da duoc gia ma: ";
					
				int abc= deleteX(arrCPed,lenAfterDeleteSpace,arrPTOri);
					
				print(arrPTOri,abc,arrSpace);
				cout <<endl;
				break;
			
		}
	}
	
}
