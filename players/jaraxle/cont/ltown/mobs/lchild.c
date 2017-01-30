#include "/players/jaraxle/ansi.h"
inherit "obj/monster.c";
object gold;
reset(arg)  {

  ::reset(arg);
  if(arg) return;

set_name("lizardman");
set_alt_name("cont_lizardchild");
set_alias("child");
set_race("lizardman");
set_short(""+GRN+"Lizardman"+NORM+" "+BOLD+"child"+NORM+"");
set_long(
"  This is a small lizardman child. It has light green skin\n"+
"and small yellow eyes. It is dressed in a simple loin cloth.\n");
set_level(1);
set_hp(15);
set_al(0);
set_wc(5);
set_ac(3);
}
