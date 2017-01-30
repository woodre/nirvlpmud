/* "Prestige Weapons" Damage in fire and ice return would like to be a growth like
   Prestige AC or WC Talk to Drag About it get the formula from him*/
   
    /* Dual Axe
 HITS: 808       Rounds: 1000     Average: 2570   Max: 112  One Special Just Ice Just Fire. 
 HITS: 808       Rounds: 1000     Average: 2602   Max: 115  With Both Fire and Ice both weapons
    */

inherit "/obj/weapon.c";
#include "/players/jareel/define.h"

#define CO call_other
#define SETNAME HIG+"Set of the Berzerker"+NORM
#define FULLSETNAME HIG+"Full Set of the Berzerker"+NORM
#define WEP BOLD+"||"+NORM
#define  F1      HIR+"             (  "+NORM+RED+".     "+HIR+" )"+NORM
#define  F2      HIR+"         )           (              )"+NORM
#define  F3      HIR+"               "+NORM+RED+".  '   "+NORM+RED+".   '  "+NORM+RED+".  '  "+NORM+RED+"."+NORM
#define  F4      HIR+"      (    "+NORM+RED+","+HIR+" )       ("+NORM+RED+".  "+HIR+" )  (   '"+NORM+RED+", "+HIR+"   )"+NORM
#define  F5      HIR+"       "+NORM+RED+".' "+HIR+") ( "+NORM+RED+". "+HIR+")    "+NORM+RED+", "+HIR+" ( "+NORM+RED+",  "+HIR+"   )   ( "+NORM+RED+"."+NORM
#define  F6      HIR+"    )"+NORM+RED+". , "+HIR+"( "+NORM+RED+"."+HIR+"   (  ) ( "+NORM+RED+", '"+HIR+")  "+NORM+RED+".'"+HIR+" (  "+NORM+RED+",  "+HIR+"  )"+NORM
#define  F7      HIR+"   (_"+NORM+RED+","+HIR+") "+NORM+RED+"."+HIR+" )"+NORM+RED+","+HIR+" ) _) _"+NORM+RED+",'"+HIR+")  ("+NORM+RED+","+HIR+" ) '"+NORM+RED+". "+HIR+")  "+NORM+RED+",. "+HIR+"(' )"+NORM
#define  F8      RED+"^<^"+BLU+">^<^>^<^>"+HIK+"^^D E M O N  F I R E^^<^>^<"+NORM+BLU+"^>^<"+RED+"^>^"+NORM

#define  F9 HIW+"   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *"+NORM
#define  F10 HIW+"   *     *     *     *     *     *     *     *     *     *     *     * "+NORM
#define  F11 HIW+" *     *     *     *     *     *     *     *     *     *     *     *"+NORM
#define  F12 HIW+"*   *    *   *   *   *   *   *   *   *   *   *   *   *   *    *   *  *"+NORM

object ob;


string *Weapon_pieces_The_Duo;

  reset(arg) {
    ::reset(arg);

  set_name("axe of the berzerker");
  set_value(4200);
  set_class(20);
  set_weight(1);
  set_type("axe");
  set_short(RED+"The Berserker Axe '"+HIW+"Roar"+NORM+RED+"' "+HIK+"["+HIC+" Chaos Honed "+HIK+"]"+NORM+" ["+SETNAME+"]"+NORM);
  set_long(
    "An Axe forged in the Hell fires of the Stormbull Gods high\n"+ 
	"blacksmith Hrgorn, the Deft. A palpable clinging darkness\n"+ 
	"seeps out of the magical Axe.  The encircling darkness\n"+
	"seems to empower the magical energy within the encrusted\n"+ 
	"Ward, great power lies within\n");

                     /* PUT THE ID FOR THE SET HERE */
  set_hit_func(this_object());
  
  Weapon_pieces_The_Duo = ({ "ChaosAxeRoar", "ChaosAxeBite" });
}

status id(string arg) { return ( ::id(arg) || arg == "ChaosAxeRoar" || arg == "axe of roar"); }

int wield(string str) { 

if (str && !id(str)) return 0;

if ((int)this_player()->query_prestige_level() < 1) {
  write("This weapon is too powerful for you to Wield.\n"); 
  return 1; 
}

  return (::wield(str) ? 1 : 0);
}

status check_full_set() {
  object wep, who;

  if(!USER) return 0;

  wep = present( "ChaosAxeBite", USER ); 
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
    set_short(RED+"The Berserker Axe '"+HIW+"Roar"+NORM+RED+"' "+HIK+"["+HIC+" Chaos Honed "+HIK+"]"+NORM+" ["+FULLSETNAME+"]"+NORM);
  else
    set_short(RED+"Berserker Axe '"+HIW+"Roar"+NORM+RED+"' "+HIK+"["+HIC+" Chaos Honed "+HIK+"]"+NORM+" ["+SETNAME+"]"+NORM+""+NORM);
  return (string) ::short();
}

weapon_hit(attacker) {
     int swordhit;
	 int swordhit2;
     int electric; /* Electric */
	 int poison;   /* Poison */
     int earth;   /* Earth */

if( !attacker )
    return 1;
	 
  if( !check_full_set() ) 
    return 0;

 electric = random(4);
 poison = random(4);
 earth = random(4);
 
  if (electric==0){
    if(!attacker) return 1;
	  write("\n"+HIW+BLINK+"Lightning arcs off the sheen of the "+HIC+"Chaos Axe!\n     "+NORM);
	  HIW+BLINK+say(environment()->query_name()+" arcs Lightning off the gleaming "+HIC+"Chaos Axe!"+NORM+"\n");
        attacker->hit_player(4+random(4)+random(4)+random(4), "other|electric");
  }

 if(poison==0){
    if(!attacker) return 1;
      write(HIG+BLINK+"The "+HIC+"Chaos Axe"+NORM+HIG+BLINK+" sinks deep infecting the new gaping wound!\n"+NORM);
      HIG+BLINK+say(environment()->query_name()+" infects a new wound!\n"+NORM);
        attacker->hit_player(4+random(4)+random(4)+random(4), "other|poison"); 
  } 

 if(earth==0){
    if(!attacker) return 1;
      write(YEL+BLINK+"The "+HIC+"Chaos Axe"+NORM+YEL+BLINK+" causes the earth to rumble!\n"+NORM);
      BLINK+say(environment()->query_name()+"s "+HIC+"Chaos Axe"+NORM+HIG+BLINK+" causes the earth to rumble!\n"+NORM);
        attacker->hit_player(4+random(4)+random(4)+random(4), "other|earth");
  }  

  swordhit=random(1000);
    if(!attacker) return 1;
      if(!random(2) && check_race(attacker)){ /* This Attack only Lights up in My area unless people use My Specific id Tags */
      

        tell_room(environment(this_player()),
F1+"\n"+
F2+"\n");

        tell_room(environment(this_player()),
F3+"\n"+
F4+"\n");

        tell_room(environment(this_player()),
F5+"\n"+
F6+"\n");

        tell_room(environment(this_player()),
F7+"\n"+
F8+"\n");

  attacker->hit_player(20+random(20), "other|evil"); /* Only affects Specific Mobs in My area sword is designed to light up to kill these mobs */
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

