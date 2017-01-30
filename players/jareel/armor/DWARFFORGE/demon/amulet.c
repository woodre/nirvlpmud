inherit "obj/armor";
#include "/open/ansi.h"
reset(arg){
   ::reset(arg);
    if(arg) return;
  set_name("demon amulet");
  set_short(HIK+"Demon Amulet"+NORM+" ["+HIY+"Sun Forged"+NORM+"]");
  set_alias("amulet");
  set_long("An amulet forged in the mystical sun fire of Yelm. An\n"+
    "ancient art that unleashes the powers of chaotic flesh.\n");
  set_type("amulet");
  set_light(1);
  set_ac(2);
  set_params("other|physical", 0, 0, "do_spec");
  set_weight(1);
  set_value(2000);
}
do_spec(object owner){
     if(!random(5)){
       tell_object(owner, 
       "The Demon Amulet "+HIY+"GLOWS"+NORM+" with protective energy.\n");
      return 0;
      }
return 0;
}
