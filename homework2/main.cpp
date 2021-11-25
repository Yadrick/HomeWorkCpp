#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

//дз2- определние промежутка куда упадет МТ, брошенная с высоты с нач ск-ю

//ф-я выведения вектора
void print_arr (vector <double> & arr){
    for (int i=0; i<arr.size(); i++){
        cout<< arr[i]<<endl;
    }
}

//ф-я чтения файла
vector<double> readFile() {
    string line;
    vector<double> points;
    ifstream file("in.txt");
    if (file.is_open()) {
        string str;
        while (!file.eof()) {
            file >> str;
            points.push_back(stod(str));
        }
        points.pop_back();
    }
    file.close();
    return points;
}

vector<double> divider(vector<double>& arr, string type) {
    int n = arr.size();
    vector<double> X_obs;
    vector<double> Y_obs;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            X_obs.push_back(arr[i]);
        }
        else {
            Y_obs.push_back(arr[i]);
        }
    }
    return (type == "X") ? X_obs : Y_obs;
}

//уравнение движения МТ
double dvizh (double h,double alpha, double x,double g, double v0){
    double y;
    y = h + tan(alpha)*x - pow(x,2)*g/(2* pow(v0*cos(alpha),2));
    return y;
}

int main(){
    vector <double> points = readFile();
    double h = (points[0]);
    points.erase(points.begin());
    double vx =points[0];
    double vy =points[1];
    points.erase(points.begin());
    points.erase(points.begin());
    vector <double> X_obs = divider(points, "X");
    vector <double> Y_obs = divider(points, "Y");
    double g = 10;
    double alpha = vy/vx;
    double v0 = vx/ cos(alpha);
    bool pp = false; // ударился ли
    int i = 0;

    for (int i=0; i<X_obs.size(); i++){
        if (dvizh(h,alpha,X_obs[i],g,v0) <= Y_obs[i]){
            cout << i<<endl;
            pp=false;
            break;
        } else{
            pp=true;
        }
    }
    if (pp==true){
        cout<< X_obs.size();
    }

    return 0;
}