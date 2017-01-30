#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
add_money(500+random(2000));
set_name("shadowman");
set_race("demon");
set_alias("man");
set_short("A Shadowman");
set_long(
  "An evil creature of the Dark One, and usually in command of a fist of trollocs.\n"+
  "This one has no eyes, but do not let that fool you.  He is dangerous by day or\n"+
  "night, so beware.  There must have been something in this room he wanted.\n");

move_object(clone_object("/players/fakir/inn/WEPS/rapier1.c"),
(this_object()));
init_command("wield rapier");

set_level(19);
set_hp(460);
set_al(-1000);
set_wc(28);
set_ac(16);
set_aggressive(1);
set_dead_ob(this_object());

set_chat_chance(10);
  load_chat("The shadowman glances at the open window.\n");
set_a_chat_chance(15);
  load_a_chat("The shadowman sneers.\n");

set_chance(10);
set_spell_dam(25);

set_spell_mess1(
  "The shadowman slashes you with his sword\n");
set_spell_mess2(
  "The shadowman"+RED+" slashes you "+OFF+"with"+YELLOW+" his sword."+OFF+" You feel a burning in your veins.  \n");


}

monster_died() {
  
  tell_room(environment(this_object()),
	"The shadowman loses his form and dies. \n");
return 0; }
