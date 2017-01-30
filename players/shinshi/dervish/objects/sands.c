inherit "/obj/monster";
#include "../defs.h"
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
 
     set_name(BOLD+RED+"The Sands"+OFF+OFF);
     set_short(BOLD+RED+"The Sands"+OFF+OFF);
     set_race( "sands");
     set_alias("flake");
     set_long("SANDS OF ETERNITY\n");
     set_level(100);
     set_ac(1000);
     set_wc(1000);
     set_hp(10000);
     set_al(0);
     set_aggressive(0);
   }
}

emit_chan(ob) {
  emit_channel("junk", "\t\t"+BOLD+RED+"The Sands"+OFF+OFF+" take the life of "+capitalize((string)ob->query_real_name())+"!\n");
}
