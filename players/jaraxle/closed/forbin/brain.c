#include "/players/jaraxle/define.h"
inherit "/obj/treasure";
query_save_flag() { return 1; }
id(str) { return str == "brain" || str == "champion brain" || str == "champion's brain"; }
short() { return "A "+MAG+"brain"+NORM+""; }
long() {
   write(
      "This is the brain of the Coorquak Champion. It is slimy and full of grooves\n"+
      "that seem at call to you, wanting you to consume it.\n");
   return 1;
}
query_weight() { return 1; }
get() { return 1; }
value() { return 0; }
init() {
   add_action("consume_brain","consume");
}
consume_brain(str){
   object spell;
   object typ;
   if(present("jar_mag",TP)){ write("You cannot bare to eat another brain so soon.\n"); return 1; }
   
   if(!id(str)){ notify_fail("Consume what?\n"); return 0; }
   if(!str){ notify_fail("Consume what?\n"); return 0; }
   
   if(TP->query_real_name() == "guest") { write("You may not be healed.\n"); return 1; }
   typ = "mag";
   spell = clone_object("/players/jaraxle/closed/forbin/mag.c");
   spell->start(typ);
   
   write("You consume the Champion's "+MAG+"brain"+NORM+" greedily.\n"+
      "You wince as an intense headache overcomes you.\n");
   say(TPN+" consumes a whole brain.\n");
   destruct(this_object());
   return 1; }
