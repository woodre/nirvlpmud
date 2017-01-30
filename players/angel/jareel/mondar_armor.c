#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

string *Armor_pieces;

  reset(arg) {
    ::reset(arg);

  set_name("death armor");
  set_ac(5);
  set_value(5000);
  set_weight(3);
  set_type("armor");
  set_short("Iron "+BOLD+BLK+"armor"+NORM+" of death");
  set_long(
    "           "+HIG+"Death Set"+NORM+"       \n"+
    "The armor of death is a dull grey with six\n"+
    "inch protruding spikes from each shoulder.\n"+
    "The armor appears to be finely crafted\n");
  Armor_pieces = ({ "death_plate", "death_amulet", "death_helm", "death_boots", "death_gauntlets", "death_guard", "death_shield" });
     }

status id(string arg) { return ( ::id(arg) || arg == "death_plate" || arg == "plate" || arg == "iron plate" || arg == "iron plate of death"); }

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
    return ("Iron "+HIK+"Plate"+NORM+" of Death "+BOLD+"("+NORM+HIG+"Set of death"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return("Iron "+HIK+"Plate"+NORM+" of Death (worn)");

  return "Iron "+HIK+"Plate"+NORM+" of Death"+NORM+NORM;
}

do_special(owner) {
  int i;
  if(!ATT || random(1000) > 100) /* hits 10% of the time */
    return 0; 
  i = sizeof(Armor_pieces);
  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);
    if (!t || !((status)t->query_worn()))
      return 0;
  }

  if(ATT->is_npc())
    ATT->heal_self(-(random(5)));
      else ATT->hit_player(random(5), "other|evil");
  tell_room(environment(USER),
   ""+BOLD+" <"+RED+"<>"+NORM+BOLD+">"+HIK+" Fury washes over "+environment()->query_name()+"'s body "+NORM+BOLD+" <"+RED+"<>"+NORM+BOLD+">\n"+NORM);
  return 0;
}

