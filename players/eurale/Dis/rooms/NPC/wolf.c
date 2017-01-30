#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("big bad wolf");
set_alias("wolf");
set_race("creature");
set_short("Big Bad Wolf");
set_long(
	"  This big brute of a wolf hasn't missed many meals.  His thick\n"+
	"glossy fur has been kept well groomed and his teeth are clean \n"+
	"and well sharpened.\n");
  set_hp(500);
  set_level(20);
  set_al(0);
  set_wc(30);
  set_ac(15);
  set_heal(2,10);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_chat_chance(15);
  set_a_chat_chance(10);
load_chat("The wolf eyes you over carefully.. \n");
load_chat("The wolf licks his chops...\n");
  load_a_chat("The wolf growls....\n");
  load_a_chat("The hungry beast lunges at you!\n"); 
  set_chance(12);
  set_spell_dam(50);
set_spell_mess1(
  "\n\nThe wolf HUFFS, and PUFFS and B L O W S hard... \n\n");
set_spell_mess2(
  "\n\nThe wolf HUFFS, and PUFFS and B L O W S in your face!\n\n");
}

monster_died() {
  move_object(clone_object("players/eurale/Dis/rooms/OBJ/fur"),
	environment(this_object()));
return 0; }

init() {
  ::init();
  add_action("Search","search");
}

Search() {
  write("The Big Bad Wolf snarls, 'No way buddy!'\n");
  return 1; }
