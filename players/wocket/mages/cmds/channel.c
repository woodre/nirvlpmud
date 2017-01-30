#include "/players/wocket/closed/ansi.h"

cmd(str){
  if(str == "mages"){
write("You unmuffle the mages guild line.\n");
present("mageguildob",this_player())->set_muffle(0);
"/players/wocket/mages/daemons/channelD.c"->resetchannel();
return 1;
}
notify_fail("What would you like to unmuffle?\n");
return 0;
}
