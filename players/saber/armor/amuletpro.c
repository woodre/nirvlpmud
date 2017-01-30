inherit "obj/armor";
#include "/open/ansi.h"
reset(arg){
   ::reset(arg);
    if(arg) return;
   set_name("amulet of protection");
  set_short(BLU+"Amulet o"+NORM+BOLD+"*"+NORM+BLU+"f Protection"+NORM);
   set_alias("amulet");
   set_long("A beautiful amulet set with a black opal.\n"+
       "It has a faint blue aura.\n");
   set_type("amulet");
   set_ac(2);
set_params("other|magical", 1, 3, "do_spec");
   set_weight(1);
   set_value(2000);
}

quest_ob()  { return 1; }

do_spec(object owner){
     if(!random(5)){
       tell_object(owner, 
       "The amulet "+HIY+"GLOWS"+NORM+"...\n");
      return 0501;
      }
return 0;
}
