/* Sliph.c
 *
 * 3/20/06 - Data
 *
 * This is the bag for my area, its got various uses
 *
*/
#include <ansi.h>
#include "/players/data/defs.h"
inherit "obj/treasure";


 reset(arg)
{   if (arg) return; 
   set_id("pack");
   set_short("a Magical Pack");
   set_long("The silver Sliph appears to be made out of living quicksilver.\n"+
      "She stretches out of her well yet seems connected to it. Long ago\n"+
      "she was a very exclusive prostitute, but the wizards of old had a\n"+
      "far more of a use for her, and so used their magic powers to turn\n"+
	  "her into the Silver Sliph. She never betrays her clients."+NORM+"\n");
   
}

can_put_and_get() { return 1; }

prevent_insert() {
    if (local_weight > 0) {
        write("You can't when there are things in the bag.\n");
        return 1;
    }
    return 0;
}
