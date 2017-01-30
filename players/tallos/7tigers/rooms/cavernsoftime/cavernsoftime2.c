#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
#define PATH2 "/players/tallos/7tigers/rooms/cavernsoftime"
inherit "/players/fred/closed/std/room";
reset(arg) {
  if(arg) return;
short_desc = HIY+"An "+WHT+"Underground "+HIB+"Chamber "+HIR+"\("+NORM+""+BLU+"Damp"+HIR+"\)"+NORM;
long_desc =       "        "+BLU+"You swim out into the water and feel the cool liquid\n"+
                  "calming your mind. Darkness creeps in and you feel the world\n"+
                  "closing in around you on all sides.  You pass out, and there\n"+
                  "is no more... "+NORM+""+HIB+"\n"+
                  "                    ______                                                \n"+
                  "                   I  ____I   __________                                                \n"+
                  "                   I I       I  ______  I                                  \n"+
                  "                   I I       I I      I I                                           \n"+
                  "                   I I_______I I      I I_________                                           \n"+
                  "                   I  _________I      I  ________@I                                           \n"+
                  "                   I I       _        I I                                           \n"+
                  "                   I I      I I       I I                                           \n"+
                  " __________________I I______I I       [_]                              \n"+
                  "I________   _______   ________I                                        \n"+
                  "         I I       I I                                  \n"+
                  "     ____I I       [_]                                      \n"+
                  "    I__"+HIY+"u"+HIB+"___I                                  \n"+
                  "       "+NORM+""+NORM+"                                   \n"+
                  "    "+HIR+"You awake deep in caverns unknown to you, nor is the way\n"+
                  "out.  The pool of water you stepped into is now nothing more\n"+
                  "then a small underground stream. The stream seems to head to\n"+
                  "the east...\n"+ 
                  "        You will need to wander to find your way back..."+NORM+"\n"+
                  "    "+HIB+"A Passage leads "+HIR+"\""+HIB+"EAST"+HIR+"\" and "+HIR+"\""+HIB+"WEST"+HIR+"\""+NORM+"\n";
    add_object("/players/tallos/7tigers/mobs/quasit.c");
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
realm() { return "NT"; }
init() {
  ::init();
  add_action("east","east");
  add_action("west","west");  
}
east() {
  string str2;
  str2= PATH2+"/cavernsoftime3.c";
  move_object(this_player(), PATH2+"/cavernsoftime3.c");
  command("look",this_player());
  return 1;
}
  west() {
  string str3;
  str3= PATH2+"/cavernsoftime1.c";
  move_object(this_player(), PATH2+"/cavernsoftime1.c");
  command("look",this_player());  
  return 1;
}
