#include "defs.h"

inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("stone");
  set_alias("heartstone");
  set_short("A "+HIR+"heartstone"+NORM);
  set_long(
"The heartstone pulses with an inner fire, seeming to possess\n"+
"a life of its own.  You suspect you could barter this for alot\n"+
"of money to someone who really wanted it.\n"
  );
  set_weight(1);
  set_value(4500+random(1000));
}

init() {
  add_action("cmd_cash","cash");
  add_action("cmd_barter","barter");
}

cmd_barter(str) {
  if(id(str)) {
    if(present("sorceress",environment(TP))) {
      write("The sorceress smiles brightly as she sees you're willing to sell\n"+
            "the heartstone to her.  Despite this, she drives a hard bargain,\n"+
            "forcing you down to "+value+" coins.\n");
      TP->add_money(value);
      TP->add_weight(-1);
      write_file("/players/feldegast/log/monsters.log",ctime(time())+" "+TPN+" cashed a heartstone\n");
      destruct(this_object());
      return 1;
    }
  }
  notify_fail("Barter what?\n");
}
