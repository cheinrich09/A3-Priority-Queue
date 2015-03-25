/*--------------------------------------------------------------------------------------------------
Comments about this program
--------------------------------------------------------------------------------------------------*/
#include "Main.h"
#include "MyVector.h"
#include "MyPriorityQueue.h"
#include "Functors.h"
#include <vector>
int main()
{
	MyPriorityQueue<int> testqueue;
	//testing the queue (not working currently)
	testqueue.Push(1);
	testqueue.Push(2);
	testqueue.Push(0);
	testqueue.Push(3);
	std::cout << testqueue.Pop() << std::endl;
	std::cout << testqueue.Pop() << std::endl;
	std::cout << testqueue.Pop() << std::endl;
	std::cout << testqueue.Pop() << std::endl;
	std::cout << "Press enter to finish ";
	getchar();
	return 0;
}
