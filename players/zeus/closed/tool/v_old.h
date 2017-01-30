/* It's just so much better than goportal!   -warp-
*/
#include "/players/zeus/closed/all.h"
vortex_cmd(str){
 if(!str){ 
	 write(
"\tUsage:  'v <location>' ||  Current Locations:\n\n"+BOLD+
"\tadvance, realm, portal, building, swamp, sheals\n"+
"\thome, green, chamber, cyber, knight\n"+NORM);
  return 1; 
 }
if(str=="advance"){ MO(TP, "room/adv_inner"); return 1; }
if(str=="realm"){ MO(TP, "players/zeus/realm/main"); return 1; }
if(str=="portal"){  MO(TP, "players/saber/ryllian/portal.c"); return 1; }
if(str=="building"){ MO(TP, "players/cosmo/apt/rooms/lobby.c"); return 1; }
if(str=="swamp"){ MO(TP, "players/zeus/newbie/swamp/s13.c"); return 1; }
if(str=="sheals"){ MO(TP, "/players/snow/ROOMS/fort_hall.c"); return 1; }
if(str=="home"){ MO(TP, "/players/zeus/workroom.c"); return 1; }
if(str=="green"){ MO(TP, "/room/vill_green.c"); return 1; }
if(str=="chamber"){ MO(TP, "/players/mythos/enterance.c"); return 1; }
if(str=="cyber"){ 
	MO(TP, "/players/dune/closed/guild/rooms/guildhall.c"); return 1; }
if(str=="knight"){ 
	MO(TP, "/players/boltar/templar/adv_guild.c"); return 1; }
 return 1;
}

