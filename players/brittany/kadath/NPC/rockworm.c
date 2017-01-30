#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("rockworm");
set_alias("drool");
set_alt_name("rockworm");
set_race("monster");
set_short("Rockworm");
set_long("This is a small rockworm.  It is smaller then\n"+
"a cavewight, but shaped the same. Its body is\n"+
"in the shape of logs.  The head is oblong from\n"+
"the front to the back and it has glowing green\n"+
"eyes.  A sharp point sticks out from its head.\n");
set_level(17);
set_hp(425);
set_al(0);
set_wc(24);
set_ac(14);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(6);
  load_chat("The rockworm eyes you carefully. \n");
set_a_chat_chance(15);
load_a_chat("The rockworm breathes heavily.\n");

set_chance(15);
set_spell_dam(30+random(35));

set_spell_mess1(
"Rockworm slashes its opponent, with the sharp point on its head.\n");
set_spell_mess2(
"Rockworm slashes you, with the sharp point on its head..\n");

}

monster_died() {
move_object(clone_object("/players/brittany/kadath/OBJ/stick.c"),
      this_object());
  tell_room(environment(this_object()),
"When the rockworm falls to the ground, the sharp point\n"+
"breaks off from its head.\n");
return 0; }

init() {
  ::init();
  add_action("dir_block", "down");
}

dir_block() {
tell_room(environment(this_object()),
  "The rockworm blocks you...\n");
  this_object()->attack_object(this_player());
  return 1;
}
