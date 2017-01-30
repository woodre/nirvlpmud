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

     set_name("dark cloak of shadows");
     set_ac(1);
     set_value(2000);
     set_weight(1);
     set_type("misc");
     set_short(HIK+"Dark"+NORM+HIK+" Cloak of "+HIK+"Shadows"+NORM);
     set_long(
       "                      "+HIG+"Set of Darkness"+NORM+"\n"+
       "A swirling blue and white crystal encrusted in a soft silver metel.\n"+
       "winged cap.  The cap looks frail and not very sturdy.  The power\n"+
       "from the helm radiates over your soul.\n");

  /* Put the id's for your special armors required in here */
  Armor_pieces = ({ "dark_amulet", "dark_armor", "dark_cloak" });
     }

status id(string arg) { return ( ::id(arg) || arg == "dark_cloak" || arg == "cloak" || arg == "dark cloak" || arg == "shadow cloak"); }

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
    return (HIK+"Dark "+NORM+BLU+"Cloak of "+NORM+HIK+"Shadows"+NORM+BOLD+" ("+NORM+HIG+"Set of Darkness"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(HIK+"Dark"+NORM+BLU+" Cloak of "+NORM+HIK+"Shadows"+NORM+NORM+" (worn)");

  return HIK+"Dark "+NORM+BLU+"Cloak of "+HIK+"Shadows"+NORM+NORM;
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
    ATT->set_ac(OAC - 2);
  else ATT->add_spell_point(-(15+random(15)));
  tell_room(environment(USER),
   ""+BOLD+" <"+HIK+"<>"+NORM+BOLD+">"+HIK+" Light is absorbed into "+environment()->query_name()+"'s cloak "+NORM+BOLD+" <"+HIK+"<>"+NORM+BOLD+">\n"+NORM);
    set_arm_light(-2);
  return 100;
}

