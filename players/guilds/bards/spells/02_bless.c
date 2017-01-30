#include "/players/guilds/bards/def.h"

status main(string str) {
  object ob;
  
  if (!str) {
    ob=TP;
  } else
  ob = present(str, environment(TP));
  if (!ob)
    FAIL("You can't find your target.  Maybe they don't want a blessing?\n");
  if (ob == TP)
    FAIL("You are already among the ranks of the blessed.\n" +
    "You are a Bard!\n");
  if (present("bard_obj",ob))
    FAIL(NAME(ob)+" is already among the ranks of the blessed.\n"+
         PRON(ob)+" is a fellow Bard!\n");
  if (spell(0, 2, 5) == -1)
    return 0;
  write("You whisper a traditional "+HIG+"Celtic"+NORM+" blessing over "
    + NAME(ob) + ".\n"
    + NAME(ob) + " is surrounded by a brief "+HIY+"halo"+NORM+" of light.\n");
  say(tp + " whispers a traditional "+HIG+"Celtic"+NORM+" blessing over " 
    + NAME(ob) + ".\n" 
    + NAME(ob) + " is surrounded by a brief "+HIY+"halo"+NORM+" of light.\n",ob);
  
  tell_object(ob, tp 
    + " whispers a traditional "+HIG+"Celtic"+NORM+" blessing over you.\n"
    +"You are surrounded by a brief "+HIY+"halo"+NORM+" of light.\n"
    +"You feel good.\n");
  call_other(TP, "add_spell_point", -5);
  return 1;
}
