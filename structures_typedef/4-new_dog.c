#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 * Return: pointer to new dog, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *newdog;
	int namlen = 0;
	int ownlen = 0;
	int i;

	if (name == NULL || owner == NULL)
		return (NULL);
	while (name[namlen] != '\0')
		namlen++;
	while (owner[ownlen] != '\0')
		ownlen++;
	newdog = malloc(sizeof(dog_t));
	if (newdog == NULL)
		return (NULL);
	newdog->name = malloc(namlen + 1);
	if (newdog->name == NULL)
	{
		free(newdog);
		return (NULL);
	}
	for (i = 0; i < namlen; i++)
		newdog->name[i] = name[i];
	newdog->name[i] = '\0';
	newdog->owner = malloc(ownlen + 1);
	if (newdog->owner == NULL)
	{
		free(newdog->name);
		free(newdog);
		return (NULL);
	}
	for (i = 0; i < ownlen; i++)
		newdog->owner[i] = owner[i];
	newdog->owner[i] = '\0';
	newdog->age = age;
	return (newdog);
}
