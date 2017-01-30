#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

string *Armor_pieces;

  reset(arg) {
    ::reset(arg);
  if(arg) return;

  set_name("death amulet");
  set_ac(2);
  set_value(1200);
  set_weight(2);
  set_type("amulet");
  set_short("Iron "+BOLD+BLK+"amulet"+NORM+" of death");
  set_long(
    "           "+HIG+"Death Set"+NORM+"       \n"+
    "The amulet of death is a dull grey with a dull rune of\n"+
    "death etched into its face.  The rune is a part of a \n"+
    "spell matrix or form of power.\n");

  /* Put the id's for your special armors required in here */
  Armor_pieces = ({ "death_plate", "death_amulet", "death_helm", "death_boots", "death_gauntlets", "death_guard", "death_shield" });
     }

status id(string arg) { return ( ::id(arg) || arg == "death_amulet" || arg == "amulet" || arg == "iron amulet" || arg == "iron amulet of death"); }

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
    return ("Iron "+HIK+"Amulet"+NORM+" of Death "+BOLD+"("+NORM+HIG+"Set of death"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return("Iron "+HIK+"Amulet"+NORM+" of Death (worn)");

  return "Iron "+HIK+"Amulet"+NORM+" of Death"+NORM+NORM;
}
