inherit "/players/vertebraker/closed/std/room.c";
#include <ansi.h>

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Above Chinle Oil Platform");
   set_long(
      
      "                    "+BOLD+"Catwalk\n"+
      ""+NORM+""+HIB+" ----------------------------------------------------"+NORM+""+BOLD+" \n"+
      "|                                            ()Lift()"+BOLD+"|  X = You \n"+
      "|                                                |   | |-| = End of Catwalk \n"+
      "|     "+YEL+"o"+NORM+""+BOLD+"---------------"+YEL+"o"+NORM+""+BOLD+"---------------"+YEL+"o"+NORM+""+BOLD+"----------|   |  o = Oil Well \n"+
      "|     |                                              |\n"+
      "|     |                                              |\n"+
      "|     |                                              |\n"+
      "|     |                                              |\n"+
      "|     |                                              |\n"+
      "|     |                                              |\n"+
      "|     |                                              |\n"+
      "|     "+YEL+"o"+NORM+""+BOLD+"                                              |\n"+
      "|     |                                              |\n"+
      "|     |                                              |\n"+
      "|     |                                              |\n"+
      "|     "+BWHT+"X"+NORM+""+BOLD+"                                              |\n"+
      "|     |                                              |\n"+
      "|     |                                              |\n"+
      "|     "+YEL+"o"+NORM+""+BOLD+"                                              |\n"+
      "|    |-|                                             |\n"+
      "|                                                    |\n"+
      "|                                                    |\n"+
      "|                                                    |\n"+
      " "+HIB+"----------------------------------------------------"+NORM+""+BOLD+" \n"+
      "                    Chinle Oil Platform"+NORM+" \n");
   
   add_exit("/players/mo/rig/ROOMS/cwalk/r10.c","north");
   add_exit("/players/mo/rig/ROOMS/cwalk/r12.c","south");
}
