#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("echidna");
set_alias("creature");
set_race("echidna");
set_short("an Echidna");
set_long(
"No idea...but trpsprngr wanted it.\n");

set_level(1);
set_hp(50);
set_al(-800);
set_wc(12);
set_ac(8);
}
