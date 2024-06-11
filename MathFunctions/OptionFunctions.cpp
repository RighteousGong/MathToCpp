#include "OptionFunctions.h"


namespace OptionFunctions{
    double cdf(double x){
        return 0.5 * ( 1 + std::erf(x / std::sqrt(2.0)));
    }


    double callBS(double K, double S, double T, double R, double sigma){
        double d1 = (std::log(S/K) + (R + 0.5 * std::pow(sigma, 2)) * T) / (sigma * sqrt(T));
        double d2 = (std::log(S/K) + (R - 0.5 * std::pow(sigma, 2)) * T) / (sigma * sqrt(T));

        double value = -1.0;

        value =  S * OptionFunctions::cdf(d1) - K * std::exp(-R * T) * OptionFunctions::cdf(d2);

        return value;
    }


    double putBS(double K, double S, double T, double R, double sigma){
        double d1 = (std::log(S/K) + (R + 0.5 * std::pow(sigma, 2)) * T) / (sigma * sqrt(T));
        double d2 = (std::log(S/K) + (R - 0.5 * std::pow(sigma, 2)) * T) / (sigma * sqrt(T));

        double value = -1.0;
        value =  K * std::exp(-R * T) * OptionFunctions::cdf(-d2) - S * OptionFunctions::cdf(-d1);
        return value;
    }


    double callBSM(double K, double S, double T, double R,double Q, double sigma){
        double d1 = (std::log(S/K) + (R - Q + 0.5 * std::pow(sigma, 2)) * T) / (sigma * sqrt(T));
        double d2 = (std::log(S/K) + (R - Q - 0.5 * std::pow(sigma, 2)) * T) / (sigma * sqrt(T));

        double value = -1.0;

        value =  S * std::exp(-Q * T) * OptionFunctions::cdf(d1) - K * std::exp(-R * T) * OptionFunctions::cdf(d2);

        return value;
    }


    double putBSM(double K, double S, double T, double R,double Q, double sigma){
        double d1 = (std::log(S/K) + (R - Q + 0.5 * std::pow(sigma, 2)) * T) / (sigma * sqrt(T));
        double d2 = (std::log(S/K) + (R - Q - 0.5 * std::pow(sigma, 2)) * T) / (sigma * sqrt(T));

        double value = -1.0;

        value =  K * std::exp(-R * T) * OptionFunctions::cdf(-d2) - S * std::exp(-Q * T) * OptionFunctions::cdf(-d1);

        return value;
    }


    double callImpliedVolatility(double C, double K, double S, double T, double R){
        double high = 2.0;
        double low = 0.0;
        double sigma = -1;
        while ((high - low) > 0.00001){
            double temp = (high + low) / 2;
            if (OptionFunctions::callBS(K, S, T, R, temp) > C){
                high = temp;
            }else if((OptionFunctions::callBS(K, S, T, R, temp) < C)){
                low = temp;
            }
            sigma = temp;
        }
        return sigma;
    }


    double putImpliedVolatility(double C, double K, double S, double T, double R){
        double high = 2.0;
        double low = 0.0;
        double sigma = -1;
        while ((high - low) > 0.00001){
            double temp = (high + low) / 2;
            if (OptionFunctions::putBS(K, S, T, R, temp) > C){
                high = temp;
            }else if((OptionFunctions::putBS(K, S, T, R, temp) < C)){
                low = temp;
            }
            sigma = temp;
        }
        return sigma;
    }


    double getCallOptionBreakEvenPoint(double strikePrice, double premium){
        return (strikePrice + premium);
    }


    double getPutOptionBreakEvenPoint(double strikePrice, double premium){
        return (strikePrice - premium);
    }


    double computRealizedVolatility(const double *arr, std::int32_t len){
        double sum = 0;
        for(int i = 1; i < len; i++){
            double r = (std::log(arr[i]) - std::log(arr[i - 1]));
            sum += std::pow(r, 2);
        }
        return sum * 242;
    }

    double KellyCriterion(double b, double p, double q)
    {
        double f = -1.0;
        f = ((b * p) - q) / b;
        return f;
    }
} // namespace