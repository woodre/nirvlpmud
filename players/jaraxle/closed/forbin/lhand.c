#include "/players/jaraxle/define.h"
inherit "/obj/treasure";
query_save_flag() { return 1; }
id(str) { return str == "bicept" || str == "champion bicept" || str == "right bicept"; }
short(){ return "A "+GRN+"bicept"+NORM+""; }
long() {
   write(
      "This is the right bicept of the Coorquak Champion. Its "+GRN+"green skin"+NORM+", and scaly texture\n"+
      "seems to call to you, wanting you to consume it.\n");
   return 1;
}
query_weight() { return 1; }
get() { return 1; }
value() { return 0; }
init() {
   add_action("consume_bicept","consume");
}
consume_bicept(str){
      object typ;
      object spell;
      int spm,hpm;
      spm = hpm = 0;
   if(!id(str)){ notify_fail("Consume what?\n"); return 0; }
   if(!str){ notify_fail("Consume what?\n"); return 0; }
   if(present("jar_str",TP)){ write("You do not think you could bare to eat another bicept.\n"); return 1; }
      
      if(TP->query_real_name() == "guest") { write("You may not be healed.\n"); return 1; }
      typ = "str";
      spell = clone_object("/players/jaraxle/closed/forbin/str.c");
      spell->start(typ);
      
      write("You consume the Champion's "+GRN+"bicept"+NORM+" greedily.\n"+
         "You feel your arms swell and your muscles grow stronger.\n");
      say(TPN+" consumes bicept.\n");
      destruct(this_object());
      return 1; }
