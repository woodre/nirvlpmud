/* "Prestige Weapons" Damage in fire and ice return would like to be a growth like
   Prestige AC or WC Talk to Drag About it get the formula from him */
   
    /* Dual Axe
 HITS: 808       Rounds: 1000     Average: 2570   Max: 112  One Special Just Ice Just Fire. 
 HITS: 808       Rounds: 1000     Average: 2602   Max: 115  With Both Fire and Ice both weapons
    */

   
/* Made a Change to this wep both parts were Ice one should have been fire */

inherit "/obj/weapon.c";
#include "/players/jareel/define.h"

#define CO call_other
#define SETNAME HIG+"Set of the Berzerker"+NORM
#define FULLSETNAME HIG+"Full Set of the Berzerker"+NORM
#define WEP BOLD+"||"+NORM

#define  F1      HIR+"/n             (  "+NORM+RED+".     "+HIR+" )"+NORM
#define  F2      HIR+"         )           (              )"+NORM
#define  F3      HIR+"               "+NORM+RED+".  '   "+NORM+RED+".   '  "+NORM+RED+".  '  "+NORM+RED+"."+NORM
#define  F4      HIR+"      (    "+NORM+RED+","+HIR+" )       ("+NORM+RED+".  "+HIR+" )  (   '"+NORM+RED+", "+HIR+"   )"+NORM
#define  F5      HIR+"       "+NORM+RED+".' "+HIR+") ( "+NORM+RED+". "+HIR+")    "+NORM+RED+", "+HIR+" ( "+NORM+RED+",  "+HIR+"   )   ( "+NORM+RED+"."+NORM
#define  F6      HIR+"    )"+NORM+RED+". , "+HIR+"( "+NORM+RED+"."+HIR+"   (  ) ( "+NORM+RED+", '"+HIR+")  "+NORM+RED+".'"+HIR+" (  "+NORM+RED+",  "+HIR+"  )"+NORM
#define  F7      HIR+"   (_"+NORM+RED+","+HIR+") "+NORM+RED+"."+HIR+" )"+NORM+RED+","+HIR+" ) _) _"+NORM+RED+",'"+HIR+")  ("+NORM+RED+","+HIR+" ) '"+NORM+RED+". "+HIR+")  "+NORM+RED+",. "+HIR+"(' )"+NORM
#define  F8      HIR+"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^/n"+NORM

#define  F9 HIY+"/n   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *"+NORM
#define  F10 HIY+"   *     *     *     *     *     *     *     *     *     *     *     * "+NORM
#define  F11 HIY+" *     *     *     *     *     *     *     *     *     *     *     *"+NORM
#define  F12 HIY+"  *   *    *   *   *   *   *   *   *   *   *   *   *   *   *    *   *  *"+NORM
#define  F13 HIY+"*   *    *   *   * "+HIW+"R I G H T E O U S  F U R Y"+HIY+"   *   *   *   *   *   */n"+NORM

object ob;


string *Weapon_pieces_The_Duo;

     reset(arg) {
       ::reset(arg);

     set_name("axe of the berzerker");
     set_value(4200);
	 set_class(20);
     set_weight(1);
     set_type("axe");
     set_short(RED+"The Berserker Axe '"+HIW+"Bite"+NORM+RED+"' "+HIK+"["+HIC+" Chaos Honed "+HIK+"]"+NORM+" ["+SETNAME+"]"+NORM);
  set_long(
    "An Axe forged in the Hell fires of the Stormbull Gods high\n"+ 
	"blacksmith Hrgorn, the Deft. A palpable clinging darkness\n"+ 
	"seeps out of the magical Axe.  The encircling darkness\n"+
	"seems to empower the magical energy within the encrusted\n"+ 
	"Ward, great power lies within\n");

                     /* PUT THE ARMOR ID FOR THE SET HERE */
     set_hit_func(this_object());
  Weapon_pieces_The_Duo = ({ "ChaosAxeRoar", "ChaosAxeBite" });
     }

status id(string arg) { return ( ::id(arg) || arg == "ChaosAxeBite" || arg == "axe of bite"); }

