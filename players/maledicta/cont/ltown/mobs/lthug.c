#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";
object gold;

/* added new id -forbin 2003.08.18 */
id(str) { return (::id(str) || str == "lizardman thug"); }

reset(arg)  {

  ::reset(arg);
  if(arg) return;

set_name("lizardman");
set_alt_name("thug");
set_race("lizardman");
set_short(""+GRN+"Lizardman "+NORM+BOLD+"Thug"+NORM+"");
set_long(
"  This is a vicious looking lizardman. His green skin is\n"+
"scarred and tattooed. He is wearing a thick leather armor\n"+
"and bone ornaments. He has a large spiked club in his right\n"+
"hand, and a dagger in his left. He looks ready to kill you.\n");
set_level(20);
set_hp(500);
set_al(-500);
set_wc(35);
set_ac(11);
set_aggressive(1);
set_chance(25);
set_spell_dam(15 + random(20));
set_spell_mess1(
  "The lizardman thug stabs at his opponent with his dagger!\n");
set_spell_mess2(
  "You feel a sharp pain as the lizardman thug stabs you with his dagger!\n");
gold = clone_object("obj/money");
gold->set_money(2700 + random(300));
move_object(gold,this_object());
move_object(clone_object("/players/maledicta/cont/ltown/objects/dshield.c"), this_object());
}


init(){
::init();
add_action("stop_move", "west", 1);
}


stop_move(){
if(this_player()->query_ghost()) return;
write("The Thug jumps in your way blocking the exit!\n");
return 1;
}
