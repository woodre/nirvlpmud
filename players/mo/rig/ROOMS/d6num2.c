#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Chinle Oil Platform - SW");
   set_long(
      
      "                    "+BOLD+"SW Chinle Oil Platform\n"+
      ""+NORM+" "+HIB+"oooooooooooooooooooooooooooooooooooooooooooooooooooo"+NORM+""+BOLD+" \n"+
      "|                                            ()Lift()| X = You \n"+
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
      "|  "+NORM+"(W    W)"+BOLD+"  "+BWHT+"X"+NORM+""+BOLD+"          <  >                         |\n"+
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
   add_exit("/players/mo/rig/ROOMS/d8.c","north");
   add_exit("/players/mo/rig/ROOMS/cmdentnorth.c","east");
   add_exit("/players/mo/rig/ROOMS/d6.c","south");
   
}
