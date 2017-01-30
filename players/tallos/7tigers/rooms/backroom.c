#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";

reset(arg){
  if(arg) return;

short_desc = HIY+"7 Tigers Inn"+NORM+":"+HIC+" Backroom"+NORM;
long_desc = ""+HIR+"This is an employee "+HIB+"area"+HIR+" of the "+HIY+"7 Tigers Inn"+HIR+". It doesn't\n"+
            "look like you should be here.  There is an "+HIC+"office"+HIR+" to the\n"+
            "north. Several security guards block your path further."+NORM+"\n";
            
   add_object("/players/tallos/7tigers/mobs/hotelsec.c", 1);
   add_item("area","This is a backroom which only employees are allowed.");
   add_item("north","To the north is a door to an office with a sign above it.");
   add_item("sign",""+HIM+"===================================\n"+
                   "= M A N A G E R ' S   O F F I C E =\n"+
                   "==================================="+NORM+""); 
   add_item("employees","They move about quickly doing their assigned tasks.");
   add_item("office","A large office with a sign above the door.");
   add_item("east","A panel to the east looks like it might be a door built into the wall.");
   add_item("west","a panel to the west looks like it might be a door built into the wall.");
   add_smell("main","The wonderful smell of roses is in the air");
   add_smell("roses","The whole hall seems to produce this wonderful odor");
   add_listen("main","You hear the sound of the Inn staff moving about performing tasks.");
   add_listen("staff","You hear them moving about quickly performing their tasks for th Inn.");
   

dest_dir = ({
    PATH+"/mainhall.c","back",
    PATH+"/office.c","enter",
    PATH+"/backroom2.c","east",
    PATH+"/backroom3.c","west",
  });
set_light(1);
}
