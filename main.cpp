#include <iostream>
#include "OptionFunctions.h"
#include <vector>

constexpr double RISK_FREE_RATE = 0.02;
constexpr double YEARDAY        = 365.0;

void testImpliedVolatility(double spotPrice, double t);
std::vector<double> computePriceList(double K, std::vector<double> price, std::vector<double> T, std::vector<double> sigma);
 
int main()
{

    // double value = OptionFunctions::callBS(2.45, spotPrice, t, RISK_FREE_RATE, 0.1426);
    // printf("C = %f\n", value);
    std::vector<double> high  = {2.4597921, 2.4740772, 2.4630194, 2.4688268, 2.479857, 2.5024514, 2.4996457,  2.4721856, 2.4701295, 2.4943585, 2.5094023, 2.4800026, 2.4678838, 2.4709609, 2.4705248, 2.466611, 2.4523232, 2.4548965, 2.463114, 2.4269485, 2.4356303, 2.4446013, 2.4517708, 2.442927, 2.4713252, 2.4563293, 2.4494257, 2.4493306, 2.4259667, 2.421825,  2.4098196,  2.430823, 2.4683154, 2.4711485, 2.4794047, 2.491815, 2.4659877};
    std::vector<double> low   = {2.4043083, 2.411151,  2.4149108, 2.4209344, 2.4255466, 2.4390516, 2.4502163, 2.4442296, 2.4424696, 2.450437, 2.4561586, 2.4473867, 2.4415643, 2.4403992, 2.443723, 2.4418738, 2.4354932, 2.4310098, 2.4199467, 2.417673, 2.4182549, 2.4178383, 2.4230225, 2.4351265, 2.4532657, 2.4496791, 2.4385898, 2.4268384, 2.4146304, 2.4053345, 2.3961499, 2.3996313, 2.4185126, 2.434164, 2.4453459, 2.4570289, 2.4485118};
    std::vector<double> T     = {55.0,      52.0,      51.0,      50.0,      49.0,      48.0,      45.0,      44.0,      43.0,      42.0,     41.0,      38.0,      37.0,      36.0,      35.0,     34.0,      31.0,      30.0,      29.0,      28.0,     27.0,      24.0,      23.0,      22.0,      17.0,      16.0,      15.0,      14.0,      13.0,      10.0,      9.0,       8.0,       7.0,       4.0,      3.0,       2.0,        1.0};
    std::vector<double> sigma = {0.1449,    0.1450,    0.1450,    0.1451,    0.1448,    0.1446,    0.1445,    0.1441,    0.1437,    0.1438,   0.1438,    0.1435,    0.1435,    0.1435,    0.1431,   0.1431,    0.1432,    0.1431,    0.1430,    0.1431,   0.1432,    0.1427,    0.1431,     0.1426,    0.1425,    0.1425,    0.1425,    0.1425,    0.1425,    0.1411,    0.1411,    0.1425,    0.1427,    0.142,    0.1411,    0.1411,     0.1412};
    
    double K = 2.45;

    std::vector<double> c = computePriceList(K, high, T, sigma);
    for(int i = 0; i < c.size(); ++i){
        std::cout << c[i] << ", ";
    }
    std::cout << std::endl;;
    c = computePriceList(K, low, T, sigma);
    for(int i = 0; i < c.size(); ++i){
        std::cout << c[i] << ", ";
    }
    return 0;
}

std::vector<double> computePriceList(double K, std::vector<double> price, std::vector<double> T, std::vector<double> sigma){
    int len = price.size();
    std::vector<double> c(len);
    for(int i = 0; i < len; ++i){
        double t = T[i] / YEARDAY;
        c[i] = OptionFunctions::putBS(K, price[i], t, RISK_FREE_RATE, sigma[i]);
    }
    return c;
}

void testImpliedVolatility(double spotPrice, double t){
    double value = OptionFunctions::callImpliedVolatility(0.0312, 2.411, spotPrice, t, RISK_FREE_RATE);
    printf("IV = %f\n", value);

    value = OptionFunctions::putImpliedVolatility(0.2643, 2.700, spotPrice, t, RISK_FREE_RATE);
    printf("IV = %f\n", value);
}