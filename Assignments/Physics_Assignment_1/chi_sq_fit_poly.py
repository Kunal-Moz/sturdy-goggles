import numpy as np

#Chi-square fit of a quadratic polynomial using a lay man approach.
def chi_square_fit_poly(x, y, err):
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
    S_2x = np.sum(x**2/err**2)
    S_3x = np.sum(x**3/err**2)
    S_4x = np.sum(x**4/err**2)
    B_y = np.sum(y/err**2)
    B_xy = np.sum(x*y/err**2)
    B_2xy = np.sum(y*x**2/err**2)
    #denominator
    denom = S_2x**3 - 2.0*S_x*S_2x*S_3x + S*S_3x**2 + S_4x*S_x**2 - S*S_2x*S_4x
    if abs(denom) < 0.00001 :
        print ('Error! Denominator is too small!')
        exit()
    a2 = ( B_2xy * S_x**2 - B_2xy * S * S_2x - B_xy * S_x * S_2x + B_y * S_2x**2 + B_xy * S *S_3x - B_y * S_x *S_3x )/denom
    a1 = ( -B_2xy * S_x * S_2x + B_xy *S_2x**2 + B_2xy * S * S_3x - B_y * S_2x * S_3x - B_xy * S * S_4x + B_y* S_x * S_4x )/denom
    a0 = ( B_2xy*S_2x**2 - B_2xy*S_x*S_3x - B_xy*S_2x*S_3x + B_y*S_3x**2 + B_xy*S_x*S_4x - B_y*S_2x*S_4x )/denom
    #computing errors : sigma_a0, sigma_a1
    #var_a0 = S_xx/denom
    #var_a1 = S/denom
    #if var_a0 < 0.0 or var_a1 < 0.0 :
    #    print ('Error! About to pass a negative to sqrt')
    #    exit()
    #sigma_a0 = np.sqrt(var_a0)
    #sigma_a1 = np.sqrt(var_a1)
    chi_square = (np.sum(((y - a0 - a1*x - a2*x**2) / err)**2))
    return(a0, a1, a2 , chi_square)

