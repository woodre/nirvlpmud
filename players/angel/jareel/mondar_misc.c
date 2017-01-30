#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

string *Armor_pieces;

     reset(arg) {
       ::reset(arg);
     
     set_name("death guard");
     set_ac(2);
     set_value(2000);
     set_weight(2);
      set_type("chest");
     set_short(
       "Iron "+BOLD+BLK+"guard"+NORM+" of death");
     set_long(
      "The guard of death is a dull grey its flat surface\n"+
       "only has the death rune inscribed on it.  The rune\n"+
       "warns all that the owner of this armor is not to be\n"+
       "taken lightly.\n");
  Armor_pieces = ({ "death_plate", "death_amulet", "death_helm", "death_boots", "death_gauntlets", "death_guard", "death_shield" });
     }

status id(string arg) { return ( ::id(arg) || arg == "death_guard" || arg == "guard" || arg == "iron guard" || arg == "iron guard of death"); }

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
    return ("Iron "+HIK+"Guard"+NORM+" of Death "+BOLD+"("+NORM+HIG+"Set of death"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return("Iron "+HIK+"Guard"+NORM+" of Death (worn)");

  return "Iron "+HIK+"Guard"+NORM+" of Death"+NORM+NORM;
}

do_special(owner) {
  int i;
  if (!ATT || random(1000) > 50) /* Hits 5% of the time */
    return 0;
  i = sizeof(Armor_pieces);
  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);
    if (!t || !((status)t->query_worn()))
      return 0;
  }

  if(ATT->is_npc())
    ATT->heal_self(-(random(3)));
      else ATT->hit_player(random(4), "other|evil");
  tell_room(environment(USER),
   ""+BOLD+" <"+RED+"<>"+NORM+BOLD+">"+HIK+" The death rune glows on "+environment()->query_name()+"'s chest guard "+NORM+BOLD+" <"+RED+"<>"+NORM+BOLD+">\n"+NORM);
  return random (2);
}

