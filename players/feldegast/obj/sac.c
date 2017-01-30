/*
File: sac.c
Author: Feldegast
Date: 2-24-02
Description:
  A venom sac from the spider cave in Caladon.
Can be bartered.
*/

#include "/players/feldegast/defines.h"

inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("sac");
  set_alias("venom sac");
  set_short("Venom Sac");
  set_long(
    "This is a bluish internal organ filled with toxic venom.\n"+
    "It is fairly exotic, so you might be able to barter it for\n"+
    "something useful with somebody interested in such things.\n"
  );
  set_weight(1);
  set_value(4500+random(1000));
}

init() {
  add_action("cmd_barter","barter");
}

cmd_barter(str) {
  object targ;
  if(id(str)) {
    targ=present("sorcerer",environment(this_player()));
    if(targ) {
      write(targ->query_name()+" looks interested in your bundle of spidersilk, but\n"+
            "negotiates its price down to "+value+" coins.  He smiles\n"+
            "and says,\"If you manage to get any more, bring it to me.\n"+
            "Venom sacs have some fascinating medicinal uses.\"\n");
      this_player()->add_money(value);
      this_player()->add_weight(-1);
      destruct(this_object());
      return 1;
    }
  }
  notify_fail("Barter what?\n");
}
