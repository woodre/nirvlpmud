#include "/players/feldegast/defines.h"
#include "/players/feldegast/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("scimitar");
  set_alias("scimitar");
  set_short("Silver Scimitar");
  set_long(
"This is a finely made scimitar with the image of a four-armed\n"+
"man brandishing a pair of swords while holding a shining jewel\n"+
"and a clover.\n"
  );
  set_type("sword");
  set_hit_func(this_object());
  set_class(18);
  set_weight(5);
  set_read("You interpret the runes on the scimitar:\n"+
           "Fire be upon ye should ye fail your liege.\n");
  set_value(1500);
}

weapon_hit(attacker) {
  if(attacker->id("quadrian lord")) {
    write("\nThe silver scimitar burns you with "+RED+"UNHOLY FLAMES"+NORM+"!\n\n");
    TP->hit_player(20);
  }
  return 0;
}
short() {
  string race;
  object who;
  who=environment();
  if(who) {
    race=who->query_race();
    if(race) {
      if(race=="quadrian")
        return short_desc+" (wielded)";
    }
  }
  return ::short();
}
