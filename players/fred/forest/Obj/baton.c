#include "/players/fred/ansi.h"
#include "/players/fred/defines.h"
inherit "/obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("baton");
  set_long(
  "  A small baton once held by the Energizer Bunny.\n");
  set_weight(1);
  set_value(500);
}

short(){
 if(environment() !=TP){
   return "A small baton";
   }
 else{
   return "A small baton (held)";
   }
  }

init(){
  ::init();
   add_action("cow","twirl");
 }

cow(str){
  if(!str){ write("Twirl what?\n"); return 1; }
  if(str == "baton"){
    write("You twirl the baton around your head like a helicopter.\n");
    say(TP->query_name()+" twirls the baton around "+POS+" head like a helicopter.\n");
    return 1; }
  }
