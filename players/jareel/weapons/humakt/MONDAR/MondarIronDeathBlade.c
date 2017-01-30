/* "Prestige Weapon" Damage in fire and ice return would like to be a growth like
   Prestige AC or WC Talk to Drag About it get the formula from him*/
   
    /* Dual Sword
 HITS: 808       Rounds: 1000     Average: 2570   Max: 112  One Special Just Ice Just Fire. 
 HITS: 808       Rounds: 1000     Average: 2602   Max: 115  With Both Fire and Ice both weapons
    */

inherit "/obj/weapon.c";
#include "/players/jareel/define.h"

#define CO call_other
#define FULLSETNAME GRN+"Set of Truth"+NORM

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

  set_name("iron death blade");
  set_value(4200);
  set_class(20);
  set_weight(1);
  set_type("sword");
  set_short(HIK+"Iron Death Blade"+NORM+NORM);
  set_long(
    "An Axe forged in the Hell fires of the Stormbull Gods high\n"+ 
	"blacksmith Hrgorn, the Deft. A palpable clinging darkness\n"+ 
	"seeps out of the magical Axe.  The encircling darkness\n"+
	"seems to empower the magical energy within the encrusted\n"+ 
	"Ward, great power lies within\n");

                     /* PUT THE ID FOR THE SET HERE */
  set_hit_func(this_object());
  
  Weapon_pieces_The_Duo = ({ "MondorIronDeathBlade", "GHUWYTSJI@&^SGBEJILSO" });
}

status id(string arg) { return ( ::id(arg) || arg == "MondarIronDeathBlade" || arg == "XIUHYSLKUGYJO*(US#)!"); }

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

  wep = present( "GHUWYTSJI@&^SGBEJILSO", USER ); 
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
    set_short(HIK+"The Iron Death Blade "+HIK+"["+HIC+" The Edge of Truth "+HIK+"]"+NORM+" ["+FULLSETNAME+"]"+NORM);
  else
    set_short(HIK+"The Iron Death Blade "+HIK+NORM+NORM);
  return (string) ::short();
}

weapon_hit(attacker) {


     int ATTACKONE;
	 int ATTACKTWO;
     int ATTACKTHREE; 
	 int ATTACKFOUR;   
     int ATTACKFIVE;   
     int ATTACKSIX;
	 int ATTACKSEVEN;

  if(!MEAT) return 0; 
   skill_hit();

 ATTACKONE = random(4);
 ATTACKTWO = random(4);
 ATTACKTHREE = random(4);
 ATTACKFOUR = random(4);
 ATTACKFIVE = random(4);
 ATTACKSIX = random(4);
 ATTACKSEVEN = random(4);
 
 
skill_hit() {
  object meat;
  meat = this_player()->query_attack();
  if(!meat) return 1;
  if(random(TPI) > random(90)) str_hit(meat);  /* Staff Will Fire Special*/ 
  if(random(TPM) > random(90)) wil_hit(meat);  /* Staff Will Fire Special*/
return 1;
}
  
str_hit(object ob) {
  int lev; string name;
  lev = TPL + (TPXL/2);
  if(!ob) return;
  name = ob->query_name();  
    get_message();
  return 1; 
}
  
wil_hit(object ob) {
  int lev; string name;
  lev = TPL + (TPXL/2);
  if(!ob) return;
  name = ob->query_name();  
    get_message();
  return 1;
}

  if( !check_full_set() ) 
    if(!random(2) && check_race(attacker)){ /* This Attack only Lights up in My area unless people use My Specific id Tags */
      if(!attacker) return 1;

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

  attacker->do_damage(20+random(20), "other|evil"); /* Only affects Specific Mobs in My area sword is designed to light up to kill these mobs */
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


get_message(object ob)
{
  int lev; string name;
  lev = TPL + (TPXL/2);
  if(!ob) return;
  name = ob->query_name();
if(environment(TP)){
if(!attacker) return 1;
	  switch(random(4))
      {

         case 0:
         {
         	
       tell_room(environment(TP),
	   if(!attacker) return 1;
               TPN+NORM+"smashed"+NORM+" the enemy with a bone crushing sound.\n");
			     ob->hit_player(lev/7, "physical");
			return 1;
         	break;
         }
         
         case 1: 
         {
		 

       tell_room(environment(TP),
	   if(!attacker) return 1;
              TPN+NORM+"massacres"+NORM+" the enemy to small fragments.");
			    ob->hit_player(lev/8, "physical");
			return 1;  
         	break;
         }
         
         case 2:
         {
         	

       tell_room(environment(TP),
	   if(!attacker) return 1;
              TPN+NORM+"hits"+NORM+" the enemy very hard.");
			    ob->hit_player(lev/10, "physical");
			return 1;  
         	break;
         }
         
         case 3: 
         {
		 

        tell_room(environment(TP),
		if(!attacker) return 1;
              TPN+NORM+"missed"+NORM,"); 
		    return 1; 
         	break;
         }
         
         
         default: 
         {
		 
       tell_room(environment(TP),
	   if(!attacker) return 1;
               TPN+NORM+"smashed"+NORM+" the enemy with a bone crushing sound.\n");
			     ob->hit_player(lev/7, "physical");
			return 1;
         	break;
         }
         
	}

}}


