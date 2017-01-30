#include <ansi.h>
inherit "obj/armor";
reset(arg){
  if(arg) return;
    ::reset();
set_ac(2); /* eh .. boost it */
set_value(250);
set_weight(1);
set_name("gloves");
set_short("A Pair of " + HIW + "White" + NORM + " Gloves");
set_alias("white gloves");
set_long("These are the 3 fingered gloves of nightcrawler.  Seeing how he had\n"+
"pretty big fingers, you could probably fit more than one finger in them.\n");
set_type("gloves");
}
