#include "/players/khrell/ansi.h"
#include "/players/khrell/define.h"

inherit "/players/vital/closed/std/heal.c";

reset(arg) {
  if(arg) return;
  set_name("malt");
  set_alias("liquor");
  set_alt_name("bottle");
  set_id( ({
    name, alias, alt_name, "bottle of fungus brew", "brew", "liquor", "drink", "fungus"
  }) );
  set_short(GRN+"Fungus Brew"+NORM);
  set_long("This grey and greenish thick liquid has been brewed from fermented\n"+
           "fungus harvested in deep caves.  Pherhaps one can drink or guzzle \n"+
           "this foul liquid.                                                 \n");
  set_intox(5);
  set_weight(1);
  set_player_msg("You manage to somehow swallow the foul liquid.\n");
  set_room_msg(" guzzles down some of the brew.\n");
  set_value(15);
  set_heal(10+random(10),5+random(15));
  set_charges(3);
  set_type("drink");
  set_too_drunk("You really can't stomach any more at this time.\n");
  set_info("Goblinoid liquor at it's finest.\n");
  set_cmds( ({
    "swig","drink","guzzle"
  }) );
}

long() {
    if(charges > 1) write(long_desc+"You still have "+HIG+charges+NORM+" "+type+"s left.\n");
    else write(long_desc+"There is just "+HIG+charges+NORM+" "+type+" left.\n");
}
