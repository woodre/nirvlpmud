/* The WizProd [tm]  Created <5/23/00> by Jara */

#include "/players/jara/misc/ansi.h"
inherit "/obj/treasure.c";

reset(int arg) {
   if(arg) return;

  set_id("prod");
  set_short("The WizProd ["+HIR+"tm"+NORM+"]");
  set_long("The WizProd is a two foot long staff, with a strangely\n"+
    "glowing prod at the end. You may '"+HIR+"prod"+NORM+"' someone with it.\n");
  set_weight(1);
  set_value(0);
  set_dest_flag(1);
}

init() {
  ::init();

  add_action("prodder","prod");
}

int prodder(string str) {
object who;
  if(!str) {
    notify_fail("Prod whom?\n");
  return 0;
  }

  who = find_player(str);
  if(!who) {
  notify_fail("They are not online now.\n");
  return 0;
  }
    tell_object(who, (this_player()->query_name())+" prods you with the WizProd ["+HIR+"tm"+NORM+"].\n");
    write("You prod "+capitalize(str)+" with the WizProd ["+HIR+"tm"+NORM+"].\n");
  return 1;
}
