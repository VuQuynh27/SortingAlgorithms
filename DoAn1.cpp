#include<bits\stdc++.h>
#include<cstdlib>
#include <ctime>

using namespace std;
#define MAX 1000000000


void swap(long long &a, long long &b){
	long long temp = a;
    a = b;
    b = temp;
}

void printArray(long long a[], int n){
	for(int i=0; i<n; i++){
		cout<< a[i]<< ' ';
	}
}

// Bubble sort
void bubbleSort(long long a[], int num){
	for(int i=0; i<num; i++){
		bool sorted = true;
		
		for(int j=0; j<num-i-1; j++){
			if(a[j] > a[j+1]){
				swap(a[j], a[j+1]);
				sorted = false;
			}
		}
		
		if(sorted == true) break;
	}
}

// Insertionn Sort
void insertionSort(long long a[], int num){
	for(int i=1; i<num; i++){
		long long last = a[i];
		int j = i;
		
		while((j>0) && (a[j-1]>last)){
			a[j] = a[j-1];
			j = j-1;
			a[j] = last;
		}
	}
}


// Selection Sort
void selectionSort(long long a[], int num){
	int i, j, min;
	for(i=0; i<num; i++){
		min = i;
		
		for(j=i+1; j<num; j++){
			if(a[j] < a[min])
				min = j;
		}
				
			swap(a[min], a[i]);
	}
}


// Quick Sort
long long partition(long long a[], int first, int last){
	long long pivot = a[last];
	int left = first;
	int right = last - 1;
	
	while(true){
		while(left <= right && a[left] < pivot) left++;
		while(left <= right && a[right] > pivot) right--;
		if(left > right) break;
		swap(a[left], a[right]);
		left++;
		right--;
	}
	
	swap(a[left], a[last]);
	return left;
}


void quickSort(long long a[], int first, int last){
	if(first < last){
		int p = partition(a, first, last);
		quickSort(a, first, p -1);
		quickSort(a, p + 1, last);
	}
}

// Merge Sort
void merge(long long a[], int first, int mid, int last){
	int n1 = mid - first + 1;
	int n2 = last - mid;
	long long *left = new long long [n1];
	long long *right = new long long [n2];
	
	for(int x=0; x<n1; x++) left[x] = a[first+x];
	for(int y=0; y<n2; y++) right[y] = a[mid+1+y];
	
	int i=0, j=0;
	int k = first;
	
	while(i<n1 && j<n2){
		if(left[i] >= right[j]){
			a[k] = right[j];
			j++;
		}
		else{
			a[k] = left[i];
			i++;
		}
		
		k++;
	}
	
	while(i<n1){
		a[k] = left[i];
		k++;
		i++;
	}
	
	while(j<n2){
		a[k] = right[j];
		k++;
		j++;
	}
	delete[] left;
	delete[] right;
}

void mergeSort(long long a[], int first, int last){
	int t;
	if(first<last){
		t = (first + last)/2;
		mergeSort(a, first, t);
		mergeSort(a, t+1, last);
		merge(a, first, t, last);
	}
	else return;
}

// Heap Sort
void heapify(long long a[], int n, int i){
	int max = i;
	int left = i*2 + 1;
	int right = left + 1;
	
	if(left<n && a[left]>a[max]) max = left;
	if(right<n && a[right]>a[max]) max = right;
	if(max != i){
		swap(a[i], a[max]);
		heapify(a, n, max);
	}
} 

void heapSort(long long a[], int n){
	for(int i=n/2-1; i>=0; i--) heapify(a, n, i);
	for(int j=n-1; j>0; j--){
		swap(a[0], a[j]);
		heapify(a, j, 0);
	}
}

void menuSort(int choice, long long arr[], int num){
	clock_t currTime;
	int runTime;
	currTime = clock();
	switch(choice){
		case 1:{
			bubbleSort(arr, num);
			break;
		}
		
		case 2:{
			selectionSort(arr, num);
			break;
		}
		
		case 3:{
			insertionSort(arr, num);
			break;
		}
		
		case 4:{
			quickSort(arr, 0, num-1);
			break;
		}
		
		case 5:{
			mergeSort(arr, 0, num-1);
			break;
		}
		
		case 6:{
			heapSort(arr, num);
			break;
		}
	}
	currTime = clock() - currTime;
	cout<<"Thoi gian chay thuat toan sap xep la: "<< (float)currTime/CLOCKS_PER_SEC <<"s\n";
	cout<< "Da sap xep xong!\n";
}

