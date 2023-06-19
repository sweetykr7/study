
import numpy as np

def my_func1(x):
    return x**2

def my_func2(x):
    return 3*x*(np.exp(x))

def numerical_derivative(f, x):
    delta_x = 1e-4
    return (f(x+delta_x) - f(x-delta_x)) / (2 * delta_x)

# result = numerical_derivative(my_func1, 3)
result = numerical_derivative(my_func2, 2)

print("result ==", result)

