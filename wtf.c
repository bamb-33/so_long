#include <stdlib.h>

int main()
{
	void **var;

	var = (void **) malloc (5 * sizeof (void *));
	var[0] = (void *) malloc (5 * sizeof (void *));
}