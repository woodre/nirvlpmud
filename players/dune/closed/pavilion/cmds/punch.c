#include "../DEFS.h"
  
status punch_mech(object targ, int dm, object attacker, string wep) {
  /* this does the actual damage to the mech */
  /* deaths are recorded                     */
  int death;
  string name, pilotwinner, pilotloser, who;
  object targroom;  
  targroom = environment(targ);
  name = capitalize((string)targ->query_myname());
  who = capitalize((string)attacker->query_myname()); 
  death = 0;
  if(targ->query_hp() <= dm) death = 1;
  tell_room(targroom, name+
              " takes a hit from "+who+"'s "+wep+".\n");
  ROOM->shout( 
    "You hear the clanking sounds of mechs bashing eachother.\n");
  if(death) {
    pilotwinner = (string)attacker->query_pilot();
    pilotloser = (string)targ->query_pilot();
    ROOM->shout(name+" falls apart from continual bashing.\n");
    write_file("/players/dune/log/ROBOMECH",
               who+" (pilot "+pilotwinner+") destroyed "+
               name+" (pilot "+pilotloser+")\n"+
               "   on the date of "+ctime()+"\n"); 
    targ->hit_player(1000);
    death = 0;
    return 1;
  }
  targ->hit_player(dm);
  death = 0;
  return 1;
}

status main(string str) {
  /* default weapon. punchs never need ammo */
  /* punchs don't do much damage either     */
  object targ;
  string file, this;
  file = file_name(ROOM);
  if(!sscanf(file, "%spavilion/rooms/field%s", this)) {
    write("Mechs must fight in the RoboMech Battlefield.\n");
    return 1;
  }
  if(!str) {
    write("What do you want to punch?\n");
    return 1;
  }
  if(!present(str, ROOM)) {
    write("There is no "+str+" here.\n");
    return 1;
  }
  targ = present(str, ROOM);
  if(!targ->is_mech()) {
    write(str+" is not a RoboMech.\n");
    return 1;
  }
  punch_mech(targ, 3, ETP, "punch");
  return 1;
}
