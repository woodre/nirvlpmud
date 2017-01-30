#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";

reset(arg){
  if(arg) return;

short_desc = HIY+"7 Tigers Inn"+NORM+":"+HIC+" Backroom"+NORM;
long_desc = "   "+HIR+"This is an employee "+HIB+"area"+HIR+" of the "+HIY+"7 Tigers Inn"+HIR+". It\n"+
            "doesn't look like you are to be in here.   There is\n"+
            "a large "+NORM+""+YEL+"wooden table"+HIR+" with several "+NORM+""+YEL+"chairs"+HIR+" around it.\n"+
            "Most likely this is an "+HIB+"employee's"+HIR+" breakroom."+NORM+"\n";
   add_object("/players/tallos/7tigers/mobs/hotelsec2.c", 1); 
   add_smell("main","The wonderful smell of roses is in the air");
   add_smell("roses","The whole hall seems to produce this wonderful odor");
   add_listen("main","You hear the sound of the Inn staff moving about performing tasks.");
   add_item("area","This is a backroom which only employees are allowed.");
   add_listen("staff","You hear them moving about quickly performing their tasks for th Inn.");
   add_item("employees","They move about quickly doing their assigned tasks.");
   add_item("west","A panel to the west looks like it might be a door built into the wall");
   add_item("table","A small oak table with severel chairs around it");
   add_item("chairs","They are made of oak and set around the table");
   

dest_dir = ({
    PATH+"/backroom.c","west",
  });
set_light(1);
}
