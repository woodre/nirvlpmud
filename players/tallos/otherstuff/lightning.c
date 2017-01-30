/*
//  Lightning Bolt ver 2.1 [rewritten] 2005.03.13 -Forbin
//    Rewritten with dtype added and more attack messages,
//    WC lowered and returns tweaked
//    [change] -Forbin
//      Weapon no longer wears, but weapon has a charge that wears
//      off with each special.  When the charge is 0, the weapon 
/       specials no long go off.
*/

#include "/players/saber/closed/esc.h"
#include "/players/saber/closed/ansi.h"
#define ME capitalize((string)you->query_name())
#define ATK capitalize((string)atk->query_name())
#define LB (!random(2) ? HIY+"Bolt of Lightning"+NORM : HIY+"Lightning Bolt"+NORM)
#define CHARGE 3000

inherit "obj/weapon.c";

object you;
int arraydef;
int charge;
string *hits1, *hits2;  

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("bolt of lightning");
  set_alias("bolt");
  set_type("lightning");
  set_short(HIY+"A Bolt of Lightning"+NORM);
  set_long(
    "A softly "+HIY+"glowing"+NORM+" bolt of lightning.  The air around\n"+
    "it crackles and sizzles as electricity flows along its length.\n"+
    "It looks like it would make an incredible weapon.\n");
  set_class(20); /* [change] -Forbin :: WC lowered from original 21 */
  charge = CHARGE;
  set_weight(9);
  set_wep_light(2);
  set_value(3000);
  set_hit_func(this_object());
    
  message_hit=({
    "smashed the "+LB+" into","",
    "ripped open"," with a vicious slice",
    "tore into"," with the "+LB+"",
    "slashed open","",
    "slashed",", zapping them",
    "stuck the "+LB+" into","",
    "hit"," with the "+LB+"",
    "swung wide of","",
  });    
}

short() {
  string tmp_short;
  if(!this_player()) return short_desc;
  tmp_short = short_desc;
  if(!tmp_short)
    tmp_short = "";
  if(this_player()->query_level() > 99)
    tmp_short += HIY+"  [CHARGE: "+NORM+charge+HIY+"]"+NORM;
  if(this_player()->query_level() > 30)
    tmp_short += HIY+"  <"+NORM+" wc " + class_of_weapon + ""+HIY+","+NORM+""+eff_wc + " "+HIY+">"+NORM;
  if(broke)
    tmp_short += HIY+" ["+NORM+"BROKEN"+HIY+"]"+NORM;
  tmp_short += enchant_shorts();
  if(offwielded) {
    if(offwield_desc)
      tmp_short += HIY+" ("+NORM+offwield_desc+HIY+")"+NORM;
    else
      tmp_short += HIY+" ("+NORM+"offwielded"+HIY+")"+NORM;
  } else if(wielded)
    tmp_short += HIY+" ("+NORM+"wielded"+HIY+")"+NORM;
  return tmp_short == "" ? 0 : tmp_short;
}

long() {
	write(
    "An oddly stable bolt of lightning almost 5 feet long.  The air\n"+
    "around it crackles and sizzles as electricity flows up and down\n"+
    "along length.  It seems alive as it pulses and shimmers at very\n"+
    "irregular intervals. The bolt ");
    if(charge > CHARGE * 9 / 10) 
      write("is glowing brightly");
    if(charge > CHARGE * 7 / 10 && charge <= CHARGE * 9 / 10)
      write("is glowing");
    if(charge > CHARGE * 5 / 10 && charge <= CHARGE * 7 / 10)
      write("is fading");
    if(charge > CHARGE * 3 / 10 && charge <= CHARGE * 5 / 10)
      write("is faded");
    if(charge > CHARGE / 10 && charge <= CHARGE * 3 / 10)
      write("is pale");
    if(charge <= CHARGE / 10)  
      write("is barely visible");
   write(
     " and it appears\n"+
     "that it would make an incredible weapon if wielded.\n");
}

void define_arrays() {
  arraydef = 1;
  hits1 =({
    "You swing the "+LB+" in front of you.\n",
    "You bring the "+LB+" downward across your body.\n",
    "You bring the "+LB+" upward across your body.\n",    
    "You leap forward with the "+LB+".\n",
    "You step left, slashing with the "+LB+".\n",
    "You step right, slashing with the "+LB+".\n",    
    "You twirl the "+LB+" deftly around your body.\n",
    "You lash out with the "+LB+".\n",
    "You spin the "+LB+" in your hand.\n",
    "You prepare to strike with the "+LB+".\n",
    "You hold the "+LB+" triumphantly overhead.\n",
    "You swing the "+LB+" quickly through the air.\n",
    "You swing the "+LB+" in an 'X' through the air.\n",
    "You lean back, defending with the "+LB+".\n",
    "You bring the "+LB+" crashing down from overhead.\n",
    "You point at your attacker with the "+LB+".\n",
  });
  
  hits2 =({
    ME+" swings the "+LB+" in front of "+you->query_objective()+".\n",
    ME+" brings the "+LB+" downward across "+you->query_possessive()+" body.\n",
    ME+" brings the "+LB+" upward across "+you->query_possessive()+" body.\n",    
    ME+" leaps forward with the "+LB+".\n",
    ME+" steps left, slashing with the "+LB+".\n",
    ME+" steps right, slashing with the "+LB+".\n",    
    ME+" twirls the "+LB+" deftly around "+you->query_possessive()+" body.\n",
    ME+" lashes out with the "+LB+".\n",
    ME+" spins the "+LB+" in "+you->query_possessive()+" hand.\n",
    ME+" prepares to strike with the "+LB+".\n",
    ME+" holds the "+LB+" triumphantly overhead.\n",
    ME+" swings the "+LB+" quickly through the air.\n",
    ME+" swings the "+LB+" in an 'X' through the air.\n",
    ME+" leans back, defending with the "+LB+".\n",
    ME+" brings the "+LB+" crashing down from overhead.\n",
    ME+" points at "+you->query_possessive()+"'s attacker with the "+LB+".\n",        
  });  
}

