#include "../include/annealing.h"
#include "../include/param.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

void SA::initParam(int init_tmp, float cooling_rate, int max_iteration){
    m_init_temp = init_tmp;
    m_cur_temp = init_tmp;
    m_cooling_rate = cooling_rate;
    m_max_iteration = max_iteration;
}

void SA::setDst(DST_FUNC dstfunc){
    m_dstfunc = dstfunc;
}

void SA::setStep(int step){
    m_step = step;
}

double SA::getNewVal(double cur_val){
    double offset = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
    return cur_val + (offset - 0.5) * 2 * m_step;
}

void SA::updateTemp(){
    m_cur_temp *= m_cur_temp * m_cooling_rate;
}

bool SA::accept(double cur_score, double new_score){
    if(new_score <= cur_score){
        std::cout << "(Accept)" << new_score << " <= " << cur_score << ", ";
        return true;
    }
    // exp prop

    float prop = exp((cur_score - new_score) / m_cur_temp);
    float randSeed = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
    if(prop > randSeed){
        std::cout << "(Accept)" << new_score << " > " << cur_score << ", but prop is " << prop << " > randSeed " << randSeed << ", ";
        return true;
    }
    std::cout << "(Reject)" << new_score << " > " << cur_score << ", and prop is " << prop << " <= randSeed " << randSeed << ", ";
    return false;

};


int SA::simulatedAnnealing(double init_value){

    int count = 0;
    double curValue = init_value;
    double curScore = (*m_dstfunc)(curValue);
    double bestValue = curValue;
    double bestScore = curScore;
    while(count < m_max_iteration){
        std::cout << "Iteration count[" << count++ << "]: ";
        if(count % 50 == 0){
            updateTemp();
        };
        double newVal = getNewVal(curValue);
        double newScore = m_dstfunc(newVal);

        bool isAccept = accept(curScore, newScore);

        if(newScore < bestScore){
            bestValue = newVal;
            bestScore = newScore;
        }
        if(isAccept){
            curValue = newVal;
            curScore = newScore;
        }

        std::cout << "\n  curVal|Score: " << curValue << "|" << curScore \
            << "bestVal|Score" << bestValue << "|" << bestScore \
            <<  ", cur temp is " << m_cur_temp << ".\n";
        count++;
    };

    g_best_val = bestValue;
    g_best_score = bestScore;

    return 0;
};
