/*
~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~
~`~
~`~	The New Monk Guild Object
~`~	- The Monks of the Hidden Path -
~`~
~`~	As envisioned and implemented by Pain
~`~
~`~
~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~
*/

/*
~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~
~`~
~`~	Defines, Inherits, Includes and Whatnot
~`~
*/

#include "/players/pain/color.h"
#include "/players/pain/closed/guild/defs.h"
#include "/players/pain/closed/guild/hits.h"
inherit "/obj/weapon.c"
#define ROBE this_object()
#define MONK this_player()
#define MASTER "/players/pain/closed/guild/m_master.c"

/*
~`~
~`~
~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~
*/

/*
~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~
~`~
~`~	Reset
~`~
*/

reset() {

}
/*
~`~
~`~
~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~
*/
