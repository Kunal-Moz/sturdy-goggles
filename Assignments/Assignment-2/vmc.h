// Variational Monte Carlo for the harmonic oscillator
#ifndef vmc_h
#define vmc_h

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include "Vec3d.h"

class He {
public :

  He(int Nin, double alphain, int MCStepsin); 

  
  void zeroAccumulators();

  // Probability of the trial given the previous x
  double p(Vector3d xTrial(), Vector3d x());

  // local energy
  double eLocal(Vector3d xi());

  // Perform one Metropolis step
  void MetropolisStep(); 

  // runs N Metropolis steps sequentially
  void oneMonteCarloStep(); 

  // Runs 20% of MCSteps to adjust
  // the step size so acceptance ~ 50%
  void adjustStep(); 

  // production steps
  void doProductionSteps( );

  void printout();

  void normPsi();

  std::vector<double> const & get_psiSqd() const { return psiSqd; }

  double get_eAve() const { return eSum / double(N) / MCSteps;}
  double get_eVar() const { double eAve = get_eAve(); return eSqdSum / double(N) / MCSteps - eAve * eAve;}


  double get_rMin() const { return rMin;}
  double get_rMax() const { return rMax;}
  double get_dr() const { return dr; }
  
protected :

  // C++11 random number generator from Mersenne twister. 
  std::random_device rd;
  std::mt19937 gen;
  std::uniform_real_distribution<> dis;
  std::normal_distribution<> gausdev;

  int N;                         // number of walkers
  std::vector<double> x;         // walker positions
  double delta;                  // step size
  double eSum;                   // accumulator to find energy
  double eSqdSum;                // accumulator to find fluctuations in E
  double rMin = 0.0;             // minimum x for histogramming psi^2(x)
  double rMax = +10;             // maximum x for histogramming psi^2(x)
  double dr = 0.1;               // psi^2(x) histogram step size
  std::vector<double> psiSqd;    // psi^2(x) histogram
  int nPsiSqd;                   // size of array
  double alpha;                  // trial function is exp(-alpha*x^2)
  int nAccept;                   // accumulator for number of accepted steps
  int MCSteps;                   // number of MC steps
};
  



#endif 
