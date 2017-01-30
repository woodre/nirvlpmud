/*
    basic/timedesc.c - time dependant descriptions
    Mar 1992 by marion@cs.tu-berlin.de
    Many ideas from Foslay.

    Apr-30-1992 Foslay, multiple timedescs

    THIS MODULE IS TO BE REPLACED BY /basic/timedepdesc
    DIESES MODUL WIRD DURCH /basic/timedepdesc ERSETZT WERDEN
*/

#include <timezone.h>
#include <server.h>  // Coogan, 04-Nov-2001

#define WHEN 0
#define WHAT 1
#define NOW 2

private mixed *timedesc;

/* set_timedesc - set time dependant descriptions
   e.g. set_timedesc (({5*3600,    20*3600}),
		      ({"daylight","moonshine"}));
   to have "daylight" from 5:00 to 20:00 and moonshine from 20:00 to 5:00.
   Times must be sorted in ascending order.
*/
varargs int
set_timedesc (int *when, string *what, int index)
{
    if (!timedesc)
      timedesc = ({});

    if (!index) {
	index = sizeof(timedesc);
	timedesc += ({ ({ ({}), ({}), ({}) }) });
    }
    else
      index--;

    if (sizeof (when) == sizeof (what) && sizeof (when)) {
	timedesc[index][WHEN] = when;
	timedesc[index][WHAT] = what;
	timedesc[index][NOW] = 0;
	return index+1;
    }
}

/* query_timedesc - get the time dependant description string */
varargs string
query_timedesc (int index)
{
    int now, time, *when;

    if (!index) index = 1; /* for backward compat. - will be removed */
    index--;

    now = SE_TIME->query_day_time();  // localdaytime();
    if (!timedesc || sizeof(timedesc) <= index) return 0;

    time = timedesc[index][NOW];
    when = timedesc[index][WHEN];

    if (when[time] > now) {
	time = 0;
	if (when[time] > now) {
	    time = sizeof (when) - 1;
	}
    }
    while (time+1 < sizeof (when) && now >= when[time+1])
	time++;
    timedesc[index][NOW] = time;
    if (time < sizeof (when))
	return timedesc[index][WHAT][time];
}

varargs void
add_timedesc (int when, string what, int index)
{
    string *new_what, *old_what;
    int *new_when, *old_when;
    int i;

    if (!index) index = 1; /* for backward compat. - will be removed */
    index--;

    old_what = timedesc[index][WHAT];
    old_when = timedesc[index][WHEN];

    if (!old_when) set_timedesc (({when}),({what}),index);
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
	set_timedesc (new_when, new_what, index);
    }
}

varargs mixed *
query_timedesc_table (int index)
{
    if (!index) index = 1; /* for backward compat. - will be removed */
    index--;

    return ({
	timedesc[index][WHEN][0..sizeof(timedesc[index][WHEN])],
	timedesc[index][WHAT][0..sizeof(timedesc[index][WHAT])]
	});
}
