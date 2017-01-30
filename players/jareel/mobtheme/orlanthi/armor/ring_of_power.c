#include "/players/jareel/ansi.h"
inherit "obj/armor";

     reset(arg) {

     if(arg) return;
       ::reset();

     set_name("ring");
     set_alias("ring");
     set_short(BLU+"Orlanth ring of Power"+NORM);
     set_long(
       "A thin iron band as orlanthi runes engraved in its surface.\n"+
       " \n");
     set_ac(1);
     set_type("ring"); 
     set_weight(1);
     set_value(200);
     call_out("generate", 40);
     }  
     
generate(){
     if(!worn) return 0;
       if(worn && worn_by && random(3)){
         if(worn_by->query_hurt()){
           worn_by->heal_self(random(3)+1);
            tell_object(worn_by,
             "You feel arcs of energy run up your arm .\n");
      }
     }  
     call_out("generate", 40);
     }

wear(str) {
     while(remove_call_out("regen_sp") != -1);
       if(!id(str) || environment() != this_player()) return 0;
         ::wear(str);
           if(worn) call_out("generate", 40);
     return 1;
     }

remove(string str) {
     if(!id(str) || environment() != this_player() || !worn) return 0;
       ::remove(str);
         while(remove_call_out("generate") != -1);
     return 1;
     }
