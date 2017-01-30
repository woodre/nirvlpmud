#include "../DEFS.h"
    
status main(string str) {
  /* installs weapons upon the mech */
  string wep, file, this;
  int capacity, maxcapacity, wepcapacity;
  file = file_name(ROOM);
  if(!sscanf(file, "%spavilion/rooms/robosh%s", this)) {
    write("You must go to the Hangar to install weapons.\n");
    return 1;
  } 
  if(!str) {
    write("Usage: install <weapon>\n");
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
  wepcapacity = (int)ROBOD->find_capacity(wep, 1);
  capacity += wepcapacity;
  if(capacity > maxcapacity) return 0;
  IPTP->add_weapon(wep);
  IPTP->add_capacity(wepcapacity);
  write("You install the "+wep+" weapon.\n");
  tell_room(ROOM, capitalize((string)ETP->query_myname())+
            " has installed the "+wep+" weapon.\n");
  return 1; 
} 
