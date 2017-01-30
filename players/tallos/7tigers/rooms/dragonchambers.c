#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";
reset(arg) {
  if(arg) return;
short_desc = HIY+"7 Tigers Inn"+NORM+": "+HIR+"DRAGON'S"+NORM+""+HIB+" Chamber"+NORM;
long_desc =       "       "+HIM+"This a huge chamber with a glowing "+HIB+"blue portal"+HIM+" behind\n"+
                  "you. There is a large dragon "+HIY+"horde"+HIM+" of "+HIY+"treasure"+HIM+" in the center\n"+
                  "of the room. A huge "+NORM+""+YEL+"dragon"+HIM+" sits atop the "+HIY+"horde"+HIM+".  The room is\n"+
                  "made of large "+HIB+"crystal"+HIM+" formations, and has a "+NORM+""+BLU+"pool of water"+HIM+" to\n"+
                  "one side."+NORM+"\n"+
                  "     "+HIB+"A Portal \""+NORM+"OUT"+HIR+"\""+NORM+"\n";
    add_object("/players/tallos/7tigers/mobs/golddragon1.c");
    add_item("portal","It glows "+HIB+"blue"+NORM+" and pulses behind you. You think you could go 'out' through it.");
    add_item("horde","thousands of "+HIY+"gold pieces"+NORM+" sit in a mound in the center of the room.");
    add_item("mound","A dragons horde of teasure no doubt, complete with the dragon atop it.");
    add_item("treasure","Several thousand gold pieces you estimate, by the looks of it.");
    add_item("crystal","Like many other others in the room it vibrates with energy.");
    add_item("crystals","The room is full of them. The very room seems to be formed entirely of these\n"+
                        "vibrating crystals.");
    add_item("pool","It is very clear and deep by the looks of it. You can see white cave fish swimming\n"+
                    "in its depths.");
    add_item("fish","White in color, they swim in great numbers in the pool of clear water.");
    add_item("water","Its clear and fresh. It makes quite a large pool to one side of the chamber. There\n"+
                     "are fish that swim about in it.");
    add_smell("main","It smells of brimstone and granite in this chamber.");
    add_smell("brimstone","Coming from the dragon nodoubt.");
    add_listen("main","You hear the heavy breathing of the colossal size gold dragon atop his horde.");
     
set_light(1);
}
init() {
  ::init();
  add_action("out","out");
}
out() {
  string str2;
  str2= PATH+"/balcony.c";
  move_object(this_player(), PATH+"/balcony.c");
  ::exit(this_player());    /* Rumplemintz - 10/26/2007 */
  command("look",this_player());
  return 1;
}
