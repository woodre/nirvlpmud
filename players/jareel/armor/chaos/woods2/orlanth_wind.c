#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())
#define WIND HIB+"S"+NORM+BLU+"w"+HIB+"i"+NORM+BLU+"r"+HIB+"l"+NORM+BLU+"i"+HIB+"n"+NORM+BLU+"g "+HIB+"W"+NORM+BLU+"i"+HIB+"n"+NORM+BLU+"d"

string *Armor_pieces;

     reset(arg) {
       ::reset(arg);

     set_name("wind");
     set_value(4200);
     set_weight(0);
     set_type("misc");
     set_short(WIND);
     set_long(
       "                      "+HIG+"Set of the Wind"+NORM+"\n"+
       "A swirling blue and white crystal encrusted in a soft silver metel.\n"+
       "The amulets chain flows like the wind.  Power resides inside the\n"+
       "crystal, yet it feels like it would provide almost no protection.\n");

  /* Put the id's for your special armors required in here */
  Armor_pieces = ({ "orlanth_wind", "orlanth_shield", "orlanth_amulet2" });
     }

status id(string arg) { return ( ::id(arg) || arg == "orlanth_wind" || arg == "misc" || arg == "wind" || arg == "swirling wind"); }

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
    return (WIND+HIW+" ("+NORM+HIG+"Set of the comming Storm"+NORM+BOLD+")"+NORM+" (Encircling)"+NORM);

  if ((status)this_object()->query_worn())
    return(WIND+NORM+" (Encircling)");

  return WIND+NORM+NORM;
}

do_special(owner) {
  int i;
  if (random(1000) > 222) /* It only hits 22% of the time */
    return 0; 
  i = sizeof(Armor_pieces);
  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);
    if (!t || !((status)t->query_worn()))
      return 0;
  }
    set_params("physical",2,2,"wind_block");
}

    wind_block(){
      int i;
          i = random(7);
      if(i==1){
         tell_room(environment(USER),
           ""+BOLD+" <"+BLU+"<>"+NORM+BOLD+">"+BLU+" Protecting wind surounds "+environment()->query_name()+"'s body "+BOLD+"            <"+BLU+"<>"+NORM+BOLD+">\n"+NORM);
         return 0;}
         return 0;}  
