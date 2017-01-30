#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/tvroom.c";

string housename;
reset(arg){
  if(arg) return;
short_desc = HIR+"The house of "+capitialize(housename)+"\n"+NORM;
long_desc = "A bare room.\n";
}

init(){
::init();
}

save_house(){
  save_object("players/wocket/houses/rooms/ent"+housename);
  return 1;
}

refresh_house(){
  restore_object("players/wocket/houses/rooms/ent"+housename);
  return 1;
}
