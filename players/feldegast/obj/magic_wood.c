#include "/players/feldegast/defines.h"

inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("wood");
  set_alias("oak");
  set_short("Enchanted Oak Wood");
  set_long(
"This raw lumber seems to radiate an aura of powerful magics.\n"+
"It also seems unusually light and durable.  You could 'barter'\n"+
"a large ammount of money for this.\n"
  );
  set_weight(2);
  set_value(4500+random(1000));
}
init() {
  add_action("cmd_barter","barter");
}
cmd_barter(str) {
  if(str=="wood"||str=="oak"||str=="lumber") {
    if(present("bedira",environment(TP))) {
      write("Bedira smiles brightly as he sees you're willing to sell\n"+
            "the enchanted lumber to him.  Despite this, he drives a hard\n"+
            "bargain, forcing you down to "+value+" coins.\n");
      TP->add_money(value);
      destruct(this_object());
      return 1;
    }
  }
  notify_fail("Barter what?\n");
}
