
inherit "obj/treasure";
#include "/players/wren/ansi.h"

int barter_value;

reset(arg) {
  if(arg) return;

  set_id("ivory"); 
  set_alias("tusks");
  set_short("smiledon's tusks");
  set_long(
"Tusks of a smiledon. These large pieces of ivory could be worth  \n"+
"a fair amount to an craftsman with time to craft them into an art  \n"+
"piece. Somebody will likely 'exchange' these for value. \n"
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


/* when I get time and figure out what to put on them I think these will be 
   changed from just a barter object to something that can be exchanged for 
   a set of scimitars or something of the kind. Have too many other large 
   weps in the works right now to add this.
*/
