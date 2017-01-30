#include "/players/puppy/define.h"
inherit "obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("quill");
   set_short("A quill");
   set_long(
      "A quill used for writing down thoughts and ideas.\n");
   set_weight(1);
   set_value(25);
}
