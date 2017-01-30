/* It's just so much better than goportal!   -warp-
*/
#include "/players/zeus/closed/all.h"

vortex_cmd(str){
object x;
string y,z;
 if(!str){ 
         write(
"\tUsage:  'v <location>' ||  Current Locations:\n\n"+BOLD+
"\tadvance, realm, portal, building, swamp, sheals\n"+
"\tdesert, post\n"+
"\thome, shome, green, chamber, cyber, knight, castle\n"+NORM);
  return 1; 
 }
 if(sscanf(str, "%sadvance%s\n",y,z))
   MO(TP, "room/adv_inner");
 else if(sscanf(str, "%srealm%s\n",y,z))
   MO(TP, "players/zeus/realm/main");
 else if(sscanf(str, "%sportal%s\n",y,z))
   MO(TP, "players/saber/ryllian/portal.c");
 else if(sscanf(str, "%sbuilding%s\n",y,z))
   MO(TP, "players/cosmo/apt/rooms/lobby.c");
 else if(sscanf(str, "%scastle%s\n",y,z))
   MO(TP, "/room/giant_path.c");
 else if(sscanf(str, "%sswamp%s\n",y,z))
   MO(TP, "players/zeus/newbie/swamp/s13.c");
 else if(sscanf(str, "%sdesert%s\n",y,z))
   MO(TP, "players/zeus/desert/r/ec14.c");
 else if(sscanf(str, "%ssheals%s\n",y,z))
   MO(TP, "/players/snow/ROOMS/fort_hall.c");
 else if(sscanf(str, "%sgreen%s\n",y,z))
   MO(TP, "/room/vill_green.c");
 else if(sscanf(str, "%spost%s\n",y,z))
   MO(TP, "/room/post.c");
 else if(sscanf(str, "%schamber%s\n",y,z))
   MO(TP, "/players/mythos/enterance.c");
 else if(sscanf(str, "%scyber%s\n",y,z))
   MO(TP, "/players/dune/closed/guild/rooms/guildhall.c");
 else if(sscanf(str, "%sknight%s\n",y,z))
   MO(TP, "/players/boltar/templar/adv_guild.c");
 else if(sscanf(str, "%sshome%s\n",y,z))
   MO(TP, "/players/zeus/workroom.c");
 else if(sscanf(str, "%shome%s\n",y,z)){
   TR(environment(TP), BOLD+BLK+capitalize((string)TP->QRN)+
	   " disappears among the shadows.\n"+NORM);
   MO(TP, "/players/zeus/workroom.c");
 }
 else {
   x = find_player(str);
   if(!x)
     x = find_living(str);
   if(!x) return 0;
   if(!environment(x))
   {
     write(x->QN+" has no environment.\n");
     return 1; 
   }
/*
   TR(environment(x), BOLD+BLK+
          "The ominous presence of "+
		  capitalize((string)TP->QRN)+" is before you.\n"+NORM);
*/
   MO(TP, environment(x));
   return 1;
 }
 return 1;
}

