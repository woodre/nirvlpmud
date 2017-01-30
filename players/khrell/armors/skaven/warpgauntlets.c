#include "/players/khrell/define.h"
#define USER environment(this_object())
#define ATT USER->query_attack()
#define LIVING USER->is_living()
#include <ansi.h>
inherit "obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
   set_name("warpgauntlets");
   set_alias("gauntlets");
   set_short(GRN+"Warpstone"+HIK+" Gauntlets"+NORM);
   set_long(
      "Warpstone gauntlets contain powdered warpstone that is\n"+
      "mixed in with the metal during its forging process. These\n"+
      "Crude looking gauntlets have jagged looking spikes on each\n"+
      "of the knuckles.\n");
   set_ac(2);
   set_res(1);   
   set_type("gloves");
   set_weight(2);
   set_value(10000);
}

do_special(owner)

{
   if(!ATT) return;
   if(random(200) < USER->query_attrib("str")) {
     if(ATT->is_npc()) 
       ATT->heal_self(-(5+random(5)));
     else ATT->add_hit_point(-(5+random(5)));
      tell_room(environment(USER),
         CAP(ATT->query_name())+" is punched in the face by "+USER->query_name()+"'s gauntlets!!\n"+
         "\n"+
         HIW+"         B O N E "+NORM+"crunches sickeningly.\n");
      
      return 0;}
   return 0;}

