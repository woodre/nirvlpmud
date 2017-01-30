#include "/players/guilds/bards/def.h"

status main(string str) {
  object *obs;
  int x;
  if (!str) FAIL("What would you like to say?\n");
  obs=all_inventory(ENV);
  obs-=({TP});
  for(x=0;x<sizeof(obs);x++) {
    if(!living(obs[x])) continue;
    if(present("bard_obj",obs[x]))
      tell_object(obs[x],format(tp+" signs '"+ str +"' in bardic cant.\n"));
    else
      tell_object(obs[x],tp+" makes a series of unusual facial and hand gestures.\n");
  }
  write(format("You sign '"+ str +"' in bardic cant.\n"));
  return 1;
}
