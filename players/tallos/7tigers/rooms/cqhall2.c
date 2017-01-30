#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";
reset(arg) {
  if(arg) return;
short_desc = HIY+"7 Tigers Inn"+NORM+": "+HIC+" C"+HIB+"e"+HIC+"l"+HIB+"e"+HIC+"s"+HIB+"t"+HIC+"i"+HIB+"a"+HIC+"l Hall"+NORM;
long_desc = "  "+HIC+"This is a short "+HIY+"hallway"+HIC+" with 3 shimmering "+HIM+"p"+HIB+"o"+HIG+"r"+HIM+"t"+HIB+"a"+HIG+"l"+HIM+"s"+HIC+".\n"+
            "There is the sound of soft "+HIM+"harp music"+HIC+" in the air and\n"+
            "the smell of "+NORM+""+MAG+"lavender"+HIC+" everywhere."+NORM+"\n"+
            "    "+HIG+"Portal \"west\"   "+HIB+"Portal \"north\"   "+HIM+"Portal \"south\""+NORM+"\n";
    add_object("/players/tallos/7tigers/mobs/asimar1.c");
    add_item("portals","The are multicolored and shinning. You feel like you want to step through them.");
    add_item("hallway","Made of shimmering colors and beams of bright light.");
    add_listen("main","Beautiful harp music that changes to perfect pitch where ever you are standing.");
    add_listen("harp","Yes the sound is definately from a harp. But it comes from somewhere you cannot find.");
    add_smell("main","the smell of sweet lavender. Its very pleasing to the senses.");
    add_item("light","The walls, floors, and ceiling seems to be make of it. There are a multitude of colors.");
    add_item("colors","A the colors of the "+HIR+"r"+HIY+"a"+HIG+"i"+HIB+"n"+HIM+"b"+HIR+"o"+HIY+"w"+NORM+".");
    

set_light(2);
}
init() {
  ::init();
  add_action("west","west");
  add_action("north","north");
  add_action("south","south");
}
west() {
  string str3;
  str3= PATH+"/cqhall.c";
  move_object(this_player(), PATH+"/cqhall.c");
  command("look",this_player());
  return 1;
}
north() {
  string str2;
  str2= PATH+"/cqroom1.c";
  move_object(this_player(), PATH+"/cqroom1.c");
  command("look",this_player());
  return 1;
}
south() {
  string str;
  str= PATH+"/cqroom2.c";
  move_object(this_player(), PATH+"/cqroom2.c");
  command("look",this_player());
  return 1;
}