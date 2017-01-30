#include "/players/guilds/bards/def.h"

status main(string str) {
  object ob,hunter;

  if (!str) {
    ob = TP;
  } else {
    ob = find_player(str);
  }
  if(!ob || ( (int)ob->query_level()>19 && ob != TP))
    FAIL("You can't find your target within the realms of magic.\n");
  if (spell(-176, 3, 10) == -1) 
    return 0;
    
  write("You play a single note upon your " + INST +".\n");
  say(tp + " plays a single note upon " + POSS(TP) + " " + INST+".\n");
  tell_object(ob, "You are briefly surrounded by a cloak of illusion.\n"+
         "Your skin tingles.\n");
  tell_room(environment(ob), 
         NAME(ob) + " is briefly surrounded by a cloak of illusion.\n",
         ({ob}));
         
  call_other(ob, "stop_hunter");
  call_other(TP, "add_spell_point", -10);
  return 1;
}
