#include <iostream>
#include <vector>
using namespace std;

void bitStuff(vector<int> &arr) {
    int length = arr.size();
    int counter = 0;
    for(int i = 0; i < length; i++ ) {
        if(arr[i] == 1){
            counter += 1;
            if(counter == 5) {
                arr.insert(arr.begin() + i + 1, 0);
                counter = 0;
                i++;
            }
        }
        else counter = 0;
    }
}

void bitUnstuff(vector<int> &arr) {
    int counter = 0;
    for(int i = 0 ; i < arr.size(); i++) {
        if(arr[i] == 1){
            counter += 1;
            if(counter == 5) {
                arr.erase(arr.begin() + i + 1);
                counter = 0;
                i++;
            }
        }
        else counter = 0;
    }
}
 
int main(){
    vector<int> arr = {0,0,1,1,1,1,1,1,1,1,0,1,0,1,0,0,0,1,1,1,1,1,0,0,1};
    cout << "Original array is : \n" ;
    cout << "{";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i != arr.size() - 1) cout << ",";
    }
    cout << "}";
    bitStuff(arr);
    cout << "\nBit stuffed array is : \n" ;
    cout << "{";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i != arr.size() - 1) cout << ",";
    }
    cout << "}";
    bitUnstuff(arr);
    cout << "\nBit UN-stuffed array is : \n" ;
    cout << "{";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i != arr.size() - 1) cout << ",";
    }
    cout << "}";
}