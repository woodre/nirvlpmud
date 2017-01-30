#include "/players/maledicta/ansi.h"
inherit "players/vertebraker/closed/std/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("smith");
set_alt_name("warrior_smith");
set_alias("lartok");
set_race("human");
set_short(HIW+"Lartok, the "+NORM+BOLD+"Smith"+NORM);
set_long(
"  Lartok is a short crusty old man with burn marks and ash\n"+
"covering him from head to toe. It is said that, despite his\n"+
"garrish look, he is perhaps one of the greatest smiths in\n"+
"all the realm.  You can '"+HIW+"ask about wares"+NORM+"'.\n");
set_level(5);
set_aggressive(0);
}

