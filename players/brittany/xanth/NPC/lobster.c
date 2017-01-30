#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("lobster");
set_alias("lobster");
set_race("monster");
set_short("Tree lobster");
set_long("This is a tree lobster.  Their\n"+
"protective coloration of red leaf claws\n"+
"and bark-blue body allows them to hide\n"+
"against tree trunks.  They nip with\n"+
"their claws.\n");
set_level(12);
set_hp(180);
set_al(-100);
set_wc(16);
set_ac(9);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(6);
  load_chat("The lobster eyes you suspiciously. \n");
set_a_chat_chance(15);
load_a_chat("The lobster snaps its claws together.\n");

set_chance(15);
set_spell_dam(20);

set_spell_mess1(
"Lobster nips its opponent, ripping their skin.\n");
set_spell_mess2(
"Lobster nips you, ripping into your skin.\n");

}

monster_died() {
move_object(clone_object("/players/brittany/xanth/OBJ/claw.c"),
      this_object());
  tell_room(environment(this_object()),
"The lobster falls dead.\n");
return 0; }
