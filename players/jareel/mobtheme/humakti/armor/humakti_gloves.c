#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

   reset(arg) {
   ::reset(arg);

    set_name("gloves");
    set_ac(0);
    set_value(1200);
    set_weight(2);
    set_save_flag(1);
    set_type("gauntlets");
    set_params("physical",0,5,"Glove");
    set_short(HIK+"Gauntlets of the Humakti"+NORM);
    set_long(
      "The gauntlets of death are a dull grey with two\n"+
      "inch protruding spikes from each knuckle.  The\n"+
      "small spikes seem like they would pack quite a\n"+
      "wallup\n");
    }

    Glove(){
      int i;
          i = random(7);
      if(i==1){
      if(ATT->is_npc())
         ATT->heal_self(-(1+random(3))); 
         else ATT->add_hit_point(-(1+random(3)));
         tell_room(environment(USER),
           CAP(USER->query_name())+" gauntlets slice into....\n\n"+
                                  "       "+ATT->query_name()+"'s "+RED+"blood"+NORM+" spurts everywhere.\n");
         return 0;}
         return 0;}
