#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())
#define WIND HIB+"S"+NORM+BLU+"w"+HIB+"i"+NORM+BLU+"r"+HIB+"l"+NORM+BLU+"i"+HIB+"n"+NORM+BLU+"g "+HIB+"A"+NORM+BLU+"m"+HIB+"u"+NORM+BLU+"l"+HIB+"e"+NORM+BLU+"t"+NORM

string *Armor_pieces;

     reset(arg) {
       ::reset(arg);

     set_name("wind amulet");
     set_ac(2);
     set_value(1200);
     set_weight(1);
     set_type("amulet");
     set_short(WIND);
     set_long(
       "                "+HIG+"Set of the comming Storm"+NORM+"\n"+
       "A swirling blue and white crystal encrusted in a soft silver metel.\n"+
       "The amulets chain flows like the wind.  Power resides inside the\n"+
       "crystal, yet it feels like it would provide decent protection.\n");

  /* Put the id's for your special armors required in here */
  Armor_pieces = ({ "orlanth_amulet2", "orlanth_shield", "orlanth_wind" });
     }

status id(string arg) { return ( ::id(arg) || arg == "orlanth_amulet2" || arg == "amulet" || arg == "storm" || arg == "amulet of the coming storm"); }

int wear(string str) { 

if (str && !id(str))
        return 0;
/* messing other stuff up, needs above -Bp */
  if ((int)this_player()->query_level() < 19) {
    write("This armor is too powerful for you to wear.\n"); 
    return 1; 
  }

  return (::wear(str) ? 1 : 0);
}

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
    return (WIND+NORM+BOLD+" ("+NORM+HIG+"Set of the comming Storm"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(WIND+NORM+" (worn)");

  return WIND+NORM+NORM;
}
