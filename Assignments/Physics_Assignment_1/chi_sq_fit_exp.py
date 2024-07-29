import numpy as np

def chi_square_fit(x, y, err):
    print('Some random stuff!!!')
    n = len(x)
    if n < 2 :
        print ('Error! Need at least 2 data points!')
        exit()
    S = np.sum(1/err**2)
    if abs(S) < 0.00001 :
        print ('Error! Denominator S is too small!')
        exit()
    #computing parameters : a0 , a1
    S_x = np.sum(x/err**2)
    S_y = np.sum(y/err**2)
    S_xx = np.sum(x**2/err**2)
    S_xy = np.sum(x*y/err**2)
    #denominator
    denom = S*S_xx - S_x**2
    if abs(denom) < 0.00001 :
        print ('Error! Denominator is too small!')
        exit()
    a0 = (S_xx*S_y - S_x*S_xy)/denom
    a1 = (S*S_xy - S_x*S_y)/denom
    #computing errors : sigma_a0, sigma_a1
    var_a0 = S_xx/denom
    var_a1 = S/denom
    if var_a0 < 0.0 or var_a1 < 0.0 :
        print ('Error! About to pass a negative to sqrt')
        exit()
    sigma_a0 = np.sqrt(var_a0)
    sigma_a1 = np.sqrt(var_a1)
    chi_square = (np.sum(((y - a0 - a1*x) / err)**2))
    return(a0, a1, sigma_a0, sigma_a1, chi_square)
