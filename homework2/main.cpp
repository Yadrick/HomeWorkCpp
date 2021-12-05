#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;


int main(int argc, char** argv)
{
    double y0=0, x0 = 0, vx = 0, vy = 0, g = 9.8, x, y;
    double  check, tmp;
    int site = 0, n = 0;

    vector<double> X;
    vector<double> Y;
    X.push_back(0);
//    ifstream fin("in.txt");
//
//    if (fin.is_open()) {
//
//        fin >> y0 >> vx >> vy;
  //      double t = (vy + sqrt(vy * vy + 2 * y0 * g)) / g;


      std::ifstream in_prev(argv[1]);
    if (in_prev.is_open()){
        in_prev >> y0;
        in_prev >> vx;
        in_prev >> vy;
        double t_end = (vy+sqrt(vy*vy+2*g*y0))/g;
        while ((!in_prev.eof()) && (check <= vx*t_end)) {
            while (in_prev >> check >> tmp) {
                n++;
            }
        }
    }
    in_prev.close();


    std::ifstream in(argv[1]);
    if (in.is_open()){
        in >> y0;
        in >> vx;
        in >> vy;
        int i = 0;
        double t_end = (vy+sqrt(vy*vy+2*g*y0))/g;
        while ((!in.eof()) && (X[i - 1] <= vx*t_end) && (i <= n - 1)) {
            in >> x;
            in >> y;
            X.push_back(x);
            Y.push_back(y);
            i++;
        }
    }
    in.close();

X.erase(X.begin());

//        while ((fin >> x >> y))
//        {
//            X.push_back(x);
//            Y.push_back(y);
//
//            // for для того, чтобы избавиться от пробелов в конце in.txt
////            for (int i = 0; i < X.size(); i++ )
////            {
////                if ((X[i] == X[i+1]) && (Y[i] == Y[i+1]))
////                {
////                    X.pop_back();
////                    Y.pop_back();
////                }
////            }
//        }
//    }
//    fin.close();

    int direction = 1;
    double t = (vy + sqrt(vy*vy+2*y0*g))/g;
    double t_col;

    for (int i = 0; (i >= 0) && (i <= n-1) ; i = i + direction)
    {
        // x = x0+vx*t
        t_col = (X[i] - x0)/vx;
        if (t_col <= t)
        {
            if ((y0 + vy * t_col - g * t_col * t_col / 2 <= Y[i])) //y = y0 + vy*t -gt^2/2
            {
                x0 = 2 * vx * t_col + x0;
                vx = -vx;
                direction = (-1) * direction;
            }
        }
        else
        {
            break ;
        }
    }

    double XX = x0 + vx*t; // поиск конечной координаты

// ЭТОТ ТЕСТ ДЛЯ 1-го ТЕСТА    
for (int i=0; (i <= n-2);i++)
{
    if ((XX >= X[i]) && (XX <= X[i+1]))
    {
        site = i+1;
        break;
    }
}
// ЭТО УСЛОВИЕ ДЛ ТЕСТА С ЦИФРОЙ 5
if((XX > X[Y.size-1]))
{
    site = Y.size();
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
return 0;
}
