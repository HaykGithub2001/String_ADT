#include"String.h"
int main()
{
	char a[] = "hayko";
	char b[] = { 'h'};
	char c[] = { 'k','j','a' };
	String ak(c, 3);
	String am;
	String al(b,1);
	al = (am+ak)+al;
	std::cout << al;
	return 0;
}