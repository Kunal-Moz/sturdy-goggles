import numpy as np
import scipy.linalg as la

# Small code to calculate the recursive surface self-energy
def SE(E,H,V,eta=1.e-3,eps=1.e-15):
    """ Calculate the surface Green function recursively """

    # Energy diagonal
    Ediag = np.asarray(np.diag(np.ones((len(H),))*(E+1j*eta)),np.complex)
    # The two forward/backward arrays (orthogonal basis-set)
    alpha = np.asarray(V.copy(),np.complex)
    beta  = np.asarray(V.T.conj().copy(),np.complex)
    # Surface Green function (this will be our result)
    gs = np.zeros(H.shape,np.complex)
    # Bulk inverted Green function (Ediag is complex
    gb = Ediag - H 
    i = 0
    while True:
        i += 1
        # Do not allow overwrite
        tA = la.solve(gb,alpha,overwrite_a=False,overwrite_b=False)
        tB = la.solve(gb,beta,overwrite_a=False,overwrite_b=False)
        tmp = np.dot(alpha,tB)
        # Update surface self-energy
        gs += tmp
        # Update bulk Green function
        gb -= tmp + np.dot(beta,tA)
        # Update forward/backward
        alpha = np.dot(alpha,tA)
        beta = np.dot(beta,tB)
        # Convergence criteria, it could be stricter
        if np.amax(np.abs(alpha)+np.abs(beta)) < eps:
            # Return the pristine Green function
            return gs

# Create the vectorized self-energy calculator
vSE = np.vectorize(SE,otypes=[np.ndarray],excluded=[1,2,3,4])

def Gf(E,H,H_el,V,eta=1.e-3):
    """ Returns the Green function and the self energies of the system
    with two equivalent leads at the left and right """
    lel = len(H_el)
    rel = len(H) - lel
    S1 = SE(E,H_el,V.T.conj(),eta=eta)
    S2 = SE(E,H_el,V,eta=eta)
    invG = np.diag(np.ones((len(H),))*(E+1j*eta)) - H
    invG[:lel,:lel] -= S1
    invG[rel:,rel:] -= S2
    G = la.inv(invG)
    return G,S1,S2

vGf = np.vectorize(Gf,otypes=[np.ndarray]*3,excluded=[1,2,3,4])

def Af(Gf,S1=None,S2=None):
    """ Returns the spectral function for the electrode which is
    passed
    """
    if S2 is None:
        lel = len(S1)
        rel = len(Gf) - lel
        A = np.dot(Gf[:,:lel],S1-S1.T.conj())
        return 1j*np.dot(A,Gf[:,:lel].T.conj())
    if S1 is None: 
        lel = len(S2)
        rel = len(Gf) - lel
        A = np.dot(Gf[:,rel:],S2-S2.T.conj())
        return 1j*np.dot(A,Gf[:,rel:].T.conj())
    raise ValueError("Either electrode self-energy must be provided")

def Trans(E,H,H_el,V,eta=1.e-3):
    """ Single junction transmission function for 2 similar leads """
    lel = len(H_el)
    rel = len(H) - lel
    G,S1,S2 = Gf(E,H,H_el,V,eta=eta)
    tmp = np.dot(G[rel:,:lel],S1-S1.T.conj())
    tmp = np.dot(tmp,G[rel:,:lel].T.conj())
    tmp = np.dot(tmp,S2-S2.T.conj())
    # We do not have i on S1/S2
    return -np.trace(tmp).real 

vTrans = np.vectorize(Trans,otypes='d',excluded=[1,2,3,4])

def matshow(ax,mat,**kwargs): 
    """ Plots the matrix in an axis without interpolation """
    a = ax.imshow(mat,interpolation='none')
    maxis(ax,**kwargs)
    return a

def maxis(axs,**kwargs):
    """ Shorthand for setting several parameters for the axis environment """
    if isinstance(axs,(list,np.ndarray)):
        for ax in axs: 
            maxis(ax,**kwargs)
        return
    tmp = kwargs.get('xlbl',None)
    if tmp: axs.set_xlabel(tmp)
    tmp = kwargs.get('ylbl',None)
    if tmp: axs.set_ylabel(tmp)
    tmp = kwargs.get('title',None)
    if tmp: axs.set_title(tmp)
    tmp = kwargs.get('xrng',None)
    if not tmp is None: axs.set_xlim(tmp)
    tmp = kwargs.get('yrng',None)
    if not tmp is None: axs.set_ylim(tmp)
    

def nf(E,kT=0.025,eta=None): 
    """ The Fermi distribution """
    if eta is None:
        # Ensures that numpy does not do anything with complex numbers!
        return 1./( np.exp( E / kT ) + 1 )
    return 1./( np.exp( (E+1j*eta) / kT) + 1)

def reimplot(ax,x,y,label=None,**kwargs):
    """
    Easy plotting a simple function with both the real and imaginary part
    """
    if label:
        return (ax.plot(x,y.real,label='$\mathrm{Re}('+label+')$',**kwargs), 
                ax.plot(x,y.imag,label='$\mathrm{Im}('+label+')$',**kwargs))
    return (ax.plot(x,y.real,**kwargs), ax.plot(x,y.imag,**kwargs))


if __name__ == "__main__":
    print('This file is intended for use in GreenFunction2.ipynb')
    print('It is not intended to be runned separately.')

        
