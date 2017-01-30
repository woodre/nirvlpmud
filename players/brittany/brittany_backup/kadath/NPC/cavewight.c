#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("cavewight");
set_alias("drool");
set_alt_name("rockworm");
set_race("monster");
set_short("Cavewight");
set_long("This is a drool rockworm creature.  It has\n"+
"thin limbs, each part of its body is in the\n"+
"shape of logs.  The head is oblong from the\n"+
"front to the back and it has bloody red eyes.\n"+
"Sharp points stick out from its shoulder and\n"+
"elbow blades.  A green radiance sparks inside\n"+
"one of its enormous hands.\n");
set_level(19);
set_hp(475);
set_al(-100);
set_wc(28);
set_ac(16);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(6);
  load_chat("The cavewight eyes you carefully. \n");
set_a_chat_chance(15);
load_a_chat("The cavewight moves in front of the steps to block them.\n");

set_chance(15);
set_spell_dam(35);

set_spell_mess1(
"Cavewight grinds its opponent into the ground, with its enormous fist.\n");
set_spell_mess2(
"Cavewight grinds you into the ground, with its enormous fist.\n");

}

monster_died() {
move_object(clone_object("/players/brittany/kadath/OBJ/stone.c"),
      this_object());
  tell_room(environment(this_object()),
"When the cavewight falls to the ground, a stone\n"+
"rolls from its hand.\n");
return 0; }

init() {
  ::init();
  add_action("dir_block", "down");
}

dir_block() {
tell_room(environment(this_object()),
  "The cavewight stops the downward descent...\n");
  this_object()->attack_object(this_player());
  return 1;
}
