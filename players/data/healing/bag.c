/* bag.c
 *
 * 8/14/14 - Data
 *
 * This is the bag for my area, its got various uses
 *
*/
inherit "obj/bag.c";
object obj;
#include <ansi.h>
#include "/players/data/healing/defs.h"
#include "/players/data/healing/bag/save.c"



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

init(){
	::init();
	restore_object(SAVE_PATH+TP);
	
}
