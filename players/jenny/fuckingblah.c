#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())
reset(arg) {
   ::reset(arg);
   set_name("death gauntlets");
   set_ac(2);
   set_value(1200);
   set_weight(1);
    set_save_flag(1);
   set_type("ring");
   set_short("Iron "+BOLD+BLK+"gauntlets"+NORM+" of death");
   set_long(
      "The gauntlets of death are a dull grey with two\n"+
      "inch protruding spikes from their knuckles.  The\n"+
      "small spikes seem like they would pack quite a\n"+
      "wallup\n");
}
do_special(owner)
{
int i;
i = random(9);
   if(i==1){
      if(ATT->is_npc())
         ATT->heal_self(-(4+random(3)));
      else ATT->add_hit_point(-(4+random(3)));
      tell_room(environment(USER),
CAP(ATT->query_name())+" is smashed with a spinning backhand.\n\n"+BOLD+RED+"               BLOOD "+NORM+"spurts from "+ATT->query_name()+" .\n");
return 0;}
return 0;}

