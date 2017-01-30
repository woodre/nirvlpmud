#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
      "     Green, leafy indigenous plants surround you on several sides.\n"
      +"Unfortunately the undergrowth is so viscous in those directions that\n"
      +"you can't continue traveling in them, no matter how hard you may\n"
      +"hack and slash your way through the foliage.  A lining of brown\n"
      +"stones lines a path around the plants.\n");
   add_item(({"plants","foliage"}),"Dark, green leafy varieties of plants surround\n you on several sides of the swamp here");
   add_item("undergrowth","Plants and cypress trees");
   add_item("trees","The trees wrap around along the path in\nseveral directions");
   add_item("directions","The path wraps around to the southwest and west directions");
   add_item("path","A roughly cut path with several stones marking the way");
   add_item("stones","Tiny brown stones that were placed here as markings");
   add_exit(ROOMS+"s1","east");
   add_exit(ROOMS+"s20","west");
   add_exit(ROOMS+"s9","southwest");
   add_touch("plants","You feel a cool, smooth texture");
   add_taste("plants","You taste leaves and detect a hint of rosemary?");
}
