#include "/players/feldegast/defines.h"
inherit "/obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("meat");
  set_alias("raw meat");
  set_short(RED+"Raw meat"+NORM);
  set_long("This is several pounds of bloody red meat, cut from\n"+
          "the dead body of some poor animal.\n");
  set_weight(1);
  set_value(250);
}
init() {
  ::init();
  add_action("cmd_eat","eat");
}
cmd_eat(str) {
  notify_fail("Eat what?\n");
  if(!str) return 0;
  if(str!="meat") return 0;
  if(TP->eat_food(14)) {
    TP->heal_self(25);
    write("You eat the raw meat.\n");
    say(TPN+" eats some raw meat.\n");
    TP->add_weight(-1);
    destruct(this_object());
    return 1;
  }
}
