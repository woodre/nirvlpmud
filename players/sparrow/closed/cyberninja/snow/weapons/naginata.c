inherit "players/dune/closed/guild/snow/weapons/wepmanager.c";
#include "../../DEFS.h"

#define NI        RED+"*~*"+OFF
#define WEP       BOLD+name+OFF
#define MIN_BONUS RED+"Fire"+OFF
#define MAX_BONUS BOLD+"Lightning"+OFF


object master;
int totaldam, alv;
string name;

query_totaldam()  { return prof; }
set_totaldam(num) { prof = num; }
mod_totaldam(num) { prof += num; }


reset (arg)
{
  int artwc;
  string ninshort;
  ::reset(arg);
  if (arg) return;

  name = "naginata";
  ninshort = "Naginata";
  if(IPTP && IPTP->query_weapon_name())
    ninshort = IPTP->query_weapon_name();
  master = this_player();
  artwc = -10;
  if(!IPTP) ninshort += " <rubber>";
  else {
    alv = (int)IPTP->query_art_level();
    artwc = (alv / 3) + 1;
    if((int)TP->query_level() < 20) { if (artwc > 6) artwc = 6; }
    if(artwc < 3)  ninshort += " <steel>";
    if(artwc == 3) ninshort += " <titanium>";
    if(artwc == 4) ninshort += " <adamantium>";
    if(artwc == 5) ninshort += " <ether-alloy>";
    if(artwc > 5)  ninshort += " <vortex-forged>"; 
  }
 
  set_name(name);
  set_alias("nagi");
  set_short(ninshort);
  set_long(
"A deadly "+FUNKYNAME+" Guild weapon, the Naginata is a polearm about\n"+
"5 1/2 feet long with a razor-edged blade and a stout black staff. When\n"+
"wielded by an expert of the art of Ninjitsu, the Naginata becomes a\n"+
"whirling instrument of destruction.\n");
  set_class(artwc + 11);
  set_weight(5);
  set_hit_func(this_object());
  ninjaWeapon();
  call_out("wep_beat",5);
}


void ninjaWeapon() {
  /* Guild Weapon Settings, defined by Weapon Manager */
  set_base_chance(random(69) + random(alv * 5) / 2);

  set_aura_attack(          106, alv * 2);
  set_max_bonus(            91);
  set_min_bonus(        71, 90);
  set_multi_attack(     91, 105);
  set_max_attack(       63, 90, "standard",     random(alv)+random(alv/2)+
                                                random(alv/3) + 6);
  set_med_attack(       52, 62, "standard",     (alv/(random(2)+2))+random(3));
  set_min_attack(       41, 51, "hit_location", random(alv/3));
 
  set_msg("min_bonus_private", 
MIN_BONUS+" races along the blade of your "+WEP+"!\n");
  set_msg("min_bonus_public", 
MIN_BONUS+" races along the blade of "+TPN+"'s "+WEP+"!\n");
  set_msg("max_bonus_private", 
MAX_BONUS+" blasts off the searing outline of your "+WEP+"!\n");
  set_msg("max_bonus_public", 
MAX_BONUS+" blasts off the searing outline of "+TPN+"'s "+WEP+"!\n");

  set_msg("min_attack_private", 
NI+"You bash the "+WEP+" staff into "+meatn+"'s ");
  set_msg("min_attack_public", 
NI+TPN+" bashes the "+WEP+" staff into "+meatn+"'s ");

  set_msg("extra_min1_private", 
NI+"You rip-slice the "+WEP+" blade into "+meatn+"'s ");
  set_msg("extra_min2_public", 
NI+TPN+" rip-slices the "+WEP+" blade into "+meatn+"'s ");

  set_msg("extra_med1_private", 
NI+"You gracefully whirl in close to "+meatn+".\n"+
NI+"You lift your "+WEP+" staff blurring toward "+meatn+"'s face!\n"+
NI+REV_BROWN+"TTTTHHHHHHHUUUUUUCCCCCCCCKKKKKKKKK"+OFF+"\n"+
meatn+" stumbles backward in a daze.\n");
  set_msg("extra_med1_public", 
NI+TPN+" gracefully whirls in close to "+meatn+".\n"+
NI+TPN+" lifts "+TP->POS+" "+WEP+" staff blurring toward "+meatn+"'s face!\n"+
NI+REV_BROWN+"TTTTHHHHHHHUUUUUUCCCCCCCCKKKKKKKKK"+OFF+"\n"+
meatn+" stumbles backward in a daze.\n");

  set_msg("extra_med2_private", 
NI+"Your "+WEP+" blade burns with a "+REV_RED+"molten"+OFF+" fury!\n"+
NI+"You charge toward your reeling foe!\n"+
NI+"You plunge your "+BOLD+"white-hot"+OFF+" "+WEP+" into "+meatn+".\n"+
meatn+" screams in burned agony!\n");
  set_msg("extra_med2_public", 
NI+TPN+"'s "+WEP+" blade burns with a "+REV_RED+"molten"+OFF+" fury!\n"+
NI+TPN+" charges toward "+TP->POS+" reeling foe!\n"+
NI+TPN+" plunges "+TP->POS+" "+BOLD+"white-hot"+OFF+" "+WEP+" into "+
meatn+".\n"+meatn+" screams in burned agony!\n");

  set_msg("med_attack_private", 
NI+"You whirl with blinding speed.\n"+
NI+"You sweep the staff of your "+WEP+" behind and through "+
meatn+"'s legs!\n"+
meatn+"'s legs crumple as "+meatn+" falls.\n"+
NI+"You spit on "+meatn+"'s pitiful, prone form.\n");
  set_msg("med_attack_public", 
NI+TPN+" whirls with blinding speed.\n"+
NI+TPN+" sweeps the shaft of "+TP->POS+" "+WEP+
" behind and through "+meatn+"'s legs!\n"+
meatn+"'s legs crumple as "+meatn+" falls.\n"+
NI+TPN+" spits on "+meatn+"'s pitiful, prone form.\n");

  set_msg("max_attack_private", 
NI+"You jump high in the air!\n"+
NI+"You hold your "+WEP+" poised above your head.\n"+
NI+"You descend upon "+meatn+" like an Angel of DEATH!\n"+
meatn+" quivers in fear and horror.\n"+
NI+REV_BROWN+"TTTTHHHHHHUUUUUUUUCCCCCCCCKKKKKKKKKK"+OFF+"\n"+
NI+"You impale "+meatn+" through the throat!\n"+
NI+"Blood spatters everywhere!\n"+
meatn+" gurgles in helpless pain.\n");
  set_msg("max_attack_public", 
NI+TPN+" jumps high into the air!\n"+
NI+TPN+" holds "+TP->POS+" "+WEP+" poised above "+TP->POS+" head.\n"+
NI+TPN+" descends upon "+meatn+" like an Angel of Death!\n"+
meatn+" quivers in fear and horror.\n"+
NI+REV_BROWN+"TTTTHHHHHHUUUUUUUUCCCCCCCCKKKKKKKKKK"+OFF+"\n"+
NI+TPN+" impales "+meatn+" through the throat!\n"+
NI+"Blood spatters everywhere!\n"+
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
