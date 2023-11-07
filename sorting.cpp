#include <iostream>
#include <windows.h>
using namespace std;

struct Student
{
	char name[32];
	int id;
	int grade;
};

Student* AddStruct(Student* Obj, const int amount)
{
	if (amount == 0)
	{
		Obj = new Student[amount+1];
	}
	else
	{
		Student* tempObj = new Student[amount+1];
		for (int i=0; i<amount; i++)
		{
			tempObj[i]=Obj[i];
		}
		delete [] Obj;
		Obj = tempObj;
	}
	return Obj;
}

void setData(Student* Obj, const int amount)
{
		cout << "Last Name: ";
		cin >> Obj[amount].name;
		cout << "St. Billet: ";
		cin >> Obj[amount].id;
		cout << "Marks: ";
		cin >> Obj[amount].grade;
		cout << endl;
}

void showData(const Student* Obj, const int amount)
{
	cout << "No  " << "St. Billet\t\t" << "L. Name\t\t" << "Mark" << endl;
	cout << "================================================" << endl;
	for (int i=0; i<amount; i++)
	{
		cout << i+1 << " | " << Obj[i].id << "\t\t" << Obj[i].name << "\t\t" << Obj[i].grade << endl;
	}
}

void sortByID(Student* Obj, const int amount)
{
	for(int i=0; i<amount; i++)
	{
    	for(int j=amount-1; j>=(i+1); j--)
		{
      		if(Obj[j].id < Obj[j-1].id)
			{
        		Student t = Obj[j];
				Obj[j] = Obj[j-1];
				Obj[j-1] = t;
      		}
    	}
  	}
}


void sortByGreade(Student* Obj, const int amount)
{
	for(int i=0; i<amount; i++)
	{
    	for(int j=amount-1; j>=(i+1); j--)
		{
      		if(Obj[j].grade < Obj[j-1].grade)
			{
        		Student t = Obj[j];
				Obj[j] = Obj[j-1];
				Obj[j-1] = t;
      		}
    	}
  	}
}

void sortByName(Student* Obj, const int amount)
{
	for(int i=0; i<amount; i++)
	{
    	for(int j=amount-1; j>=(i+1); j--)
		{
      		if(Obj[j].name[0] < Obj[j-1].name[0])
			{
        		Student t = Obj[j];
				Obj[j] = Obj[j-1];
				Obj[j-1] = t;
      		}
    	}
  	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	Student* Group = 0;
	int studentAmount = 0;

	int t = 0;
	do{

		cout<<"\n\t 1 - New Group "<<
		"\n\t 2 - Group List "<<
		"\n\t 3 - Sort student billet"<<
		"\n\t 4 - Sort marks "<<
		"\n\t 5 - Sort name "<<
		"\n\t 0 - exit \n>";
		cin >> t;

		switch (t)
		{
			case 1:

				if(studentAmount>0)
						delete[] Group;

				cout << "Enter the number of students in the group: ";
				cin >> studentAmount;
				for(int i=0; i<studentAmount; i++)
				{
					Group = AddStruct(Group, i);
					setData(Group, i);
				}
				break;
			case 2:
				showData(Group, studentAmount);
				break;
			case 3:
				sortByID(Group, studentAmount);
				break;
			case 4:
				sortByGreade(Group, studentAmount);
				break;
			case 5:
				sortByName(Group, studentAmount);
				cout<<"\n sorted MaxToMin";
				break;
			case 0:
				break;
			default:
				cout<<"\n Error";
				break;
		}

	}while(t!=0);

	delete[] Group;
	return 0;
}



/*
	
#include <iostream>
#include <algorithm>
using namespace std;

struct Student
{
	int n = 0;
	string name;
	float score = 0;
};

void input (Student* &arr, int size)
{
	arr = new Student[size];
	cout << "Input name, ID, score";
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << " ";
		cin >> arr[i].name;
    cout << "  ";
    cin >> arr[i].n;
    cout << "  ";
    cin >> arr[i].score;
	}
}

void output (Student* &arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i].name << "  " << arr[i].n << "  " << arr[i].score << endl;
	}
}

void free_arr (int *& arr)
{
  delete []arr;
}

bool sort1 (Student A, Student B)
{
	return A.n < B.n;
}

bool sort2 (Student A, Student B)
{
	return A.score < B.score;
}

bool sort3 (Student A, Student B)
{
	if (A.name == B.name)
		return false;
	int i = 0;
	for (; A.name[i] != '\0' && B.name[i] != '\0'; i++)
	{
		if (A.name[i] != B.name[i])
    {
			return A.name[i] < B.name[i];
    }
	}
	if (A.name[i] == '\0')
  {
		return true;
  }
  else
	return false;
}



int main()
{
	Student* arr = nullptr;
	int size = 0;
  cout << "Size:";
  cin >> size;
	int x;
  do
  {
		switch (x)
		{
		case 1:
			cout << "Input size: ";
				cin >> size;
					break;
		case 2:
			output (arr, size);
			break;
		case 3:
			cout << "Sort 1:";
      sort(arr, arr+size, sort1);
      cout << endl;
			break;
		case 4:
    cout << "Sort 2:";
			sort(arr, arr + size, sort2);
      cout << endl;
			break;
		case 5:
    cout << "Sort 3:";
			sort(arr, arr + size, sort3);
      cout << endl;
			break;
    default:
      ;
		}
	} while (x != 0);
	return 0;
}

*/
