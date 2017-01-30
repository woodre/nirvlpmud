/* **********************************************
*                                               *
*               Jareel 1/8/2004                 *
* /players/jareel/armor/zoranzoran/death_plate.c*
* Main Armor that Makes your Alignment evil     *
* This is more for Anti Knight Code, cause the  *
* Yelmalian Set is made more for the Knights    *
* The Set shares Pieces with the Wind Set and   *
* The Sun Set, so comboing out sets will not    *
* be a possibility yet.                         *
********************************************** */
#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

string *Armor_pieces;
  
reset(arg) {
  ::reset(arg);

  set_name("dark plate of the night");
  set_ac(5);
  set_value(5000);
  set_weight(3);
  set_type("armor");
  set_short(HIK+"Dark"+NORM+BLU+" Plate of the "+HIK+"Night"+NORM);
  set_long(
    "                      "+HIG+"Set of Darkness"+NORM+"\n"+
    "A sturdy shell of metalic armor.  The chest is encrusted with the\n"+
    "Undead and Death Runes.  A dark eerie black aura covers the plate.  \n"+
    "Untold power resides within this armor.\n");
/* Put the id's for your special armors required in here */
Armor_pieces = ({ "dark_amulet", "dark_cloak", "dark_armor" });
}

status id(string arg) { return ( ::id(arg) || arg == "dark_armor" || arg == "plate" || arg == "night plate" || arg == "dark plate"); }

status check_full_set() {
  int i;

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
    return (HIK+"Dark "+NORM+BLU+"Plate of the "+NORM+HIK+"Night"+NORM+BOLD+" ("+NORM+HIG+"Set of Darkness"+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(HIK+"Dark"+NORM+BLU+" Plate of the "+HIK+"Night"+NORM+NORM+" (worn)");

  return HIK+"Dark "+NORM+BLU+"Plate of the "+HIK+"Night"+NORM+NORM;
}

do_special(owner) {
  int i;
  if (random(1000) > 800) /* It only hits 15% of the time */
    return 0; 
  i = sizeof(Armor_pieces);
  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);
    if (!t || !((status)t->query_worn()))
      return 0;
  }

  if(!environment(this_object())) return 1;
  if(environment(this_object())->query_alignment() > -1000) {
    call_other(environment(this_object()),"add_alignment",-1000);
    }
  }

