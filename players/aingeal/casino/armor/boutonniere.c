/* Wayne Newton's boutonniere  */

inherit"obj/armor";
#include "/players/aingeal/ansi.h"

reset(arg) {
   ::reset(arg);
   if(arg) return;

   set_name("boutonniere");
   set_alias("rose");
   set_short("A "+RED+"blood-red "+NORM+"boutonniere");
   set_long("Wayne Newton's boutonniere is a single blood-red rose with a\n"+
	"tiny spray of baby's breath that attaches with a viscious looking\n"+
	"straight pin.\n");
   set_weight(1);
   set_value(1100);
   set_ac(3);
   set_type("misc");
   }
