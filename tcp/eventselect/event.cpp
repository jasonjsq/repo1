#include"eventserver.h"
using namespace std;


int main()
{

	eventserver event(1);
	event.Socket();
	event.Bind("192.168.101.4", 12306);
	event.Binglisten();
	event.accept();


	return 0;
}