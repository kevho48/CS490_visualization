#pragma once
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <random>
#include <algorithm>


class cell_t
		{
			public:
    		std::vector<double> pos;
    		double              fitness;
    		double              health;
		};

class bacteria
{
	public:
		bacteria();
		void bacterialOptimization(int n);
		void eliminatePop(std::vector<cell_t> &population);
		void chemotaxisAndSwim(
 			   					std::vector<cell_t> &population,
    							int n,
    							const double STEP_SIZE,     // Same as book
    							const int    ELDISP_STEPS,    // elimination/dispersal events
    							const int    REPRO_STEPS,     // reproduction steps
    							const int    CHEMO_STEPS,    // chemotaxis/swim events
    							const int    SWIM_LEN,        // how long to swim?
    							const double ELIM_PROB,    // Probability of elimination
    							const double ATTRACT_D,       // attraction coefficient
    							const double ATTRACT_W,     // attraction weight?
    							const double REPEL_H,       // repel coefficient
    							const double REPEL_W      // repel weight 
								);
		double cellInteraction(std::vector<cell_t> population, cell_t cell, double ATTRACT_D, double ATTRACT_W, double REPEL_H, double REPEL_W);
		std::vector<double> getRandDir(int n);
		std::vector<double> genRandSol(int n);
		double evalFitness(std::vector<double> v);
		void printVector(std::vector<double> v);

	private:
	    const int    POP_SIZE = 20;       // population size - book uses 50
	    const double STEP_SIZE = 0.1;     // Same as book
	    const int    ELDISP_STEPS = 5;    // elimination/dispersal events
	    const int    REPRO_STEPS = 4;     // reproduction steps
    	const int    CHEMO_STEPS = 350;    // chemotaxis/swim events - set as 7*ELDISP_STEPS
    	const int    SWIM_LEN = 4;        // how long to swim?
    	const double ELIM_PROB = 0.25;    // Probability of elimination
    	const double ATTRACT_D = 0.1;       // attraction coefficient
    	const double ATTRACT_W = 0.2;     // attraction weight?
    	const double REPEL_H = 0.1;       // repel coefficient
    	const double REPEL_W = 10.0;      // repel weight 

    	const int MIN_X = -8.0;
		const int MAX_X = 8.0;

};
