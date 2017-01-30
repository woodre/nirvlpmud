/*  Changed to new doc/build/RULES/monster.guide 8/12/02 - Eurale  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";
#define TO this_object()
#define ETO environment(this_object())

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("bulette");
set_short(HIB+"bulette"+NORM);
set_long(
  "Aptly called a landshark, the bulette (pronounced boo-lay) is a\n"+
  "terrifying predator that lives only to eat.  It is even universally\n"+
  "shunned by other monsters.  It is rumored that the bulette is a\n"+
  "cross between an armadillo and a snapping turtle.  The bulette's\n"+
  "head is blue-brown and it is covered with plates and scales that\n"+
  "are often green.  Nails and teeth on this creature are dull ivory.\n"+
  "The area around the eyes is black with the eyes themselves being\n"+
  "yellowish with green pupils.\n");

set_race("creature");
set_level(17);
set_hp(350 + random(60));
set_al(0);
set_wc(27);
if(!present("bulette shell")) {
  move_object(clone_object("/players/eurale/Lab/OBJ/shell.c"),TO); }
init_command("wear shell");
set_ac(15);
set_aggressive(1);

}
