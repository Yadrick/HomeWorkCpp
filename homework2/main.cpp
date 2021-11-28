#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;
void printArray(vector < double > & arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
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
vector<double> divider(vector<double>& arr, bool isX) {
    vector<double> inarr;
    if (isX) {
        for (int i = 0; i < arr.size(); i+=2) {
           inarr.push_back(arr[i]);
        }
    }
    else {
        for (int i = 1; i < arr.size(); i+=2) {
            inarr.push_back(arr[i]);
        }
    }
    return inarr;
}
//уравнение движения МТ
double move(double h, double x, double vx, double vy,double g = 10) {
    double y;
    y = h + vy/vx * x - pow(x, 2) * g / (2 * pow(vx, 2));
    return y;
}
double Hmax(double h, double vy, double g = 10) {
    return h + (vy * vy) / (2 * g);

}
double Lmax(double h, double vx, double vy, double g = 10) {
    //return 2*vx * sqrt(vy * vy + 2 * g * h) / g;
    return 2 * vx * vy / g;
}
double Lmaxh(double h, double vx, double vy, double g = 10) {
    return 2*vx * sqrt(vy * vy + 2 * g * h) / g;
    
}
double newAlpha(double h, double x, double y, double v0,double g = 10) {
    double alpha = asin(((y - h) / 2 + g * x * x / (2 * v0 * v0)) / sqrt(x * x / 4 + (y - h) * (y - h) / 4)) / 4;
    return alpha;
}

vector<double> fisrtCollision(double h, double vx, double vy, vector < double > X_barrier, vector<double> Y_barrier,double alpha, double g = 10 ) {
    bool pp = false;
    bool rightway = true;
    for (int i = 0; i < X_barrier.size(); i++) {
        bool perelet = (move(h, X_barrier[i], vx, vy) <= Y_barrier[i]);
        if (perelet) {
            /* Когда совпадают все идеально, точка возвращается в самое начало */
            if (move(h, X_barrier[i], vx, vy) == Hmax(h, vy) && X_barrier[i] == Lmax(h, vx, vy) / 2) {
                cout << 0 << endl;
            }
            /* нетривиальные случаи */
            pp = false;
            rightway = false;
            double newvx = vx / cos(alpha) * cos(newAlpha(h, X_barrier[i], move(h, X_barrier[i], vx, vy), vx/cos(alpha)));
            double newvy = vy / sin(alpha) * sin(newAlpha(h, X_barrier[i], move(h, X_barrier[i], vx, vy), vx / cos(alpha)));
            return { newvx, newvy, double(i) };
            
        }
        else {
            pp = true;
            
        }
    }
    if (pp) {
        /*  все перелетел */
        if (Lmaxh(h, vx, vy) > X_barrier[X_barrier.size() - 1]) {
            cout << X_barrier.size();
            return { 0 };
        }
        /* перелетел без соударении но не все */
        else {
            for (int i = 0; i < X_barrier.size(); i++) {
                if (Lmaxh(h, vx, vy) <= X_barrier[i]) {
                    cout << i << endl;
                    return { 0 };
                    break;
                }
            }
        }
    }
return {0};
}
int main() {
    
        vector<double> points = readFile();
        double h0 = points[0];
        double vx = points[1];
        double vy = points[2];
        points.erase(points.begin());
        points.erase(points.begin());
        points.erase(points.begin());
        vector<double> X_barrier = divider(points, true);
        vector<double> Y_barrier = divider(points, false);
        double alpha = atan(vy / vx);
        double hmax = Hmax(h0, vy);
        double lmax = Lmax(h0, vx, vy);
        
        /* первое столкновение */

        vector<double> items = fisrtCollision(h0, vx,vy,X_barrier,Y_barrier,alpha);
        double newvx = items[0];
        double newvy = items[1];
        int i_c = items[2];
        bool isRight = false;
        /* n - е столкновение  */

        if (X_barrier[i_c] < lmax / 2) {
            /* полетит наверх */
            for (int j = i_c - 1; j > -1; j--) {
                if (move(move(h0, X_barrier[i_c], vx, vy), X_barrier[j], newvx, newvy) <= Y_barrier[j]) {
                    isRight = true;

                }
                else {

                }
            }

        }
        else {
            /* полетит вниз */
        }
    

    return 0;
}
