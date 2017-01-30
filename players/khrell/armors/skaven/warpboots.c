#include "/players/khrell/define.h"
object ob;
#define USER environment(this_object())
#define ATT USER->query_attack()
#include <ansi.h>
inherit "obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
   set_name("warpgboots");
   set_alias("boots");
   set_short(GRN+"Warpstone"+HIK+" Boots"+NORM);
   set_long(
      "Warpstone boots contain powdered warpstone that is\n"+
      "mixed in with the metal during its forging process. These\n"+
      "Crude looking boots have jagged looking spikes on each\n"+
      "of the toes.\n");
   set_ac(2);
   set_res(1);
   set_type("boots");
   set_weight(2);
   set_value(10000);
}

do_special(owner)

{
   if(!ATT) return;
   if(random(200) < USER->query_attrib("dex")) {
     if(ATT->is_npc()) 
       ATT->heal_self(-(5+random(5)));
     else ATT->add_hit_point(-(5+random(5)));
      tell_room(environment(USER),
         CAP(ATT->query_name())+" is kicked in the groin by "+USER->query_name()+"'s spiked boots.\n"+
         "\n"+
         BOLD+RED+"               B L O O D "+NORM+"sprays outward.\n");
      
      return 0;}
   return 0;}
