#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";
object gold;

/* added new id -forbin 2003.08.18 */
id(str) { return (::id(str) || str == "civilian" || str == "lizardman civilian"); }

reset(arg)  {

  ::reset(arg);
  if(arg) return;

set_name("lizardman");
set_alt_name("cont_lizardman");
set_race("lizardman");
set_short(""+GRN+"Lizardman"+NORM+" "+BOLD+"civilian"+NORM+"");
set_long(
"  This is one of the many lizardman civilians that inhabit\n"+
"this village. It is covered in green scales and has yellow\n"+
"eyes. It is hard to tell if it is male or female though.\n");
set_level(5);
set_hp(75);
set_al(800);
set_wc(11);
set_ac(4);
gold = clone_object("obj/money");
gold->set_money(150 + random(100));
move_object(gold,this_object());
}
