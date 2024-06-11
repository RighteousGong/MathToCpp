#ifndef __MODEL_MATHFUNCTIONS_OPTIONFUNCTIONS_H__
#define __MODEL_MATHFUNCTIONS_OPTIONFUNCTIONS_H__

#include <cmath>
#include <cstdint>

namespace OptionFunctions{
    /**
    * 使用误差函数实现标准正态分布的累计分布函数
    * f(x) = 1/2 * [1 + erf(x)]
    * @brief 标准正态分布的累计分布函数实现
    * @author GongZheng
    */  
    double cdf(double x);


    /**
     * 不分红认购期权的 B-S 模型实现
     * K: t时刻的行权价格
     * S: t时刻的现货价格
     * T: 期权合约的总时间，当前时刻到行权日期的时间为T-t （以年为单位）
     * R: 无风险利率
     * sigma: 现货价格的标准差
     * @brief 不分红股票的 B-S 模型实现
     *        注意，返回值为负数代表失败
     * @author GongZheng
     */
    double callBS(double K, double S, double T, double R, double sigma);


    /**
     * 不分红认沽期权的 B-S 模型实现
     * K: t时刻的行权价格
     * S: t时刻的现货价格
     * T: 期权合约的总时间，当前时刻到行权日期的时间为T-t （以年为单位）
     * R: 无风险利率
     * sigma: 现货价格的标准差
     * @brief 不分红股票的 B-S 模型实现
     *        注意，返回值为负数代表失败
     * @author GongZheng
     */
    double putBS(double K, double S, double T, double R, double sigma);


    /**
     * 分红认购期权的 B-S 模型实现
     * K: t时刻的行权价格
     * S: t时刻的现货价格
     * T: 期权合约的总时间，当前时刻到行权日期的时间为T-t （以年为单位）
     * R: 无风险利率
     * Q: 分红率，假设是连续分红
     * sigma: 现货价格的标准差
     * @brief 分红股票的 B-S 模型实现
     *        注意，返回值为负数代表失败
     * @author GongZheng
     */
    double callBSM(double K, double S, double T, double R,double Q, double sigma);


    /**
     * 分红认沽期权的 B-S 模型实现
     * K: t时刻的行权价格
     * S: t时刻的现货价格
     * T: 期权合约的总时间，当前时刻到行权日期的时间为T-t （以年为单位）
     * R: 无风险利率
     * Q: 分红率，假设是连续分红
     * sigma: 现货价格的标准差
     * @brief 分红股票的 B-S 模型实现
     *        注意，返回值为负数代表失败
     * @author GongZheng
     */
    double putBSM(double K, double S, double T, double R,double Q, double sigma);


    /**
     * 计算认购期权的隐含波动率
     * C: t时刻期权价格
     * K: t时刻的行权价格
     * S: t时刻的现货价格
     * T: 期权合约的总时间，当前时刻到行权日期的时间为T-t （以年为单位）
     * R: 无风险利率
     * @brief 计算认购期权的隐含波动率
     *        注意，返回值为负数代表失败
     * @author GongZheng
     */
    double callImpliedVolatility(double C, double K, double S, double T, double R);


    /**
     * 计算认沽期权隐含波动率
     * C: t时刻期权价格
     * K: t时刻的行权价格
     * S: t时刻的现货价格
     * T: 期权合约的总时间，当前时刻到行权日期的时间为T-t （以年为单位）
     * R: 无风险利率
     * @brief 计算认沽期权隐含波动率
     *        注意，返回值为负数代表失败
     * @author GongZheng
     */
    double putImpliedVolatility(double C, double K, double S, double T, double R);

    
    /**
     * 计算认购期权的盈亏平衡点
     * strikePrice: 行权价格
     * premium: 期权费
     * @brief 计算认购期权的盈亏平衡点
     *        注意，返回值为负数代表失败
     * @author GongZheng
     */
    double getCallOptionBreakEvenPoint(double strikePrice, double premium);


    /**
     * 计算认沽期权的盈亏平衡点
     * strikePrice: 行权价格
     * premium: 期权费
     * @brief 计算认沽期权的盈亏平衡点
     *        注意，返回值为负数代表失败
     * @author GongZheng
     */
    double getPutOptionBreakEvenPoint(double strikePrice, double premium);


    /**
     * 计算历史隐含波动率
     * arr: 历史数据数组
     * len: 历史数据长度
     * @brief 计算历史隐含波动率
     *        注意，返回值为负数代表失败
     * @author GongZheng
     */
    double computRealizedVolatility(const double *arr, std::int32_t len);
} // namespace OptionFunctions

#endif