#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("ankheg");
set_race("creature");
set_short(HIY+"Ankheg"+NORM);
set_long(
  "  Ankheg resembles an enormous many-legged worm.  Its six legs end\n"+
  "in sharp hooks suitable for burrowing and grasping, and its powerful\n"+
  "mandibles are capable of snapping a small tree in half with a single\n"+
  "bite.  A tough yellow chitinous shell covers its entire body except\n"+
  "for its soft pink belly.  It has glistening black eyes, a small\n"+
  "mouth lined with tiny rows of teeth, and two sensitive antennae that\n"+
  "can detect movement from up to 300 feet away.\n");

set_level(18);
set_hp(450);
set_al(0);
set_wc(26);
set_ac(17);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(5);
  load_chat("The powerful mandibles slowly open and close.\n");
  load_chat("The long antennae quiver in your direction.\n");
set_a_chat_chance(11);
  load_a_chat("Ankheg's mandibles just miss your arm....\n");
  load_a_chat("Your angle screams with pain as Ankheg bites you.\n");

set_chance(5);
set_spell_dam(30);
set_spell_mess1(
  "Ankheg spits a stream of vile liquid at its target...\n\n");
set_spell_mess2(
  "Ankheg spits a stream of vile liquid at you...\n\n");

}

monster_died() {
move_object(clone_object("players/eurale/Glade/OBJ/ankheg_shell.c"),
  environment(this_object()));
return 0; }
