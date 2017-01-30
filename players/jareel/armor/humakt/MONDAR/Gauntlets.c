#include "/players/jareel/define.h"
inherit "/obj/armor.c";

#define SETNAME HIG+"Set of the Death"+NORM
#define FULLSETNAME HIG+"Full Set of Death"+NORM

object ob;
string *Armor_pieces;
string *Armor_pieces2;

     reset(arg) {
       ::reset(arg);

     set_name("death gauntlets");
     set_ac(2);
     set_value(1200);
     set_weight(2);
     set_type("gloves");
     set_short(
       "Iron "+BOLD+BLK+"gauntlets"+NORM+" of death");
     set_long(
       "The gauntlets of death are a dull grey with two\n"+
       "inch protruding spikes from each knuckle.  The\n"+
       "small spikes seem like they would pack quite a\n"+
       "wallup\n");


  Armor_pieces = ({ "death_armor", "death_gauntlets" });
  Armor_pieces2 = ({ "death_plate", "death_amulet", "death_helm", "death_boots", "death_gauntlets", "death_guard", "death_shield" });
     }

status id(string arg) { return ( ::id(arg) || arg == "death_gauntlets" || arg == "ring" || arg == "gauntlets" || arg == "gloves"); }

status check_full_set() {
  int i;

  if(!USER) return 0; 
  i = sizeof(Armor_pieces2);

  while(i--) {
    object t;
    t = present(Armor_pieces2[i], USER);

    if (!t || !((status)t->query_worn()))
      return 0;
  }
  return 1;
}


string short() {

  if (check_full_set())
    return ("Iron "+BOLD+BLK+"gauntlets"+NORM+" of death ["+FULLSETNAME+"]"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return("Iron "+BOLD+BLK+"gauntlets"+NORM+" of death ["+SETNAME+"]"+NORM+" (worn)"+NORM);

  return "Iron "+BOLD+BLK+"gauntlets"+NORM+" of death ["+SETNAME+"]"+NORM+""+NORM+NORM;
}

do_special(owner) {
  int i;
  if(ATT->is_npc())
    if (!ATT || random(1000) > 100) /* hits 10% of the time */
    ATT->heal_self(-(4+random(6)));
  else ATT->add_hit_point(-(4+random(6)));
  tell_room(environment(USER),
  CAP(ATT->query_name())+" is smashed with a spinning backhand.\n\n"+
      ""+ATT->query_name()+"'s "+RED+"blood"+NORM+" spurts everywhere.\n");
  return 100;
}

