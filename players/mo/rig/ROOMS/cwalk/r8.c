inherit "/players/vertebraker/closed/std/room.c";
#include <ansi.h>
int random_index;
reset(arg) {
   if(arg) return;
   random_index=random(2);
   move_object(clone_object(({"/players/mo/rig/MON/geologist.c","/players/mo/rig/MON/roughneck.c"})[random_index]),
      this_object());
   set_light(1);
   set_short("Above Chinle Oil Platform");
   set_long(
      
      "                    "+BOLD+"Catwalk\n"+
      ""+NORM+""+HIB+" ----------------------------------------------------"+NORM+""+BOLD+" \n"+
      "|                                            ()Lift()"+BOLD+"|  X = You \n"+
      "|                                                |   | |-| = End of Catwalk \n"+
      "|     "+YEL+""+BWHT+"X"+NORM+""+BOLD+"---------------"+YEL+"o"+NORM+""+BOLD+"---------------"+YEL+"o"+NORM+""+BOLD+"----------|   |  o = Oil Well \n"+
      "|     |                                              |\n"+
      "|     |                                              |\n"+
      "|     |                                              |\n"+
      "|     |                                              |\n"+
      "|     |                                              |\n"+
      "|     |                                              |\n"+
      "|     |                                              |\n"+
      "|     "+YEL+"o"+NORM+""+BOLD+"                                              |\n"+
      "|     |                                              | You are standing above\n"+
      "|     |                                              | Well 3. A pressure meter\n"+
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
   
   add_exit("/players/mo/rig/ROOMS/cwalk/r7.c","east");
   add_exit("/players/mo/rig/ROOMS/cwalk/r9.c","south");
   add_item("meter","A pressure meter monitoring the well.\n");
   add_item("casing","Sheet metal covering pipes.\n");
}
