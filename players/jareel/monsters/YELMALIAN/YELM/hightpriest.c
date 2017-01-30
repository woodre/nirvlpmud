inherit "/obj/monster";
#include "/players/jareel/define.h"
#define NAME HIY+"L"+NORM+BOLD+"ady "+HIY+"V"+NORM+BOLD+"ega "+HIY+"G"+NORM+BOLD+"oldbreath"+NORM+", "+HIY+"G"+NORM+BOLD+"uardian of the "+HIY+"S"+NORM+BOLD+"un "+HIY+"C"+NORM+BOLD+"ountry"
#define NAME1 HIY+"L"+NORM+BOLD+"ady "+HIY+"V"+NORM+BOLD+"ega "+HIY+"G"+NORM+BOLD+"oldbreath"+NORM+""
#define HIT1 "\n          -------------------------------\n"
#define HIT2 "          Lady Vega unleashes a Sunspear!\n"
#define HIT3 "          -------------------------------\n\n"
#define HIT4 "              An Allied spirit attacks\n"
#define HIT5 "           Vega unleashes a glowing force\n"
int K;

reset(arg) {
  
  ::reset(arg);
  if (arg) return;

  set_alias("vega");
  set_alt_name("goldbreath");
  set_name(NAME1+NORM);
  set_race("human");
  set_al(-1000);
  set_level(24);
  set_aggressive(0);
  set_hp(800+random(600));
  add_money(17000+random(7000));
  set_ac(10+random(20));
  set_heal(40,1);
  set_wc(5);
  set_armor_params("other|evil",0,100,"prot_from_evil");  
  set_armor_params("other|electric",0,10,"prot_from_electric"); 
  set_armor_params("other|good",0,10,"prot_from_good"); 
  set_armor_params("other|earth",0,20,"prot_from_earth"); 
  set_armor_params("other|light",0,90,"prot_from_light"); 
  set_dead_ob(this_object());
  set_short(NAME+NORM);
  set_long(BOLD+HIY+
    "Lady Vega Goldbreath is the Highpriest guardian of Sun Country.  Blessing \n"+
    "all that surround her in a warm golden light.  Lady Vega has no flaw the \n"+
    "curve of her form and grace of her stance show her as a master of her art.\n"+
    "She radiates power.\n"+
    "\n"+NORM);
    
  /* Not sure what was up with these spells.  Updating with more reasonable damage
     chances, but they can now hit any attacker
     */
  add_spell(
    "light hit","\n\
          -------------------------------\n\
        Lady Vega unleashes a Sunspear on you!\n\
          -------------------------------\n\n",
"Lady Vega hits #TN# with a Sunspear!\n",    
    40,"6d6+20","other|light");

  add_spell(
    "beam charge","\n\
          -------------------------------\n\
       Lady Vega unleashes a a glowing force on you!\n\
          -------------------------------\n\n",
"Lady Vega hits #TN# with a glowing force!\n",    

    20,"3d6+10","other|light",6);
    
  add_spell(
    "spirit_aid","\n\
          -------------------------------\n\
            An Allied spirit attacks you!\n\
          -------------------------------\n\n",
"      Lady Vega hits #TN# with an allied spirit!\n",    

    20,"3d6+10","other|light",6);    
    
    /* exp bonus for the extra attacks */
    set_wc_bonus((this_object()->query_damage_potential() + this_object()->query_spell_exp())*2);
}

prot_from_evil(){
    write(HIK+"Evil flows over Lady Vega's aura of Protection.\n"+NORM);
  return 1;
}

prot_from_electric(){  
    write(HBBLU+"Sparks flash off Lady Vega's Aura.\n"+NORM);
  return 1;
}

prot_from_good(){   
    write(BOLD+"Lady Vega's aura flickers.\n"+NORM);
  return 1;
}

prot_from_light(){   
    write(HBYEL+"Lady Vega absorbs the the light attack.\n"+NORM);
  return 1;
}

prot_from_earth(){   
    write(YEL+"Lady Vega's aura flickers.\n"+NORM);
  return 1;
}

monster_died() {
}

heart_beat() {
  ::heart_beat();
  if(attacker_ob) {
    already_fight=0;
    attack();
  }
  if(attacker_ob) {
    already_fight=0;
    attack();
  }
}
