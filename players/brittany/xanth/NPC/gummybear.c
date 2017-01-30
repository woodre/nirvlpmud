#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("bear");
set_alias("bear");
set_race("monster");
set_short("A "+HIR+"Gummy"+NORM+" bear");
set_long("This is a red gummy bear.  It consists of a sticky matter that\n"+
"resembles gum.  It's head is big and it has short limbs.  It\n"+
"stands on its hind legs and looks completely harmless.\n");
set_level(9);
set_hp(135);
set_al(-100);
set_wc(13);
set_ac(7);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(6);
  load_chat("The bear yawns. \n");
set_a_chat_chance(15);
load_a_chat("The bear moves in front of you.\n");

set_chance(15);
set_spell_dam(15);

set_spell_mess1(
"Bear spits gummy balls at its opponent.\n");
set_spell_mess2(
"Bear spits gummy balls at you.\n");

}

monster_died() {
move_object(clone_object("/players/brittany/xanth/OBJ/lollipop.c"),
      this_object());
  tell_room(environment(this_object()),
"The The bear falls dead to the ground,\n"+
"a lollipop rolls from his hands.\n");
return 0; }
