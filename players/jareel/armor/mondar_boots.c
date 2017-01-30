#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

string *Armor_pieces;

     reset(arg) {
       ::reset(arg);

     set_name("death boots");
     set_ac(2);
     set_value(2200);
     set_weight(2);
     set_type("boots");

     set_short(
       "Iron "+BOLD+BLK+"boots"+NORM+" of death");
     set_long(
       "The boots of death are a dull grey with two\n"+
       "inch protruding spikes from each ankle.  The\n"+
       "small spikes seem like they would pack quite a\n"+
       "wallup\n");
  Armor_pieces = ({ "death_plate", "death_amulet", "death_helm", "death_boots", "death_gauntlets", "death_guard", "death_shield" });
     }

status id(string arg) { return ( ::id(arg) || arg == "death_boots" || arg == "boots" || arg == "iron boots" || arg == "iron boots of death"); }

status check_full_set() {
  int i;

  if(!USER) return 0; /* verte, damn noobs, heh */
  i = sizeof(Armor_pieces);

  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);

    if (!t || !((status)t->query_worn()))
      return 0;
  }
  return 1;
}

string short() {

  if (check_full_set())
    return ("Iron "+HIK+"Boots"+NORM+" of Death "+BOLD+"("+NORM+HIG+"Set of death"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return("Iron "+HIK+"Boots"+NORM+" of Death (worn)");

  return "Iron "+HIK+"Boots"+NORM+" of Death"+NORM+NORM;
}

do_special(owner) {
  int i;
  if (!ATT || random(1000) > 50) /* hits 5% of the time */
    return 0; 
  i = sizeof(Armor_pieces);
  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);
    if (!t || !((status)t->query_worn()))
      return 0;
  }

  if(ATT->is_npc())
    owner->add_hit_point(random(5));
      else owner->add_hit_point(3+random(5));
  tell_room(environment(USER),
   ""+BOLD+" <"+RED+"<>"+NORM+BOLD+">"+HIK+" Health washes over "+environment()->query_name()+"'s body "+NORM+BOLD+" <"+RED+"<>"+NORM+BOLD+">\n"+NORM);
  return random (2);
}

