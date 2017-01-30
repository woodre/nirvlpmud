#include "/players/jareel/define.h"
inherit "/obj/armor.c";

#define SETNAME HIG+"Set of Shadows"+NORM
#define FULLSETNAME HIG+"Full Set of Shadows"+NORM

object ob;
string *Armor_pieces;

     reset(arg) {
       ::reset(arg);

  set_ac(4);
  set_res(10);
  set_value(40000);
  set_weight(2);
  set_type("armor");
  set_name("plate of darkness");
  set_alias("plate");
  set_short(HIK+"Plate of "+HIK+"Darkness"+NORM+" ["+SETNAME+"]"); 
  set_long(
    "Plate Armor forged in the moon forge of the Red Goddess by the high blacksmith Kar-relk,\n"+
    "The Mighty.  A palpable clinging darkness seeps out of the magical bracelet.  The encircling\n"+
	"darkness seems to empower the magical energy within the encrusted armor.\n");

                     /* PUT THE ARMOR ID FOR THE SET HERE */
  Armor_pieces = ({ "PlateOfDarkness", "BraceletOfDarkness", "MiscOfDarkness", "GuardOfDarkNess" });
     }

status id(string arg) { return ( ::id(arg) || arg == "PlateOfDarkness" || arg == "plate of darkness"); }

int wear(string str) { 

if (str && !id(str))
        return 0;
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
    return (HIK+"Plate of "+HIK+"Darkness"+NORM+" ["+FULLSETNAME+"]"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(HIK+"Plate of "+HIK+"Darkness"+NORM+" ["+SETNAME+"]"+NORM+" (worn)"+NORM);

  return HIK+"Plate of "+HIK+"Darkness"+NORM+" ["+SETNAME+"]"+NORM+""+NORM+NORM;
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
    set_params("physical",2,2,"powerupneck");
}
  
    powerupneck(){
	    int i;
          i = random(4);
        if(i==1){	
         tell_room(environment(USER),
           HIK+"D A R K N E S S "+NORM+"engulfs "+environment()->query_name()+"'s body "+NORM+BOLD+" you feel empowered as the "+HIK+"D A R K N E S S"+NORM+" flows within you!!!@!\n"+NORM);
		 USER->add_hit_point(10+random(10));
         return 1;}
         return 1;} 