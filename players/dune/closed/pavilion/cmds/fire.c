#include "../DEFS.h"

fire_away(string str, int num_of_wep) {
  /* function for calculating weapon features */
  int dm, rg, bm, ht, maxheat, temp, heat;
  object tracer;
  switch(str) {
    case "autocannon":  dm=16; rg=0; bm=0; ht=8; break;
    case "srm":         dm=14; rg=2; bm=1; ht=6; break;
    case "lrm":         dm=13; rg=5; bm=2; ht=5; break;
    case "laser":       dm=13; rg=3; bm=0; ht=5; break;
    case "rifle":       dm=12; rg=2; bm=1; ht=4; break;
    case "ppc":         dm=17; rg=2; bm=2; ht=9; break;
  }
  dm *= num_of_wep;
  ht *= num_of_wep;
  IPTP->add_heat(ht);
  if (!IPTP) return 1;
  if (IPTP->is_overheated()) return 1;
  tracer = clone_object(
           "/players/dune/closed/pavilion/tracer.c");
  move_object(tracer, ROOM);
  tell_room(ROOM, capitalize((string)ETP->query_myname())+
            " fires its "+str+".\n");
  ROOM->shout("The blast of "+str+
                 " rings through the battlefield.\n");
  tracer->activate(ETP, dm, rg, bm, ht, str);
  return 1;
}

status main(string str) {
  /* allows pilot to fire a specified weapon */
  int num_of_wep;
  string wep, file, this;
  file = file_name(ROOM);
  if(!sscanf(file, "%spavilion/rooms/field%s", this)) {
    write("Mechs must fight in the RoboMech Battlefield.\n");
    return 1;
  }
  if(!str) {
    write("Usage: fire <weapon>\n");
    return 1;
  }
  wep = (string)ROBOD->find_weapon(str);
  if(wep == "none") {
    write("No such weapon as "+str+", your choices are:\n"+
          "'autocannon, srm, lrm, laser, rifle, or ppc'\n");
    return 1;
  }
  num_of_wep = (int)IPTP->have_weapon(wep);
  if(!num_of_wep) {
    write("You do not have the "+str+" weapon.\n");
    return 1;
  }
  if(IPTP->ammo(wep)) {
    IPTP->reduce_ammo(wep);
    fire_away(wep, num_of_wep);
    return 1;
  }
  else {
    write("You're out of "+str+" ammo!\n");
    return 1;
  }
  return 1;
}
