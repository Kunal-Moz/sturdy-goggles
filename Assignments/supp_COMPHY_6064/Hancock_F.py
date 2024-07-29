import sisl

bond = 1.42
# Construct the atom with the appropriate
# orbital range
C = sisl.Atom(6, R = bond * 2 + 0.01)
# Create graphene unit-cell
gr = sisl.geom.graphene(bond, C)

# Create the tight-binding HaHmiltonian
HS = sisl.Hamiltonian(gr, ortho=False)
dR = [0.1 * bond, bond + 0.01, bond * 3**.5 + 0.01, bond * 2 + 0.01]

for ia in gr:
    idx_a = gr.close(ia, dR=dR)
    HS[ia, idx_a[0]] = 0.   , 1. 
    HS[ia, idx_a[1]] = 2.7  , 0.11 
    HS[ia, idx_a[2]] = 0.09 , 0.045
    HS[ia, idx_a[3]] = 0.27 , 0.065


from graphene_band_structure import *
bandstructure(100, HS)
