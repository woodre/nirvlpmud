#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
#define PATH2 "/players/tallos/7tigers/rooms/cavernsoftime"
inherit "/players/fred/closed/std/room";
reset(arg) {
  if(arg) return;
short_desc = HIY+"An "+WHT+"Underground "+HIB+"Chamber "+HIR+"\("+NORM+""+BLU+"Damp"+HIR+"\)"+NORM;
long_desc =       "    You wander into the cave and find unique patterns taking\n"+
                  "shape on the rock surface. The pattern shits and colors spin\n"+
                  "all around you. You seem to have stepped through into an odd\n"+
                  "maze of sorts. An old man resides here. He seems very out of\n"+
                  "place. He seems to have some sort of a map for you. Grasping\n"+
                  "the map in one hand he points deeper into the dungeon simply\n"+
                  "smiling. You take the map and examine it.  There seems to be\n"+
                  "a glowing yellow mark on the map that represents you?!?   As\n"+
                  "you look up to ask the man a question,  you find that he has\n"+
                  "vanished, how odd?\n"+
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
                  "    I_"+HIY+"u"+HIB+"____I                                  \n"+
                  "       "+NORM+""+NORM+"                                   \n"+
                  " "+NORM+"\n"+
                  "     "+HIB+"A Passage leads "+HIR+"\""+HIB+"EAST"+HIR+"\" and "+HIR+"\""+HIB+"WEST"+HIR+"\""+NORM+"\n";
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
  str2= PATH2+"/cavernsoftime2.c";
  move_object(this_player(), PATH2+"/cavernsoftime2.c");
  command("look",this_player());
  return 1;
}
west() {
  string str3;
  str3= PATH2+"/waterroom1.c";
  move_object(this_player(), PATH2+"/waterroom1.c");
  command("look",this_player());
  return 1;
}