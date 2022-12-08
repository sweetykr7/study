DIR=/usr/local

TEST=testFile

all:
	c++ -o main main.cpp -std=c++14

test:
	c++ -o testFile testFile.cpp -isystem -I${DIR}/include -L${DIR}/lib -pthread -lgtest -std=c++14
	./testFile

clean:
	rm -rf testFile main