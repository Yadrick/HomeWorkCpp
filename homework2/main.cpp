#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;
void printArray(vector<double>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << endl;
	}
}
double recurs(vector < double > X, int n) {
	if (n == 0) {
		return 0;
	}
	else {
		return 2 * X[n - 1] - recurs(X, n - 1);
	}
}
double y(double x, double h, double alpha, double g, double vx, double vy, vector<double>& X, int n) {
	double f = h + pow(-1, n) * (x - recurs(X, n)) * vy / vx - g / (2 * pow(vx, 2)) * pow(x - recurs(X, n), 2);
	return f;
}
vector<double> parabolicSolver(double vx, double vy, double g, double h, double n, vector<double>& X) {
	double a = -g / (2 * pow(vx, 2));
	double b = pow((-1), n);
	double c = h;
	double t1, t2;
	t1 = -b + sqrt(b * b - 4 * a * c) / (2 * a);
	t2 = -b - sqrt(b * b - 4 * a * c) / (2 * a);
	double x1, x2;
	x1 = t1 + recurs(X, n);
	x2 = t2 + recurs(X, n);
	return { x1,x2 };
}
int main(int argc, char* argv)
{
	if (argc == 2) {
		ifstream file(argv);

		vector <double> X;
		vector <double> Y;
		double h;
		file >> h;
		double vx;
		double vy;
		file >> vx >> vy;
		double alpha = atan(vy / vx);
		bool way = true;
		int n_p = 0, n = 0;
		double x, yh;
		while (file >> x >> yh) {
			X.push_back(x);
			Y.push_back(yh);
		}
		vector <double> hY;
		vector <double> Xsaved;
		double y0 = y(X[0], h, alpha, 9.81, vx, vy, X, n);
		if (y0 < Y[0]) {
			cout << 0;
			return 0;
		}
		int isHigh = 0;

		for (int i = 0; i < X.size(); i++) {

			y0 = y(X[i], h, alpha, 9.81, vx, vy, X, n);
			hY.push_back(y0);
			if (y0 > Y[i]) {
				isHigh += 1;
			}
		}
		// 1 1 0 1
		if (isHigh == X.size()) {
			cout << "All is high";
			return 0;
		}
		// first collision
		for (int i = 0; i < X.size(); i++) {
			y0 = y(X[i], h, alpha, 9.81, vx, vy, X, n);
			if (y0 < Y[i]) {
				n_p = i;
				way = false;
				n = 1;

				Xsaved.push_back(X[i]);
				break;
			}
		}

		while (true) {
			if (!way) {
				for (int i = n_p - 1; i >= 0; i--) {
					y0 = y(X[i], h, alpha, 9.81, vx, vy, Xsaved, n);
					if (y0 < Y[i]) {
						n_p = i;
						way = true;
						n++;
						Xsaved.push_back(X[i]);
						break;
					}
				}
				double y1 = y0;
				if (y1 < 0) break;
			}
			if (way) {
				for (int i = n_p + 1; i < X.size(); i++) {
					y0 = y(X[i], h, alpha, 9.81, vx, vy, Xsaved, n);
					if (y0 < Y[i]) {
						n_p = i;
						way = false;
						n++;
						Xsaved.push_back(X[i]);
						break;
					}
				}
				double y1 = y0;
				if (y1 < 0) break;
			}
		}

		if (way) {
			cout << n_p + 1;
		}
		else if (!way) {
			cout << n_p;
		}
	}
	else {
		cout << "Wrong arguments";
	}
	
	return 0;
}
