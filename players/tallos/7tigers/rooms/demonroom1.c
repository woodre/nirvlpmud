#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";
reset(arg) {
  if(arg) return; 
short_desc = HIY+"7 Tigers Inn"+NORM+": "+HIR+"DEMON"+NORM+""+HIB+" Room 1"+NORM;
long_desc = "    "+HIR+"This is a strange and dark place. It simply is a large\n"+
                  ""+NORM+""+RED+"dirt room"+HIR+" with a "+BLK+"hole"+HIR+" you may go up from. Unusal place for\n"+
                  "a guest of the hotel to stay.\n"+
                  "     A hole \""+NORM+"Up"+HIR+"\""+NORM+"\n";
    add_object("/players/tallos/7tigers/mobs/bonedevil2.c");
    add_object("/players/tallos/7tigers/mobs/succubus1.c"); 
    add_item("room","The room is large made of hard red rock with a dirt floor.");
    add_item("rock","It is hot to the touch and seems to bleed.");
    add_item("blood","It is dripping from the walls as if they were bleeding.");
    add_smell("main","The smell of burning sulfer is heavy in the air.");
    add_listen("main","As you listen closely you can hear the sounds of people yelling out\n"+
                      "in pain.");    
    add_item("hole","It seems to travel somewhere else.");
                      
set_light(0);
}
init() {
  ::init();
  add_action("up","up");
}
up() {
  string str2;
  str2= PATH+"/demonhall.c";
  move_object(this_player(), PATH+"/demonhall.c");
  command("look",this_player());
  return 1;
}
