#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/turtleville"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
  short_desc = HIG+"The Wait room"+NORM;
  long_desc = "   This is for pet waiting periods.\n"+
              "This is a wiz only room.  If your a player\n"+
              "your in trouble.\n";  
  set_light(1);
   dest_dir = ({
  });
}

