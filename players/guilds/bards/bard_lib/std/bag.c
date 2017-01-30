#include "/players/guilds/bards/bard_lib/lib.h"
#define WEIGHT_DIV 8

inherit ITEM;
int	InvWeight, InvItems;
int	MaxWeight, MaxItems;

void create()
{
    ::create();
    InvWeight = InvItems = MaxWeight = MaxItems = 0;
    set_name("bag");
    set_short("A bag");
    set_long("A bag. ");
}

void set_max_weight(int w) { MaxWeight = w;}
void set_max_items(int i) { MaxItems = i;}

void long(string arg)
{
    ::long(arg);
    if (first_inventory(this_object()))
	write("There is something in it.\n");
    else
	write("You can put things in it.\n");
}

int query_weight()
{
    if (!MaxWeight && !MaxItems)
	return ::query_weight() + InvWeight/WEIGHT_DIV;
    return ::query_weight();
}

status add_weight(int w)
{
    if (MaxWeight && InvWeight + w > MaxWeight)
	return 0;
    if (MaxItems && InvItems >= MaxItems)
	return 0;

    if (!((status) environment()->add_weight(-query_weight()))) {
	/* is this possible at all? */
	return 0;
    }

    InvWeight += w;
    InvItems++;

    if (!((status) environment()->add_weight(query_weight()))) {
	/* is this possible at all? */
	InvWeight -= w;
	InvItems--;
	return 0;
    }

    return 1;
}

status can_put_and_get()
{
    return 1; /* can look at contents */
}

status prevent_insert()
{
    if (InvItems) {
	write("You can't when there are things in the bag.\n");
	return 1;
    }
    return 0;
}
