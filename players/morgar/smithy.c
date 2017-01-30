#include "std.h"

#undef EXTRA_INIT
#ifndef __LDMUD__ /* Rumplemintz */
#define EXTRA_INIT\
    add_action("buy"); add_verb("buy");\
    add_action("list"); add_verb("list");\
    add_action("look"); add_verb("read");\
    add_action("look", "look");\
    add_action("look", "l");\
    add_action("look", "examine");
#else
#define EXTRA_INIT\
  add_action("buy", "buy");\
  add_action("list", "list");\
  add_action("look", "read");\
  add_action("look", "look");\
  add_action("look", "examine");\
  add_action("look", "l");
#endif

ONE_EXIT("room/northroad1", "east",
         "The smithy",
         "You enter the smithy, the shop floor is plain wood and dirty.\n"+
         "At the far end there is a walled off area and an old man can\n"+
         "be seen scurring about behind the built-in counter. Over the\n"+
         "counter is a metal mesh designed to keep people away from the\n"+
         "inventory. Through the mesh a variety of armor and weapons are\n"+
         "hung on the wall and stored on shelves. There is an inventory\n"+
         "list tacked to the wall of items you may buy.\n", 1)

buy(item) {
    if (!item)
        return 0;
    write("The man pulls the item from inventory handing it to you only\n"+
     "when your coins have passed through the opening in the mesh.\n");
    call_other("players/morgar/smithystore", "fill", 0);
    call_other("players/morgar/smithystore", "buy", item);
    return 1;
}

list(obj) {
    call_other("players/morgar/smithystore", "fill", 0);
    call_other("players/morgar/smithystore", "inventory", obj);
    return 1;
}

find_item_in_player(i)
{
    object ob;

    ob = first_inventory(this_player());
    while(ob) {
        if (call_other(ob, "id", i))
            return ob;
        ob = next_inventory(ob);
    }
    return 0;
}
look(str) {
  if (!str) return 0;
 if(str=="at list"||str=="at inventory list"||str=="list"||str=="inventory list") {
     write("This tattered hand written list indicates the inventory.\n"+
      "and prices of all the items in the shop. It reads:\n");
      list();
      return 1;
    }
    if(str=="at floor") {
      write("The floor is badly worn, dirty, and in need of repair.\n");
      return 1;
    }
    if(str=="at counter") { 
      write("The wooden counter has been recently painted a dark green \n"+
      "what was clearly chipping paint.\n");
    }
    if(str=="at mesh") {
      write("The steel mesh protects the back room from intruders and \n"+
      "theives. There is a small slot that items and money may be passed.\n");
      return 1;
    }
    if(str=="at inventory") {
      write("You can see the following on the shelves with price tags.\n");
      list(); 
      return 1;
     }
    if(str=="at man" || str=="at old man") {
      write("An old man wearing worn, faded, blue overalls and a green \n"+
      "apron. He scurries about the backroom of the shop not paying \n"+
      "attention to people in the front until they are ready to buy.\n");
      return 1;
     }
    return 0;
}
