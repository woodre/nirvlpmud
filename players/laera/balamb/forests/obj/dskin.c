#include "/players/laera/closed/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("dragon skin");
  set_alias("skin");
  set_short(BLU+"Dragon Skin"+OFF);
set_long(
	"Soft, yet very supple, this is a piece of skin from a Blue Dragon.\n" +
	"It is used to make durable armour when taken to a shop.  Legend says\n" +
	"that it was also a powerful magic item at one time, as well as a \n" +
	"lethal component to a weapon.\n");

  set_value(2500 + random(2000));
  set_weight(2);
}

init() {
  add_action("cmd_barter","barter");
}

cmd_barter(str) {
  if(id(str)) {
    if(present("etien",environment(this_player()))) {
      write("Etien looks over the item and decides its worth.  He pays \n" +
      		"you " + value + " for it then thanks you for your business.\n");
      say(this_player()->query_name() + " barters an item to Etien.\n");
      this_player()->add_money(value);
      this_player()->add_weight(-2);
      destruct(this_object());
      return (1);
    }
  }
  notify_fail("Barter what?\n");
}