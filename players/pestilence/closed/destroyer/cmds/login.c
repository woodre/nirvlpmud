#include "/players/pestilence/define.h"

status main(string str) {
   if(!str){write("Where do you want to login? (church/guild)\n"); return 1;}
  if(str == "church") {tp->set_home("/room/church.c"); }
  if(str == "guild") {tp->set_home("/players/pestilence/closed/destroyer/room/hall.c"); }
 write(">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+NORM+"< Your login position has been changed.\n");
  return 1;
}
