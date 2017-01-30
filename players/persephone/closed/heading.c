inherit "obj/treasure";
#include "/players/persephone/rooms.h"
reset (int arg){
 if(!arg){
  set_id("jeny's head");
  set_alias("head");
  set_short("A Woman's Head");
  set_long("The head of a gorgeous woman that looks like it has\n" +
           "been chopped off by a hook.  Perhaps this is the missing\n" +
           "pirates head\n\n");
  set_weight(2);
  set_value(10);
 }
}
