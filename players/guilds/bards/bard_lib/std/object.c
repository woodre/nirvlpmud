#include "/players/guilds/bards/bard_lib/lib.h"
#include "object.h"
#pragma strict_types
#pragma save_types
inherit BASE;
inherit CLEANUP;
private string  RealName, CapName;
private string	Short, Long;
private string *Ids;
private int     Weight, Value;
private mapping Props;

status
get()
{
    mixed s;
    if (stringp(s = query_property("prevent_get")))
      return (write(s), 0);	/* no get */
    return !s;
}

status
drop(int silently)
{
    mixed s;
    if (stringp(s = query_property("prevent_drop"))) {
	if (!silently) write(s);
	return 1;		/* no drop */
    }
    return s;
}

status
prevent_insert()
{
    mixed s;
    if (stringp(s = query_property("prevent_insert"))) {
	write(s);
	return 1;		/* no insert */
    }
    return s;
}

status
id(string s)
{
    return (s == RealName) || (Ids && member_array(s, Ids) >= 0);
}

string
short()
{
    return Short;
}

string
query_short()
{
    return Short;
}

void
long(string id)
{
    write(Long);
}

varargs string
query_long(string id)
{
    return Long;
}

string
query_name()
{
    return CapName;
}

string
query_real_name()
{
    return RealName;
}

int
query_weight()
{
    return Weight;
}

int
query_value()
{
    return Value;
}

void
set_name(string nom)
{
    if (stringp(nom)) {
	CapName = nom;
	if (!RealName) RealName = lower_case(nom);
    }
}

void
set_real_name(string nom)
{
    if (stringp(nom)) {
	RealName = nom;
    }
}

void
set_ids(mixed i)
{
    if (pointerp(i)) Ids = i;
    else if (stringp(i)) Ids = ({ i });
}

void
set_weight(int x)
{
    if (x >= 0) Weight = x;
}

void
set_value(int x)
{
    if (x >= 0) Value = x;
}

void
set_short(string s)
{
    if (!s || stringp(s)) Short = s;
}

void
set_long(string s)
{
    if (stringp(s)) Long = s;
}

status
save_thing(string path)
{
/*    
    if (path[0] == '/')
      save_object(path[1..]);
    else
*/
      save_object(path);
    return 1;
}

status
restore_thing(string path)
{
/*    
    if (path[0] == '/')
      restore_object(path[1..]);
    else
*/
      restore_object(path);
    return 1;
}

status
generic_object()
{
    return 1;
}

/* 
 * I have skipped CLEANUP and BASE (base has no variables)
 * Generally the format used by Catwoman's lockers is bad--
 * expected output is just a string.
 * My own format is not perfect either--objects and closures can't save
 * mappings would be better than arrays, but they don't save on 3.1.2-DR
 */
mixed
locker_arg(int mix)
{
    if (mix)
      return order_alist(
	({ "Name", "Short", "Long", "Ids", "Weight", "Value", }),
	({ CapName, Short, Long, Ids, Weight, Value, }));
    return "\"" + CapName + "\" \"" + Short + "\" " + Weight + " " + Value;
}

void
locker_init(mixed a)
{
    if (pointerp(a)) {
	if (pointerp(a[0])) {
	    a = order_alist(a);
	    set_name(assoc("Name", a));
	    Short = assoc("Short", a);
	    Long = assoc("Long", a);
	    Ids = assoc("Ids", a);
	    Weight = assoc("Weight", a);
	    Value = assoc("Value", a);
	}
    }
    else if (stringp(a)) {
	string a0, a1;
	int a2, a3;
	
	if (sscanf(a, "\"%s\" \"%s\" %d %d", a0, a1, a2, a3) == 4) {
	    set_name(a0); Short = a1;
	    Weight = a2; Value = a3;
	}
    }
}

/*
 * Special properties of the object
 */
mixed
query_property(string p)
{
    return (Props && Props[p]);
}

void
add_property(string p, mixed v)
{
    if (Props) Props[p] += v; else Props = ([ p : v ]);
}

void
set_property(string p, mixed v)
{
    if (Props) Props[p] = v; else Props = ([ p : v ]);
}

void
set_properties(mapping m)
{
    if (Props) Props += m;
    else Props = m; /* danger! mapping not copied */
}
