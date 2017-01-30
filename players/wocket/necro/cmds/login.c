#include "../defs.h"

cmd(str) {
  if(!str || (str !="church" && str !="guild")){write("Where do you want to login? (church/guild)\n"); return 1;}
  if(str == "church") {tp->set_home("/room/church.c"); }
  if(str == "guild") {tp->set_home(PATH+"/room/necro2.c"); }
  write(NECRO+"Your login position has been changed.\n");
  return 1;
}