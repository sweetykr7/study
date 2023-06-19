
import numpy as np

def func1(input_obj):
    w = input_obj[0, 0]
    x = input_obj[0, 1]
    y = input_obj[1, 0]
    z = input_obj[1, 1]
    return (w * x + x * y * z + 3 * w + z * np.power(y,2))

def numerical_derivative(f, x): 
    delta_x = 1e-4
    grad = np.zeros_like(x)  #수치 미분값을 저장할 곳. 0으로 초기화

    it = np.nditer(x, flags=['multi_index'], op_flags=['readwrite']) #x를 처음부터 끝까지 돌리기 위해서 이터레이터 

    while not it.finished:
        idx = it.multi_index

        tmp_val = x[idx] #임시 변수에 원본 값을 저장하지 않으면, 원본에다가 값을 써서 임시변수 쓴것
        x[idx] = float(tmp_val) + delta_x
        fx1 = f(x)

        x[idx] = tmp_val - delta_x
        fx2 = f(x)
        grad[idx] = (fx1 - fx2) / (2 * delta_x)

        x[idx] = tmp_val
        it.iternext()

    return grad



input = np.array([[1.0, 2.0], [3.0, 4.0]])
res = numerical_derivative(func1, input)

print(res)