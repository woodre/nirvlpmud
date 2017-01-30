#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
object att,ob;
int h;
reset(int arg) {
   if(arg) return;
   set_id("whistle");
   set_short("whistle");
   set_long(
      "This is a small chrome whistle.  Referees and linesmen blow it\n"+
      "to stop play.\n");
   set_weight(1);
   set_value(50);
}
init() {
   ::init();
   add_action("whistle","blow");
}
whistle(arg) {
   if(arg == "whistle" || arg == "the whistle") {
      if(!arg) { return 0; }
      if(random(WILSTAT) < 2) {
         write("You weakly blow the whistle and it makes no sound.\n");
         return 1;}
      ob = all_inventory(environment(TP));
      h = 0;
      while(h<sizeof(ob)) {
         if(ob[h]->query_attack()) { 
            att = ob[h]->query_attack();
            ob[h]->stop_fight();
            att->stop_fight();
            }
         h++;
      }
      tell_room(environment(TP),BOLD+WHT+capitalize(TPN)+" blows "+POS+" whistle and everyone stops fighting."+NORM+"\n");
      if(random(5) == 0) {
         write("The bead inside the whistle comes off and you throw the useless thing away.\n");
         destruct(this_object()); TP->recalc_carry();
      }
      return 1; }}
