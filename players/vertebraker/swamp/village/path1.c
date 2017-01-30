#include "../define.h"

inherit ROOM;
reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A village pathway");
   set_long(
"     Emerging from the darkened forest to the north is a stone-laid\n"+
"path.  To the southeast you can see a small hut and a small village.\n"+
"The wind whistles through the trees slowly and softly.\n");
   add_item("path","The stone laid path continues to the southeast");
   add_item("guards","A few guards roam around the village,\n"+
      " appearing to be hunting for something ..");
   add_item("grounds","The immediate area is a small field that seems\n"+
      "clear from the dank, dark forest north");
   add_exit(FOREST+"end","north");
   set_chance(5);
   add_msg("A guard roams around the town.");
   add_msg("A guard calls out, \"ceEeLliAAAA!!!!\"");
   add_exit(VILLAGE+"path2","southeast");
   add_object(NPC_DIR+"guard");
   if(random(2)) add_object(NPC_DIR+"guard"); }
