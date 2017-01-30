#include "../DEFS.h"

int find_capacity(string wep, int flag) {
  /* returns 1)weapon and 2)ammo capacities and 3)ammo packages */
  switch(wep) {
    case "autocannon": if(flag==1) return 15;  
                       if(flag==2) return 10;  
                       if(flag==3) return 14;
                       break;
    case "srm":        if(flag==1) return 12;
                       if(flag==2) return 6;
                       if(flag==3) return 10;
                       break;
    case "lrm":        if(flag==1) return 11;
                       if(flag==2) return 8;
                       if(flag==3) return 10;  
                       break;
    case "laser":      if(flag==1) return 10;
                       if(flag==2) return 9;
                       if(flag==3) return 12;  
                       break;
    case "rifle":      if(flag==1) return 9;
                       if(flag==2) return 10;
                       if(flag==3) return 16;  
                       break;
    case "ppc":        if(flag==1) return 15;
                       if(flag==2) return 9;
                       if(flag==3) return 12;  
                       break;
  }  
  return 0;
}


string find_weapon(string str) {
  /* returns the string used to identify the weapon */
  switch(str) {
    case "autocannon": return "autocannon";
    case "cannon":     return "autocannon";
    case "srm":        return "srm";
    case "lrm":        return "lrm";
    case "laser":      return "laser";
    case "rifle":      return "rifle";
    case "ppc":        return "ppc";
    }
  return "none";
}

status comm(string str) {
  /* annoucements for all mechs */
  object *everyone;
  object pilot, ob;
  int i;
  everyone = users();
  for(i = 0; i < sizeof(everyone); i++) {
    ob = everyone[i];
    if(environment(ob) && IPOB) {
      pilot = IPOB;
      if(pilot)
        tell_object(ob, "[[RoboComm]] "+str+"\n");
    }
  }
  return 1;
}
