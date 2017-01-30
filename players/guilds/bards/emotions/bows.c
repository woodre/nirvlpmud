#include "/players/guilds/bards/def.h"

status main(string str) {
  object ob;
  
  if (!str) {
    write("You make an elaborate bow.\n");
    say(tp + " makes an elaborate bow.\n");
    return 1;
  }
  ob = present(str, ENV);
  if (!ob) FAIL("You can't find that person here.\n");
  write("You make an elaborate bow to " + NAME(ob) + ".\n");
  say(tp + " makes an elaborate bow to " + NAME(ob) + ".\n",ob);
  tell_object(ob, tp + " makes an elaborate bow to you.\n");
  return 1;
}
