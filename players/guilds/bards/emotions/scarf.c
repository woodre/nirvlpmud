#include "/players/guilds/bards/def.h"

status main(string str){
  object ob;
  
  if (!str) {
    write("You conjure a scarf from thin air.\n" +
    "  Aren't hidden pockets wonderful?\n");
    say(tp + " conjures a scarf from thin air.\n");
    return 1;
  }
  ob = present(str, ENV);
  if (!ob) FAIL("You can't find a "+str+"\n");
  write("You conjure a scarf from behind " + NAME(ob) + "'s ear.\n" +
  "  Aren't hidden pockets wonderful?\n");
  say(tp + " conjures a scarf from behind " + NAME(ob) + "'s ear.  Wow!\n",
  ob);
  tell_object(ob,
    tp + " conjures a scarf from behind your ear.\n" +
  "  Hey, where did that come from?\n");
  return 1;
}

