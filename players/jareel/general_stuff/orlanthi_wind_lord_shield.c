inherit "obj/armor";
#include "/players/jareel/ansi.h"
#include "/players/jareel/define.h"
#define ATT USER->query_attack()
#define USER environment(this_object())

     reset() {
     set_name("shield");
     set_id("shield");
     set_alias("wind shield");
     set_short(BLU+"Wind Shield"+NORM);
     set_long(
       "This shield is made up of a enchanted '"+BOLD+"swirl"+NORM+"'ing pocket of air.\n"+
       "The mystical Orlanthi phophets say Wind Shields are made by\n"+
       "the god Orlanth himself.\n");
     set_ac(1);
     set_type("shield");
     set_weight(1);
     set_value(1200);
     }

     do_special(owner){
       if(!random(6)){ 
         tell_room(environment(USER),
           BLU+CAP(USER->query_name())+"'s shield lessons the blow."+NORM+".\n");
             return 0;}
               return 0;
     }

     init(){
       ::init();
         add_action("swirl", "swirl");
     }

     swirl(){
       set_short(BLU+"Wind Shield"+NORM+BOLD+" ( "+BLU+"Swirling Wind"+NORM+BOLD+" )"+NORM);
       set_long(
         "This shield is made up of a enchanted swirling pocket of air.\n"+
         "The mystical Orlanthi phophets say Wind Shields are made by\n"+
         "the god Orlanth himself.\n");
       tell_room(environment(USER),
         BLU+CAP(USER->query_name())+"'s summons a swirling wind to cover the shield."+NORM+".\n");
         return 1;
     }
