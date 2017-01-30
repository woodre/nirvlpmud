#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";

reset(arg){
  if(arg) return;

short_desc = HIY+"7 Tigers Inn"+NORM+":"+HIC+" Backroom"+NORM;
long_desc = "       "+HIR+"This is an "+HIB+"employee area"+HIR+" of the "+HIY+"7 Tigers Inn"+HIR+". It\n"+
            "doesn't look like you are to be in this area. There are\n"+
            "several "+NORM+""+CYN+"lockers"+HIR+" along the far wall and a row of "+NORM+""+YEL+"pegs"+HIR+" on\n"+
            "the opposite one. There is a "+NORM+""+YEL+"bench"+HIR+" in the center of the\n"+
            "room that runs its length."+NORM+"\n";
   add_object("/players/tallos/7tigers/mobs/hotelsec2.c", 1);            
   add_smell("main","The wonderful smell of roses is in the air");
   add_smell("roses","The whole hall seems to produce this wonderful odor");
   add_listen("main","You hear the sound of the Inn staff moving about performing tasks.");
   add_item("lockers","There are at least 10 of them with locks hanging on them. Most likely for employees");
   add_item("locks","Hanging from the doors of the lockers. They seem quite strong, and require keys.");
   add_item("bench","A long wooden bench used to sit on while changing clothes.");
   add_item("pegs","To hang employee clothes on.");
   add_item("area","This is a backroom which only employees are allowed.");
   add_listen("staff","You hear them moving about quickly performing their tasks for th Inn.");
   add_item("employees","They move about quickly doing their assigned tasks.");
   add_item("east","A panel to the east looks like it might be a door built into the wall");


dest_dir = ({
    PATH+"/backroom.c","east",
  });
set_light(1);
}