void menuInput(int choice, long long arr[], int &num){
	switch(choice){
    	case 1:{
    		int n;
    		cout<<"\nHay nhap vao so phan tu cua day so can sap xep!\n";
    		cin>>n;
    		for(int i=0; i<n; i++){
    			cin>> arr[i];
			}
			num = n;
			break;
		}
		
		case 2:{
			ifstream fileInput("C:/Users/DELL/OneDrive - Hanoi University of Science and Technology/Documents/Code/input.txt");
 
			if (fileInput.fail())
				cout << "Khong the mo file input!\n";
			
			else{						
			
				while (!fileInput.eof() && num<MAX)
				{
					fileInput >> arr[num++];
				}
	
				fileInput.close();			
				}
			break;
			}
		
		case 3:{
			int n;
			cout<< "Hay nhap so luong so duoc sinh ngau nhien!\n";
			cin>> n;
			
			srand(int(time(NULL)));
			arr[0] = rand() % 100000;
			
			for(int i=1; i<n; i++){
				arr[i] = 1 + (int)(rand()*(100000-1+1.0)/(1.0+RAND_MAX));
			} 
			
	/*		for(int i=0; i<n; i++){
				arr[i] = rand() % 100;
			} 
			
			for(int i=0; i<n; i++){
				cout<< arr[i]<< " "; 
			} */
			
			num = n;
			break;
		}
	}
	
//	printArray(arr, num);
	cout<< endl;
}

void menuOutput(int outputChoice, long long arr[], int num){
	if(outputChoice == 1){
		printArray(arr, num);
		cout<< "\n";
	}
	
	else if(outputChoice == 2){
	ofstream fileOutput;
	fileOutput.open("C:/Users/DELL/OneDrive - Hanoi University of Science and Technology/Documents/Code/output.txt", ios::trunc);
	
	if (fileOutput.fail())
		cout << "Khong the mo file output!\n";
	else 
		cout<< "Du lieu da duoc xuat vao file\n";
		
	for(int i=0; i<num; i++){
		fileOutput << arr[i]<<' ';
	}
	cout<< ' ';
	
	fileOutput.close();
	}

}


int main(){
	
	Menu:
	long long *arr = new long long [MAX];
	if (arr != nullptr)
		cout << "Memory allocated\n";
	else
		cout << "Bad allocate\n";
	int num = 0;
	
	cout << "***************Dash Board*******************\n";
	cout << "Cach nhap input\n";
    cout << "1. Nhap tu ban phim\n";
    cout << "2. Nhap tu file\n";
    cout << "3. Sinh ngau nhien\n";
    cout << "-------------------\n";
    cout << "Cac thuat toan sap xep\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Quick Sort\n";
    cout << "5. Merge Sort\n";
    cout << "6. Heap Sort\n";
    cout << "--------------------\n";
    cout << "Cach xuat output\n";
    cout << "1. In ra man hinh\n";
    cout << "2. Xuat vao file\n\n";
    cout << "\nDau tien, hay chon cach nhap input!\n";
    
    
    int inputChoice, sortChoice, outputChoice;
    cin>> inputChoice;
    
    while(inputChoice>3 || inputChoice<1){
    	cout<< "Khong hop le! Hay nhap lai!\n";
    	cin>> inputChoice;
	}
	
	menuInput(inputChoice, arr, num);
	
//	ifstream fileInput("C:/Users/DELL/OneDrive - Hanoi University of Science and Technology/Documents/Code/input.txt");
//	ofstream fileOutput("C:/Users/DELL/OneDrive - Hanoi University of Science and Technology/Documents/Code/output.txt", ios::trunc);

// ---------------------
	cout<< "\nHay chon thuat toan sap xep!\n";
	cin>> sortChoice;
	
	while(sortChoice>6 || sortChoice<1){
    	cout<< "Khong hop le! Hay nhap lai!\n";
    	cin>> sortChoice;
	}
	
	menuSort(sortChoice, arr, num);
	
// ----------------------
	cout<< "\nHay chon cach xuat output!\n";
	cin>> outputChoice;
	
	while(outputChoice>2 || outputChoice<1){
    	cout<< "Khong hop le! Hay nhap lai!\n";
    	cin>> outputChoice;
	}
	
	menuOutput(outputChoice, arr, num);
	
	delete[] arr;
	cout<< "Ban co muon tiep tuc chuong trinh sap xep? (y/n)\n\n";
	char loop;
	cin>> loop;
	if(loop == 'y') goto Menu;
	else{
	//	system("PAUSE");
		return 0;
	}
}
