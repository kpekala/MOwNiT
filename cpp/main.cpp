#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef long double value_type;

void test_random(value_type x, value_type y);

value_type method1(value_type x, value_type y){
    return sqrt(pow(x,2) + pow(y,2));
}
value_type method2(value_type x, value_type y){
    value_type v = max(abs(x),abs(y));
    value_type w = min(abs(x),abs(y));
    return v * sqrt(1 + pow(w/v,2));
}
value_type method3(value_type x, value_type y){
    value_type v = max(abs(x),abs(y));
    value_type w = min(abs(x),abs(y));
    return 2 * v * sqrt(0.25 + pow(w/(2*v),2));
}

void full_test(value_type x, value_type y){
    cout<<"Testing "<<x<<" + "<<y<<"i"<<endl;
    function<value_type(value_type,value_type)> methods[] = {&method1,&method2,&method3};
    for(int i=0; i<3; i++){
        cout<<"Method "<<i<<": "<<methods[i](x,y)<<endl;
    }
}

int main() {
    srand (static_cast <unsigned> (time(0)));
    cout.precision(30);
    //full_test(1,1);
    //full_test(1.0/10.0,1.0/10.0);
    full_test(1.0/3.0,1.0/3.0);
    full_test(M_PI,M_PI);
    test_random(1.0, 3.0);

    return 0;
}

value_type random_value(value_type low, value_type top){
    return low + static_cast <value_type> (rand()) /( static_cast <value_type> (RAND_MAX/(top-low)));
}

void test_random(value_type x, value_type y) {
    for(int i=0; i<100;i++){
        full_test(x,y);
        cout<<"r: "<<random_value(2.0,3.0)<<endl;
        x *= random_value(2.0,3.0);
        y *= random_value(2.0,3.0);
    }
}
