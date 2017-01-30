#include "../define.h"
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_short("A dark cavern");
   set_long(
"    The cavern ends here, in a solid granite wall that blocks any \n"+
"exit through this side.  A curious amount of black dirt has been\n"+
"arranged in a powdered circle, tracing out some sort of symbol.\n"+
"An especially thick black rock seems to have some sort of a\n"+
"curvature to it, as if someone was standing or sitting upon it.\n");
   add_item(({"wall","granite wall"}),
      "The thick granite wall has a few deep scratches on the\n"+
      " side of it");
   add_item("scratches",
      "The deep scratches were formed by claw marks, possibly . . ");
   add_item(({"black rock","rock"}),
      "The thick black rock has a small curvature in the center,\n"+
      " as if someone HEAVY was sitting upon it");
   add_item(({"dirt","circle","symbol"}),
      "The dirt has been arranged in a circle around a three\n"+
      " pronged symbol, the center of which has a strange eye");
   add_item("eye","The eye looks perfectly formed, but the pupil is missing");
   add_exit(ROOMS+"c1","west");
}
