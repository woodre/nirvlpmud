#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
"     Feelings of dizziness and confusion descend upon the depths of\n"+
"your mind as you wander aimlessly among the swamp's creeping\n"+
"murkiness and noncomplacent vegetation that sprouts among all sides\n"+
"of your form.  You can barely see in any direction because of the fog.\n");
   add_item("vegetation","Lush vegetation and foresting");
   add_item("foresting","Lush vegetation and foresting");
   add_item("fog","It is thick");
   add_smell("main","You smell the waters");
   add_exit(ROOMS+"s3","west");
   add_exit(ROOMS+"s13","northeast");
   add_exit(ROOMS+"s11","southwest");
   add_exit(ROOMS+"s38","south");
}
