all: run

run: 
	g++ -g ./c++/easy/climbingStairs.cpp
	./a.out

clean: 
	rm -rf ./c++/easy/a.out

