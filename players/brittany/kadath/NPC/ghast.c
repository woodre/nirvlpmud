#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("ghast");
set_alias("ghast");
set_alt_name("humanoid");
set_race("monster");
set_short("Ghast humanoid");
set_long("The ghast is about the size of a small horse, with\n"+
"a face somewhat human looking.  There are no signs\n"+
"of a nose or forehead, and its eyes are a yellowish\n"+
"red color.  It has pointed hooves that look deadly.\n");

set_level(19);
set_hp(475);
set_al(0);
set_wc(28);
set_ac(16);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(6);
  load_chat("Ghast glares at you suspiciously. \n");
set_a_chat_chance(15);
load_a_chat("Ghast stumps the ground with its hoof.\n");

set_chance(17);
set_spell_dam(40+random(50));

set_spell_mess1(
"Ghast stomps its opponent into the ground, mauling them with its hooves.\n");
set_spell_mess2(
"Ghast stomps you into the ground, mauling you with its hooves.\n");
}

monster_died() {
move_object(clone_object("/players/brittany/kadath/OBJ/hoof.c"),
      this_object());
  tell_room(environment(this_object()),
"As the ghast falls dead, one of its hooves break off.\n");
return 0; }
