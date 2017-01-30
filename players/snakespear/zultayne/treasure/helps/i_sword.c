#include "/players/snakespear/closed/ansi.h"
inherit "obj/weapon";
reset(arg) {
  ::reset(arg);
  if(arg) return;
set_class(18);
set_value(1000);
set_weight(3);
set_light(1);
set_alias("blade");
set_long("This is an invisible blade probably made by a rogue gargoyle.\n");
set_hit_func(this_object());
}

weapon_hit(attacker) {
  int a;
  a=random(12);
 
  if(a == 0) {
  say("Bright light flashes and sparks fly!\n");
  write("The blade shakes violently in your hands.\n");
  return 5;
  }

  if(a == 1) {
  say("Someting slices through you and it hurts!\n");
  write("You slice deftly, watching your enemy writhe in pain!\n");
  return 1;
  }

  if(a == 2) {
  say(HIR+"BLOOD "+NORM+"showers the room, spraying from your open wounds!\n");
  write("You "+HIR+"E V I S I C R A T E "+NORM+"your opponent with accurate slices!\n");
  return 6;
  }

  if(a == 3) {
  say(HIC+"Ice shards "+NORM+"fly into your soul!\n");
  write("You send "+HIC+"ice shards "+NORM+"flying about the room!\n");
  return 11;
  }

  if(a > 4) {
  say("The light grows dim and is absorbed by <wielder>.\n");
  write("You absorb the surrounding "+HIW+"light"+NORM+", readying for another attack.\n");
  return 7;
  }
}
