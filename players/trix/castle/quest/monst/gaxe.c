#include "/players/feldegast/closed/ansi.h"
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("axe");
   set_alt_name("golden axe");
   set_alias("axe");
  set_short(HIY+"A golden axe"+NORM);
   set_long("A huge axe made of gold, it could be valuable, but it's not the best weapon\n"+
            "around.\n");
   set_class(18); /* From wc10 to wc18 for thematic reasons...I can't imagine why somebody would make a platinum record wc18, and a golden axe wc10.  -Feldegast 9-23-00 */
   set_weight(3);
   set_value(400);
}
