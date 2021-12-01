#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int main(int argc, char** argv)
{
    double y0=0, x0 = 0, vx = 0, vy = 0, g = 9.8, x, y, check = 0,tmp;
    int site = 0;
    int n = 0;
    vector<double> X;
    vector<double> Y;

   // string path = "in.txt";
//    ifstream fin;
//    fin.open(path);
//    if (fin.is_open()) {
//        fin >> y0;
//        fin >> vx;
//        fin >> vy;
//        double v0 = sqrt(vx * vx + vy * vy);
//        // 0 = y0 + vy*t - (gt^2)/2; (gt^2)/2 - vy*t-y0
//        double t = (vy + sqrt(vy * vy + 2 * y0 * g)) / g;
//
//        while ((!fin.eof()) && (check <=vx*t))
//        {
//            if (fin >> check >> tmp) {
//                n++;
//            }
//        }
//        cout << n << endl;
//    }
//    fin.close();

    ifstream fin;
    fin.open(argv[1]);
    if (fin.is_open()) {
        fin >> y0 >> vx >> vy;


        double t = (vy + sqrt(vy * vy + 2 * y0 * g)) / g;

//        while ((!fin.eof()) && (check <= vx*t)) {
//            if (fin >> check >> tmp) {
//                n++;
//            }
//        }
//        cout << n <<endl;
            while (!fin.eof())
        {
            fin >> x >> y;
            X.push_back(x);
            Y.push_back(y);

            for (int i = 0; i < X.size(); i++ )
            {
                if (X[i] == X[i+1])
                X.pop_back();
            }
            
        }
cout << X.size() << endl;


    }
    fin.close();


    int napravl = 1;
    double t = (vy + sqrt(vy*vy+2*y0*g))/g;
    double t_col = 0;
    for (int i = 0; (i >= 0) && (i <= X.size()-1); i = i + napravl)
    {
    // x = x0+vx*t
        t_col = (X[i] - x0)/vx;
        if (t_col <= t) {
            if ((y0 + vy * t - g * t_col * t_col / 2 <= Y[i])) //y = y0 + vy*t -gt^2/2
            {
                x0 = 2 * vx * t_col + x0;
                vx = -vx;
                napravl = (-1) * napravl;
            }
        }else
            {
                break ;
            }
        }

double XX = x0 + vx*t; // поиск конечной координаты

for (int i=0; i <= X.size()-2;i++)
{
    if ((XX >= X[i]) && (XX <= X[i+1]))
    {
        site = i+1;
        break;
    }
}

if(XX > X[X.size()-1])
{
    site = X.size();
}

if(XX < X[0])
{
    site = 0;
}


X.clear();
X.shrink_to_fit();
    cout << site << endl;
    return 0;
}
