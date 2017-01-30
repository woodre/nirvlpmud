#include <ansi.h>
#include "../lib/guild_defs.h"

inherit G_HALL;

void reset(status arg)
{
   if(arg) return;
   set_light(-5);
   set_short(CEN);
   set_long("\
  You stand in a corridor within " + CEN + ".\n\
Two grand pillars rise from the floor. Obviously, this is the main\n\
gallery, because paintings of the dark lords of the castle line\n\
the walls. An eerie glow surrounds this dusty room. Moans of pain\n\
and torture echo throughout the halls. The northeastern pillar\n\
is encircled by a broken spiral staircase which you cannot traverse.\n\
Above however, you do see a balcony rising above the gallery.\n\
To the north is a set of double doors, south lies the courtyard,\n\
and halls on all other sides of you.\n");
  add_item(({
   "pillars","gallery","paintings","lords","dark lords","walls",
   "glow","room","pillar","northeast pillar","spiral staircase",
   "staircase","balcony","doors","double doors" }),"");
  set_exits(({
ROOMDIR + "f4","north",
ROOMDIR + "f2","south",
 }));
}
