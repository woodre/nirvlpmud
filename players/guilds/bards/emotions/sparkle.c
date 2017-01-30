#include "/players/guilds/bards/def.h"

status main(string str) {
  object ob;
  
  if (!str) {
    write("You look up with a sparkle in your eyes.\n");
    say(tp + " looks up with a sparkle in " + POSS(TP) +" eyes.\n");
    return 1;
  }
  ob = present(str, ENV);
  if (!ob) FAIL("You don't see anyone by that name here.\n");
  
  write("You look up at " + NAME(ob) + " with a sparkle in your eyes.\n");
  say(tp + " looks up at " + NAME(ob) + " with a sparkle in " 
  + POSS(TP) + " eyes.\n", ob);
  tell_object(ob,
    tp + " looks up at you with a sparkle in " + POSS(TP) + " eyes.\n");
  return 1;
}
