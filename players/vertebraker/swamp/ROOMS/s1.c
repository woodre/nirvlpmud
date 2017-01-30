#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg); 
   set_long(
"     Tangled vines and twisted cypress trees wrap in many directions,\n"+
"turning around the many sides of the bog, full of life.  You smell\n"+
"the stench of the swampwaters around you, and a thick fog enfolds\n"+
"the area.  A rickety sign stands to your left, and a small hole in\n"+
"the ground rests to your right.\n");
   add_item("sign",
      "You can only read the sign");
   add_smell("main","You smell the swamp waters.");
   add_listen("main","You do not hear anything.");
   add_touch("vines","It feels cold and strong");
   add_item("vines","Dark green, twisted vines");
   add_item("hole",
      "A small, dank hole that you could \"descend\" if you wished");
   add_item("trees","Large trees that are full of life and soaked with moisture");
   add_smell("stench","You smell the swamp waters");
   add_item("fog","You can't see through it");
   add_item("bog","The murky waters slosh over your skin");
   add_exit(ROOMS+"s2","north");
   add_exit(ROOMS+"s3","east");
   add_exit(ROOMS+"s4","west");
   add_object(OBJ_DIR+"campfire");
   add_object(NPC_DIR+"swamp_guard");
   if(!random(3)) add_object(NPC_DIR+"swamp_guard");
}

init() {
   ::init();
   add_action("read","read");
   add_action("descend","enter");
   add_action("descend","descend"); }

descend(str) {
   if(str == "hole") {
      write("You descend into the dark hole...\n");
      TP->move_player("down into the hole#"+VILLAGE+"tun2");
      return 1; }
}

read(str) {
   if(str == "sign" || str == "the sign") {
      write("         WARNING!\n"+
         "Swamp closed by order of Juribel, 8-2000.\n");
      return 1; }
}

void
long(string str)
{
    if(str == "sign" || str == "the sign")
    {
      command("read the sign", this_player());
      return;
    }
    else ::long(str);
}
