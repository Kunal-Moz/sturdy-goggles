#ifndef Ising_h
#define Ising_h

#include <string>
#include <cmath>
#include <random>
#include <iostream>
#include <fstream>
#include <vector>


class Ising {
public :

  typedef std::vector<std::vector<std::vector<double> > > matrix_dtype;
  typedef std::vector<std::vector<std::vector<int> > > matrix_itype;

  Ising(double iJ, int iL, double iT, double iH);

  void reset_averages();
  
  void compute_boltzmann_factors();

  bool metropolis_step();

  void one_monte_carlo_step_per_spin ( );

  double magnetizationPerSpin ( );

  double energyPerSpin ( );

  void run(int MCSteps);

  void set_H(double iH) { H = iH ;}
  void set_T(double iT) { T = iT ;}
  
  double get_mAvg() const { return mAv;}
  double get_m2Avg() const { return m2Av;}
  double get_eAvg() const { return eAv;}
  double get_e2Avg() const { return e2Av;}
  double get_T() const {return T;}
  double get_H() const {return H;}

  std::vector<double> const & get_mvals() const { return mvals; }
  std::vector<double> const & get_evals() const { return evals; }

protected : 
  // C++11 random number generator from Mersenne twister. 
  std::random_device rd;
  std::mt19937 gen;
  std::uniform_real_distribution<> dis;
  

  double J;                       // ferromagnetic coupling
  int L, Lx, Ly, Lz;                  // number of spins in x, y and z
  int N;                          // number of spins
  matrix_itype s;                 // the spins
  double T;                       // temperature
  double H;                       // magnetic field

  double w[27][3];                // Boltzmann factors

  double acceptanceRatio;
  int steps;                      // steps so far

  double mAv;
  double m2Av;
  double eAv;
  double e2Av;

  std::vector<double> mvals, evals; 
};



#endif
