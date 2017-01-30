#include "/players/guilds/bards/def.h"

status main(string str) {
  object ob;
  
  if(!str) FAIL("Whose hand do you want to kiss?\n");
  ob = present(str, ENV);
  if (!ob) FAIL("You can't find their hand to kiss.\n");
  if(ob==TP) {
    write("You bow slightly, and kiss your own hand.\n");
    say(tp+" bows slightly, then kisses "+POSS(TP)+" own hand.\n"+
        "  Bards can be strange like that sometimes.\n");
    return 1;
  }
  write("Bowing slightly, you kiss " + NAME(ob) + "'s hand.\n");
  say(format(tp + " bows slightly, takes "+NAME(ob)+"'s hand, "+
  " and kisses it lightly.\n"), ob);
  tell_object(ob,
    tp +" bows slightly, takes your hand, and kisses it lightly.\n");
  return 1;
}
