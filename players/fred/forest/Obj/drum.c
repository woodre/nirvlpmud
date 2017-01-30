#include "/players/fred/ansi.h"
#include "/players/fred/defines.h"
inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("drum");
  set_short("A small drum");
  set_long(
  "  A small drum with the word Energizer written across it.\n");
  set_type("armor");
  set_ac(2);
  set_weight(1);
  set_value(500);
}

init(){
  ::init();
   add_action("growl","hit");
   add_action("growl","sound");
   add_action("growl","beat");
   add_action("growl","tap");
}

growl(str){
if(!str){ write("Tap what?\n"); return 1; }
if(str == "drum"){
  write("You tap the drum letting the sound fill the air.\n");
  say(capitalize(TP->query_name())+" taps the drum letting sound fill the air.\n");
  return 1; }
}

