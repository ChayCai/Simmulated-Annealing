# This is a simple demo for running simulated-annealing

## quik start
```
cd .
make
./run.sh
```

## program descripton
Simulated-Annealing is a very classic and commonly used heuristic search algorithm in FPGA P&R. Key Parameters are: cooling-rate, temprature, exploration-policy, accept-probabilty.

Since the evaluation function in this problem is quite simple, we adopt a simple exploration policy that generating a random offset within a specified step-length and updating current value by adding this offset.

Currently, after 1000 iterations, it is sufficient to converge to a good result. However, in order to converge to a better result, we suggest that after running the SA function once, lower the Step Size, and take the optimal value obtained from the it as the initial exploration point of the second run of the SA function. We have implemented in **main.cpp** function. 

Of course, current scheme are already sufficient to solve this problem.

Multi-threading strategy, multiple starting exploration positions, and optimized exploration strategy may further improve the effectiveness of simulated annealing

## file description
./bin/*: ELFs, **main** for running
./src/*: src files, notice that **./src/cpp/annealing.cpp** for annealing function, and **./src/include/param.h** for parameters in annealing function