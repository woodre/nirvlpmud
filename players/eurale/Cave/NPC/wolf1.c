#include "defs.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("wolf");
  set_alt_name("black wolf");
  set_race("creature");
  set_short("Black Wolf");
set_long(
	"  A giant black wolf found only in the caves of Drygulch.  It's \n"+
	"jet-black fur, yellow fangs and fire red eyes give it a hideous \n"+
	"appearance.  The pelt, however, is a precious commodity.  It \n"+
	"seems to be hungering for blood...... yours! \n");
  set_hp(475);
  set_level(18);
  set_al(-50);
  set_wc(28);
  set_ac(16);
  set_heal(2,20);
  set_aggressive(1);
  set_dead_ob(this_object());
  set_a_chat_chance(5);
  load_chat("Glassy eyes gleam out from the darkness....\n");
  load_chat("Something hungers....\n");
  load_a_chat("A black beast growls....\n");
  load_a_chat("The black beast lunges at you!\n"); 

  set_chance(13);
  set_spell_dam(35);
set_spell_mess1(
  "\n\nThe wolf bites deeply into flesh...\n\n");
set_spell_mess2(
  "\n\nThe wolf sinks his teeth into your flesh....\n"+
  "and with a shake of his head... "+
  RED+"TEARS OPEN "+NORM+" your flesh..\n\n");
}

monster_died() {
  move_object(clone_object("players/eurale/Cave/OBJ/pelt"),
      environment(this_object()));
return 0; }

init() {
  ::init();
  add_action("Nope","north");
  add_action("Nope","west");
}

Nope() {
  tell_room(environment(),"The wolf snarls and blocks the path...\n");
  return 1; }
