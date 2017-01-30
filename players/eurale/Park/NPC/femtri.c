/*  Triceratops  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg) {

::reset(arg);
if(arg) return;
set_name("triceratops");
set_alias("female");
set_race("creature");
set_short("Female triceratops");
set_long(
	"  Triceratops was one of the last dinosaurs to appear.  It had \n"+
	"three horns, a smaller one on its nose and two longer ones on \n"+
	"it's head.  The longer horns were almost 3 feet in length. \n"+
	"Triceratops was 30 feet long and had a reputation as a savage \n"+
	"fighter.  This large female is guarding her nest and will fight\n"+
	"to the death to defend her eggs.\n");

set_level(20);
set_hp(550 + random(50));
set_al(-1);
set_wc(31);
set_ac(18);
set_aggressive(1);
set_dead_ob(this_object());

set_chat_chance(5);
  load_chat("The triceratops snorts..... \n");
  load_chat("The female triceratops positions herself in front of\n"+
	"her nest...\n");
  load_chat("You feel fear as the triceratops stares at you.\n");
set_a_chat_chance(8);
  load_a_chat("\nThe triceratops swings her head to gore you...\n\n");
  load_a_chat("The triceratops charges you...\n");
  load_a_chat("The triceratops trumpets loudly!\n");

set_chance(10);
set_spell_dam(45);
set_spell_mess1(
  "\n\nWith a mighty lunge... the beast GORES its prey..\n\n");
set_spell_mess2(
  "\n\nThe beast swings its head and.... "+MAG+"GORES YOU "+NORM+" in the side.\n\n");

}

monster_died() {
int M;
M = random(3);
if(M == 1) {
  tell_room(environment(this_object()),
  "As the mighty beast falls, one of its horns breaks off and\n"+
  "and falls to the ground with a THUD!\n");
  }
if(M == 2) {
  tell_room(environment(this_object()),
  "The mighty beast makes one last charge and CRACK...runs square\n"+
  "into a large boulder breaking off one of it's horns...\n\n"); }
if(M == 0) {
  tell_room(environment(this_object()),
  "\nWith a killer swing, you cleanly sever one of the triceratops\n"+
  "pointed horns just before you kill it....\n\n"); }
  move_object(clone_object("players/eurale/Park/OBJ/horn"),
    environment(this_object()));
return 0; }
