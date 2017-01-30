#include "/players/guilds/bards/def.h"

status check_findable(object ob) {
  if(!ob)
    return 0;
  if(ob->query_invis())
    return 0;
  if((int)ob->query_level() > 19)
    return 0;
  return 1;
}

status main(string str) {
  object ob;
  object env;
  object *people;
  int x;

  if (spell(-150, 4, 10) == -1)
    return 0;
  if (!str)
    FAIL("What do you wish to search out?\n");

  write("You play the Eyes of the Hawk on your "+ INST +".\n");
    ("Your music flows through the Realms of Magic in search of "
     + capitalize(str) + ".\n\n");  
  say(tp + " plays a light turn upon " + POSS(TP) + " " + INST + ".\n");
  
  call_other(TP, "add_spell_point", -10);
  
  
  if (ob = present(str, TP)) {
    write("You have the object for which you search in your inventory.\n");
      return 1;
  }
  if (ob = present(str, environment(TP))) {
    write("The object of your search is in your room.\n");
    return 1;
  }
  if (str == "silversword") {
    write("Silversword can be found in the 'Circle'\n");
    return 1;
  }
  people=users();
  for(x=0;x<sizeof(people);x++) {
    if(!check_findable(people[x]))
      continue;
    if(people[x]->id(str) && (env =environment(people[x]))) {
      write(capitalize(str)+" can be found in "+ env->short() +".\n");
      tell_object(people[x],"You hear soft music for a moment.\n");
      return 1;
    }
    if(present(str,people[x])) {
      write(capitalize(str)+" can be found on "+ people[x]->short()+ ".\n");
      tell_object(people[x],"You hear soft music for a moment.\n");      
      return 1;
    }
  } 
  write("You can find no traces of " + capitalize(str) + ".\n");
  return 1;
}
