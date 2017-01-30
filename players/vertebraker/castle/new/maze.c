#include "../../define.h"
#define DEST "/players/vertebraker/ed/ed/room/b3"
int c;
inherit ROOM;

short() { return "A darkened forest [many exits]"; }

reset(x) {if(!x) {
      
      set_light(1);
      items = ({
            "trees","Tall, dark trees",
            "earth","The earth has been scorched",
            "horizon","You cannot see very far, but the horizon stretches around your head",
            "leaves","Grey leaves fall to the ground...",
            "path","The trampled path wraps in many directions", });
   } }

long(str) {
if(!str)
   write(
      "     Humongous trees sprout from the blackened earth around your feet,\n"+
      "acting as tall monoliths across the darkened horizon.  Ash-colored\n"+
      "leaves float gingerly to the ground every now and then.  The tired,\n"
      +"trampled path wraps in several directions, providing you no glimpse\n"
      +"of safety in any of your exits.\n"+
      "\tYou can head in any direction.\n");
else ::long(str);
}

init() {
   ::init();
   add_action("move","north");
   add_action("move","east");
   add_action("move","south");
   add_action("move","west");
   add_action("move","northeast");
   add_action("move","northwest");
   add_action("move","southeast");
   add_action("move","southwest"); }

move() {
   string v;
   v = query_verb();
   if(v == "north" && !c) c = 1;
   if(v == "east" && c == 1) c = 2;
   if(v == "south" && c == 2) c = 3;
   if(v == "west" && c == 3) xevil();
   else xmove();
   return 1; }

xmove() {
   string v;
   v = query_verb();
   write("You trudge in the "+v+" direction.\n");
   long();
   return 1; }

xevil() {
   write("Your surroundings seem to have changed...\n");
   move_object(TP,DEST);
   command("look",TP);
   return 1; }
