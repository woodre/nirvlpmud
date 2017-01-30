#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

string *Armor_pieces;

     reset(arg) {
       ::reset(arg);

     set_name("death helm");
     set_ac(2);
     set_value(2000);
     set_weight(2);
     set_type("helmet");
     set_short(
       "Iron "+BOLD+BLK+"helmet"+NORM+" of death");
     set_long(
       "The helmet of death are a dull grey with two horns\n"+
       "protruding  from each side of the visor.  The dull\n"+
       "sheen of the helmet absorbs some of the surrounding\n"+
       "light.\n");
  Armor_pieces = ({ "death_plate", "death_amulet", "death_helm", "death_boots", "death_gauntlets", "death_guard", "death_shield" });
     }

status id(string arg) { return ( ::id(arg) || arg == "death_helm" || arg == "helm" || arg == "iron helm" || arg == "iron helm of death"); }

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
    return ("Iron "+HIK+"Helm"+NORM+" of Death "+BOLD+"("+NORM+HIG+"Set of death"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return("Iron "+HIK+"Helm"+NORM+" of Death (worn)");

  return "Iron "+HIK+"Helm"+NORM+" of Death"+NORM+NORM;
}
