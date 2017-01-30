/* A magic ruby to serve as a gargoyle's heart */
#include "/players/feldegast/defines.h"

inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("ruby");
  set_alias("gem");
  set_short("An enchanted ruby");
  set_long(
"This enchanted ruby seems to pulse with an inner fire.\n"+
"You may 'cash' it or 'barter' it to the right person.\n"
  );
  set_weight(1);
  set_value(1000+random(500));
}
init() {
  add_action("cmd_cash","cash");
  add_action("cmd_barter","barter");
}
cmd_barter(str) {
  if(id(str)) {
    if(present("bedira",environment(TP))) {
      write("Bedira smiles brightly as he sees you're willing to sell\n"+
            "the gargoyle heart to him.  Despite this, he drives a hard\n"+
            "bargain, forcing you down to "+value+" coins.\n");
      TP->add_money(value);
      destruct(this_object());
      return 1;
    }
  }
  notify_fail("Barter what?\n");
}
cmd_cash(str) {
  if(id(str)) {
    write("You sell the enchanted ruby to a passing gem merchant for\n"+
           "1000 coins.  You both smile happily, thinking you got the\n"+
           "better part of the deal.\n");
    TP->add_money(1000);
    destruct(this_object());
    return 1;
  }
  notify_fail("Cash what?\n");
}
