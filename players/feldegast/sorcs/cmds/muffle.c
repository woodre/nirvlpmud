#include "/players/wocket/closed/ansi.h"

cmd(str){
  if(str == "mages"){
write("You muffle the mages guild line.\n");
present("mageguildob",this_player())->set_muffle(1);
"/players/wocket/mages/daemons/channelD.c"->resetchannel();
return 1;
}
notify_fail("What would you like to muffle?\n");
return 0;
}
