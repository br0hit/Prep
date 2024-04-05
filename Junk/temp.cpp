#include <iostream>
#include <vector>

using namespace std;

long  getTriangleArea(vector<int>x, vector<int>y)
    {
        long long area;
        

        if(x[0] == x[1])
        {
            area = (y[1] - y[0]);
            area = area * (x[2] - x[1]);
            area = area/2;


        }

        else if(x[0] == x[2])
        {
            area = (y[0] - y[2])*(x[1] - x[2])/2;
        }

        else if(x[1] == x[2])
        {
            area = (y[1] - y[2])*(x[0] - x[2])/2;
        }

        else if(y[0] == y[1])
        {
            area = (x[0] - x[1])*(y[2] - y[1])/2;
        }

        else if(y[0] == y[2])
        {
            area = (x[0] - x[2])*(y[1] - y[2])/2;
        }

        else 
        {
            area = (x[1] - x[2])*(y[0] - y[2])/2;
        }

        cout <<area;
        return area;
    }

int main() {
   
    vector<int> x = {0, 0, 99999};
    vector<int> y = {0, 99998, 99999};

   long  area;

    area = getTriangleArea(x,y);

    cout << "Area of the triangle: " << area << endl;

    return 0;
}
