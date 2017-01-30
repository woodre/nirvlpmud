#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("moire");
set_alias("woman");
set_alt_name("queen");
set_race("human");
set_short("Queen Moire");
set_long("A woman with green hair streaked with silver, and her\n"+
"eyes are round as moons of jade and her brows rose like\n"+
"the wings of olive gulls.  Her mouth and chin are small\n"+
"her cheeks are high and rounded.  There is a crystal\n"+
"necklace around her neck.  She wore scaled trunks of blue\n"+
"and a silver belt.  She holds a scepter of pink coral in\n"+
"her right hand.\n");

set_gender("female");
set_level(10);
   set_hp(150);
   set_wc(14);
   set_ac(8);
   set_al(0);
   set_aggressive(0);
   set_dead_ob(this_object());
   
set_chat_chance(5);
load_chat("Moire says:  What seek you here, outcasts of Amber.\n");
load_chat("Moire says:  I will not give troops to assault Amber.\n");
load_chat("Moire says:  You will die first.\n");
   
   gold = clone_object("obj/money");
gold->set_money(450);
   move_object(gold,this_object());
}

monster_died() {
move_object(clone_obect("/players/brittany/amber/OBJ/grayswindir.c"),
		this_object());
   tell_room(environment(this_object()),
     "The queen collapses to the ground.\n");
   return 0; }