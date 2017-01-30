#include "../define.h"
inherit ROOM;
reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Atop a cliff");
   set_long(
"     You stand on the edge of a rocky cliff, the swamplands extend\n"+
" for miles in front of you.  You can see different birds fluttering\n"+
"away around you in several places, and tiny forms of animal life\n"+
"chitter below you.  A mist rises sharply to the west and falls\n"+
"in rhythm with your heart's beat.\n");
   add_item("swamplands","They extend for miles in front of you, you spot\nmany species of plants and animals");
   add_item("birds","Mostly some sort of osprey flock around your head");
   add_item("osprey","An omnivorous bird that flaps its small wings\ngallantly around the swamp");
   add_item("forms","You can make out the rising shape of a alligator before it descends\nbeneath the murky depths");
   add_item("mist","A cloudy mist rises and wraps itself around the swamp to the west, and\nthen suddenly dissipates");
   add_exit(ROOMS+"s41","down");
   add_object(OBJ_DIR+"flame");
}

