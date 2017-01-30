#include "/players/pestilence/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("letter");
  set_alias("letter");
  set_short("A letter");
set_long(
"A letter addressed to Blue and Steve.  It would be illegal to open their mail.\n");
  set_value(100);
  set_weight(2);
}
init () {
   ::init() ;
     add_action ("open_letter","open");
     }

open_letter(str) {
if(!id(str)) { notify_fail("Open what?\n");
 return 0; }
  
     write("You can't open Steve and Blue's letter.\n");
     return 1;}
