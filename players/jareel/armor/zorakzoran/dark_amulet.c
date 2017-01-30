#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

string *Armor_pieces;

     reset(arg) {
       ::reset(arg);

     set_name("dark amulet");
     set_ac(2);
     set_value(2200);
     set_weight(1);
     set_type("amulet");
     set_short(HIK+"Dark"+NORM+BLU+" Amulet of the "+HIK+"Void"+NORM);
     set_long(
       "                      "+HIG+"Set of Darkness"+NORM+"\n"+
       "A swirling blue and white crystal encrusted in a soft silver metel.\n"+
       "The amulets chain flows like the wind.  Power resides inside the\n"+
       "crystal, yet it feels like it would provide almost no protection.\n");

  /* Put the id's for your special armors required in here */
  Armor_pieces = ({ "dark_amulet", "dark_cloak", "dark_armor" });
     }

status id(string arg) { return ( ::id(arg) || arg == "dark_amulet" || arg == "amulet" || arg == "amulet of the void" || arg == "void amulet"); }

int wear(string str) { 

  if ((int)this_player()->query_level() < 19) {
    write("This armor is too powerful for you to wear.\n"); 
    return 1; 
  }

  return (::wear(str) ? 1 : 0);
}

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
    return (HIK+"Dark "+NORM+BLU+"Amulet of the "+NORM+HIK+"Void"+NORM+BOLD+" ("+NORM+HIG+"Set of Darkness"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(HIK+"Dark"+NORM+BLU+" Amulet of the"+NORM+HIK+" Void"+NORM+NORM+" (worn)");

  return HIK+"Dark "+NORM+BLU+"Amulet of the "+HIK+"Void"+NORM+NORM;
}

do_special(owner) {
  int i;
  if (random(1000) > 200) /* It only hits 20% of the time */
    return 0; 
  i = sizeof(Armor_pieces);
  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);
    if (!t || !((status)t->query_worn()))
      return 0;
  }

  if(ATT->is_npc())
    ATT->heal_self(-(5+random(5)));
  else ATT->hit_player(random(5)+5, "other|evil");
  tell_room(environment(USER),
   ""+BOLD+" <"+HIK+"<>"+NORM+BOLD+">"+HIK+" The Amulet lashes tendrils of agony "+NORM+BOLD+" <"+HIK+"<>"+NORM+BOLD+">\n"+NORM);
  return 100;
}
