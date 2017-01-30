#include "/players/guilds/bards/def.h"

status main(string str) {
  object ob;
  int health,x;
  string aa;

  if (spell(-100, 2, 5) == -1)
    return 0;
  if (!str) 
    FAIL("You must pick a target for the Melody of Strength.\n");
  ob = present(str, environment(TP));
  if (!ob)
    FAIL("You can't find your target.\n");
  if(!living(ob))
    FAIL("You can only gauge the strength of a living thing.\n");
  say(tp + " plays a simple melody upon " + POSS(TP) + INST + ".\n");
  write("You play the Melody of Strength upon your " + INST + ".\n\n");
  if(!ob->query_mhp()) {
    write(NAME(ob)+"'s strength is impossible to determine.\n");
    return 1;
  }
  health = ((int)ob->query_hp()) * 100 / ((int)ob->query_mhp());
  aa = "";
  for(x=4;x<health;x+=5)
    aa+="___";
  write("You divine "+NAME(ob)+"'s health:\n");
  write(BOLD+
      "  ____________________________________________________________\n"+NORM);
  write("  "+HIR+aa+"\n"+NORM);
  write(BOLD+
      "  ____________________________________________________________\n"+NORM);
  call_other(TP, "add_spell_point", -5);
  return 1;
}
