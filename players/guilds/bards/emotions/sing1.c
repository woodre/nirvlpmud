#include "/players/guilds/bards/def.h"

status main(string str){
  object ob;
  
  if (!str) {
    write("You sing part of an old Irish love ballad.\n");
    say(tp + " sings part of an old Irish love ballad.\n" +
    "  You covertly wipe away a single tear.\n");
    return 1;
  }
  ob = present(str, ENV);
  if (!ob) FAIL("You must sing the ballad in person.\n");
  write(format("You sing " + CAP + " part of an old Irish love "+
  "ballad to "+NAME(ob)+".\n")); 
  say(format(tp + " sings " + CAP + " part of an old Irish love ballad to "+
  NAME(ob)+".\n  You covertly wipe away a single tear.\n"), ob);
  tell_object(ob, tp + " sings you part of an old Irish love ballad to you.\n" +
  "  Your heart fills with longing.\n");
  return 1;
}
