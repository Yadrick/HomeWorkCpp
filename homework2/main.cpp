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

    //string path = "in.txt";
    ifstream fin;
    fin.open(argv[1]);

    if (fin.is_open()) {

        fin >> y0 >> vx >> vy;
        double t = (vy + sqrt(vy * vy + 2 * y0 * g)) / g;

        while (fin >> x >> y)
        {
            X.push_back(x);
            Y.push_back(y);
            // for для того, чтобы избавиться от пробелов в конце in.txt
            for (int i = 0; i < X.size(); i++ )
            {
                if ((X[i] == X[i+1]) && (Y[i] == Y[i+1]))
                {
                    X.pop_back();
                    Y.pop_back();
                }
            }
        }

    }
    fin.close();

    int napravl = 1;
    double t = (vy + sqrt(vy*vy+2*y0*g))/g;
    double t_col;
    double A_x = vx, A_y = vy, B_x = x0, B_y = y0;

    for (int i = 0; (i >= 0) && (i <= X.size()-1); i = i + napravl)
    {
    // x = x0+vx*t
        t_col = (X[i] - B_x)/A_x;
        if (t_col <= t)
        {
            if ((B_y + A_y * t_col - g * t_col * t_col / 2 <= Y[i])) //y = y0 + vy*t -gt^2/2
            {
                B_x = 2 * A_x * t_col + B_x;
                A_x = -A_x;
                napravl = (-1) * napravl;
            }
        }
        else
            {
                break ;
            }
        }

double XX = B_x + A_x*t; // поиск конечной координаты

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
Y.clear();
X.shrink_to_fit();
Y.shrink_to_fit();
    cout << site << endl;

}
