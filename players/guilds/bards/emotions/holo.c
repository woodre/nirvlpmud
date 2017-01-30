#include "/players/guilds/bards/def.h"

status main(string str) {
  object ob;
  
  if (!str) {
    write("You look up with dark holocaust eyes.\n");
    say(tp + " looks up with dark holocaust eyes.\n");
    return 1;
  }
  ob = present(str, ENV);
  if (!ob) FAIL("The effect would be lost on someone not here.\n");
  write("You look up at " + NAME(ob) + " with dark holocaust eyes.\n");
  say(tp + " looks up at " + NAME(ob) + " with dark holocaust eyes.\n", ob);
  tell_object(ob, tp + " looks up at you with dark holocaust eyes.\n");
  return 1;
}