weapon_hit(attacker) {
  object atk;
  int a, b;
  this_object()->set_hits(0);
  this_object()->set_misses(0);  
  you = environment();
  atk = attacker;
  if(!arraydef) 
    define_arrays();
  a = random(sizeof(hits1));
  b = random(26);

  if(!random(3)) {
    tell_object(environment(), hits1[a]);
    tell_room(environment(you), hits2[a], ({ environment() }));
  }
    
  if(!charge) return;    
    
  switch(b) {
    case 0: /* 3% change of damage to player */
      tell_object(environment(), 
        "There is a bright burst of electic energy.\n"+
        "You are shocked by backlash from the "+LB+".\n");
      tell_room(environment(you), 
        "There is a bright burst of electic energy.\n"+
        ME+" is shocked by backlash from the "+LB+".\n", ({ you }));
      you->hit_player(10+random(10), "other|electric");
      return 0;
      break;
    case 1: /* 3% chance */
      tell_object(environment(), 
        "You rush forward, driving the "+LB+" into "+ATK+"..\n\n"+
        "              "+HIY+"-~-~-~ "+HIW+"F L A S H "+HIY+"~-~-~-"+NORM+"\n\n"+
        ATK+" is blasted by "+HIY+"electricity"+NORM+".\n\n");
      tell_room(environment(you), 
        ME+" rushes forward, driving the "+LB+" into "+ATK+"...\n\n"+
        "              "+HIY+"-~-~-~ "+HIW+"F L A S H "+HIY+"~-~-~-"+NORM+"\n\n"+
        ATK+" is blasted by "+HIY+"electricity"+NORM+".\n\n", ({ you }));     
      charge -= 7;
      atk->hit_player(6+random(6), "other|electric");          
      return 3;
      break;
    case 2: /* 3% chance */
      tell_object(environment(), 
        "You thrust the "+LB+" overhead with both hands and scream...\n\n"+
        "\tThe sky flashes bright with "+HIY+"lightning"+NORM+"...\n"+
        "\t\tA tremendous "+HIB+"B  O  O  M"+NORM+" rolls from the heavens...\n\n"+
        ATK+" crumbles from the elemental assualt.\n\n");
      tell_room(environment(you), 
        ME+" thrusts the "+LB+" overhead with both hands and screams...\n\n"+
        "\tThe sky flashes bright with "+HIY+"lightning"+NORM+"...\n"+
        "\t\tA tremendous "+HIB+"B  O  O  M"+NORM+" rolls from the heavens...\n\n"+
        ATK+" crumbles from the elemental assualt.\n\n", ({ you }));
      charge -= 7;             
      atk->hit_player(2+random(3), "other|electric");          
      atk->hit_player(2+random(3), "other|electric");                
      return 0;
      break;      
    case 3..4: /* 7% chance */
      tell_object(environment(), 
        "You plunge the "+LB+" into the ground...\n\n"+
        "A streak of "+HIY+"electricity"+NORM+
        " surges across the space between you and your\n"+
        "attacker, jolting "+ATK+" with a burst of current.\n\n"); 
      tell_room(environment(you), 
        ME+" plunges the "+LB+" into the ground...\n\n"+
        "A streak of "+HIY+"electricity"+NORM+
        " surges across the space between "+
        you->query_objective()+" and "+you->query_possessive()+
        "\nattacker, jolting "+ATK+" with a burst of current.\n\n", ({ you }));      
      charge -= 5;
      atk->hit_player(2+random(3), "other|electric");          
      return 0;    
      break;
    case 5..6: /* 7% chance */
      tell_object(environment(), 
        "You hold the "+LB+" outstretched in front of you..\n\n"+
        "\tA bolt of "+
        (!random(2) ? HIW+"EnERgy"+NORM : HIW+"ENeRgY"+NORM)+
        " streaks into "+ATK+".\n\n");
      tell_room(environment(you), 
        ME+" holds the "+LB+" outstretched in front of "+
        you->query_objective()+"self..\n\n"+
        "\tA bolt of "+
        (!random(2) ? HIW+"EnERgy"+NORM : HIW+"ENeRgY"+NORM)+
        " streaks into "+ATK+".\n\n", ({ you })); 
      charge -= 4;      
      atk->hit_player(1+random(3), "other|electric");          
      return 0;    
      break;
    case 7..9: /* 11% chance */
      tell_object(environment(), 
        "\nYou hurl the "+LB+" through the air at "+ATK+"...\n"+
        "It hits the mark, zapping "+ATK+" and stunning "+
        atk->query_objective()+", before\n"+
        "returning to your grasp.\n\n");
      tell_room(environment(you),"\n"+ 
        ME+" hurls the "+LB+" through the air at "+ATK+"...\n"+
        "It hits the mark, zapping "+ATK+" and stunning "+
        atk->query_objective()+", before\n"+
        "returning to "+ME+"'s grasp.\n\n", ({ you })); 
      charge -= 3;    
      atk->hit_player(1+random(2), "other|electric");          
      return 2;
      break;    
    case 10..1000:
      break;
  }  
}

quest_ob() { return 1; }
