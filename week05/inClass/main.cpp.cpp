#include "Student.h"
int main()
{
	Person one;
	Person two("Ceco", 22);
	Person three(two);
	Person four = three;
	cout << four << endl;

	Student first_term;
	Student second_term("Panda", 21, "PandaUniversity", 2);
	cout << second_term << endl;
	Student third_term(second_term);
	Student fourth_term = third_term;
	cout << fourth_term << endl;
	fourth_term.move();
}



