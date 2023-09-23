#include <iostream>
#include <random>

using namespace std;

int main(){
    random_device device;
    mt19937 random(device());
    uniform_real_distribution<double> distribution(0.0, 10.0);

    double a = 0;
    double b = 0;
    double pi = 0;


    for (int n = 0; n < 1000; ++n){
        double x = distribution(random);
        double y = distribution(random);

        if (x*x + y*y <= 100)
            a += 1;
        else if (x*x + y*y > 100)
            b += 1;
    }

    pi = (4 * a) / (a + b);
    cout << pi << endl;;
    return 0;
}