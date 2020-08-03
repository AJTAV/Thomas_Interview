default:
		g++ -std=c++11 -o LinkedListProblem LinkedListProblem.cpp
		g++ -std=c++11 -o MaxSumProblem MaxSumProblem.cpp

clean:
	rm LinkedListProblem
	rm MaxSumProblem
	g++ -o LinkedListProblem LinkedListProblem.cpp
	g++ -o MaxSumProblem MaxSumProblem.cpp
