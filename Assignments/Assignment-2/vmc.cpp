// Variational Monte Carlo for the Helium Atom
#include "vmc.h"
#include "Vec3d.h"

He::He(int Nin, double alphain, int MCStepsin) :
  rd(), gen(rd()), dis(0,1.), gausdev(),
  N(Nin), alpha(alphain), MCSteps(MCStepsin)
{
  x.resize(N);
//  y.resize(N);
//  z.resize(N);
//  for (int i = 0; i < N; i++)
//    x[i] = dis(gen)-0.5;
//  for (int i = 0; i < N; i++)
//    y[i] = dis(gen)-0.5;
//  for (int i = 0; i < N; i++)
//    z[i] = dis(gen)-0.5;
  for (int i = 0; i < N*N*N; i++)
    x = (dis(gen)-0.5,dis(gen)-0.5,dis(gen)-0.5)
//    Vector3d v1(1.0,0.0,0.0);
  delta = 1;

  nPsiSqd = int((rMax - rMin) / dr);
  psiSqd.resize(nPsiSqd);
  nAccept = 0;

  zeroAccumulators();
}

void He::zeroAccumulators() {
  eSum = eSqdSum = 0;
  for (int i = 0; i < nPsiSqd; i++)
    psiSqd[i] = 0;
}

double He::p(Vector3d xTrial, Vector3d x) {
  double rTrial, rr;
//   compute the ratio of rho(xTrial) / rho(x)
  rTrial = xTrial.r();
  rr = x.r();
  return exp(- 2 * alpha * (rTrial*rTrial - rr*rr));
//  return exp(-2 * alpha * (xTrial*xTrial - x*x )) ;
}

double He::eLocal(Vector3d xi) {
  double rij, csij;
  double t0, t1, t2, t3, t4, t5 ;
  // compute the local energy
  rij = xi.r();
  csij = xi.cosTheta();
  t0 = -4.0;
  t1 = alpha/(1.0 + alpha*rij);
  t2 = alpha/((1.0 + alpha*rij)*(1.0 + alpha*rij)) ;
  t3 = alpha/((1.0 + alpha*rij)*(1.0 + alpha*rij)*(1.0 + alpha*rij)) ;
  t4 = alpha/((1.0 + alpha*rij)*(1.0 + alpha*rij)*(1.0 + alpha*rij)*(1.0 + alpha*rij)) ;
  t5 = csij*csij/((1.0 + alpha*rij)*(1.0 + alpha*rij)) ;
  return t0 + t1 + t2 + t3 + t4 + t5;
//  alpha + xi * xi * (0.5 - 2 * alpha * alpha);
}

void He::MetropolisStep() {
  double rTrial , delta, rr;
  Vector3d xTrial;
  
  rTrial = xTrial.r()
  // choose a walker at random
  int n = int(dis(gen) * N);
  
  // make a trial move
  rr = sqrt(x[n]*xx[n] + y[n]*y[n] + z[n]*z[n]);
  rTrial = rr + delta * gausdev(gen);

  // Metropolis test
  if (p(xTrial, rr) > dis(gen) ) {
    rr = rTrial;
    ++nAccept;
  }

  // accumulate energy and wave function
  double e = eLocal(rr);
  eSum += e;
  eSqdSum += e * e;
  int i = int((x[n] - xMin) / dx);
  if (i >= 0 && i < nPsiSqd)
    psiSqd[i] += 1;
}

void He::oneMonteCarloStep() {

  // perform N Metropolis steps
  for (int i = 0; i < N; i++) {
    MetropolisStep();
  }
}

void He::adjustStep() {
  // perform 20% of MCSteps as thermalization steps
  // and adjust step size so acceptance ratio ~50%
  int thermSteps = int(0.2 * MCSteps);
  int adjustInterval = int(0.1 * thermSteps) + 1;

  std::cout << " Performing " << thermSteps << " thermalization steps ..."
	    << std::flush;
  for (int i = 0; i < thermSteps; i++) {
    oneMonteCarloStep();
    if ((i+1) % adjustInterval == 0) {
      delta *= nAccept / (0.5 * N * adjustInterval) ;
      nAccept = 0;
    }
  }
  std::cout << "\n Adjusted Gaussian step size = " << delta << std::endl;    
}


// production steps
void He::doProductionSteps( ) {
  zeroAccumulators();
  nAccept = 0;
  std::cout << " Performing " << MCSteps << " production steps ..." << std::flush;
  for (int i = 0; i < MCSteps; i++)
    oneMonteCarloStep();
}

void He::printout() {

  // compute and print energy
  double eAve = get_eAve(); 
  double eVar = get_eVar(); 
  double error = sqrt(eVar) / sqrt(double(N) * MCSteps);
  std::cout << "\n <Energy> = " << eAve << " +/- " << error
	    << "\n Variance = " << eVar << std::endl;

}


void He::normPsi() {
  double psiNorm = 0;
  for (int i = 0; i < nPsiSqd; i++)
    psiNorm += psiSqd[i] * dx;
  for (int i = 0; i < nPsiSqd; i++) {
     psiSqd[i] /= psiNorm;
  }
}
