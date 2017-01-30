#include <ansi.h>
inherit "/obj/generic_heal.c";

     void reset(int arg) {
       ::reset(arg);
         if(arg) return;
     set_name("spirit");
     add_alias("blue");
     add_alias("energy");
     set_short(RED+"[ "+NORM+BLU+"Swirling Energy"+NORM+RED+" ]"+NORM);
     set_long("A electrically charged ball.\n"+
              "You feel that you can 'free'\n"+
              "its magical 'spirit'.\n");
     set_type("spirit");
     set_type_single("spirit");
     set_msg("You mutter a few words.\n"+
             "You are surrounded by a "+RED+"Crimson "+NORM+"aura.\n");
     set_msg2(" is engulfed by a "+RED+"Crimson aura"+NORM+".\n");
     add_cmd("free");
     set_msg_postcharges(NORM+RED+" ]"+NORM);
     set_msg_precharges(RED+"[ "+CYN);
     set_heal(75,0);
     set_charges(3);
     set_soak(3);
     set_stuff(3);
     set_value(100);
     }

     query_save_flag(){
     return 1;
     }
