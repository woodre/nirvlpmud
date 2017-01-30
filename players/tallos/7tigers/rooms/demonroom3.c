#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";
reset(arg) {
  if(arg) return;
short_desc = HIY+"7 Tigers Inn"+NORM+": "+HIR+"DEMON"+NORM+""+HIB+" Room 3"+NORM;
long_desc = ""+HIR+"This is a much better "+HIB+"room"+HIR+" then the others in this area. It\n"+
            "is still made of "+NORM+""+RED+"red rock"+HIR+" and dirt, there is also a "+HIM+"bed"+HIR+" and\n"+
            "a large "+NORM+""+RED+"chair"+HIR+" at a "+BLK+"table"+HIR+" with a spread of raw humanoid "+NORM+""+RED+"meat"+HIR+"\n"+
            "on it. This is certainly different from all the other rooms\n"+
            "in the hotel.\n"+
            "     A hole \""+NORM+"Down"+HIR+"\""+NORM+"\n";
    add_object("/players/tallos/7tigers/mobs/balor1.c");
    add_item("room","The room is large made of hard red rock with a dirt floor.");
    add_item("rock","It is hot to the touch and seems to bleed.");
    add_item("blood","It is dripping from the walls as if they were bleeding.");
    add_smell("main","The smell of burning sulfer is heavy in the air.");
    add_listen("main","As you listen closely you can hear the sounds of people yelling out\n"+
                      "in pain.");    
    add_item("chair","This is a large red velvet chair set in front of the table.");
    add_item("table","It is made of oak and has a large mass of raw meat upon it.");
    add_item("meat","It's the main torso of a humanoid creature. It's impossible to tell\n"+
                    "what type of creature it originally was.");
    add_item("hole","It seems to travel somewhere else.");
    add_item("dirt","Red soil that has been packed down.");
    add_item("bed","It is very large and has several soft pillows on it.");    
set_light(0);
}
init() {
  ::init();
  add_action("down","down");
}
down() {
  string str2;
  str2= PATH+"/demonhall.c";
  move_object(this_player(), PATH+"/demonhall.c");
  command("look",this_player());
  return 1;
}
