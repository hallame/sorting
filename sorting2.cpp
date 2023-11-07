


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
