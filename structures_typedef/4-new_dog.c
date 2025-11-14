#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"
/**
 * new_dog - create a new dog
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 * Return: NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *newdog;
	int i = 0;
	int j = 0;
	char *scpyname;
	char *scpyowner;

	if (name == NULL || owner == NULL)
		return (NULL);

	newdog = malloc(sizeof(dog_t));
	if (newdog == NULL)
		return (NULL);

	scpyname = malloc(strlen(name) + 1);
	if (scpyname == NULL)
	{
		free(newdog);
		return (NULL);
	}

	scpyowner = malloc(strlen(owner) + 1);
	if (scpyowner == NULL)
	{
		free(scpyname);
		free(newdog);
		return (NULL);
	}

	while (name[i] != '\0')
	{
		scpyname[i] = name[i];
		i++;
	}
	scpyname[i] = '\0';

	while (owner[j] != '\0')
	{
		scpyowner[j] = owner[j];
		j++;
	}
	scpyowner[j] = '\0';

	newdog->name = scpyname;
	newdog->age = age;
	newdog->owner = scpyowner;
	return (newdog);
}
