#include "/players/puppy/define.h"
inherit "obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("ruler");
   set_short("A wooden ruler");
   set_long(
      "A small wooden ruler with many marks on the side of it.\n"+
      "The corners are a little worn from all the years of use, \n"+
      "but not enough to discourage use of this tool.\n");
   set_weight(1);
   set_value(25);
}
