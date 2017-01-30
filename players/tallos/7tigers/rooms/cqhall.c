#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";
reset(arg) {
  if(arg) return;

short_desc = HIY+"7 Tigers Inn"+NORM+":"+HIC+" C"+HIB+"e"+HIC+"l"+HIB+"e"+HIC+"s"+HIB+"t"+HIC+"i"+HIB+"a"+HIC+"l Quarters"+NORM;
long_desc = "     "+HIC+"You reach out and enter the "+HIB+"a"+HIM+"n"+HIB+"g"+HIM+"e"+HIB+"l"+HIM+"s"+HIC+" arms. She flys\n"+
            "up into the "+HIR+"m"+HIY+"u"+HIG+"r"+HIB+"a"+HIC+"l"+HIC+" and sets you down inside it. You are\n"+
            "in another part of the hotel now, for sure.  Beautiful\n"+
            ""+HIB+"p"+HIG+"a"+HIR+"i"+HIB+"n"+HIG+"t"+HIR+"i"+HIB+"n"+HIG+"g"+HIR+"s"+HIC+" and soft colors lift your heart with joy and\n"+
            "happiness. There are 3 large "+HIB+"swirling"+HIC+" "+HIM+"p"+HIB+"o"+HIG+"r"+HIM+"t"+HIB+"a"+HIG+"l"+HIM+"s"+HIC+" here.\n"+
            "    "+HIG+"Portal \"east\"   "+HIB+"Portal \"west\"   "+HIM+"Portal \"leave\""+NORM+"\n";
  add_item("paintings","A wonderful seletion of paintings from artists all over the multiverse");
  add_item("inn","The 7 Tigers Inn is one of the most famous hotels in all of the Forgotten\n"+
                 "Realms.  It links itself to many different planes and appears there as it\n"+
                 "does here"); 
  add_item("angel","She has flown back throw the portal from which you came.");
  add_item("mural",
  "The large ceiling lays acres of stone canvas for several scenes displaying\n"+
  "a multitude of different planes and dimensions of existence.  Here you can\n"+
  "see a large "+HIC+"a"+NORM+"n"+HIC+"g"+NORM+"e"+HIC+"l"+NORM+" with it's wings stretched wide. It's arms are open as if\n"+
  "to welcome you into them.");
  add_item("hotel","The 7 Tigers Inn, the greatest hotel in the all the planes!");
  add_item("paintings",
  "A wonderful seletion of paintings from artists all over the multiverse");
  add_item("portals","These multicolored sparkling portals are the only exits to the room.");
  add_smell("main","the smell of sweet lavender. Its very pleasing to the senses.");

  
set_light(1);
}
init() {
  ::init();
  add_action("east","east");
  add_action("west","west");
  add_action("leave","leave");
}
east() {
  string str3;
  str3= PATH+"/cqhall2.c";
  move_object(this_player(), PATH+"/cqhall2.c");
  command("look",this_player());
  return 1;
}
west() {
  string str2;
  str2= PATH+"/cqhall3.c";
  move_object(this_player(), PATH+"/cqhall3.c");
  command("look",this_player());
  return 1;
}
leave() {
  string str;
  str= PATH+"/3ftopstairs.c";
  move_object(this_player(), PATH+"/3ftopstairs.c");
  command("look",this_player());
  return 1;
}