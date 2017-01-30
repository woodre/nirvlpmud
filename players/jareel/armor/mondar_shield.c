#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define OAC ATT->query_ac()
#define USER environment(this_object())

string *Armor_pieces;

     reset(arg) {
       ::reset(arg);
  if(arg) return;

     set_name("death shield");
     set_ac(2);
     set_value(2200);
     set_weight(2);
     set_type("shield");
     set_short(
       "Iron "+BOLD+BLK+"shield"+NORM+" of death");
     set_long(
       "The shield of death are a dull grey with the \n"+ 
       "Rune of Truth and the Rune of Death inscribed\n"+
       "into it.  The rune of truth is said to guide the\n"+
       "blow of the weapon of the user.\n");
  Armor_pieces = ({ "death_plate", "death_amulet", "death_helm", "death_boots", "death_gauntlets", "death_guard", "death_shield" });
     }

status id(string arg) { return ( ::id(arg) || arg == "death_shield" || arg == "shield" || arg == "iron shield" || arg == "iron shield of death"); }

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
    return ("Iron "+HIK+"Shield"+NORM+" of Death "+BOLD+"("+NORM+HIG+"Set of death"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return("Iron "+HIK+"Shield"+NORM+" of Death (worn)");

  return "Iron "+HIK+"Shield"+NORM+" of Death"+NORM+NORM;
}

do_special(owner) {
  int i;
  if (!ATT || random(1000) > 100) /* hits 10% of the time */
    return 0; 
  i = sizeof(Armor_pieces);
  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);
    if (!t || !((status)t->query_worn()))
      return 0;
  }

  if(ATT->is_npc())
    ATT->heal_self(-(random(4)));
  else ATT->add_spell_point(-(random(5)));
  tell_room(environment(USER),
   ""+BOLD+" <"+RED+"<>"+NORM+BOLD+">"+HIK+" A black aura washes over "+environment()->query_name()+"'s shield "+NORM+BOLD+" <"+RED+"<>"+NORM+BOLD+">\n"+NORM);
  return random (2);
}


