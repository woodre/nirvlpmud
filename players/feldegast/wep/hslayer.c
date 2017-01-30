#include "/players/feldegast/defines.h"
#include "/players/feldegast/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("slayer");
  set_alias("human slayer");
  set_short("Humanslayer");
  set_long(
"This two-handed broadsword isn't fancy, but it is remarkeably\n"+
"solid and heavy.  The only adornment besides the leather grip,\n"+
"is an odd symbol with four hands worked into the crosspiece.\n"
  );
  set_type("sword");
  set_class(18);
  set_weight(7);
  set_read("You think the runes on the blade mean:\n"+
           "Like the mountain above us, we shall\n"+
           "stand the test of time.\n");
  set_value(1500);
  set_hit_func(this_object());
}
weapon_hit(attacker) {
  if(environment()->query_attrib("str")>random(60)) {
    tell_room(environment(environment()),
TPN+" swings "+TP->query_possessive()+" mighty two handed broadsword\n"+
"striking "+attacker->query_name()+" with an overhand blow.\n"
    );
    return 5;
  }
  if(attacker->query_race()=="human" && !random(10)) {
    write("Humanslayer glows with an unholy red light as it senses the\n"+
          "presence of one of its mortal foes.\n");
    return 10;
  }
}
