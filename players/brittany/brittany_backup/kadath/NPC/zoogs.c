#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("zoog");
set_alias("zoog");
set_race("monster");
set_short("A Zoog");
set_long("A small and brown creature, with a sharp tail\n"+
"across the length of its back.  Powerful enough to\n"+
"slices apart enemies with its sharp tail.  This small\n"+
"brute has sometimes been known to render himself\n"+
"invulnerable through forces of an evil nature.\n");

set_level(15);
set_hp(225);
set_al(-50);
set_wc(20);
set_ac(12);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(3);
load_chat("Something skitters across the floor.\n");
set_a_chat_chance(10);
load_a_chat("The zoog's glowing eyes gaze at you.\n");

set_chance(12);
set_spell_dam(30);

set_spell_mess1(
"Zoog swings at its opponent wildly with his sharp tail, slicing deeply.\n");
set_spell_mess2(
"Zoog swings at you wildly with his sharp tail, slicing you deeply.\n");
}
monster_died() {
move_object(clone_object("/players/brittany/kadath/OBJ/tail1.c"),
     this_object());
  tell_room(environment(this_object()),
"Zoog falls to the ground and his tail breaks.\n");
return 0; }
