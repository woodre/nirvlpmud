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
      "|     "+YEL+"o"+NORM+""+BOLD+"---------------"+YEL+""+BWHT+"X"+NORM+""+BOLD+"---------------"+YEL+"o"+NORM+""+BOLD+"----------|   |  o = Oil Well \n"+
      "|     |                                              |\n"+
      "|     |                                              |\n"+
      "|     |                                              |\n"+
      "|     |                                              |\n"+
      "|     |                                              |\n"+
      "|     |                                              |\n"+
      "|     |                                              |\n"+
      "|     "+YEL+"o"+NORM+""+BOLD+"                                              |\n"+
      "|     |                                              | You are standing above\n"+
      "|     |                                              | Well 4. A pressure meter\n"+
      "|     |                                              | is located on some metal\n"+
      "|     |                                              | casing that covers the\n"+
      "|     |                                              | well.\n"+
      "|     |                                              |\n"+
      "|     "+YEL+"o"+NORM+""+BOLD+"                                              |\n"+
      "|    |-|                                             |\n"+
      "|                                                    |\n"+
      "|                                                    |\n"+
      "|                                                    |\n"+
      " "+HIB+"----------------------------------------------------"+NORM+""+BOLD+" \n"+
      "                    Chinle Oil Platform"+NORM+" \n");
   
   add_exit("/players/mo/rig/ROOMS/cwalk/r5.c","east");
   add_exit("/players/mo/rig/ROOMS/cwalk/r7.c","west");
   add_item("meter","A pressure meter monitoring the well.\n");
   add_item("casing","Sheet metal covering pipes.\n");
}
