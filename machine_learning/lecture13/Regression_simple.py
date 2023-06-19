import numpy as np

W = np.random.rand(1,1)
b = np.random.rand(1)

def loss_func(x, t):
    y = np.dot(x, W) + b #matrix multiply 
    return (np.sum((t - y)**2)) / (len(x))


def numerical_derivative(f, x): 
    delta_x = 1e-4 #0.0001
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

def error_val(x, t):
    y = np.dot(x, W) + b #matrix multiply 
    return (np.sum((t - y)**2)) / (len(x))

def predict(x):
    y = np.dot(x, W) + b
    return y

x_data = np.array([1, 2, 3, 4, 5]).reshape(5,1) #vector > matrix
t_data = np.array([2, 3, 4, 5, 6]).reshape(5,1)

learning_rate = 1e-2 #발산하는 경우, 1e-3 ~ 1e-6등으로 바꾸어서 실행

f = lambda x : loss_func(x_data, t_data) #f(x) = loss_func(x_data, t_data)

print("Initial error value = ", error_val(x_data, t_data), "Initial W = ", W, "\n", ", b = ", b)

for step in range(8001):
    W -= learning_rate * numerical_derivative(f, W)

    b -= learning_rate * numerical_derivative(f, b)
    
    if(step % 400 == 0):
        print("step = ", step, "error_value = ", error_val(x_data, t_data), "W = ", W, ", b = ", b)

print(predict(43))