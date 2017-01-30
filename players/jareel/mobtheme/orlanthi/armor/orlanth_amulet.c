/*

Amulet   - Not full set AC-0 (No special)
Bracelet - Not Full Set AC-0 (no Special)
Earring  - Not Full set AC-0 (No Special)

FULL SET
Amulet   - Full Set AC-0 (10% Physical Resistance)
Bracelet - Full Set AC-0 ( Add Attack() ) 'Wax Code'
Earring  - Full Set AC-0 ( adds sps now prolly will switch it up)

*/

#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

string *Armor_pieces;

     reset(arg) {
       ::reset(arg);

     set_name("wind amulet");
     set_res(10);
     set_ac(0);
     set_value(4200);
     set_weight(1);
     set_type("amulet");
     set_short(HIB+"Amulet"+NORM+BLU+" of the coming "+HIB+"Storm"+NORM);
     set_long(
       "                      "+HIG+"Set of the Wind"+NORM+"\n"+
       "A swirling blue and white crystal encrusted in a soft silver metel.\n"+
       "The amulets chain flows like the wind.  Power resides inside the\n"+
       "crystal, yet it feels like it would provide almost no protection.\n");

  /* Put the id's for your special armors required in here */
  Armor_pieces = ({ "orlanth_amulet", "orlanth_earring", "orlanth_bracelet" });
     }

status id(string arg) { return ( ::id(arg) || arg == "orlanth_amulet" || arg == "amulet" || arg == "storm" || arg == "amulet of the coming storm"); }

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
    return (HIB+"Amulet "+NORM+BLU+"of the coming "+NORM+HIB+"Storm"+NORM+BOLD+" ("+NORM+HIG+"Set of the Wind"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(HIB+"Amulet"+NORM+BLU+" of the coming "+NORM+HIB+"Storm"+NORM+NORM+" (worn)");

  return HIB+"Amulet "+NORM+BLU+"of the coming "+HIB+"Storm"+NORM+NORM;
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
    set_params("physical",0,10,"wind_block");
}

    wind_block(){
      int i;
          i = random(7);
      if(i==1){
         tell_room(environment(USER),
           ""+BOLD+" <"+BLU+"<>"+NORM+BOLD+">"+BLU+" Protecting wind surounds "+environment()->query_name()+"'s body "+BOLD+"            <"+BLU+"<>"+NORM+BOLD+">\n"+NORM);
         return 0;}
         return 0;}      
         