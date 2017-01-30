#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("bedbug");
set_alias("bug");
set_race("monster");
set_short("Bedbug");
set_long("It looks like a comfortable bed, with four\n"+
"little rollers for feet.  Its back is made\n"+
"out of a spring and its head is shaped into\n"+
"a fat pillow.\n");
set_level(9);
set_hp(135);
set_al(-100);
28et_wc(28);
set_ac(7);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(6);
  load_chat("The bedbug squeaks loudly. \n");
set_a_chat_chance(15);
load_a_chat("The bedbug moves closer.\n");

set_chance(15);
set_spell_dam(15);

set_spell_mess1(
"Bedbug kicks its opponent hard.\n");
set_spell_mess2(
"Bedbug kicks you hard.\n");

}

monster_died() {
move_object(clone_object("/players/brittany/xanth/OBJ/feather.c"),
      this_object());
  tell_room(environment(this_object()),
"The bedbug breaks in half and dies,\n"+
"a feather floats near by.\n");
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
