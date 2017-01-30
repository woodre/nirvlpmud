
#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";
object gold;

/* added new id -forbin 2003.08.18 */
id(str) { return (::id(str) || str == "guard" || str == "lizardman guard"); }

reset(arg)  {

  ::reset(arg);
  if(arg) return;

set_name("lizardman");
set_alt_name("cont_lizardguard");
set_race("lizardman");
set_short(""+GRN+"Lizardman"+NORM+" "+HIG+"guard"+NORM+"");
set_long(
"  This is a lizardman.  He has green skin and a long\n"+
"snout. His yellow eyes glance about the town watching\n"+
"for any trouble. He wears bone armor and carries a\n"+
"long spear.\n");
set_level(20);
set_hp(500);
set_al(800);
set_wc(30);
set_ac(17);
set_chance(25);
set_spell_dam(15+ random(15));
set_spell_mess1(
  "The lizardman stabs at his opponent with his long spear!\n");
set_spell_mess2(
  "You feel a sharp pain as the lizardman stabs you with his spear!\n");
gold = clone_object("obj/money");
gold->set_money(4000 + random(2000));
move_object(gold,this_object());
set_dead_ob(this_object()); /* added -forbin 2003.08.18 */
}

/* added to explain the spear spell attack and why there is no
 * spear left over -forbin 2003.08.18
 */
monster_died() {
  tell_room(environment(this_object()),
  "\nAs the guard topples over, it falls onto its spear, shattering it!\n");
    return 0; 
}