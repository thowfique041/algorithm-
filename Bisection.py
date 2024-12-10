def f(x):
    
    return x**3 - 2*x - 5 

def bisection_method(a, b):
    
    if f(a) * f(b) >= 0:
        print("Bisection Method is not possible")
        return None

    print(f"{'Iteration':<10} {'a':<10} {'b':<10} {'c':<10} {'f(c)':<10} {'Error':<10}")
    iteration = 0
    c_old = None

    while True:
        iteration += 1
        c = (a + b) / 2  
        error = (abs(c - c_old)/c)*100 if c_old is not None else None
        c_old = c 

        print(f"{iteration:<10} {a:<10.6f} {b:<10.6f} {c:<10.6f} {f(c):<10.6f} {error if error else 'N/A':<10}")

        if f(c) == 0:
            return c
        elif f(a) * f(c) < 0:
            b = c 
        else:
            a = c  
        if iteration == 5 : return c
        # if error is not None and error < 5 : return c



a = 2  
b = 3  

root = bisection_method(a, b)
if root is not None:
    print(f"\nRoot is : {root:.6f}")
