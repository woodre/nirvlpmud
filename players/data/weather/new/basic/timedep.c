/*
    $Id: timedep.c,v 1.2 11-Jun-1992 11:59:52 tubmud Exp $
    basic/timedep.c - time dependant references

    This module requires you to inherit /basic/namespace in your code.

    Jun 1992 by marion@cs.tu-berlin.de
    Many ideas from Foslay.
*/

#pragma strong_types

#include <libs.h>
#include <timezone.h>
#include <timedep.h> // Coogan, 24-Oct-1997
#include "/basic/namespace.h"
#include "/basic/timedep.h"
#include <server.h> // Coogan, 04-Nov-2001

private string *timedep_space;

/* set_timedep - set time dependant references
   e.g. set_timedep (({5*3600,    20*3600}),
		      ({"daylight","moonshine"}), ({"light"}));
   to have "daylight" from 5:00 to 20:00 and moonshine from 20:00 to 5:00.
   Times must be sorted in ascending order.
*/
varargs string *
set_timedep (int *when, mixed *what, string *space, string which) {
  if (!space)
    space = timedep_space ? timedep_space : ({ LIB_ID->string_id() });

  if (!get_namespace(({ space[0] })))
    add_namespace(space[0]);

  if (sizeof(when) == sizeof(what) && sizeof(when)) {
    timedep_space = space;
    return (set_namespace(space + ({ "when" }), when) &&
            set_namespace(space + ({ "what" }), what) &&
            set_namespace(space + ({ "now" }), 0)) &&
            (which ? set_namespace(space + ({ "which" }), which) : 1)
              ? space : 0;
  }
}

/* query_timedep - get the time dependant reference */
varargs mixed
query_timedep (string *space)
{
    int now, time, *when;
    string *now_space, which;

    if (!space) space = timedep_space;

    // next 2 lines inserted by Ugh Jul-17-1996
    if (!space)
      // replaced stdlib.h's call to unique_string() with the lib-call,
      // Coogan, 20-Mar-1999
      space = timedep_space = ({ LIB_ID->string_id() });

    when = get_namespace (space+({"when"}));
    time = get_namespace (now_space = space+({"now"}));

    if (!when) return 0;

    if (which = get_namespace (space+({"which"}))) /* Foslay Apr-11-1993 */
	now = call_other(SE_TIME, which);
    else
	now = SE_TIME->query_day_time();  // Coogan, was localdaytime();

    /* adjust and wrap around */
    if (when[time] > now) {
	time = 0;
	if (when[time] > now) {
	    time = sizeof (when) - 1;
	}
    }
    while (time+1 < sizeof (when) && now >= when[time+1])
	time++;

    set_namespace (now_space, time);

    if (time < sizeof (when))
	return get_namespace (space+({"what"}))[time];
}

varargs string *
add_timedep (int when, mixed what, string *space)
{
    string *new_what, *old_what;
    int *new_when, *old_when;
    int i;

    if (!space) space = timedep_space;

    old_when = get_namespace (space+({"when"}));
    old_what = get_namespace (space+({"what"}));

    if (!old_when) return set_timedep (({when}),({what}),space);
    else {
	for (i = 0; i < sizeof (old_when) &&
	    old_when[i] < when; i++);
	new_when = old_when[0..i-1] + ({when}) +
	    old_when[i..sizeof (old_when)];
	new_what = old_what[0..i-1] + ({what}) +
	    old_what[i..sizeof (old_what)];
	if (i > 0 && (new_when[i-1] == when || new_what[i-1] == what)) {
	    new_when = new_when[0..i-2]+new_when[i..sizeof (new_when)];
	    new_what = new_what[0..i-2]+new_what[i..sizeof (new_what)];
	    i--;
	}
	if (i+1 < sizeof (new_when) &&
	    (new_when[i+1] == when || new_what[i+1] == what)) {
	    new_when = new_when[0..i]+new_when[i+2..sizeof (new_when)];
	    new_what = new_what[0..i]+new_what[i+2..sizeof (new_what)];
	}
	if ((!i && new_what[sizeof (new_what)-1] == what) ||
	    (i == sizeof (new_when)-1 && new_what[0] == what)) {
	    new_when = new_when[1..sizeof (new_when)];
	    new_what = new_what[1..sizeof (new_what)];
	    i--;
	}
	return set_timedep (new_when, new_what, space);
    }
}

varargs mixed *
query_timedep_table (string *space)
{
    int *when;
    mixed *what;

    if (!space) space = timedep_space;
    when = get_namespace (space+({"when"}));
    what = get_namespace (space+({"what"}));
    return when ? ({ when[0..sizeof(when)], what[0..sizeof(what)] }) : 0;
}

void
set_timedep_space (string *space)
{
    timedep_space = space;
}

void
set_default_depspace (string *depspace)
{
    set_timedep (TD_WHEN[depspace[0]], TD_WHAT[depspace[0]], depspace,
		TD_WHICH[depspace[0]]);
}

mixed
query_timedep_space ()
{
  return timedep_space; 
}
