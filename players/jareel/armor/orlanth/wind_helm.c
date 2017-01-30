/* **********************************************
*                                               *
*               Jareel 1/8/2004                 *
* /players/jareel/armor/orlanth/wind_helm.c     *
*                                               *
*    Object lowers NPC's AC by 1 if worn with   *
*              the complete set                 *
* Armor specials hit 22% of the time in order   *
* to get the specials a player sacrifices 6     *
* points of armor, cause he needs all 3 pieces  *
* worn for the specials to work.                *
********************************************** */
#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())
#define OAC ATT->query_ac()

string *Armor_pieces;
  
     reset(arg) {
       ::reset(arg);

     set_name("wind helm");
     set_ac(0);
     set_value(5000);
     set_weight(1);
     set_type("helmet");
     set_short(HIB+"Helmet"+NORM+BLU+" of the raging "+HIB+"Storm"+NORM);
     set_long(
       "                      "+HIG+"Set of the Wind"+NORM+"\n"+
       "A swirling blue and white crystal encrusted in a soft silver metel.\n"+
       "winged cap.  The cap looks frail and not very sturdy.  The power\n"+
       "from the helm radiates over your soul.\n");

  /* Put the id's for your special armors required in here */
  Armor_pieces = ({ "wind_amulet", "wind_helm", "wind_sandles" });
     }

status id(string arg) { return ( ::id(arg) || arg == "wind_helm" || arg == "helm" || arg == "storm helm" || arg == "helmet of the raging storm"); }

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
    return (HIB+"Helmet "+NORM+BLU+"of the raging "+NORM+HIB+"Storm"+NORM+BOLD+" ("+NORM+HIG+"Set of the Wind"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(HIB+"Helmet"+NORM+BLU+" of the raging "+NORM+HIB+"Storm"+NORM+NORM+" (worn)");

  return HIB+"Helmet "+NORM+BLU+"of the raging "+HIB+"Storm"+NORM+NORM;
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

  if(ATT->is_npc())
    ATT->set_ac(OAC - 1);
  else ATT->add_spell_point(-(15+random(15)));
  tell_room(environment(USER),
   ""+BOLD+" <"+BLU+"<>"+NORM+BOLD+">"+BLU+" Raging wind surounds "+environment()->query_name()+"'s body "+BOLD+" <"+BLU+"<>"+NORM+BOLD+">\n"+NORM);
  return 100;
}