int wield(string str) { 

if (str && !id(str))
        return 0;
  if ((int)this_player()->query_prestige_level() < 1) {
    write("This weapon is too powerful for you to Wield.\n"); 
    return 1; 
  }

  return (::wield(str) ? 1 : 0);
}

status check_full_set() {
  object wep, who;

  if(!USER) return 0;

  wep = present( "ChaosAxeRoar", USER ); 
  if( wep ) {
    who = (object) wep->query_wielded_by();
    if( who )
    /** If it is wielded **/
    if( who == USER )
      return 1;
    /** If it is offwield **/
    if( (object) USER->query_second_weapon() == wep )
      return 1;
    if( wep->query_wep_shadow() )
      return 1;
  }
  return 0;
}

int check_wielded() {
  return (int) this_object()->query_wielded() || (int) this_object()->query_wep_shadow();
}

string short() {

  if (check_full_set() && check_wielded() )
    set_short(RED+"The Berserker Axe '"+HIW+"Bite"+NORM+RED+"' "+HIK+"["+HIC+" Chaos Honed "+HIK+"]"+NORM+" ["+FULLSETNAME+"]"+NORM);
  else
    set_short(RED+"The Berserker Axe '"+HIW+"Bite"+NORM+RED+"' "+HIK+"["+HIC+" Chaos Honed "+HIK+"]"+NORM+" ["+SETNAME+"]"+NORM+""+NORM);
  return (string) ::short();
}

weapon_hit(attacker) {
     int swordhit;
     int ice;
	 int fire;
     int wind;

  if( !check_full_set() ) 
    return 0;

 ice = random(4);
 fire = random(4);
  wind = random(4);
 
  if (wind==0){
      if(!attacker) return 1;
	  write("\n"+HIC+BLINK+"Sheering wind slashes off the "+HIC+"Chaos Axe"+NORM+HIC+BLINK+" and tears flesh!\n     "+NORM);
	  BLINK+HIC+say(environment()->query_name()+" "+HIC+"Chaos Axe"+NORM+HIC+BLINK+" and tears flesh!"+NORM+"\n");
  attacker->hit_player(4+random(4)+random(4)+random(4), "other|wind");
    return 1;
  }

 if(ice==0){
    if(!attacker) return 1;
    write(BLU+BLINK+"The "+HIC+"Chaos Axe"+NORM+BLU+BLINK+" becomes cold to the touch as it freezes the wound\n"+NORM);
    BLINK+BLU+say(environment()->query_name()+"s "+HIC+"Chaos Axe"+NORM+BLU+BLINK+" becomes cold to the touch as it freezes the wound\n"+NORM);
  attacker->hit_player(4+random(4)+random(4)+random(4), "other|ice"); 
  } 

 if(fire==0){
    if(!attacker) return 1;
    write(RED+BLINK+"The "+HIC+"Chaos Axe"+NORM+RED+BLINK+" becomes hot to the touch as it burns the wound!\n"+NORM);
    BLINK+RED+say(environment()->query_name()+"s "+HIC+"Chaos Axe"+NORM+RED+BLINK+" becomes hot to the touch as it burns the wound!\n"+NORM);
  attacker->hit_player(4+random(4)+random(4)+random(4), "other|fire");
  }  

   swordhit=random(1000);
   if(!random(2) && check_race(attacker)){   /* This Attack only Lights up in My area unless people use My Specific id Tags */
       if(!attacker) return 1;

        tell_room(environment(this_player()),
F9+"\n"+
F10+"\n");

        tell_room(environment(this_player()),
F11+"\n"+
F12+"\n");

       tell_room(environment(this_player()),
F13+"\n");

 
  attacker->hit_player(10+random(10), "other|light");
  attacker->hit_player(10+random(10), "other|good"); /* Only affects Specific Mobs in My area sword is designed to light up to kill these mobs */
      return 1;
	  return 1;
   }
}

check_race(object ob) {
  if(
    CO(ob,"id","broo") ||
    CO(ob,"id","chaos") ||
    CO(ob,"id","dark") ||
    CO(ob,"id","sembrak") ||
    CO(ob,"id","cacodemon") ) return 1;
  else return 0;
}


