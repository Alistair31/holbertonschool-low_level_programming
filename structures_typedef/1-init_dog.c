#include <stdio.h>
#include "dog.h"
/**
 * init_dog - initialize the variable struct dog
 * @d: pointer to structure
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
	{
		return;
	}
	(*d).age = age;
	(*d).name = name;
	(*d).owner = owner;
}
