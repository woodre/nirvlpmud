#include "/players/feldegast/defines.h"
#include "/players/feldegast/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("hammer");
  set_alias("hammer");
  set_short("Silver Hammer");
  set_long(
"This is a fourty pound silver hammer made for both forging and fighting.\n"
  );
  set_hit_func(this_object());
  set_type("polearm");
  set_class(17);
  set_weight(5);
  set_read("You interpret the runes on the hammer:\n"+
           "Fire be upon ye should ye fail your liege.\n");
  set_value(1500);
}

weapon_hit(attacker) {
  if(attacker->id("quadrian lord")) {
    write("\nThe Silver Hammer burns you with "+RED+"UNHOLY FLAMES"+NORM+"!\n\n");
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
