#include "../DEFS.h"

status main(string str) {
  /* see what other mechs (and their pilots) are playing */
  int i;
  object *everyone;
  object ob, mech, room;
  string pilot_name, mech_name, type, loc;
  everyone = users();
  write("RoboMech     Pilot        Type      Location\n");
  write("###################################################\n");
  for(i = 0; i < sizeof(everyone); i++)  {
   ob = everyone[i];
   if(environment(ob) && IPOB) {
    pilot_name = OPN;
    mech = environment(ob);
    room = environment(mech);
    mech_name = capitalize((string)mech->query_myname());
    type = capitalize((string)mech->query_type());
    loc = (string)room->zone();
    if(!loc) loc = "Off Battlefield";
    write(pad(mech_name,13));
    write(pad(pilot_name,13));
    write(pad(type, 10));
    write(pad(loc, 16));
    write("\n");
    }
  }
  write("###################################################\n");
  return 1;
}
