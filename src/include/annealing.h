#ifndef annealing_h
#define annealing_h

typedef double (*DST_FUNC)(double input); // dst function as a parameter

class SA{
public:
    SA(){};
    ~SA(){};

    double g_best_val;
    double g_best_score;

    void setDst(DST_FUNC dstfunc);
    void setStep(int step);
    void initParam(int init_tmp, float cooling_rate, int m_max_iteration);
    
    int simulatedAnnealing(double init_value);

    bool accept(double cur_score, double new_score);
    double getNewVal(double cur_val);
    void updateTemp();
private:
    int m_init_temp;
    float m_cooling_rate;
    int m_max_iteration;
    int m_step;
    DST_FUNC m_dstfunc;

    int m_cur_temp;
};


#endif