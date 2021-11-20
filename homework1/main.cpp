#include <iostream>
#include <fstream>              // библиотека для чтения файла
#include <cmath>

using namespace std;

int main()
{
    string path = "in.txt";
    ifstream fin; // для считывания данных из файла, а ofstream для создания файла или ввода данных
    fin.open(path);
    if (!fin.is_open())
    {
//        cout<<"File open error!"<<endl;
    }
    else
    {
//        cout << "File is open!" << endl;
        int x_0, y_0;
        fin>>x_0>>y_0;                            // переменные начальные для работы с данными из файла
        int x,y;                                  // переменные дял записи координат
        int xL,yL,xR,yR;                          // переменные для наиболее левых и правых координат
        double cosR=1,cosL=1;                     // начальные косинусы при 0 градусах
        while(fin>>x>>y)
        {
            double cos = (x*x_0 + y*y_0)/(sqrt(x*x+y*y)*sqrt(x_0*x_0+y_0*y_0)); // cos угла между напр. вект. и следующими
            cos =round(cos * 1000.0) / 1000.0;
            if(cos < cosR && ((y_0*x) >= (y*x_0) ))
            {
                cosR = cos;
                xR = x;
                yR = y;
            }
            if(cos <= cosL && ((y_0*x) < (y*x_0) ))
            {
                cosL = cos;
                xL = x;
                yL = y;
            }
        }
        cout << "Leftmost:: "<< xL <<" " << yL <<endl;
        cout << "Rightmost: " << xR << " " << yR << endl;
    }
    fin.close();
    return 0;
}
