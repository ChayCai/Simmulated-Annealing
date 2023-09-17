#include "../src/include/annealing.h"
#include "../src/include/dstfunc.h"
#include "../src/include/param.h"

#include <ctime>
#include <iostream>
#include <random>

int main(){
    SA sa;
    sa.initParam(INIT_TEMP, COOLING_RATE, MAX_ITERATION);

    srand(time(nullptr));
    int init_value;
#ifdef INIT_VAL
    init_value = INIT_VAL;
#else 
    init_value = std::uniform_real_distribution<float>(-50, 50);
#endif
    DST_FUNC dst_func = E;

    // running ones
    sa.initParam(INIT_TEMP, COOLING_RATE, MAX_ITERATION);
    sa.setStep(STEP_LEN);
    sa.setDst(dst_func);
    sa.simulatedAnnealing(init_value);
    double bestVal = sa.g_best_val;
    double bestScore = sa.g_best_score;

    // running twice
    sa.initParam(INIT_TEMP, COOLING_RATE, MAX_ITERATION);
    sa.setStep(STEP_LEN / 10);
    sa.setDst(dst_func);
    sa.simulatedAnnealing(bestVal);
    bestVal = sa.g_best_val;
    bestScore = sa.g_best_score;

    std::cout << " ---- sa complete ----\n";
    std::cout << "  start with value: " << init_value << ", end with value: " << bestVal \
    << ", evaluate result: " << bestScore << std::endl;

    return 0;
};