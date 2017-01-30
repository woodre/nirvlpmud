#include "/players/mythos/closed/ansi.h"
inherit "players/mythos/amon/forest/monster1";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("dj");
  set_race("human");
  set_gender("male");
  set_alias("dj");
  set_short("dj");
  set_long("A dj.\n");
  set_hp(1000);
  set_level(22);
  set_al(-random(1500));
  set_wc(40);
  set_ac(17);
  set_heal(3,20);
  set_aggressive(0);
  set_chat_chance(20);
  set_chat_chance(30);
  set_a_chat_chance(15);
  load_chat("The DJ moves to the beat.\n");
  load_chat("The music and the dance make your pulse run.\n");
  load_a_chat("The DJ whips around and smashes you with a great blow!\n");
  load_a_chat("Suddenly, things arent as much fun anymore.\n");
  load_a_chat("The DJ laughs at you.\n");
  set_chance(40);
  set_spell_dam(40);
  set_spell_mess1("The DJ lashes out with great fury!\n");
  set_spell_mess2("The DJ lashes out with great fury!\n");
  set_mult(2);
  set_mult_chance(30);
  set_mult_dam1(10);
  set_mult_dam2(10);
}
