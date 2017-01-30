
#include "/players/jaraxle/define.h"
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("helm") ;
   set_alias("ages");
   set_short("Helm of "+HIC+"Ages"+NORM);
   set_long("This is a simple helmet made from Warrior Maiden\n"+
      "Mithril.  The helmet is light as a feather and\n"+
      "covers your entire head for full protection.\n");
   set_weight(1) ;
   set_value(1500+random(1501));
   set_type("helmet") ;
   set_ac(2) ;
}
