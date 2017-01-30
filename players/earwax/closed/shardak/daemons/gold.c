/*
 * Shardak guild, by Dragnar & Balowski
 * A daemon for remembering what people have donated and borrowed
 * Shardak the dragonman keeps this hoard of gold
 * 
 * donated and borrowed values will always be positive
 * overflow has not been taken into account
 * player purging cannot be done yet
 * 
 * 1996-10-21	[Bal] Created
 */
#pragma strict_types
#include "/players/balowski/lib.h"
#include "../include/def.h"
#include "../include/ansi.h"
#define SAVEFILE file_name(this_object())
inherit BASE;                   /* make a DAEMON? */

mixed	      People;
int	      Total;

void create()
{
    ::create();
    if(!SAVEFILE) return;
    if (restore_object(SAVEFILE)) {
	People = order_alist(People);
    }
    else {
	People = ({ ({ }), ({ }), ({ }), });
    }
}

int query_donated(string who)
{
    return assoc(who, People);
}

int query_borrowed(string who)
{
    return assoc(who, People[0], People[2]);
}

int query_hoard()
{
    return Total;
}

void add_hoard(int amt)
{
    if (intp(amt)) Total += amt;
    save_object(SAVEFILE);
}

/*
 * the donated value will always be positive
 * amt can only be positive? (consider robbery..)
 */
int add_donated(string who, int amt)
{
    int i, value;

    if (!stringp(who) || !intp(amt)) return 0;

    Total += amt;
    i = assoc(who, People[0]);
    if (i >= 0) {
	value = (People[1][i] += amt);
    }
    else {
	People = insert_alist(who, amt, 0, People);
	value = amt;
    }
    save_object(SAVEFILE);
    return value;
}

/*
 * the borrowed value will always be positive
 * amt can be -/+
 */
int add_borrowed(string who, int amt)
{
    int i, value;

    if (!stringp(who) || !intp(amt)) return 0;

    Total -= amt;	/* this ignores any voided remainder */
    i = assoc(who, People[0]);
    if (i >= 0) {
	if (amt < 0 && -amt > People[2][i]) {
	    /* void the rest? */
	    value = (People[2][i] = 0);
	}
	else {
	    value = (People[2][i] += amt);
	}
    }
    else {
	if (amt > 0) {
	    People = insert_alist(who, 0, amt, People);
	}
    }
    save_object(SAVEFILE);
    return value;
}
