import numpy as np

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

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

class LogicGate:
    def __init__(self, gate_name, xdata, tdata): #xdata, tdata => numpy.array(...)
        #self하면 private됨
        self.name = gate_name

        self.__xdata = xdata.reshape(4,2) #input data (0,0), (0,1), (1,0), (1,1)
        self.__tdata = tdata.reshape(4,1)

        self.__W = np.random.rand(2,1) # weight, 2 X 1 matrix
        self.__b = np.random.rand(1)
        self.__learning_rate = 1e-2

    def __loss_func(self):
        delta = 1e-7
        z = np.dot(self.__xdata, self.__W) + self.__b
        y = sigmoid(z)

        #cross-entropy
        return -np.sum(self.__tdata * np.log(y + delta) + (1 - self.__tdata) * np.log((1 - y) + delta)) #delta is needed for infinity

    def error_val(self):
        delta = 1e-7
        z = np.dot(self.__xdata, self.__W) + self.__b
        y = sigmoid(z)

        #cross-entropy
        return -np.sum(self.__tdata * np.log(y + delta) + (1 - self.__tdata) * np.log((1 - y) + delta)) #delta is needed for infinity

    def train(self):
        f = lambda x : self.__loss_func() #f(x) = loss_func(x_data, t_data)

        print("Initial error value = ", self.error_val())

        for step in range(10001):
            self.__W -= self.__learning_rate * numerical_derivative(f, self.__W)

            self.__b -= self.__learning_rate * numerical_derivative(f, self.__b)
            
            if(step % 400 == 0):
                print("step = ", step, "error_value = ", self.error_val())


    def predict(self, input_data):
        z = np.dot(input_data, self.__W) + self.__b
        y = sigmoid(z)

        if y > 0.5:
            result = 1 #True
        else:
            result = 0 #False
        return y, result


# learning_rate = 1e-2 #발산하는 경우, 1e-3 ~ 1e-6등으로 바꾸어서 실행



xdata = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
tdata1 = np.array([0, 0, 0, 1]) # AND
tdata2 = np.array([0, 1, 1, 1]) # OR
tdata3 = np.array([1, 1, 1, 0]) # NAND
tdata4 = np.array([0, 1, 1, 1]) # XOR
AND_obj = LogicGate("AND_GATE", xdata, tdata1)
AND_obj.train()
AND_obj = LogicGate("OR_GATE", xdata, tdata2)
AND_obj.train()
AND_obj = LogicGate("NAND_GATE", xdata, tdata3)
AND_obj.train()
AND_obj = LogicGate("XOR_GATE", xdata, tdata4)
AND_obj.train()
