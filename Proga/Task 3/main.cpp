#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double func(double x){
    return cos(x)/sqrt(5-x*x*x);
}
void pCells(vector<double> &arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<"\t"<<func(arr[i])<<endl;
    }
}

vector<double> cell(double x0,double xn,int n){
    vector<double> xcells;
    double h = (xn-x0)/(n);
    xcells.reserve(n+1);
    for(int i = 0; i < n+1; i++) {
        xcells.push_back(x0 + i * h);
    }
    return xcells;
}

int main(){
    cout<<"enter x0 & xn: ";
    double x0,xn;
    int n;
    cin>>x0>>xn;
    cout<<"enter n: ";
    cin>>n;
    vector<double> arr = cell(x0, xn, n);
    pCells(arr);
}