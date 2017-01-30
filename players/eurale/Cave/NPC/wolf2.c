#include "defs.h"

#include "/players/eurale/closed/ansi.h"
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
  set_heal(2,5);
  set_aggressive(1);
  set_dead_ob(this_object());
  set_a_chat_chance(10);
  load_chat("Glazed eyes gleam out from the darkness....\n");
  load_chat("Something hungers....\n");
  load_a_chat("A black beast growls....\n");
  load_a_chat("The black beast lunges at you!\n"); 

  set_chance(15);
  set_spell_dam(38);
  set_spell_mess1("The wolf suddenly lunges and its teeth sink into flesh!\n");
set_spell_mess2(
  "\n\nThe black beast's canine teeth "+
  RED+"RIP OPEN "+NORM+"a huge wound...\n\n");
}

monster_died() {
  move_object(clone_object("players/eurale/Cave/OBJ/pelt"),
      environment(this_object()));
return 0; }

init() {
  ::init();
  add_action("Nope","west");
}

Nope() {
  tell_room(environment(),"The wolf snarls and blocks the way...\n");
  return 1; }