#include <iostream>
using namespace std;

class Array
{
	private:
		int size;
		int* arr;
	public:
		Array(int s)
		{
			size = s;
			arr=new int[size];
			cout<<"Array Size is :"<<size;
			cout<<endl;
		}
		~Array()
		{
			delete[] arr;
			cout<<"Memory deleted"<<endl;
		}
		void Accept()
		{
			cout<<"Enter Elemts: ";
			for(int i=0;i<size;i++)
			{
				cin>>arr[i];
			}
		}
		void Display()
		{
			for(int i=0;i<size;i++)
			{
				cout<<arr[i]<<" "<<endl;
			}
		}
};
			
int main()
{
	int n;
	cout<<"Enter size of an array: ";
	cin>>n;

	Array arr(n);

	arr.Accept();
	arr.Display();

	return 0;
}
