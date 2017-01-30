#include "/players/jaraxle/define.h"
inherit "/obj/treasure";
query_save_flag() { return 1; }
id(str) { return str == "foot" || str == "champion foot" || str == "left foot"; }
short(){ return "A "+GRN+"foot"+NORM+""; }
long() {
   write(
      "This is the left foot of the Coorquak Champion. Its green skin, and scaly feel\n"+
      "seems to call to you, wanting you to consume it.\n");
   return 1;
}
query_weight() { return 1; }
get() { return 1; }
value() { return 0; }
init() {
   add_action("consume_foot","consume");
}
consume_foot(str){
   object typ;
   object spell;
   if(present("jar_ste",TP)){ write("You do not think you could bare to eat another foot.\n"); return 1; }
      
      if(!id(str)){ notify_fail("Consume what?\n"); return 0; }
      if(!str){ notify_fail("Consume what?\n"); return 0; }
      if(TP->query_real_name() == "guest") { write("You may not be healed.\n"); return 1; }
      typ = "ste";
      spell = clone_object("/players/jaraxle/closed/forbin/ste.c");
      spell->start(typ);
      
      write("You consume the Champion's "+GRN+"foot"+NORM+" greedily.\n"+
         "You feel the muscles in your legs begin to tense up.\n");
      say(TPN+" consumes a foot.\n");
      destruct(this_object());
      return 1; }
