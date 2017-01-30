inherit "/players/vertebraker/closed/std/room.c";
#include <ansi.h>
int onitsway;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Launchpad on a fixed-platform oil rig");
   set_long(
      
      "                    "+BOLD+"Launchpad\n"+
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
      "|  "+NORM+"(W    W)"+BOLD+"             <  >                         |\n"+
      "|   "+NORM+"(WWWW)"+BOLD+"           __<    >__                      |\n"+
      "|                   |  "+NORM+""+BBLU+"Control"+NORM+""+BOLD+" |             ()Lift()| A red phone is\n"+
      "|                   |  "+NORM+""+BBLU+"Center"+NORM+""+BOLD+"  |                     | attached to a pole \n"+
      "|                   |__      __|            _________| next to the platform.\n"+
      "|    "+NORM+"_||_"+BOLD+"              |    |              |"+NORM+""+RED+"PPPPPPPPP"+NORM+""+BOLD+"|\n"+
      "|   "+NORM+"(WWWW)"+BOLD+"             |    |              |"+NORM+""+RED+"P"+NORM+"PP   PP"+RED+"P"+NORM+""+BOLD+"|\n"+
      "|  "+NORM+"(W    W)"+BOLD+"            |    |              |"+NORM+""+RED+"P"+NORM+"P"+RED+"P"+NORM+""+BWHT+""+BLK+" X "+NORM+""+RED+"P"+NORM+"P"+RED+"P"+NORM+""+BOLD+"|\n"+
      "|   "+NORM+"(WWWW)"+BOLD+"             |    |              |"+NORM+""+RED+"P"+NORM+"PP   PP"+RED+"P"+NORM+""+BOLD+"|\n"+
      "|                      |    |              |"+NORM+""+RED+"PPPPPPPPP"+NORM+""+BOLD+"|\n"+
      ""+NORM+""+HIB+" oooooooooooooooooooooooooooooooooooooooooooooooooooo"+NORM+""+BOLD+" \n"+
      "                   "+NORM+" Chinle Oil Platform \n");
   
   add_exit("/players/mo/rig/ROOMS/d1.c","west");
   add_exit("/players/mo/rig/ROOMS/lift1.c","north");
   add_exit("/players/mo/rig/ROOMS/sea/r7.c","south");
   add_object("/players/mo/rig/MON/pilot_oil.c");
   add_property("NF");
   add_item("phone","A device used to talk to folks on land. Perhaps you\n"+
      "could "+BOLD+"call"+NORM+" for a "+BOLD+"helicopter"+NORM+".\n");
   add_item("pole","A flag-pole with a phone attached to it.\n");
}
query_launch_pad() { return 1; }
status move(string str)
{
   if(query_verb()=="south")
      {
      
      if(!this_player()->query_copter()) 
         {
         write(
            "You can't go south.\n\n"+
            "Ahnuld telepaths: GET TO THE CHOPPA!\n");
         return 1;
      }
   }
   if(query_verb()=="west")
      {
      
      if(this_player()->query_copter()) {
         write("No fly zone.\n");
         return 1;
      }
      
   }
   if(query_verb()=="north")
      {
      
      if(this_player()->query_copter()) {
         write("No fly zone.\n");
         return 1;
      }
   onitsway = 0;
      
   }
   
   
   return ::move(str);
}

init() {
   ::init();
   add_action("fly_in","fly_in");
   add_action("land_ing","land_ing");
   add_action("call_me","call");
   add_action("we_are_talking","we_are_talking");
   add_action("other_pilot","other_pilot");
}

call_me(string str) {
   
   object helicopter;
   object pilot;
   
   helicopter = present("helicopter",this_object());
   pilot = present("pilot",this_object());
   
   if(!str) {
      
      write(""+BOLD+"Call"+NORM+" for "+BOLD+"what?"+NORM+"\n");
      
      return 1; }
   
   if(helicopter) {
      
      write("No need to call, a helicopter is already here.\n");
      
      return 1; }
   

   if(onitsway) {


   write("Settle the fuck down.  It's coming.\n");

   return 1; }

   if(str != "for helicopter") {
      
      write("What?\n");
      
      return 1; }
   
   
   write(
      "You pick up the phone.\n"+
      "|on the other end| Be right there...\n");
   
   say(""+this_player()->query_name()+" picks up the phone and calls for a helicopter.\n");
   
   call_out("fly_in", 12);

   onitsway = 1;
   
   return 1; }


fly_in() {
   
   say("A helicopter is approaching...\n");
   
   move_object(clone_object("/players/mo/rig/OBJ/hover.c"),this_object());
   
   call_out("land_ing", 5);
   
   return 1; }

land_ing() {
   
   object hover;
   object pilot;
   
   say(
      "A helicopter lands on the platform...\n"+
      "A pilot climbs down the ladder of the helicopter.\n");
   
   destruct(present("hover",this_object()));
   
   move_object(clone_object("/players/mo/rig/OBJ/copter.c"),this_object());
   move_object(clone_object("/players/mo/rig/MON/pilot_oil.c"),this_object());

onitsway = 0;
   
   if(present("pilot",this_object())) {
      
      call_out("other_pilot", 4);
      
      return 1; }
   
   return 0;
   
}

other_pilot() {
   
   object pilot;
   
   int random_loc;
   int random_act;
   
   random_loc=random(4);
   
   say("a Pilot waves as he heads to "+({"the Cafeteria","the Command Center","the Catwalk","Well #4"})[random_loc]+" to "+({"eat some food","talk to the Head of Operations","catch some air","shoot the shit"})[random_loc]+".\n");
   
   destruct(present("pilot",this_object()));
   
   return 1; }
