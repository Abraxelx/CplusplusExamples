#include <iostream>
#include <iomanip>
#include <fstream>
#include <list> 
#include <iterator>
using namespace std;

int sum(list <int> value);

void printList(list <int> myList) 
{ 
    list <int> :: iterator it; 
    for(it = myList.begin(); it != myList.end(); ++it) 
        cout << ' ' << *it; 
    cout << '\n'; 
} 

int sum(list <int> value){
    int sum = 0;
    list <int> :: iterator it; 
    for(it = value.begin(); it != value.end(); ++it) 
        sum = sum + *it;
    return sum;
}

int product(list <int> value){
    int product = 1;
    list <int> :: iterator it; 
    for(it = value.begin(); it != value.end(); ++it) 
        product = product * *it;
    return product;
}

double average(list <int> value){
    double avarage = 0;
    list <int> :: iterator it; 
    int sumX = sum(value);
    return sumX / value.size();
}

int smallest(list <int> value){
    int smallest = 0;            
    list <int> :: iterator it; 
    for(it = value.begin(); it != value.end(); ++it){
        smallest = *it; 
         if(*it < smallest){
            smallest = *it;
        }
    }
       return smallest;
       
}

int main() {
    int x;
    list <int> values;
    ifstream inFile;
    
    inFile.open("example.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    
    while (inFile >> x) {
        values.push_back(x);
    }
        
    inFile.close();

     cout << "\nList  (Values) is : "; 
    printList(values);
    cout << "Sum is " << sum(values) << endl; 
    cout << "Product is " << product(values) << endl;
    cout << "Avarage is " << average(values) << endl;
    cout << "Smallest is " << smallest(values) << endl;
    return 0;
}



