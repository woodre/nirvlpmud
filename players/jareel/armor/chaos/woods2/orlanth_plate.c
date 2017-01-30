/* Viable option for Warpstone, Shin Pads, BoS so not everyone has same gear */

#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())
#define THUNDER HIY+"T"+HIB+"*"+HIY+"H"+HIB+"*"+HIY+"U"+HIB+"*"+HIY+"N"+HIB+"*"+HIY+"D"+HIB+"*"+HIY+"E"+HIB+"*"+HIY+"R"+NORM 

string *Armor_pieces;

     reset(arg) {
       ::reset(arg);
     if(arg) return;
     
     set_name("plate");
     set_res(10);
     set_value(8000);
     set_weight(4);
     set_type("armor");
     set_short(HIB+"Plate"+NORM+" of "+HIY+"T"+HIB+"*"+HIY+"H"+HIB+"*"+HIY+"U"+HIB+"*"+HIY+"N"+HIB+"*"+HIY+"D"+HIB+"*"+HIY+"E"+HIB+"*"+HIY+"R"+NORM);
     set_long(
       "                      "+HIG+"Set of the Wind"+NORM+"\n"+
       "A swirling blue and white crystal encrusted in a soft silver metel.\n"+
       "The amulets chain flows like the wind.  Power resides inside the\n"+
       "crystal, yet it feels like it would provide almost no protection.\n");

  /* Put the id's for your special armors required in here */
  Armor_pieces = ({ "orlanth_plate", "orlanth_vambraces", "orlanth_bracers" });
     }

status id(string arg) { return ( ::id(arg) || arg == "orlanth_plate" || arg == "plate" || arg == "thunder" || arg == "plate of thunder"); }

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
    return (HIB+"Plate"+NORM+" of "+THUNDER+NORM+BOLD+" ("+NORM+HIG+"Set of "+THUNDER+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(HIB+"Plate"+NORM+" of "+THUNDER+NORM+" (worn)");

  return HIB+"Plate"+NORM+" of "+THUNDER+NORM;
}
