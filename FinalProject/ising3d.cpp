
#include "ising3d.h"



Ising::Ising(double iJ, int iL, double iT, double iH) :
  rd(), gen(rd()), dis(0,1.),
  J(iJ), L(iL), Lx(L), Ly(L), Lz(L), N(Lx*Ly*Lz), T(iT), H(iH)
{
//  int s[Lx][Ly][Lz] ;
  s.resize(Lx);
  for (int i = 0; i < Lx; i++){
    s[i].resize(Ly);
    for (int k = 0; k < Ly; k++){
      s[i][k].resize(Lz);
      for (int j = 0; j < Ly; j++){
        s[i][k][j] =  dis(gen) < 0.5 ? +1 : -1;   // hot start, completely random lattice.
      }
    }
  }
//  compute_boltzmann_factors();
  steps = 0;
//
//  reset_averages();
}


void Ising::reset_averages(){
  mAv = 0;
  m2Av = 0;
  eAv = 0;
  e2Av = 0;
  mvals.clear();
  evals.clear();
}
  
void Ising::compute_boltzmann_factors()
{
  for (int i = -12; i <= 12; i += 4) {
    w[i + 12][0] = exp( - (i * J - 2 * H) / T);
    w[i + 12][2] = exp( - (i * J + 2 * H) / T);
    
  }
}

bool Ising::metropolis_step()
{
  // choose a random spin
  int i = int(Lx * dis(gen));
  int j = int(Ly * dis(gen));
  int k = int(Lz * dis(gen));

  // find its neighbors using periodic boundary conditions
  int iPrev = i == 0 ? Lx-1 : i-1;
  int iNext = i == Lx-1 ? 0 : i+1;
  int jPrev = j == 0 ? Ly-1 : j-1;
  int jNext = j == Ly-1 ? 0 : j+1;
  int kPrev = k == 0 ? Lz-1 : k-1;
  int kNext = k == Lz-1 ? 0 : k+1;

  // find sum of neighbors
  int sumNeighbors = s[iPrev][j][k] + s[iNext][j][k] + s[i][jPrev][k] + s[i][jNext][k] + s[i][j][kPrev] + s[i][j][kNext] ;
  int delta_ss = 2*s[i][j][k]*sumNeighbors;

  // ratio of Boltzmann factors
  double ratio = w[delta_ss+12][1+s[i][j][k]];
  if (dis(gen) < ratio) {
    s[i][j][k] = -s[i][j][k];
    return true;
  } else return false;
}

void Ising::one_monte_carlo_step_per_spin ( ) {
  int accepts = 0;
  for (int i = 0; i < N; i++)
    if (metropolis_step())
      ++accepts;
  acceptanceRatio = accepts/double(N);
  ++steps;
}

double Ising::magnetizationPerSpin ( ) {
  int sSum = 0;
  for (int i = 0; i < Lx; i++){
    for (int j = 0; j < Ly; j++) {
      for (int k = 0; k < Lz; k++){
        sSum += s[i][j][k];
      }
    }
  }
  return sSum / double(N);
}

double Ising::energyPerSpin ( ) {
  int sSum = 0, ssSum = 0;
  for (int i = 0; i < Lx; i++){
    for (int j = 0; j < Ly; j++) {
      for (int k =0; k < Lz; k++){
        sSum += s[i][j][k];
        int iNext = i == Lx-1 ? 0 : i+1;
        int jNext = j == Ly-1 ? 0 : j+1;
        int kNext = k == Lz-1 ? 0 : k+1;
        ssSum += s[i][j][k]*(s[iNext][j][k] + s[i][jNext][k] + s[i][j][kNext]);
      }
    }
  }
  return -(J*ssSum + H*sSum)/N;
}

void Ising::run(int MCSteps){
  int thermSteps = int(0.2*MCSteps);
//  std::cout << " Performing " << thermSteps
//	    << " steps to thermalize the system ..." << std::flush;
  for (int s = 0; s < thermSteps; s++)
    one_monte_carlo_step_per_spin();

//  std::cout << " Done\n Performing production steps ..." << std::flush;
  reset_averages();
  for (int s = 0; s < MCSteps; s++) {
    this->one_monte_carlo_step_per_spin();
    double m = this->magnetizationPerSpin();
    double e = this->energyPerSpin();
    mAv += m; m2Av += m * m;
    eAv += e; e2Av += e * e;
    mvals.push_back(m);
    evals.push_back(e);
  }
  mAv /= MCSteps; m2Av /= MCSteps;
  eAv /= MCSteps; e2Av /= MCSteps;
//  std::cout << " <m> = " << mAv << " +/- " << sqrt(m2Av - mAv*mAv) << std::endl;
//  std::cout << " <e> = " << eAv << " +/- " << sqrt(e2Av - eAv*eAv) << std::endl;
    
}

