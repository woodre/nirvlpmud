#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
set_name("fade");
set_alias("demon");
add_money(4000+random(1500));
set_race("demon");
set_short("A Fade");
set_long(
  "His lips draw back from yellowed uneven teeth, half snarl and half\n"+  
  "fear-laced smirk.  His pasty-pale face is that of a man, but eyeless\n"+
  "as an egg, like a maggot in a grave.  Thin, bloodless hands grip the\n"+
  "hilt of a wickedly sharp sword, forged in the fires of Skull Mountain.\n");
set_level(20);
set_hp(600);
set_al(-1000);
set_wc(30);
set_ac(17);
set_aggressive(1);
set_dead_ob(this_object());

set_chat_chance(5);
  load_chat("The Fade hisses: "+YELLOW+"Today your flesh shall feed my trolloc horde."+OFF+"\n");
set_a_chat_chance(15);
  load_a_chat("The Fade says: "+YELLOW+"You will now taste death, foolish one."+OFF+"\n");
  load_a_chat("The Fade whispers: "+YELLOW+"I know the Ways.  They belong to the Dark One now!"+OFF+"\n");
  load_a_chat("Tendrills of evil begin to reach out to you from the Fade.\n");
set_chance(20);
set_spell_dam(60);

set_spell_mess1(
  "The Fade slashes out with his dark blade of evil.\n");

set_spell_mess2(
  "The Fade slashes you with a dark blade of pure evil.\n");

}

monster_died() {
  
  tell_room(environment(this_object()),
	"The Fade's demon-spirit hisses and shrivels into shifting smoke and drifts away.\n");
return 0; }
