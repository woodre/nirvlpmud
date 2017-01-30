#include "/players/jaraxle/define.h"
inherit "/obj/treasure";
query_save_flag() { return 1; }
id(str) { return str == "heart" || str == "champion heart" || str == "champion's heart"; }
short() { return "A "+RED+"heart"+NORM+""; }
long() {
   write(
      "This is the heart of the Coorquak Champion. Deep "+RED+"crimson"+NORM+", and "+RED+"bloody"+NORM+" it\n"+
      "seems to call to you, wanting you to consume it.\n");
   return 1;
}
query_weight() { return 1; }
get() { return 1; }
value() { return 0; }
init() {
   add_action("consume_heart","consume");
}
consume_heart(str){
   
      object typ;
      object spell;
 if(!id(str)){ notify_fail("Consume what?\n"); return 0; }
   if(!str){ notify_fail("Consume what?\n"); return 0; }
   if(present("jar_sta",TP)){ write("You cannot bare to eat another heart so soon.\n"); return 1; }
      
      if(TP->query_real_name() == "guest") { write("You may not be healed.\n"); return 1; }
      typ = "sta";
      spell = clone_object("/players/jaraxle/closed/forbin/sta.c");
      spell->start(typ);
      
      write("You consume the Champion's "+RED+"heart"+NORM+" greedily.\n"+
         "You feel heart racing, pounding inside your chest.\n");
      say(TPN+" consumes a whole heart.\n");
      destruct(this_object());
      return 1; }
