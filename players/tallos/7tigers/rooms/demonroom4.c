#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";
reset(arg) {
  if(arg) return; 
short_desc = HIY+"7 Tigers Inn"+NORM+": "+HIR+"DEMON"+NORM+""+HIB+" Room 4"+NORM;
long_desc = "      "+HIR+"This is a strange and dark place. It simply is a large\n"+
                  "dirt room with several small creatures in it.   Unusal place\n"+
                  "for a guest of the hotel to stay. There is a large "+BLK+"black"+HIR+" and\n"+
                  ""+NORM+"white"+HIR+" swirling "+NORM+"p"+HIY+""+BLK+"o"+NORM+"r"+HIY+""+BLK+"t"+NORM+"a"+HIY+""+BLK+"l"+HIR+" in one of the walls."+NORM+"\n";
    add_object("/players/tallos/7tigers/mobs/babau.c"); 
    add_object("/players/tallos/7tigers/mobs/quasit.c",4);
   
    add_item("room","The room is large made of hard red rock with a dirt floor.");
    add_item("rock","It is hot to the touch and seems to bleed.");
    add_item("blood","It is dripping from the walls as if they were bleeding.");
    add_smell("main","The smell of burning sulfer is heavy in the air.");
    add_listen("main","As you listen closely you can hear the sounds of people yelling out\n"+
                      "in pain.");
    add_item("portal","It swirls with darkness and light. Perhaps you could follow the\n"+
                      "light 'out' or go further 'in' the darkness of the portal.");
    add_item("walls","made of red rock, they seem to bleed.");
    add_item("blood","It seems to bleed from the walls. Very creepy.");

set_light(0);
}
init() {
  ::init();
  add_action("out","out");
  add_action("in","in");
}
out() {
  string str2;
  str2= PATH+"/demonhall.c";
  move_object(this_player(), PATH+"/demonhall.c");
  command("look",this_player());
  return 1;
}
in() {
  string str3;
  str3= PATH+"/demonroom5.c";
  move_object(this_player(), PATH+"/demonroom5.c");
  command("look",this_player());
  return 1;
}