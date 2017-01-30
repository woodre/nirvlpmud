
#include "/players/wren/ansi.h"

inherit "obj/treasure";
int barter_value;

reset(arg) {
  if(arg) return;

  set_id("ivory"); 
  set_alias("tusks");
  set_short("large ivory tusks");
  set_long(
"Tusks from the oliphant. These large pieces of ivory could be worth  \n"+
"a fair amount of coinage once they are carved and cleaned up. A good \n"+
"scrimshander or other artisan might be able to use this. Seek a middle \n"+
"man to 'exchange' it for closer to it true value. \n"
  );
  set_weight(2);
  set_value(500);
barter_value = (2500+random(2000));
}

init() {
  add_action("cmd_exchange","exchange");
}


cmd_exchange(str) {
  if(str=="tusks") {
    if(present("cormorant",environment(this_player()))) {
      write("Cormorant examines and weighs the tusks.  \n"+
            "He scrawls "+barter_value+" in coins on a scrap of velum.\n"+
            "and says,\"I'll have to knock off some value for the \n"+
            "exchange but I assure you it is a fair deal.\n");
      this_player()->add_money(barter_value);
      this_player()->recalc_carry();
      destruct(this_object());
      return 1;
    }
  }
  notify_fail("Exchange what?\n");
}
