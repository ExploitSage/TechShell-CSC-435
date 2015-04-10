#ifndef VARIABLE_TS_H
#define VARIABLE_TS_H

#include <stdlib.h>
#include <string.h>

struct variable
{
	char *name;
	char *value;
	struct variable *link;
};
typedef struct variable Variable;

Variable *allocate_new_variable(Variable *var, char *name, char *value);
Variable *remove_variable(Variable *var, Variable *item);
void update_variable(Variable *item, char *value);
Variable *set_variable(Variable *var, char *name, char *value);
Variable *get_variable(Variable *var, char *name);

#endif