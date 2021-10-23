#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
double func(double xn, double yn, double x) {
    return yn / xn * x;
}
vector<double> whichSide(double xn, double yn, vector<double>& x, vector<double>& y, string coordType, string side) {
    vector<double> xright;
    vector<double> xleft;
    vector<double> yright;
    vector<double> yleft;
    vector<double> xzeros;
    vector<double> yzeros;
    for (int i = 0; i < x.size(); i++) {
        if (func(xn, yn, x[i]) - y[i] > 0) {
            xright.push_back(x[i]);
            yright.push_back(y[i]);
        }
        else if (func(xn, yn, x[i]) - y[i] < 0) {
            xleft.push_back(x[i]);
            yleft.push_back(y[i]);
        }
        else {
            xzeros.push_back(x[i]);
            yzeros.push_back(y[i]);
        }
    }
    if (coordType == "X") {
        if (side == "Right") {
            return xright;
        }
        else if (side == "Left") {
            return xleft;
        }
        else {
            return xzeros;
        }
    }
    else {
        if (side == "Right") {
            return yright;
        }
        else if (side == "Left") {
            return yleft;
        }
        else {
            return yzeros;
        }
    }
}
void printArray(vector<double>& arr) {
    for (const double& i : arr) {
        cout << i << endl;
    }
}
vector<string> readFile() {
    string line;
    vector<string> points;
    ifstream file("file.txt");
    if (file.is_open()) {
        string str;
        while (!file.eof()) {
            file >> str;
            points.push_back(str);
        }
        points.pop_back();
    }
    file.close();
    return points;
}
vector<double> divider(vector<string>& arr, string type) {
    int n = arr.size();
    vector<double> Xcell;
    vector<double> Ycell;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            Xcell.push_back(stoi(arr[i]));
        }
        else {
            Ycell.push_back(stoi(arr[i]));
        }
    }
    return (type == "X") ? Xcell : Ycell;
}
vector<double> calculate(vector<double>& x, vector<double>& y, double xn, double yn) {
    double A = yn / xn;
    int B = -1;
    double distance;
    vector<double> distances;
    for (int i = 0; i < x.size(); i++) {
        distance = fabs(A * x[i] + B * y[i]) / sqrt(A * A + B * B);
        distances.push_back(distance);
    }
    return distances;
}
vector<double> bubbleSort(vector<double>& arr){
    double temp;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size()-1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}
int findIndex(double def, vector<double> &dist) {
    for (int i = 0; i < dist.size(); i++) {
        if (dist[i] == def) {
            return i;
        }
    }
}
int main() {
    vector<string> points = readFile();
    vector<double> vectorX = divider(points, "X");
    vector<double> vectorY = divider(points, "Y");

    double xn = 1, yn = 1;
    vector<double> xRight = whichSide(xn, yn, vectorX, vectorY, "X", "Right");
    vector<double> xLeft = whichSide(xn, yn, vectorX, vectorY, "X", "Left");
    vector<double> yRight = whichSide(xn, yn, vectorX, vectorY, "Y", "Right");
    vector<double> yLeft = whichSide(xn, yn, vectorX, vectorY, "Y", "Left");
    vector<double> xZeros = whichSide(xn, yn, vectorX, vectorY, "X", "Zeros");
    vector<double> yZeros = whichSide(xn, yn, vectorX, vectorY, "Y", "Zeros");

    vector<double> allPoints = calculate(vectorX, vectorY, xn, yn);
    vector<double> distancesR = calculate(xRight, yRight, xn, yn);
    vector<double> distancesL = calculate(xLeft, yLeft, xn, yn);

    vector<double> distR_sorted = bubbleSort(distancesR);
    vector<double> distL_sorted = bubbleSort(distancesL);

    int indexLeftMin = findIndex(distL_sorted[0], allPoints);
    int indexLeftMax = findIndex(distL_sorted[distL_sorted.size()-1], allPoints);

    int indexRightMin = findIndex(distR_sorted[0], allPoints);
    int indexRightMax = findIndex(distR_sorted[distR_sorted.size()-1], allPoints);

    cout << "Left most: " << vectorX[indexLeftMax] << "\t" << vectorY[indexLeftMax] << endl;
    cout << "Right most: " << vectorX[indexRightMax] << "\t" << vectorY[indexRightMax] << endl;

    return 0;
}