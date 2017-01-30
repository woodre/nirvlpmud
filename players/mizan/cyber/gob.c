/*
 * This is the guild object of the new CN guild.
 * Contents personal copyright Mizan@Nirvana, 2003.
 * Exclusive rights also to Boltar@Nirvana.
 * Reproduction on other muds restricted, under penalty of personal retribution.
 *
 */

#include "config.h"
#include "definitions.h"
#include "router.h"
#include "/obj/ansi.h"

/*
 * gob.c
 *
 * This is the new CN guild object.
 *
 */

int arr_attribs;                /* an array of our attributes */
int arr_counts;                 /* an array of all our counters... */
int arr_toggles;                /* an array of our toggles */
int arr_chances;                /* an array of chance objects */
int arr_ints;                   /* an array of general settings */

string arr_strings;             /* an array of strings for general settings */
object arr_objs;                /* an array of objects we use for pointers */

id(str)
{
    return str == "gob";
}


reset(arg)
{

}

extra_reset()
{

}


init()
{

}


short()
{
    "A gob";
}

long()
{

}


/*********************************************
 *
 * O T H E R  M E T H O D S
 *
 *********************************************/

/* for counters and stuff */
toggle_on(arg) { arr_toggles[(int) arg] = 1; }
toggle_off(arg) { arr_toggles[(int) arg] = 0; }
query_toggle(arg) { return arr_toggles[(int) arg]; }
is(arg) { return arr_toggles[(int) arg]; }

set_obj(arg, value) { arr_objs[(int) arg] = value; }
query_obj(arg) { return arr_objs[(int) arg]; }

set_int(arg, value) { arr_ints[(int) arg] = value; }
query_int(arg) { return arr_ints[(int) arg]; }

set_string(arg, value) { arr_strings[(int) arg] = value; }
query_string(arg) { return arr_strings[(int) arg]; }

set_count(arg, value)
{
    arr_counts[(int) arg] = value; 
    /* keep counts from dipping below zero */
    if(arr_counts[(int) arg] < 0) arr_counts[(int) arg] = 0;
}

query_count(arg) { return arr_counts[(int) arg]; }
add_count(arg, value) { arr_counts[(int) arg] = arr_counts[(int) arg] + value; }
increment_count(arg) { arr_counts[(int) arg] = arr_counts[(int) arg] + 1; }
decrement_count(arg)
{
    arr_counts[(int) arg] = arr_counts[(int) arg] - 1; 
    if(arr_counts[(int) arg] < 0) arr_counts[(int) arg] = 0; 
}

deduct_count(arg, value)
{
    arr_counts[(int) arg] = arr_counts[(int) arg] - value; 
    if(arr_counts[(int) arg] < 0) arr_counts[(int) arg] = 0; 
}

dump_counts()
{
    int i;
    for(i = 0; i < sizeof(arr_counts); i ++)
    {
        write("Member " + i + ": " + arr_counts[i] + "\n");
    }
}


/* eof */
