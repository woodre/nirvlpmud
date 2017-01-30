/*  Stegosaurus  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg) {

::reset(arg);
if(arg) return;
set_name("stegosaurus");
set_race("creature");
set_short("Stegosaurus");
set_alias("steg");
set_long(
	"  Stegosaurus was a slow moving animal with large plates on its \n"+
	"back and huge spikes on its tail, which it used when attacked. \n"+
	"It grew to a length of 20 feet. \n");
set_level(20);
set_hp(495 + random(75));
set_al(-1);
set_aggressive(1);
set_dead_ob(this_object());

set_wc(30);
set_ac(17);


set_chat_chance(5);
  load_chat("The big tail swishes slowly.... \n");

set_chance(15);
set_spell_dam(35 + random(12));
set_spell_mess1(
  "\n\nThe spiked tail..."+BOLD+" E M B E D S "+NORM+" itself in its foe.\n\n");
set_spell_mess2(
  "\n\nThe big tail.. "+BOLD+" E M B E D S "+NORM+" itself in your flesh.\n\n");

}

monster_died() {
int num;
num = random(100);
if(num > 50) {
  tell_room(environment(this_object()),
  "As the big stegosaurus falls, one of its large back plates breaks\n"+
  "off and crashes to the ground.\n\n");
  move_object(clone_object("players/eurale/Park/OBJ/steg_plate"),
    environment(this_object()));
  return 0; }
else {
  tell_room(environment(this_object()),
  "With a final vicious swing of its tail which hits the tree nearby,\n"+
  "the big animal falls forever silent...\n\n");
  move_object(clone_object("players/eurale/Park/OBJ/steg_spike"),
    environment(this_object()));
  return 0; }
}
