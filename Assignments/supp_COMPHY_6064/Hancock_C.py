import sisl

bond = 1.42
# Construct the atom with the appropriate
# orbital range
C = sisl.Atom(6, R = bond * 3**.5 + 0.01)
# Create graphene unit-cell
gr = sisl.geom.graphene(bond, C)

# Create the tight-binding HaHmiltonian
H = sisl.Hamiltonian(gr)
dR = [0.1 * bond, bond + 0.01, bond * 3**.5 + 0.01]

for ia in gr:
    idx_a = gr.close(ia, dR=dR)
    H[ia, idx_a[0]] = 0.
    H[ia, idx_a[1]] = 2.7
    H[ia, idx_a[2]] = 0.2

from graphene_band_structure import *
bandstructure(100, H)
