#include "../DEFS.h"
    
status main(string str) {
  /* allows pilot to add ammo to the mech's weapons */
  string wep, file, this;    
  int maxcapacity, capacity, ammocapacity, pack;
  file = file_name(ROOM);
  if(!sscanf(file, "%spavilion/rooms/robosh%s", this)) {
    write("You must go to the Hangar to supply weapons.\n");
    return 1;
  }
  if(!str) {
    write("Usage: supply <weapon>\n");
    return 1;
  }
  wep = (string)ROBOD->find_weapon(str);
  if(wep == "none") {
    write("No such weapon as "+str+", your choices are:\n"+
          "'autocannon, srm, lrm, laser, rifle, or ppc'\n");
    return 1;
  }
  maxcapacity = (int)(ETP->query_maxcapacity());
  capacity = (int)(IPTP->query_capacity());
  ammocapacity = (int)ROBOD->find_capacity(wep, 2);
  capacity += ammocapacity;
  if(capacity > maxcapacity) {
     write("You have run out of capacity\n");
     return 1;
  }
  pack = (int)ROBOD->find_capacity(wep, 3);
  IPTP->add_ammo(wep, pack);
  IPTP->add_capacity(ammocapacity);
  write("You supply your mech with "+wep+" ammo.\n");
  tell_room(ROOM, capitalize((string)ETP->query_myname())+
            " has added "+wep+" ammo.\n");
  return 1;
}
