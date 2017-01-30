inherit "/players/vertebraker/closed/std/room.c";
#include <ansi.h>
string str;
int cost;
object item;
reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Launchpad before Sea of Hirandea");
   set_long(
      ""+NORM+""+BLU+" ~~~~~~~~~~~~~~~~~~"+NORM+""+GRN+"###################"+NORM+""+BLU+"~~~~~~~~~~~~~~~\n"+
      ""+NORM+""+BLU+" ~~~~~~~~~~~~~~~~~~~~"+NORM+""+GRN+"####################"+NORM+""+BLU+"~~~~~~~~~~~~\n"+
      ""+NORM+""+BLU+" ~~~~~~~~~~~~"+NORM+""+GRN+"################################"+NORM+""+BLU+"~~~~~~~~\n"+
      ""+NORM+""+BLU+" ~~~~~~~"+NORM+""+GRN+"#########################################"+NORM+""+BLU+"~~~~\n"+
      ""+NORM+""+BLU+" ~~~~~~~"+NORM+""+GRN+"#########################################"+NORM+""+BLU+"~~~~\n"+
      ""+NORM+""+BLU+" ~~~~~"+NORM+""+GRN+"##############################################"+NORM+""+BLU+"~\n"+
      " "+BLU+"~~~~~"+NORM+""+GRN+"#################|"+NORM+""+RED+"PPPPPPPPP"+NORM+""+BOLD+"|"+NORM+""+GRN+"####################\n"+
      " "+BLU+"~~~~~"+NORM+""+GRN+"#################|"+NORM+""+RED+"P"+NORM+"PP   PP"+RED+"P"+NORM+""+BOLD+"|"+NORM+""+GRN+"####################\n"+
      " "+BLU+"~~~~~"+NORM+""+GRN+"#################|"+NORM+""+RED+"P"+NORM+"P"+RED+"P"+NORM+"   "+RED+"P"+NORM+"P"+RED+"P"+NORM+""+BOLD+"|"+NORM+""+GRN+"####################\n"+
      " "+BLU+"~~~~~"+NORM+""+GRN+"#################|"+NORM+""+RED+"P"+NORM+"PP   PP"+RED+"P"+NORM+""+BOLD+"|"+NORM+""+GRN+"####################\n"+
      " "+BLU+"~~~~~"+NORM+""+GRN+"#################|"+NORM+""+RED+"PPPPPPPPP"+NORM+""+BOLD+"|"+NORM+""+GRN+"####################"+NORM+"\n");
   
   add_exit("/players/mo/rig/ROOMS/sea/r2.c","north");
   add_object("/players/mo/rig/MON/pilot.c");
   add_property("NF");
}
query_launch_pad() { return 1; }

/* Note: I modified copter.c slightly - added a query_copter() flag accessor. */
   /* I could have used the pre-existing query_launcher(), but that seemed strange. */

/* i thought about it, and this is a "better" solution to blocking the exit
with another function. essentially, move() is an inherited function from
/room/room.
*/

status move(string str)
{
   if(query_verb()=="north")  /* exit to be modified */
      {
      
      /* this next bit is bizarre functionality, due to the nature of the
      Heli-Tractor.
      
      Basically, the Tractor is for all intents and purposes for this project,
      an "NPC".  Meaning it has some detectable life signs to the driver.
         This may seem strange, but the nature of the tractor using "catch_tell"
      to parse messages to the passengers in the tractor flags the tractor as
      a "living" object.
      
      Because of this, and the usage of command() to drive the tractor in
      different directions, this_player() that is last referenced before this
         function is the Tractor.... So you have to check whether the "player"
      who gave the last "command()" is a chopper, or something else (pet,
            mudkid, tractor, Hoth monster, player, etc).
      
      If TP != COPTER, block exit */
      
      if(!this_player()->query_copter()) 
         {
         write(
            "You can't go north.\n\n"+
            "Ahnuld telepaths: GET TO THE CHOPPA!\n");
         return 1;
      }
   }
   
   
   /* Allow all exit functionality other than that specific case. */
      return ::move(str);
}
init() {
   ::init();
   add_action("fly_in","fly_in");
   add_action("land_ing","land_ing");
   add_action("rent","rent");
   
}

rent(string str) {
   
   object helicopter;
   object pilot;
   
   helicopter = present("helicopter",this_object());
   pilot = present("pilot",this_object());
   
   if(!str) {
      write("Rent what?\n");
      return 1; }
   if(!pilot) {
      write("There's no pilot to rent a Helicopter from.\n");
      return 1; }
   
   if(helicopter) {
      
      write("Only one helicopter can be on a platform at a time.\n");
      return 1; }
   if(str != "helicopter") {
      write("They don't rent that here.\n");
      return 1; }
   write("The Pilot tells you: I'll be right back!\n");
   say("the Pilot leaves...\n");
   call_out("fly_in", 12);
   destruct(pilot);
   return 1; }



fly_in() {
   
   say("A helicopter flies in...\n");
   move_object(clone_object("/players/mo/rig/OBJ/hover.c"),this_object());
   call_out("land_ing", 5);
   return 1; }

land_ing() {
   
   object hover;
   
   say(
      "A helicopter lands on the platform...\n"+
      "A pilot climbs down the ladder of the helicopter.\n");
   move_object(clone_object("/players/mo/rig/OBJ/copter.c"),this_object());
   move_object(clone_object("/players/mo/rig/MON/pilot.c"),this_object());
destruct(present("hover"),this_object());
}
query_hirandea() { return 1; }
