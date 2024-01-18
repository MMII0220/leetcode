all: run

run: 
	g++ -g ./c++/easy/longestcommonprefix.cpp
	./a.out

clean: 
	rm -rf ./c++/easy/a.out

