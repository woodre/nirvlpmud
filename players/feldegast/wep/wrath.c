#include "defs.h"

inherit "/obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("wrath");
  set_alias("morningstar");
  set_short(RED+"Wrath"+NORM+" the Morningstar");
  set_type("club");
  set_long(
    "Wrath is a silver morningstar with a ball of spikes attached by\n"+
    "a long chain to the hilt.  There is an inscription on the hilt.\n"
  );
  set_read(HIR+"WRATH\n"+NORM);
  set_class(18);
  set_weight(4);
  set_value(1500);
  set_hit_func(this_object());
  message_hit=({
    "massacred"," to small fragments",
    "crushed"," with a bone crushing sound",
    "smashed"," very hard",
    "smashed"," hard",
    "whacked","",
    "grazed","",
    "tickled"," in the stomach"
  });
}

int weapon_hit(object attacker) {
  if(this_player()->query_alignment() < attacker->query_alignment()) {
    if(!random(10))
      write("You cannot summon any righteousness against "+(string)attacker->query_name()+".\n");
    return 0;
  }
  if(TP->query_attrib("pie") > random(120)) {
    tell_room(environment(attacker),short_desc+" burns with the "+HIR+"A"+HIW+"nger"+NORM+" of the "+HIR+"R"+HIW+"ighteous"+NORM+"!\n");
    return 5;
  }
  if(TP->query_attrib("wil") > random(120)) {
    write((string)attacker->query_name()+" is scorched by your "+HIR+"WRATH"+NORM+"!\n");
    say((string)attacker->query_name()+" is scorched by "+TPN+"'s "+HIR+"WRATH"+NORM+"!\n");
    return 7;
  }
}
