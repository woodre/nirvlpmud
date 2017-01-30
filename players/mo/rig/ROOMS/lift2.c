inherit "/players/vertebraker/closed/std/room.c";
#include <ansi.h>

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Chinle Oil Platform - Lift #2");
   set_long(
      
      "                    "+BOLD+"Lift #2\n"+
      ""+NORM+" "+HIB+"oooooooooooooooooooooooooooooooooooooooooooooooooooo"+NORM+""+BOLD+" \n"+
      "|                                            "+BWHT+"()Lift()"+NORM+""+BOLD+"| X = You \n"+
      "|    "+NORM+"_||_            _||_            _||_"+BOLD+"            | P = Launchpad \n"+
      "|   "+NORM+"(WWWW)          (WWWW)          (WWWW)"+BOLD+"           | W = Oil Well \n"+
      "|  "+NORM+"(W    W)        (W    W)        (W    W)"+BOLD+"          |\n"+
      "|   "+NORM+"(WWWW)          (WWWW)          (WWWW)"+BOLD+"           |\n"+
      "|                                                    |\n"+
      "|                                                    |\n"+
      "|                                                    |\n"+
      "|                                     ___________    |\n"+
      "|                                    |           |   |\n"+
      "|    "+NORM+"_||_"+BOLD+"                            | Cafeteria |   |\n"+
      "|   "+NORM+"(WWWW)"+BOLD+"               __          |___________|   |\n"+
      "|  "+NORM+"(W    W)"+BOLD+"             <  >                         |\n"+
      "|   "+NORM+"(WWWW)"+BOLD+"           __<    >__                      |\n"+
      "|                   |  "+NORM+""+BBLU+"Control"+NORM+""+BOLD+" |             ()Lift()|\n"+
      "|                   |  "+NORM+""+BBLU+"Center"+NORM+""+BOLD+"  |                     |\n"+
      "|                   |__      __|            _________|\n"+
      "|    "+NORM+"_||_"+BOLD+"              |    |              |"+NORM+""+RED+"PPPPPPPPP"+NORM+""+BOLD+"|\n"+
      "|   "+NORM+"(WWWW)"+BOLD+"             |    |              |"+NORM+""+RED+"P"+NORM+"PP   PP"+RED+"P"+NORM+""+BOLD+"|\n"+
      "|  "+NORM+"(W    W)"+BOLD+"            |    |              |"+NORM+""+RED+"P"+NORM+"P"+RED+"P"+NORM+"   "+RED+"P"+NORM+"P"+RED+"P"+NORM+""+BOLD+"|\n"+
      "|   "+NORM+"(WWWW)"+BOLD+"             |    |              |"+NORM+""+RED+"P"+NORM+"PP   PP"+RED+"P"+NORM+""+BOLD+"|\n"+
      "|                      |    |              |"+NORM+""+RED+"PPPPPPPPP"+NORM+""+BOLD+"|\n"+
      ""+NORM+""+HIB+" oooooooooooooooooooooooooooooooooooooooooooooooooooo"+NORM+""+BOLD+" \n"+
      "                   "+NORM+" Chinle Oil Platform \n");
   add_exit("/players/mo/rig/ROOMS/w5ent.c","west");
   add_exit("/players/mo/rig/ROOMS/d16.c","south");
   add_exit("/players/mo/rig/ROOMS/cwalk/r1.c","up");
   
   
}
