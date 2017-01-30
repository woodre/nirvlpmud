#include "/players/cosmo/dc/defs.h"
inherit "players/cosmo/dc/dc_room";

int i;

reset(arg) {
  if(arg) return;
  set_room_type("building");
  short_desc = BLU+"Grounds of the Jefferson"+NORM;
  long_desc = 
"You walk up to the front of the Memorial and are greatly\n"+
"disappointed to see that there is scaffolding up on every\n"+
"side.  You can't even see the wonderous statue of Thomas\n"+
"Jefferson on the inside.  Many other tourists are in the area\n"+
"trying to view the bronze statue of our third president.  Try\n"+
"coming back later and hopefully this monument will be open\n"+
"for viewing.\n\n";

  items = ({
    "memorial", "The Memorial is currently closed for renovations",
  });

  dest_dir = ({
    DCSTR+"s001", "northeast",
  });

  if(!present("worker", TO)) {
    for(i=0;i<2;i++) { MO(CO(DCMON+"worker.c"), TO); }  
  }
    
}

init() {
  ::init();
}
