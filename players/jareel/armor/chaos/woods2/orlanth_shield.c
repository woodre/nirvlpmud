#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())
#define WIND HIB+"S"+NORM+BLU+"w"+HIB+"i"+NORM+BLU+"r"+HIB+"l"+NORM+BLU+"i"+HIB+"n"+NORM+BLU+"g "+HIB+"S"+NORM+BLU+"h"+HIB+"i"+NORM+BLU+"e"+HIB+"l"+NORM+BLU+"d"+NORM


string *Armor_pieces;

  reset(arg) {
    ::reset(arg);

  set_name("swirling shield");
  set_ac(1);
  set_value(1000);
  set_weight(1);
  set_type("shield");
  set_short(WIND);
  set_long(
    "           "+HIG+"Set of the Coming Storm"+NORM+"       \n"+
    "This is an Orlanthi Wind Lords Shield.  It is very light by itself\n"+
    "it does not seem to provide a lot of protection.  Perhaps if you were\n"+
    "to find other Orlanthi Wind Lords with gear it may prove better.\n"); 
 Armor_pieces = ({ "orlanth_shield", "orlanth_wind", "orlanth_amulet2" });
     }

status id(string arg) { return ( ::id(arg) || arg == "orlanth_shield" || arg == "shield" || arg == "swirling shield"); }

status check_full_set() {
  int i;

  if(!USER) return 0; 
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
    return (WIND+BOLD+" ("+NORM+HIG+"Set of the comming Storm"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(WIND+" (worn)");

  return WIND+NORM+NORM;
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
      else ATT->hit_player(random(5), "other|wind");
  tell_room(environment(USER),
   ""+BOLD+" <"+BLU+"<>"+NORM+BOLD+">"+HIK+" wind flows over "+environment()->query_name()+"'s body "+NORM+BOLD+" <"+BLU+"<>"+NORM+BOLD+">\n"+NORM);
  return 0;
}