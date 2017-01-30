#include "/players/mythos/closed/guild/def.h"
inherit "players/mythos/closed/guild/spells/monster2";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("thorns");
  set_alias("vine");
  set_race("plant");
  set_short(BOLD+"Thorns of Vraith"+NORM);
  set_long("Deep purple thorns cover the white vine you see before you.\n"+
           "It is often said that this plant contains some hidden magical\n"+
           "properties.  Whatever they may be, many a brave man has ventured\n"+
           "into the Forbidden to retrieve this vine.....\n"+
           "Beware, something is sinister about the Thorns of Vraith\n");
  set_hp(700);
  set_level(18);
  set_al(-1000);
  set_wc(25);
  set_ac(15);
  set_disease(5);
  set_heal(4,10);
  set_mult(4);
  set_mult_chance(25);
  set_mult_dam1(1);
  set_mult_dam2(3);
  set_dead_ob(this_object());
  set_a_chat_chance(80);
  load_a_chat("The Thorns slash at you!\n");
  load_a_chat("The vine thrashes out and whips around!\n");
  load_a_chat("The vine grows!\n");
  load_a_chat("The ground erupts and thorns lash out!\n");
}

monster_died() {
object prop;
  prop = clone_object("/players/mythos/closed/guild/forest/misc/prop.c");
  tell_room(environment(this_object()),"The vines shudder in great pain!\n");
  move_object(prop,environment(this_object()));
return 0; }
