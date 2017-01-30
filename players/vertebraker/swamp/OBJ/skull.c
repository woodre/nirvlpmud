#include "../define.h"
inherit ITEM;

reset(arg) {
   if(arg) return;
   set_short("A small human skull");
   set_id("skull");
   set_alias("human skull");
   set_long(
      "  This is a miniature human skull, the details are perfect,\n"+
      "and it looks absolutely real.  From the dimensions, you\n"+
      "can guess this came from a very small person, or a child...\n");
   set_weight(2);
   set_value(10);
}
