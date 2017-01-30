#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())
#define NAME HIK+"Dark "+NORM+RED+"Cha"+HIR+"os "+HIK+"Earring"+NORM

string *Armor_pieces;


     reset(arg) {
       ::reset(arg);

     set_name("earring");
     set_ac();
     set_value(1200);
     set_weight();
     set_type("earring");
     set_short(NAME);
     set_long(
       "\n"+
       "\n"+
       "\n"+
       "\n");

  /* Put the id's for your special armors required in here */

  Armor_pieces = ({ "chaos_armor", "chaos_amulet", "chaos_helm", "chaos_boots", "chaos_gloves", "chaos_chest", "chaos_shield", "chaos_misc", "chaos_pants", "chaos_ring", "chaos_underwear", "chaos_earring", "chaos_bracers", "chaos_necklace", "chaos_cloak", "chaos_belt" });
     }

status id(string arg) { return ( ::id(arg) || arg == "chaos_earring" || arg == "earring" || arg == "ear" || arg == "chaos earring"); }

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
    return (NAME+"   ("+NORM+HIG+"Set of Chaos"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(NAME+"(worn)");

  return NAME;
}
