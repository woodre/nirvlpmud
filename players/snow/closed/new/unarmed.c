#include "/players/dune/closed/guild/DEFS.h"
inherit "/players/dune/closed/guild/snow/weapons/wepmanager";

#define NI        RED+"*~*"+OFF
#define MIN_BONUS RED+"Fire"+OFF


object master;
int totaldam, alv;

query_totaldam()  { return prof; }
set_totaldam(num) { prof = num; }
mod_totaldam(num) { prof += num; }

string side() {
  if(random(2) == 1) return "left";
  return "right";
}

short() {}

reset(arg) {
  int artwc;
  string ninshort;
  ::reset(arg);
  if (arg) return;

  master = this_player();
  artwc = -10;
  if(IPTP) {
    alv = (int)IPTP->query_art_level();
    artwc = (alv / 2) + 6;
    if((int)TP->query_level() < 20) { if (artwc > 14) artwc = 14; }
  }
 
  set_name("unarmed");
  set_alias("chi");
  set_class(artwc);
  set_weight(0);
  set_hit_func(this_object());
  ninjaWeapon();
  call_out("wep_beat",5);
}


void ninjaWeapon() {
  /* Guild Weapon Settings, defined by Weapon Manager */
  set_base_chance(random(alv * 5));

  set_aura_attack(          81, alv * 2);
  set_min_bonus(        61, 90); /* no max bonus attack for hands */
  set_multi_attack(     46, 80);
  set_max_attack(       36, 45, "standard",     random(alv) + random(alv/3));
  set_med_attack(       26, 35, "standard",     random(alv/3) + 2);
  set_min_attack(       16, 25, "hit_location", random(alv/5));
 
  set_msg("min_bonus_private", 
"Streams of "+MIN_BONUS+" violently billow your fists!\n");
  set_msg("min_bonus_public", 
"Streams of "+MIN_BONUS+" violently billow around "+TPN+"'s fists!\n");

  set_msg("min_attack_private", 
NI+"You smash your "+side()+" foot into "+meatn+"'s ");
  set_msg("min_attack_public", 
NI+TPN+" smashes "+TP->POS+" "+side()+" foot into "+meatn+"'s ");

  set_msg("extra_min1_private", 
NI+"You jab your "+side()+" hand into "+meatn+"'s ");
  set_msg("extra_min1_public", 
NI+TPN+" jabs "+TP->POS+" "+side()+" hand into "+meatn+"'s ");

  set_msg("med_attack_private", 
NI+"You whirl with blinding speed.\n"+
NI+"You sweep your "+side()+" leg behind and through "+meatn+"'s legs!\n"+
meatn+"'s legs crumple as "+meatn+" falls.\n"+
NI+"You spit on "+meatn+"'s pitiful, prone form.\n");
  set_msg("med_attack_public", 
NI+TPN+" whirls with blinding speed.\n"+
NI+TPN+" sweeps "+TP->POS+" "+side()+" leg behind and through "+
meatn+"'s legs!\n"+meatn+"'s legs crumple as "+meatn+" falls.\n"+
NI+TPN+" spits on "+meatn+"'s pitiful, prone form.\n");

  set_msg("extra_med1_private", 
NI+"You gracefully whirl in close to "+meatn+".\n"+
NI+"You lift your "+side()+" elbow smashing into "+meatn+"'s face!\n"+
NI+BOLD+"CCRRRRRAAAAACCCCCCCCKKKKKKKKK!!!!!!!!!!"+OFF+"\n"+
meatn+" stumbles backward in a daze.\n");
  set_msg("extra_med1_public", 
NI+TPN+" gracefully whirls in close to "+meatn+".\n"+
NI+TPN+" lifts "+TP->POS+" "+side()+" elbow smashing into "+
meatn+"'s face!\n"+
NI+BOLD+"CCRRRRRAAAAACCCCCCCCKKKKKKKKK!!!!!!!!!!"+OFF+"\n"+
meatn+" stumbles backward in a daze.\n");

  set_msg("extra_med2_private", 
NI+"You raise your hands to the heavens.\n"+
NI+"Your hands are wreathed in black "+
BOLD+"energy"+OFF+"!\n"+
NI+"You plunge your hands into "+meatn+".\n"+
meatn+"'s body writhes in arcs of "+
YELLOW+"electricity"+OFF+"!\n");
  set_msg("extra_med2_public", 
NI+TPN+" raises "+TP->POS+" hands to the heavens.\n"+
NI+TPN+"'s hands are wreathed with black "+
BOLD+"energy"+OFF+"!\n"+
NI+TPN+" plunges "+TP->POS+" hands into "+meatn+".\n"+
meatn+"'s body writhes in arcs of "+
YELLOW+"electricity"+OFF+"!\n");

  set_msg("extra_med3_private", 
NI+BOLD+"Lightning"+OFF+
" crackles down the length of your forearm.\n"+
NI+"You deliver a punishing strike to "+meatn+"'s throat!\n"+
NI+meatn+" screams as "+BOLD+"lightning"+OFF+
" pours from his mouth, nose, and eyes!\n");
  set_msg("extra_med3_public", 
NI+BOLD+"Lightning"+OFF+
" crackles down the length of "+TPN+"'s forearm.\n"+
NI+TPN+" delivers a punishing strike to "+meatn+"'s throat!\n"+
NI+meatn+" screams as "+BOLD+"lightning"+OFF+
" pours from his mouth, nose, and eyes!\n");

  set_msg("extra_med4_private", 
NI+"You glide gracefully behind your opponent.\n"+
NI+"You smash your fist into "+meatn+"'s kidney.\n"+
NI+meatn+" doubles over in excruciating pain!\n");
  set_msg("extra_med4_public", 
NI+TPN+" glides gracefully behind "+TP->POS+" opponent.\n"+
NI+TPN+" smashes "+TP->POS+" fist into "+meatn+"'s kidney.\n"+
NI+meatn+" doubles over in excruciating pain!\n");

  set_msg("max_attack_private", 
NI+"You flip high into the air!\n"+
NI+"You blur as you descend.\n"+
NI+"Your hands and feet "+BOLD+"flash"+OFF+" out!\n"+
meatn+"'s eyes widen in fear and horror.\n"+
NI+REV_RED+"TTTHHHHHAAAAAACCCCCCCCCCKKKKK!!!!!!!!!"+OFF+"\n"+
meatn+"'s throat appears to be crushed!\n"+
meatn+" gurgles in helpless pain.\n");
  set_msg("max_attack_public", 
NI+TPN+" flips high into the air!\n"+
NI+TPN+" blurs as "+TP->POS+" descends.\n"+
NI+TPN+"'s hands and feet "+BOLD+"flash"+OFF+" out!\n"+
meatn+"'s eyes widen in fear and horror.\n"+
NI+REV_RED+"TTTHHHHHAAAAAACCCCCCCCCCKKKKK!!!!!!!!!"+OFF+"\n"+
meatn+"'s throat appears to be crushed!\n"+
meatn+" gurgles in helpless pain.\n");
}


wep_beat() {
  object myenv;
  myenv = environment(this_object());
  if(!myenv) return 1;
  if(!master) { 
    destruct(this_object()); 
    return 1; 
  }
  if(myenv != master 
  && myenv->is_player() 
  && this_object()->wielded()) {
    myenv->stop_wielding(); 
    destruct(this_object()); 
    return 1; 
  }
  if(!myenv->is_player()) destruct(this_object());
  call_out("wep_beat",25);
  return 1;
}
