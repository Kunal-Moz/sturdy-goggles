import sisl

bond = 1.42
# Construct the atom with the appropriate
# orbital range
C = sisl.Atom(6, R = bond * 2 + 0.01)
# Create graphene unit-cell
gr = sisl.geom.graphene(bond, C)

# Create the tight-binding HaHmiltonian
dR = [0.1 * bond, bond + 0.01, bond * 3**.5 + 0.01, bond * 2 + 0.01]
TB = [[0.   , 1.   ],
      [2.7  , 0.11 ],
      [0.09 , 0.045],
      [0.27 , 0.065]]

# create electrode
elec = sisl.Hamiltonian(gr.repeat(2, 1), ortho=False)
# This is a shorthand if the tight-binding parameter sets
# are simple and similar for all species.
# It can also be used to initially construct the Hamiltonian
# and subsequently the Hamiltonian can be changed 
elec.construct(dR, TB)
elec.write('ELEC.nc')

device = sisl.Hamiltonian(elec.geom.tile(4, 0), ortho=False)
device.construct(dR, TB)
device.write('DEVICE.nc')

# Create input for tbtrans
with open('RUN.fdf','w') as fh:
    def w(line):
        fh.write(line + '\n')
    def nl():
        fh.write('\n')
    # Write contents
    w('%block TBT.k')
    w(' diag 1 500 1')
    w('%endblock TBT.k')
    nl()
    w('TBT.HS DEVICE.nc')
    nl()
    
    w('%block TBT.Elec.Left')
    w('  HS ELEC.nc')
    w('  chemical-potential Left')
    w('  semi-inf-direction -a1')
    w('  electrode-position 1')
    w('%endblock TBT.Elec.Left')

    w('%block TBT.Elec.Right')
    w('  HS ELEC.nc')
    w('  chemical-potential Right')
    w('  semi-inf-direction +a1')
    w('  electrode-position end -1')
    w('%endblock TBT.Elec.Right')
