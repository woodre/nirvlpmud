/*
 *  Weapons Mastery
 *
 *    Low level attacks for Bards
 *
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

weapon_mast(str)  {
object TO_HIT;
string HIT_ME, OPPONENT, COPPONENT, WEAPON;
int DAMAGE, OPPO, ATTACK_TYPE, WACK, TYPE;

  WACK = 0;
  
  if(!str && TP->query_attack())  {
    str = TP->query_attack()->query_real_name();
        }
  
  if(!str)  {
    write("Weapons Mastery must be used on a creature.\n");
    write("Syntax: we < target > < optional: amount >\n");
    return 1;
        }

  if(sscanf(str, "%s %d", HIT_ME, DAMAGE) < 2)  { sscanf(str, "%s", HIT_ME); }         
   
  if(TP->query_wc() < 4)  {
    write("You must wield a weapon to use Weapons Mastery.\n");
    return 1;
        }
  
  if(BLVL > 5 && HIT_ME != lower_case(HIT_ME))  { WACK = 1; }

  if(!(TO_HIT = present(lower_case(HIT_ME), ENV)))  {
    write("You do not see a \n");
    return 1;
        }
          
  if(DAMAGE > 0)  { if(attack_spell(-3000,2,DAMAGE,TO_HIT) == -1) return 0; }
  else if(attack_spell(-3000,2,10,TO_HIT) == -1) return 0;
  
  if(DAMAGE > BLVL + TP->query_attrib("str") || DAMAGE < 1)  
      {  DAMAGE = BLVL + TP->query_attrib("str");  }
  if(DAMAGE > 25) DAMAGE = 25; 


        if(BLVL <  3            ) ATTACK_TYPE = 5;
   else if(BLVL > 2 && BLVL < 6 ) ATTACK_TYPE = 5;
   else if(BLVL > 5             ) ATTACK_TYPE = 5;

  OPPONENT = lower_case(TO_HIT->short());
  COPPONENT = TO_HIT->query_name();
  WEAPON = TP->query_weapon()->query_name();

  TYPE = random(ATTACK_TYPE);

/* Basic Attacks */
if(TYPE == 0)  {
  write("\nSpinning wildly, you "+BOLD+"WACK"+NORM+" "+OPPONENT+" with your "+WEAPON+".\n\n");
  say("\n"+tp+" spins wildly, "+BOLD+"WACKING"+NORM+" "+OPPONENT+" with "+POSS+" "+WEAPON+".\n\n");
  }

else if(TYPE == 1)  {
  write("\nYou pull a handfull of marbles from your pouch & throw them to the ground.\n\n"+
        COPPONENT+" flails wildly and then falls to the ground with a  "+BOLD+"> > T H U D < <"+NORM+"\n"+
        "You lunge forward and kick "+OPPONENT+" in the head.\n\n");
  say("\n"+tp+" pulls a handfull of marbles from "+POSS+" pouch & throws them to the ground.\n\n"+
      COPPONENT+" flails wildly and then falls to the ground with a "+BOLD+"> > T H U D < <"+NORM+".\n"+
      tp+" lunges forward and kicks "+OPPONENT+" in the head.\n\n");
  }

else if(TYPE == 2)  {
  write("\nLunging forward, you duck under "+COPPONENT+"'s guard.\n"+
        "Swinging your "+WEAPON+", you smash "+COPPONENT+" with a mighty blow.\n\n");
  say("\n"+tp+" lunges forward, ducking under "+COPPONENT+"'s guard.\n"+
        "Swinging "+POSS+" "+WEAPON+", "+tp+" smashes "+OPPONENT+" with a mighty blow.\n\n");
  }

else if(TYPE == 3)  {
  write("\Tumbling forward, you come up behind "+OPPONENT+".\n"+
        "Screaming loudly, you hammer "+COPPONENT+" in the head with your "+WEAPON+".\n\n");
  say("\n"+tp+" tumbles forward, coming up behind "+OPPONENT+".\n"+
        "Screaming loudly, "+tp+" hammers "+COPPONENT+" in the head with "+POSS+" "+WEAPON+".\n\n");
  }

else if(TYPE == 4)  {
  write("\Parrying "+COPPONENT+"'s attack with your "+WEAPON+", you draw your knife and\n"+
        "slash "+COPPONENT+" across the face.\n\n");
  say("\n"+tp+" parries "+COPPONENT+"'s attack with "+POSS+" "+WEAPON+" as "+PRO+" draws a knife and\n"+
        "slashes "+COPPONENT+" across the face.\n\n");
  }
/* End Basic Attacks */

   TP->attack_object(TO_HIT);
   TO_HIT->hit_player(random(DAMAGE*2));
  if(WACK)  TO_HIT->attack_object(TP);

   OPPO = TO_HIT->query_hp() * 100 / TO_HIT->query_mhp();
   write(BOLD+"[ "+OPPO+"% opponent ]\n"+NORM);

  call_other(TP, "add_spell_points", -DAMAGE);
  return 1;
  
        }
