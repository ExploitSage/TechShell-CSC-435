#include "Variable.h"

Variable *allocate_new_variable(Variable *var, char *name, char *value)
{
	Variable *last = NULL;
	Variable *link;
	for(link = var; link != NULL; link = link->link) //Find Last Allocated Variable
		last = link;

	if(last == NULL) //Allocating First Variable
		last = var = (Variable*)malloc(sizeof(Variable));
	else //Allocating Any Other Variable
		last = last->link = (Variable*)malloc(sizeof(Variable));
	
	if(last != NULL) //Set new Variable
	{
		last->name = malloc(strlen(name)+1);
		if(last->name != NULL)
			strcpy(last->name, name);
		last->value = malloc(strlen(value)+1);
		if(last->value != NULL)
			strcpy(last->value, value);

		last->link = NULL;
	}
	return var;
}

Variable *remove_variable(Variable *var, Variable *item)
{
	Variable *before = NULL;
	Variable *link = NULL;
	Variable *after = item->link;

	for(link = var; link != NULL && link->link != item; link = link->link) {} //find last var before item
		before = link;
	
	free(item->name);
	free(item->value);
	free(item);

	if(before == NULL) //remove first item
		var = after;
	else //remove any other item
		before->link = after;
	return var;
}

void update_variable(Variable *item, char *value)
{
	item->value = realloc(item->value, strlen(value)+1);
	strcpy(item->value, value);
}

Variable *get_variable(Variable *var, char *name)
{
	Variable *link = NULL;
	for(link = var; link != NULL && strcmp(link->name, name) != 0; link = link->link);
	return link;
}

Variable * set_variable(Variable *var, char *name, char *value)
{
	Variable *link = get_variable(var, name);

	if(link != NULL) //Variable Exists
	{
		if((*value) == '\0') //Remove it
			var = remove_variable(var, link);
		else //Update it
			update_variable(link, value);
	}
	else if((*value) != '\0') //Variable Doesn't Exist && Create it
		var = allocate_new_variable(var, name, value);

	return var;
}
