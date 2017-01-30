#include "/players/jaraxle/define.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
   ::reset(arg);
   if(arg) return;
   
   set_name("flask of healing");
   add_alias("flask");
   add_alias("healing");
   set_short("Flask of "+HBBLU+HIW+"Healing"+NORM);
   set_long("  This flask, formed from clear glass and topped\n"+
      "by a cork, contains a thick blue fluid. It looks\n"+
      "cool and refreshing.\n");
   set_type("sips");
   set_type_single("sip");
   set_msg(HIW+"\t-= "+HIB+"You take a sip from the flask of healing "+HIW+"=-\n"+NORM);
   add_cmd("sip");
   set_heal(50,50);
   set_charges(3);
   set_msg_precharges(HIB+"["+NORM);
   set_msg_postcharges(HIB+"]"+NORM);
   set_soak(7);
   set_value(600);
   set_msg_soaked("You try to take a sip, but spit up immediately\n");
set_empty_msg(HIW+"~"+BLU+" As you take the last sip, you toss the flask aside. "+HIW+"~\n"+NORM);
}
