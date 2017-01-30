/*
 * This is my base object, sort of like the dgd auto object
 * I will place wrappers and 'simul_efuns' here
 */
#pragma strict_types
#pragma save_types
#include "/players/balowski/lib.h"

/* compat mode wrapper */
void
create()
{
}

void
reset(int arg)
{
    if (!arg) create();
}

object
load()
{
    return this_object();
}

#ifndef __VERSION__
/* m_values sefun */
mixed *
m_values(mapping m)
{
    int i;
    mixed *vals;

    if (!mappingp(m)) return ({ });
    i = sizeof(vals = m_indices(m));
    while (i--)
        vals[i] = m[vals[i]];
    return vals;
}

int member(mapping m, string key) {
    return (member_array(key, m_indices(m)) >= 0);
}
#endif

mixed to_alist(mapping m)
{
    /* assumption ok? sequence of m_indices correspond to m_values */
    return order_alist(m_indices(m), m_values(m));
}

mixed *distinct_array(mixed *arr)
{
#ifdef __VERSION__
    if (!pointerp(arr)) return 0;
    return m_indices(mkmapping(arr));
#else
    mapping m; int i;
    if (!pointerp(arr)) return 0;
    if ((i = sizeof(arr)) == 1) return arr;
    m = ([ ]);
    while (i--) m[arr[i]] = 0;
    return m_indices(m);
#endif    
}

/* some very simple grammar functions */
string
definite(string name)
{
    if (!stringp(name)) return 0;
    return "the " + name;
}

string
indefinite(string name)
{
    if (!stringp(name)) return 0;
    switch (lower_case(name)[0]) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
            return "an " + name;
        default:
            return "a " + name;
    }
}

/* everybody needs this.. */
varargs object
find_vis_player(string name, object tp)
{
    object ob;
    int    lvl;

    if (ob = find_player(name)) {
        if (objectp(tp))
            lvl = (int) tp->query_level();
        if ((int) ob->query_invis(lvl) > 0)
            ob = 0;
    }
    return ob;
}

string basename(mixed ob) {
    string fname, no;

    if (objectp(ob)) fname = file_name(ob);
    else if (stringp(ob)) fname = ob;
    else return 0;

    sscanf(fname, "%s#%s", fname, no);
    if (fname[0] != '/') return ("/" + fname);
    return fname;
}

#if 0
varargs void
message(string class, string message, mixed target, mixed exclude)
{
    if (!message || !target) return;
    
    if (objectp(target)) {
	if (living(target)) {
	    if ((target != exclude) &&
		(!pointerp(exclude) || member_array(target, exclude) < 0))
	      tell_object(target, mess);
	    return;
	}
	else
	  target = all_inventory(target);
    }
    
    if (pointerp(target)) {
	int i;
	
	if (objectp(exclude))
	    target -= ({ exclude });
	else if (pointerp(exclude))
	    target -= exclude;

	for (i = sizeof(target) - 1; i >= 0; i--)
	  tell_object(target[i], message);
    }
}
#endif

/*
 * get the directory of a filename (path is assumed to be a filename)
 */
varargs string
directory(string path, int count)
{
    int i;

    if (count >= 0) {
	/* search forwards */
	
	i = (path[0] == '/') ? 1 : 0;

	for (; i >= 0 && count--;) {
	    i = index(path, '/', i);
	}
	return (i > 0) ? path[0 .. i] : path;
    }
    else {
	/* search backwards */

	for (i = strlen(path); i && count;) {
	    if (path[--i] == '/') count++;
	}
	return path[0 .. i];
    }

}
