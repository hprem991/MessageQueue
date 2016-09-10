./a :
	g++ -x c -lpthread MessageQueue.c
	g++ -x -pthread -o sender Sender.cpp MessageQueue.o
	g++ -x -pthread -o receiver Receiver.cpp MessageQueue.o

