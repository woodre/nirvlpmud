#include "std.h"
object corridor;
#undef EXTRA_INIT
#define EXTRA_INIT\
    add_action("buy"); add_verb("buy");\
    add_action("list"); add_verb("list");\
    add_action("search1"); add_verb("search");\
    add_action("southeast"); add_verb("southeast");

ONE_EXIT("players/rumplemintz/room/elevall/room3","east",
	"Elevallie Toy shop",
	"You are in the Elevallie Toy shop.  You can buy toys here.\n"+
    "Commands are: 'buy <item>', 'list',\n",1)

buy(item) {
  if(!item)
    return 0;
  call_other("players/rumplemintz/room/elevall/toystore", "fill", 0);
  call_other("players/rumplemintz/room/elevall/toystore", "buy", item);
  return 1;
}

search1() {
  write("After a great deal of searching, you flip a switch, and open\n"+
        "a door to the southeast.\n");
  say(capitalize(this_player()->query_name())+" searches the room.\n");
  corridor = this_player();
  return 1;
}
southeast() {
  if(corridor==this_player()){
  write("You go southeast through the back of the Toy Shop, into the new\n"+
	"place you've found.\n");
  this_player()->move_player("leaves#players/rumplemintz/room/elevall/castle/ent");
  return(1);
  }
  write("What?\n");
  return 1;
}
list(obj) {
  call_other("players/rumplemintz/room/elevall/toystore", "fill", 0);
  call_other("players/rumplemintz/room/elevall/toystore", "inventory", obj);
  return 1;
}

find_item_in_player(i) {
  object ob;
  ob = first_inventory(this_player());
  while(ob) {
    if (call_other(ob, "id", i))
      return ob;
    ob = next_inventory(ob);
  }
  return 0;
}
