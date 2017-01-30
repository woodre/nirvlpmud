inherit "/players/vertebraker/closed/std/room.c";
#include <ansi.h>

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Sea of Hirandea");
   set_long(
      ""+BOLD+"\n"+
      "|  "+NORM+"(W    W)"+BOLD+"            |    |              |"+NORM+""+RED+"P"+NORM+"P"+RED+"P"+NORM+"   "+RED+"P"+NORM+"P"+RED+"P"+NORM+""+BOLD+"|\n"+
      "|   "+NORM+"(WWWW)"+BOLD+"             |    |              |"+NORM+""+RED+"P"+NORM+"PP   PP"+RED+"P"+NORM+""+BOLD+"|\n"+
      "|                      |    |              |"+NORM+""+RED+"PPPPPPPPP"+NORM+""+BOLD+"|\n"+
      ""+NORM+""+HIB+" oooooooooooooooooooooooooooooooooooooooooooooooooooo"+NORM+""+BOLD+" \n"+
      ""+NORM+""+BLU+" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
      ""+NORM+""+BLU+" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
      ""+NORM+""+BLU+" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
      ""+NORM+""+BLU+" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
      ""+NORM+""+BLU+" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
      ""+NORM+""+BLU+" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
      ""+NORM+""+BLU+" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
      ""+NORM+""+BLU+" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+NORM+"\n");
   add_exit("/players/mo/rig/ROOMS/sea/r5.c","south");
   add_exit("/players/mo/rig/ROOMS/sea/r7.c","north");
}
